#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string & data) {

    std::ifstream hist_prices(data.c_str(), std::ios::in);
    if (!hist_prices.is_open())
        throw std::invalid_argument("Error: could not open CSV file.");
    initialize_prices(hist_prices);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) { _hist_prices = other._hist_prices;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != & other) 
        (*this)._hist_prices = other._hist_prices;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::initialize_prices(std::ifstream & hist_prices) {

    std::string line;
    std::getline(hist_prices, line);
    int i = 0;

    while (std::getline(hist_prices, line))
    {
        size_t sep = line.find(',');
        std::string date = line.substr(0, sep);
        std::string str_rate = line.substr(sep + 1);
        double double_rate = checkExchangeRate(str_rate);

        if (checkDate(date) == false || double_rate== -1) {
            std::cerr << "Data Error at Line: " << i <<  " from CSV." << std::endl;
            continue;
        }

        if (_hist_prices.insert(std::make_pair(date, double_rate)).second == false)
            std::cerr << "Duplicate Data Error at line: " << i << " from CSV." << std::endl;
        ++i;
    }
}

bool BitcoinExchange::checkDate(std::string const & date) {

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[2] = 29;

    if (day > daysInMonth[month])
        return false;

    return true;
}

double BitcoinExchange::checkExchangeRate(std::string const & exchange_rate) {

    double rate;
    std::stringstream ss(exchange_rate);
    ss >> rate;
    if (rate < 0)
        return -1;
    return rate;
}

double BitcoinExchange::getDailyPrice(std::string const & date) const {

    std::map<std::string, double>::const_iterator it = _hist_prices.find(date);
    if (it != _hist_prices.end())
        return it->second;
    return -1.0;
}

void BitcoinExchange::displayResults(std::ifstream & input_file) {

    if (!input_file.is_open()) 
        throw std::invalid_argument("Error: could not open input file.");

    std::string line;
    std::getline(input_file, line);

    while (std::getline(input_file, line))
    {
        size_t sep = line.find('|');
        std::string date = line.substr(0, sep);
        std::string amount = line.substr(sep + 1);
        getOutput(date, amount);
    }
    
}

void BitcoinExchange::getOutput(std::string const & date, std::string const & amount) {

    switch (checkInputFileLine(date, amount))
    {
        case 1:

            break;
        case 2:

        case 3:

        case 4:
        
        default:
            std::cout << date << " => " << amount << " = " << getDailyPrice(date) * amount << std::endl;
            break;
    }
} 

int BitcoinExchange::checkInputFileLine(std::string const & date, std::string const & amount) {

    if (BitcoinExchange::checkDate(date) == false)
        return 1;

    else if (amount.length() == 0) 
        return 2;
    
    else if (amount < 0)
        return 3;

    else if (amount > 1000)
        return 4;

}