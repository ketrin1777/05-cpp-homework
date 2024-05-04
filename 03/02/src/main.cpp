#include <iostream>
#include "table.h"

int main()
{
    /*
    table<int> t1(2, 3);
    table<int> t2(2, 3);

    t1 = t2; // Запрещено
    */

    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; // выводит 4

    std::cout << "Rows: " << test.GetRows() << "; Cols: " << test.GetCols() << std::endl; // выводит 4
}