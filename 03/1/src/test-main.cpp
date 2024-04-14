#include "list.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("test List", "[list]")
{
    List list;
    
    CHECK(list.Empty() == true);
    CHECK(list.Size() == 0);
    INFO("Empty List");

    // Добавляем 1 элемент
    list.PushBack(15);
    CHECK(list.Size() == 1);
    INFO("Add One element to List");

    // Добавляем 1 элемент
    list.PushBack(5);
    CHECK(list.Size() == 2);
    INFO("Add One element to List");

    CHECK(list.Empty() == false);

    // Очищаем список
    list.Clear();
    CHECK(list.Empty() == true);
    CHECK(list.Size() == 0);
    INFO("Clear List");
}


int main(){
   return Catch::Session().run();
}
