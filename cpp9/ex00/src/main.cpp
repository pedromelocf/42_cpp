#include "../includes/BitcoinExchange.hpp"

int main (int argc, char **argv) {
    
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments." << std::endl;
        return 1;    
    }

    std::ifstream input_file(argv[1], std::ios::in);
    if (!input_file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return 2;    
    }

    std::string data = "src/data/data.csv";
    std::ifstream hist_prices_file(data.c_str(), std::ios::in);
    if (!hist_prices_file.is_open()) {
        std::cerr<< "Error: could not open data file." << std::endl;
        return 3;    
    }

    BitcoinExchange bitcoin_exchange(data);
    bitcoin_exchange.displayResults(input_file);

    input_file.close();
    hist_prices_file.close();
    
    return 0;
}