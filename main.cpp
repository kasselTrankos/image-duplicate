#include "dev/duplicate.hpp"
#include <sys/stat.h> 
#include <fcntl.h>
#include <iostream>
#include<stdlib.h> 
using namespace dups;




int main(int argc, char *argv[]) {
  std::string input;
  if (argc == 2) {
    input = argv[1];
  } else {
    std::cout << "Include th path of the images" << std::endl;
    std::getline(std::cin, input);
  }
  get(input);
  return 0;
}