#ifndef SAMENAME_HPP
#define SAMENAME_HPP

#include <algorithm>
#include <string>
#include "functional.hpp"
#include "../file.hpp"
#include "../utils.hpp"
#include "../print.hpp"


using namespace utils;
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace same {
      struct name_fn {
        template <typename T>
        const std::vector<T> operator()(const std::vector<T>& vi) const {
          std::vector<T> op;
          for (int i = 0; i < vi.size(); i++) {
            auto current = vi.at(i);
            for (int j = 0; j < vi.size(); j++) {
              auto dup = vi.at(j);
              if (toUpperCase(current.name) == toUpperCase(dup.name) 
                && i!=j) {
                // found a duplicate
                op.push_back(current);
                echo::sameline("Founded " + std::to_string(op.size()) + " with same name from " + std::to_string(vi.size()) + " images");
                break;
              }
            }
          }

          return op;
        }
      };
      const pipe_closure<same::name_fn> name = {};
    }
  }
  /// @}
}

#endif