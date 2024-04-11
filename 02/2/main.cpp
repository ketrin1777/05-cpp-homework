#include <iostream>
#include "smart_array.h"

int main()
{
	try
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(14);
		new_array.add_element(15);

		arr = new_array;

		
		smart_array new_array_two(arr);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}