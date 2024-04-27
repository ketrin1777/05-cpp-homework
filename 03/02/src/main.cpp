#include <iostream>
#include "table.h"

int main()
{
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; // выводит 4

    std::cout << "Rows: " << test.GetRows() << "; Cols: " << test.GetCols() << std::endl; // выводит 4
}
