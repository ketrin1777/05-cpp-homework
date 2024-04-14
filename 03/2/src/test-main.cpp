#include "list.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("test List", "[list]")
{
    List list;
    
    CHECK(list.Empty() == true);
    CHECK(list.Size() == 0);
    INFO("Empty List");

    // Добавляем 1 элемент в конец
    list.PushBack(5);
    CHECK(list.Size() == 1);
    INFO("Add One element to List Back");

    // Добавляем 1 элемент в начало
    list.PushFront(15);
    CHECK(list.Size() == 2);
    INFO("Add One element to List Front");

    CHECK(list.Empty() == false);

    // Извлекаем элемент с конца
    int numb = list.PopBack();
    CHECK(list.Size() == 1);
    CHECK(numb == 5);
    INFO("Extract One element to List Back");

    // Извлекаем элемент с начала
    numb = list.PopFront();
    CHECK(list.Size() == 0);
    CHECK(numb == 15);
    INFO("Extract One element to List Front");

    CHECK(list.Empty() == true);

    // Добавляем 1 элемент в конец
    list.PushBack(5);
    CHECK(list.Size() == 1);
    INFO("Add One element to List Back");

    // Добавляем 1 элемент в начало
    list.PushFront(15);
    CHECK(list.Size() == 2);
    INFO("Add One element to List Front");

    CHECK(list.Empty() == false);

    // Очищаем список
    list.Clear();
    CHECK(list.Empty() == true);
    CHECK(list.Size() == 0);
    INFO("Clear List");

    // Извлекаем элемент с конца (Пустой список)
    try
    {
        numb = list.PopBack();
    }
    catch(const std::exception& e)
    {
        std::string text = e.what();
        CHECK(text == "list is empty");
        INFO("Extract One element to Empty List Back");
    }

    // Извлекаем элемент с начала (Пустой список)
    try
    {
        numb = list.PopFront();
    }
    catch(const std::exception& e)
    {
        std::string text = e.what();
        CHECK(text == "list is empty");
        INFO("Extract One element to Empty List Back");
    }
    
}

int main()
{
    return Catch::Session().run();
}