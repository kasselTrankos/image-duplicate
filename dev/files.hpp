#include <iostream>
#include <string>
#include <vector>
#include "print.hpp"

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include "file.hpp"
#include "utils.hpp"

using namespace boost::filesystem;
using namespace boost::system;
using namespace utils::file;
using namespace std;

namespace files {
  std::vector<File> images(string filepath) {
    std::vector<File> result;
    
    path p(filepath);
    if(is_directory(p)) {
      int i = 0;
      string Path;
      for(auto& it: recursive_directory_iterator(filepath)){
        Path = it.path().string();
        if (!is_directory(it.path())
          && isImage(Path) && isValidFolder(Path)) {
          File file = File();
          file.Path = it.path(); 
          file.name = getName(Path);
          file.isImage = isImage(Path);
          file.size = file_size(it.path());
          result.push_back(file);
          echo::sameline(to_string(i) + " ::: " + Path);
          i++;
        }
      }
    }
    return result;
  }
}