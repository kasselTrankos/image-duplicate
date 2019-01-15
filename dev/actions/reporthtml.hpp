#ifndef REPORTHTML_HPP
#define REPORTHTML_HPP

#include <iostream>
#include <string>
#include "functional.hpp"


using namespace utils;
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace report {
      struct html_fn {
        template <typename T>
        const std::vector<T> operator()(const std::vector<T>& vi) const {

          return vi;
        }
      };
      const pipe_closure<report::html_fn> name = {};
    }
  }
  /// @}
}

#endif