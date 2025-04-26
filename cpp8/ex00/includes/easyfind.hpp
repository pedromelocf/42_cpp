#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>

template <typename T>
int easyfind(T intcontainer, int tofind)
{
    typename T::iterator it = std::find(intcontainer.begin(), intcontainer.end(), tofind);;

    if (it != intcontainer.end())
        return *it;

    throw std::out_of_range("Value was not found.");
}

#endif