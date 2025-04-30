#include "../includes/BitcoinExchange.hpp"

int main (int argc, char **argv) {
    
    if (argc != 2) {
        std::cout << "Error: invalid number of arguments." << std::endl;
        return 1;    
    }

    std::ifstream input_file(argv[1], std::ios::in);
    if (!input_file.is_open()) {
        std::cout << "Error: could not open input file." << std::endl;
        return 2;    
    }

    std::ifstream hist_prices_file("src/data/data.csv", std::ios::in);
    if (!hist_prices_file.is_open()) {
        std::cout << "Error: could not open data file." << std::endl;
        return 3;    
    }

    BitcoinExchange obj = BitcoinExchange(hist_prices_file);

    input_file.close();
    hist_prices_file.close();
    
    return 0;
}