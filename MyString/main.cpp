#include <iostream>
#include "String.h"

int main(int, char **)
{
    utils::String c_str;
    c_str = "ma ";
    c_str += "kota ";
    c_str += std::move("jakis string ");
    c_str = std::move(c_str + "i psa");

    std::cout << c_str.toString() << std::endl;

    utils::String c_str1;
    std::cout << (bool)c_str1 << std::endl;

    utils::String str;
    str = "lukaszfabia";
    std::cout << str.substring(-1, 2) << std::endl;
    std::cout << str.substring(6) << std::endl;
    std::cout << str.char_at(utils::len(str.toString()) - 1) << std::endl;
    std::cout << str.char_at(0) << std::endl;
    std::cout << str.char_at(-1) << std::endl;

    return 0;
}
