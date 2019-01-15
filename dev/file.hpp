#ifndef FILE_HPP
#define FILE_HPP

#include <iostream> 
#include <vector>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
using namespace std;
class File {
  public:
    path Path;
    string name;
    bool isImage;
    path same;
    double size;
};

#endif