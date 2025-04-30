#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>

class BitcoinExchange {

    private:
        std::map<std::string, float>    _hist_prices;

        void initialize_prices(std::ifstream & hist_prices);

    public:
        BitcoinExchange();
        BitcoinExchange(std::ifstream & hist_prices);
        // BitcoinExchange(const BitcoinExchange& other);
        // BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        int  get_daily_price(std::string & date);
        void get_output(std::string & date, int amount);
        void display_results(std::ifstream & input_file);
};

#endif 
