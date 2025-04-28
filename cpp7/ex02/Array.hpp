#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <iostream>

template <typename T>
class Array {

	private:
		T*		  _array;
		unsigned int _size;

	public:
		Array() : _array(0), _size(0) {};
		Array(unsigned int n) : _array(new T[n]), _size(n) {};
		Array(const Array & other) {
			std::cout << "Copy constructor called" << std::endl;
			_array = new T[other._size];
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		};

		Array & operator=(const Array & other) {
			std::cout << "Copy assignment operator called" << std::endl;
			if (this == &other)
				return *this;

			this->deletearray();
			_array = new T[other._size];
			_size = other._size;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			return *this;
		};

		~Array() {deletearray();};

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

		void deletearray() {
			if (this->_array != NULL) {
				delete [] this->_array;
				this->_array = NULL;
			}
		};

};

#endif