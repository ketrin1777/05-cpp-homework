#pragma once

#include <vector>
#include <algorithm>

template <class T>
class TreeCount
{
public:
    TreeCount(T){};
    // ~Tree();

    void operator()(T &val) { summ_ += val; count_++;};

    T get_sum()
    {
        return summ_;
    };

    size_t get_count()
    {
        return count_;
    };

protected:
    size_t count_{};
    T summ_{};
};