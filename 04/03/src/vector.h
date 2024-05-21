#pragma once

#include <iostream>
#include <cmath>

template <class T>
class Vector
{
public:
    Vector(){};
    ~Vector() { delete[] array; };

    // Добавляем новый элемент
    void push_back(T value)
    {
        size_t new_size = size_ + 1;
        if (size_ < 2)
        {
            capacity_ = 2;
        }
        else if (new_size >= capacity_)
        {
            // Создаем резерв массива
            double cap = static_cast<double>(capacity_) / 2;
            capacity_ = capacity_ + round(cap);
        }

        T *array_new = new T[capacity_];
        if (size_ > 0)
        {
            for (size_t i = 0; i < size_; i++)
            {
                array_new[i] = array[i];
            }
        }
        size_ = new_size;
        array_new[size_ - 1] = value;
        delete[] array;
        array = array_new;
    }

    size_t size() { return size_; }; // Получаем размер массива

    T at(int index)
    {
        if (index < size_)
        {
            return array[index];
        }
        throw std::runtime_error("Out of range");
    }

    size_t capacity() { return capacity_; }; // Получаем размер резерва массива

private:
    size_t size_{};
    T *array = nullptr;
    size_t capacity_{};
};
