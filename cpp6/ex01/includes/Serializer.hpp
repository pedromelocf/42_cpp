#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <cstdlib>
#include <cassert>

struct Data;

class Serializer {

	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif
