#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> vec;
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(8);

    std::cout << "Size: " << vec.size() << std::endl;

    try
    {
        std::cout << vec.at(2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Capacity: " << vec.capacity() << std::endl;
}
