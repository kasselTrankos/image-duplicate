#include <iostream>
#include <string>
#include <vector>
#include "actions/samesize.hpp"
#include "actions/samebytes.hpp"
#include "actions/reporthtml.hpp"
#include "actions/reportplain.hpp"
#include "actions/makedelete.hpp"
#include "files.hpp"
#include "file.hpp"
#include <algorithm>

using namespace std;
using namespace files::actions;
namespace dups {
  void get (string filepath) {
    vector<File> _files = files::images(filepath);
    vector<File> dups = _files | same::size | same::bytes | report::plain | report::html | make::deletion;
    // for ( int i =0 ; i< dups.size(); i++)
    //   std::cout << "\n file: " << dups[i].Path << " with ->" << dups[i].same << std::endl;
  }
}