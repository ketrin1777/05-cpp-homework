#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <iostream>

class big_integer
{

public:
    big_integer(std::string b_int) : digits_(b_int){};

    big_integer(big_integer &&b_int)
    {
        digits_ = std::move(b_int.digits_);
        // b_int.digits_.clear();
    };

    big_integer &operator=(const big_integer &a)
    {
        digits_ = a.digits_;
        return *this;
    };

    big_integer &operator=(const big_integer &&a) noexcept
    {
        digits_ = std::move(a.digits_);
        return *this;
    };

    big_integer operator+(big_integer &a)
    {

        std::string numb;

        size_t s_a = this->digits_.size(), s_b = a.numb().size();
        size_t s_all = s_a;
        if (s_b > s_a)
        {
            s_all = s_b;
        }

        int ost = 0;
        for (size_t i = 0; i < s_all; i++)
        {
            int numb_a = 0;
            int numb_b = 0;
            if (i < s_a)
            {
                std::string symb_a(1, digits_[(s_a - i) - 1]);
                numb_a = std::stoi(symb_a);
            }

            if (i < s_b)
            {
                std::string symb_b(1, a.numb()[(s_b - i) - 1]);
                numb_b = std::stoi(symb_b);
            }

            int sum_ost = numb_b + numb_a + ost;
            int sum = sum_ost % 10;
            ost = (sum_ost - sum) / 10;

            // Проверка суммирования
            // std::cout << numb_a << " + " << numb_b << " = " << sum << " ost " << ost << std::endl; // 193099

            char n_str = std::to_string(sum)[0];
            numb.push_back(n_str);
        }

        std::reverse(numb.begin(), numb.end());
        big_integer temp(numb);

        return temp;
    };

    big_integer operator*(big_integer &a)
    {

        big_integer numb_old("0");

        size_t s_a = this->digits_.size(), s_b = a.numb().size();
        for (size_t i = 0; i < s_b; i++)
        {
            std::string numb_new;

            std::string symb_b(1, a.numb()[(s_b - i) - 1]);
            int numb_b = std::stoi(symb_b);

            int ost = 0;

            for (size_t j = 0; j < s_a; j++)
            {
                std::string symb_a(1, digits_[(s_a - j) - 1]);
                int numb_a = std::stoi(symb_a);

                int sum_ost = (numb_b * numb_a) + ost;
                int sum = sum_ost % 10;
                ost = (sum_ost - sum) / 10;

                // Проверка умножения
                // std::cout << numb_a << " * " << numb_b << " = " << sum << " ost " << ost << std::endl; // 193099

                char n_str = std::to_string(sum)[0];
                numb_new.push_back(n_str);
            }
            if (ost > 0)
            {
                char n_str = std::to_string(ost)[0];
                numb_new.push_back(n_str);
            }
            std::reverse(numb_new.begin(), numb_new.end());
            if (i > 0)
            {
                for (size_t pr = 0; pr < i; pr++)
                {
                    numb_new.push_back('0');
                }
            }

            // Вывод информации
            // std::cout << " " << numb_old.digits_ << std::endl;
            // std::cout << "+" << numb_new << std::endl;

            big_integer new_int(numb_new);
            numb_old = numb_old + new_int;

            // Вывод информации
            // std::cout << " -------------------" << std::endl;
            // std::cout << numb_old.digits_ << "\n\n";
        }

        return numb_old;
    };

    std::string &numb()
    {
        return this->digits_;
    };

    std::string digits_;

private:
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    auto result1 = number1 * number2;
    std::cout << result.numb() << "\n";  // 193099
    std::cout << result1.numb() << "\n"; // 114575 * 78524 = 8 996 887 300

    return 0;
}
