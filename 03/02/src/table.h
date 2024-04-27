#pragma once

template <class T>
class table
{
public:
    table(int row, int col) : row_(row), col_(col)
    {
        if (row > 0)
        {
            elements = new T *[row];
            if (col > 0)
            {
                for (size_t j = 0; j < row; j++)
                {
                    elements[j] = new T[col]{};
                }
            }
        }
    }
    ~table()
    {
        for (size_t j = 0; j < row_; j++)
        {
            delete[] elements[j];
        }
        delete[] elements;
    };

    T *operator[](const int i) const { return elements[i]; };
    T *operator[](const int i) { return elements[i]; };

    const int GetRows() { return row_; };
    const int GetCols() { return col_; };

private:
    T **elements = nullptr;
    int row_ = 0;
    int col_ = 0;
};
