#include <iostream>
#include <vector>
#include <memory>

template <typename T>
std::vector<T> move_vectors(std::vector<T>& val_one)
{
    return std::move(val_one);
};

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

int main()
{
    std::vector<std::string> one = {"test_string1", "test_string2"};
    std::vector<std::string> two;
    two = move_vectors(one);

    std::cout << "Out TWO: ";
    print(two);

    std::cout << "Out One: ";
    print(one);

    return 0;
}
