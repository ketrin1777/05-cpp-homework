#include "smart_array.h"

smart_array::smart_array(size_t n_s) : size_(n_s)
{
	arr_ = new int[size_]{};
}

smart_array::smart_array(smart_array &v)
{
	idx_add = 0;
	arr_ = nullptr;
	rsize_t size_ = v.get_size();

	if (size_ > 0)
	{
		arr_ = new int[size_]{};
		for (size_t i = 0; i < size_; i++)
		{
			arr_[i] = v[i];
		}
		idx_add = v.get_index_add();
	}
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

int smart_array::get_element(int idx)
{
	if (idx < size_)
	{
		return arr_[idx];
	}
	else
	{
		throw std::runtime_error("Index of an element outside the array");
	}

	return arr_[0];
}

smart_array &smart_array::operator=(smart_array &v)
{
	if (this != &v)
	{	
		delete[] arr_;
		idx_add = 0;
		arr_ = nullptr;
		rsize_t size_ = v.get_size();

		if (size_ > 0)
		{
			arr_ = new int[size_]{};
			for (size_t i = 0; i < size_; i++)
			{
				arr_[i] = v[i];
			}
			idx_add = v.get_index_add();
		}
	}
	return *this;
}

int smart_array::operator[](size_t idx)
{
	return arr_[idx];
}

size_t smart_array::get_index_add()
{
	return idx_add;
}

size_t smart_array::get_size()
{
	return size_;
}