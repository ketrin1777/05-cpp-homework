#pragma once

#include <vector>
#include <algorithm>

template <class T>
class TreeCount
{
public:
    TreeCount(T){};
    // ~Tree();

    void operator()(T &val)
    {
        if (val % 3 == 0)
        {
            summ_ += val;
            count_++;
        }
    };

    int get_sum()
    {
        return summ_;
    };

    int get_count()
    {
        return count_;
    };

protected:
    size_t count_{};
    T summ_{};
};