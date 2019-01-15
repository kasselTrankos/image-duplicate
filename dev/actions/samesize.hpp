#ifndef SAMESIZE_HPP
#define SAMESIZE_HPP

#include <algorithm>
#include <string>
#include "functional.hpp"
#include "../file.hpp"
#include "../utils.hpp"
#include "../print.hpp"


using namespace utils;
using namespace std;

bool isSameSize(File r1, File r2)  {
  if(r1.size != r2.size)
    return r1.size < r2.size;
  return r1.size < r2.size;
}
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace same {
      struct size_fn {
        template <typename T>
        const std::vector<T> operator()(vector<T> vi) const {
          vector<T> op;
          sort(vi.begin(), vi.end(), isSameSize); 
          if (vi.size() > 2) {
            auto prev = vi.at(1);
            for (int i = 0; i < vi.size(); i++) {
              if(vi.at(i).size == prev.size) {
                op.push_back(vi.at(i));
              }
              prev = vi.at(i);
            }
          }
          return op;
        }
      };
      const pipe_closure<same::size_fn> size = {};
    }
  }
  /// @}
}

#endif