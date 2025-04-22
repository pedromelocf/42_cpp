#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <iostream>

template <typename T>
class Array {

    private:
        T*          _array;
        unsigned int _size;

    public:
        Array() : _array(0), _size(0) {}; 
        Array(unsigned int n) : _array(new T[n]), _size(n) {};

        Array(const Array & other) {

            _array = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        };

        Array & operator=(const Array & other) { 
            // if (*this->_array)
            //     delete [] _array;
            _array = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
                
            return *this;

        };

        ~Array() {};

        T & operator[] (int i) {
            if (this->_size <= static_cast<unsigned int>(i) || i < 0)
                throw std::out_of_range("Invalid index");
            return _array[i];
        };

        T operator[] (int i) const {
            if (this->_size <= static_cast<unsigned int>(i) || i < 0)
                throw std::out_of_range("Invalid index");
            return _array[i];
        };

        unsigned int getsize() {return this->_size;};

};

#endif 