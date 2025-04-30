#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::ifstream & hist_prices) {

    if (!hist_prices.is_open())
        throw std::invalid_argument("Error: could not open file.");
    initialize_prices(hist_prices);
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) {
//     // Copy constructor implementation
// }

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
//     if (this != & other) {
//         // Copy assignment implementation
//     }
//     return *this;
// }

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::initialize_prices(std::ifstream & hist_prices) {

    static_cast<void>(hist_prices);
    _hist_prices["oi"] = 21.7;
}

int BitcoinExchange::get_daily_price(std::string & date) { return _hist_prices[date]; }

void BitcoinExchange::get_output(std::string & date, int amount) {

    // check valid date and amout

    std::cout << date << " => " << amount << " = " << get_daily_price(date) * amount << std::endl;

} 

void BitcoinExchange::display_results(std::ifstream & input_file) {
    
}
