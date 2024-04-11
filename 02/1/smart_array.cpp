#include "smart_array.h"


smart_array::smart_array(size_t n_s) : size_(n_s)
{
	arr_ = new int[size_]{};
}

smart_array::~smart_array()
{
	delete[] arr_;
}

void smart_array::add_element(int n_s)
{
	if (idx_add < size_)
	{
		arr_[idx_add] = n_s;
		idx_add++;
	}
	else
	{
		throw std::runtime_error("out of the array");
	}
}

int smart_array::get_element(size_t idx)
{
	if (idx < size_)
	{
		return arr_[idx];
	}
	else
	{
		throw  std::runtime_error("Index of an element outside the array");
	}

	return arr_[0];
}