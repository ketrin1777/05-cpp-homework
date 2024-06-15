#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print(const std::vector<T> &val)
{
    if (!val.empty())
    {
        for (size_t i = 0; i < val.size(); i++)
        {
            std::cout << ((i > 0) ? " " : "") << val[i];
        }
    }
    std::cout << std::endl;
}

template <typename T>
void set_uniq(std::vector<T> &val)
{
    std::sort(val.begin(), val.end());
    auto last = std::unique(val.begin(), val.end());
    val.erase(last, val.end());
}

int main()
{
    std::vector<int> vIn{1, 1, 2, 5, 6, 1, 2, 4};
    std::cout << "[IN]: ";
    print(vIn);

    set_uniq(vIn);

    std::cout << "[OUT]: ";
    print(vIn);
}
