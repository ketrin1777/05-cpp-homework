#pragma once

#include <iostream>

class smart_array
{
public:
	smart_array(size_t n_s);
	smart_array(smart_array& v);
	~smart_array();

	void add_element(int n_s);
	int get_element(int idx);
	size_t get_size();

	smart_array & operator=(smart_array& v);
	int operator[](size_t idx);

	size_t get_index_add();

private:
	int *arr_;
	size_t idx_add{};
	size_t size_{};
};
