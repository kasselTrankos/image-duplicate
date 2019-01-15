#ifndef REPORTPLAIN_HPP
#define REPORTPLAIN_HPP

#include <iostream>
#include <string>
#include "functional.hpp"
#include <fstream>


using namespace utils;
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace report {
      struct plain_fn {
        template <typename T>
        const std::vector<T> operator()(const std::vector<T>& vi) const {
          std::ofstream myfile;
          myfile.open ("report.plain");
          for (int i=0; i< vi.size(); i++) {
            myfile << vi[i].Path.string() << ";"<< vi[i].same.string() << "\n";
          }
          myfile.close();
          return vi;
        }
      };
      const pipe_closure<report::plain_fn> plain = {};
    }
  }
  /// @}
}

#endif