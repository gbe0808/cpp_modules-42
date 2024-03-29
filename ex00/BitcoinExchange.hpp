#pragma once

#include <list>
#include <map>
#include <string>

// singleton
class BitcoinExchange {
private:
    static BitcoinExchange *_instance;

    BitcoinExchange();
    BitcoinExchange(const char *path);
    BitcoinExchange(const BitcoinExchange &ref);
    BitcoinExchange &operator=(const BitcoinExchange &ref);
    ~BitcoinExchange();

    std::map<std::string, double> _data;
    std::list<std::string> _inputs;

    static void _check_valid_date(std::string &date);
    static void _check_valid_rate(std::string &rate);
    static double _check_valid_value(std::string &value);
    static double _get_actual_value(const std::string &date, double value);

public:
    static BitcoinExchange *get_instance(const char *path);
    static void release_instance();

    static void exchange();
};