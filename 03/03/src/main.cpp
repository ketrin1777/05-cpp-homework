#include <iostream>
#include "treecount.h"

template <typename T>
void print(std::vector<T> &val)
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
    std::vector<int> vIn{4, 1, 3, 6, 25, 54};
    // squaring(vIn);
    std::cout << "[IN]: ";
    print(vIn);

    TreeCount tree(vIn[0]);
    tree(vIn);

    std::cout << "[OUT]: get_sum() = " << tree.get_sum() << std::endl;

    std::cout << "[OUT]: get_count() = " << tree.get_count();
}
