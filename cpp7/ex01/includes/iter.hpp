#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cstdio>

template <typename T, typename N, typename F>
void iter (T * arr_addr, N arr_len, F func) {
    if (arr_addr != NULL) {
        for (N i = 0; i < arr_len ; i++) {
            func(arr_addr[i]);
        }
    }
}

template <typename T>
void printelement (T & arr_elem) { std::cout << "[" << arr_elem << "]"; }

template <typename T>
void increment (T & arr_elem) { arr_elem++; }

template <typename T>
void uppercase (T & arr_elem) {

    static_cast<std::string>(arr_elem);
    for (size_t i = 0; i < arr_elem.length(); i++) {
        arr_elem[i] = toupper(arr_elem[i]); 
    }
}

struct Data {

    std::string s;
    int i;

    Data (const std::string & s, int i) 
    : s(s), i(i) {};

    Data & operator++ (int) {
        static Data tmp (*this);
        this->i++;
        return tmp;
    };


};

std::ostream & operator<< ( std::ostream& os, const Data & data)
{
    os << data.s << " , " << data.i;
    return os;
};

#endif 