#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::fstream hist_prices) {
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    // Copy constructor implementation
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != & other) {
        // Copy assignment implementation
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::get_daily_price(std::string & date) {}

std::string & BitcoinExchange::get_multiplied_output(int daily_price, std::string & date) {} 