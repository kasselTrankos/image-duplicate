#ifndef PRINT_HPP
#define PRINT_HPP
#include <iostream>
#include <string>

namespace echo {
  void sameline (std::string str) {
    std::cout << "\e[A\r\e[0K" << str << std::endl;
  }
  // std::ostream& operator<< (std::ostream& os, const std::string& str) {
  //   os << "\e[A\r\e[0K" << str;
  //   return os;
  // }
}
#endif