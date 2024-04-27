#pragma once

#include <vector>


template <class T>
class TreeCount
{
public:
    TreeCount(T){};
    // ~Tree();

    void operator()(std::vector<T> &val) { val_ = val; };

    int get_sum()
    {
        T res = 0;
        if (!val_.empty())
        {
            for (const T &item : val_)
            {
                if (item % 3 == 0)
                {
                    res = res + item;
                }
            }
        }

        return res;
    };

    int get_count()
    {
        T res = 0;
        if (!val_.empty())
        {
            for (const T &item : val_)
            {
                if (item % 3 == 0)
                {
                    res++;
                }
            }
        }

        return res;
    };

protected:
    std::vector<T> val_;
};