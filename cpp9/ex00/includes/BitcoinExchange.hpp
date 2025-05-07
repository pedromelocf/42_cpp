#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iterator>

class BitcoinExchange {

    private:
        std::map<std::string, double>  _hist_prices;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string & data);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void initialize_prices(std::ifstream & hist_prices);
        static bool checkDate(std::string const & date);
        static double checkExchangeRate(std::string const & exchange_rate);
        double getDailyPrice(std::string const & date) const;
 
        void displayResults(std::ifstream & input_file);
        void getOutput(std::string const & date, std::string const &  amount) ;
        static int checkInputFileLine(std::string const & date, std::string const & amount);
};

#endif 