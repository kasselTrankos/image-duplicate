#ifndef MAKEDELETION__HPP
#define MAKEDELETION__HPP

#include <string>
#include <iostream>
#include "functional.hpp"
#include <stdio.h>

using namespace utils;
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace make {
      struct deletion_fn {
        template <typename T>
        const std::vector<T> operator()(const std::vector<T>& vi) const {
          for (int i=0; i< vi.size(); i++) {
            std::ifstream file(vi[i].Path.string());
            std::ifstream file1(vi[i].same.string());
            if(file && file1) {

              std::string input;
              std::string images = "feh -g 400x400 \"";
              images += vi[i].Path.string();
              images +="\"";
              images +=" && feh -g 400x400  \"";
              images += vi[i].same.string();
              images +="\"";
              // std::cout << images << std::endl;
              system(images.c_str() );
              // std::string deletes =""
              std::cout << "\n Wich delete:\n\t(1) delete first\n\t(2) delete second\n\t(3) delete both\n\t(0) delete none" << std::endl;

              std::getline(std::cin, input);
              if(input=="1" || input=="3") {
                remove (vi[i].Path.string());
              } else if(input == "2" || input=="3") {
                remove (vi[i].same.string());
              }
            }

          }
          return vi;
        }
      };
      const pipe_closure<make::deletion_fn> deletion = {};
    }
  }
  /// @}
}

#endif