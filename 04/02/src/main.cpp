#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

auto print = [](const int &n)
{
    std::cout << (1 - n) << '\n';
};

int main()
{
    size_t size;

    std::set<int> inp;
    std::cout << "[IN]: " << std::endl;
    std::cin >> size;
    for (size_t i = 0; i < size; i++)
    {
        int val;
        std::cin >> val;
        inp.insert(1 - val);
    }
    std::cout << "[OUT]: " << std::endl;

    std::for_each(inp.cbegin(), inp.end(), print);
}
