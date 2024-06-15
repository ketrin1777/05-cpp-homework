#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

template <typename T>
void print_container(const T &val)
{
    if (!val.empty())
    {
        
        // Вариант 1
        // for (const auto & item :  val)
        // {
        //     std::cout << item << " ";
        // }

        // Вариант 2
        auto item = val.cbegin();
        for (; item != val.cend(); item++)
        {
            std::cout << *item << " ";
        }
    }
    std::cout << std::endl;
}


int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::cout << "[SET]: ";
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::cout << "[LIST]: ";
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::cout << "[VECTOR]: ";
    print_container(test_vector);

}
