#pragma once

#include <map>
#include <string>

// singleton
class BitcoinExchange {
private:
    static BitcoinExchange _instance;

    BitcoinExchange(); // X
    BitcoinExchange(std::string &path);
    BitcoinExchange(const BitcoinExchange &ref);
    BitcoinExchange &operator=(const BitcoinExchange &ref);
    ~BitcoinExchange();

    std::map<std::string, double> data;
    std::map<std::string, double> dealings;

public:
    static BitcoinExchange &getBitcoinExchange(std::string &path);


};