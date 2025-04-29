#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange {

    private:
        std::map<std::string, float> _hist_prices;

    public:
        BitcoinExchange();
        BitcoinExchange(std::fstream hist_prices);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        int get_daily_price(std::string & date);
        std::string & get_multiplied_output(int daily_price, std::string & date);
};

#endif 
