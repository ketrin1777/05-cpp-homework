#include <iostream>
#include <vector>

template <typename T>
T squaring(const T &val)
{
    return (val * val);
}

template <typename T>
std::vector<T> squaring(const std::vector<T> &val)
{
    std::vector<T> res;
    if (!val.empty())
    {
        for (const T & item : val)
        {
            res.push_back(item * item);
        }
    }
    return res;
}

template <typename T>
void print(const T &val)
{
    std::cout << val << std::endl;
}

template <typename T>
void print(const std::vector<T> &val)
{
    if (!val.empty())
    {
        for (size_t i = 0; i < val.size(); i++)
        {
            std::cout << ((i > 0) ? ", " : "") << val[i];
        }
    }
    std::cout << std::endl;
}

int main()
{
    int in = 4;
    std::cout << "[IN]: ";
    print(in);
    std::cout << "[OUT]: ";
    print(squaring(in));

    std::vector<int> vIn{-1, 4, 8};
    // squaring(vIn);
    std::cout << "[IN]: ";
    print(vIn);

    std::vector<int> out = squaring(vIn);
    std::cout << "[OUT]: ";
    print(out);
}
