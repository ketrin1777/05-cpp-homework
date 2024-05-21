#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

struct Data
{
public:
    std::string symb;
    size_t count;
};

int main()
{
    std::string s = "Hello world!!";
    std::cout << "[IN]: " << s << std::endl;
    std::map<const char, size_t> maps;
    for (const auto &item : s)
    {
        size_t count = std::count(s.begin(), s.end(), item);

        // Копируем в map
        maps.insert(std::make_pair(item, count));
    }

    if (maps.size() > 0)
    {
        std::vector<Data> data;

        // переносим в вектор для сортировки
        for (const auto &it : maps)
        {
            Data new_item;
            new_item.count = it.second;
            new_item.symb = it.first;
            data.push_back(new_item);
        }

        // Сортируем по счетчику
        std::sort(data.begin(), data.end(), [](Data &a, Data &b)
                  { return a.count > b.count; });

        std::cout << "[OUT]: " << std::endl;
        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << data[i].symb << ": " << data[i].count << std::endl;
        }
    }
}
