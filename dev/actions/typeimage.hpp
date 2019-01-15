#ifndef TYPEIMAGE_HPP
#define TYPEIMAGE_HPP

#include <algorithm>
#include <string>
#include "functional.hpp"
#include "../utils.hpp"


using namespace utils::file;
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace type {
      struct image_fn {
        template <typename T>
        const std::vector<T> operator()(const std::vector<T>& vi) const {
          std::vector<T> op;
          for (auto it=vi.begin() ; it < vi.end(); it++ ) {
            if (it->isImage) {
              op.push_back(*it);
            }
          }
          return op;
        }
      };
      const pipe_closure<type::image_fn> image = {};
    }
  }
  /// @}
}

#endif