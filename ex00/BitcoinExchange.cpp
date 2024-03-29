#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange *BitcoinExchange::_instance = NULL;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::_check_valid_date(std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw "Wrong format in date";
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            throw "Wrong format in date";
    }

    std::stringstream ss(date);
    int year, month, day;
    char dash;
    bool flag = false;

    ss >> year >> dash >> month >> dash >> day;

    if (year < 2009 || month == 0 || month > 12 || day == 0 || day > 31)
        flag = true;
    else if (month == 2) {
        int leap = 0;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            ++leap;
        if (day > 28 + leap)
            flag = true;
    }
    else if (!(month & 1) && month <= 6) {
        if (day == 31)
            flag = true;
    }
    else if ((month & 1) && month >= 9) {
        if (day == 31)
            flag = true;
    }

    if (flag)
        throw "Wrong date";
}

void BitcoinExchange::_check_valid_rate(std::string &rate)
{
    int dot_cnt = 0;
    for (size_t i = 0; i < rate.length(); i++) {
        if (!std::isdigit(rate[i])) {
            if (rate[i] == '.')
                ++dot_cnt;
            else
                throw "wrong number.";
        }
    }

    if (dot_cnt > 1)
        throw "not a number.";
}

double BitcoinExchange::_check_valid_value(std::string &value)
{
    if (value[0] == '-')
        throw "not a positive number.";
    _check_valid_rate(value);
    double val = strtod(value.c_str(), NULL);
    if (val > 1000.0)
        throw "too large number.";
    return val;
}

BitcoinExchange::BitcoinExchange(const char *path)
{
    std::ifstream csv_file("./data.csv");
    if (!csv_file.is_open())
        throw "could not open data.csv file";

    std::string line;
    if (!std::getline(csv_file, line))
        throw "Empty csv file";
    if (line != "date,exchange_rate")
        throw "Wrong format in csv file";
    
    while (std::getline(csv_file, line)) {
        const size_t pos = line.find(',');
        if (pos == std::string::npos)
            throw "Wrong format in csv file";
        std::string date = line.substr(0, pos);
        std::string rate = line.substr(pos + 1);
        _check_valid_date(date);
        _check_valid_rate(rate);

        double rate_val = strtod(rate.c_str(), NULL);
        _data.insert(make_pair(date, rate_val));
    }
    csv_file.close();

    std::ifstream input_file(path);
    if (!input_file.is_open())
        throw "Input file open failed";

    if (!std::getline(input_file, line))
        throw "Empty input file";
    if (line != "date | value")
        throw "bad input";

    while (std::getline(input_file, line))
        _inputs.push_back(line);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
    (void) ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
    (void) ref;
    return *this;
}

BitcoinExchange *BitcoinExchange::getBitcoinExchange(const char *path)
{
    if (!_instance)
        _instance = new BitcoinExchange(path);
    return _instance;
}

void BitcoinExchange::releaseInstance()
{
    delete _instance;
    _instance = NULL;
}

double BitcoinExchange::_get_actual_value(const std::string &date, double value)
{
    std::map<std::string, double>::iterator it;

    it = _instance->_data.lower_bound(date);
    if (it == _instance->_data.end() || date != it->first) {
        if (it == _instance->_data.begin())
            throw "early accessor";
        --it;
    }
    return value * it->second;
}

void BitcoinExchange::exchange()
{
    std::list<std::string>::iterator it = _instance->_inputs.begin();

    for (; it != _instance->_inputs.end(); ++it) {
        const size_t pos = it->find(" | ");
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => no \" | \"" << '\n';
            continue;
        }
        std::string date = it->substr(0, pos);
        std::string value_str = it->substr(pos + 3);
        double value;

        try {
            _check_valid_date(date);
        } catch (const char *error) {
            (void) error;
            std::cout << "Error: bad input => " << date << '\n';
            continue;
        }

        try {
            value = _check_valid_value(value_str);
        } catch (const char *error) {
            std::cout << "Error: " << error << '\n';
            continue;
        }

        const double act_val = _get_actual_value(date, value);
        std::cout << date << " => " << value << " = " << act_val << '\n';
    }
}