#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>

class ElementNotFound : public std::exception
{
    public:
    const char * what() const throw()
    {
        return "Element Not Found";
    }
};

template<class T>

typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(),container.end(),value);
    if (it == container.end())
        throw ElementNotFound();
    else
        return (it);
}
#endif