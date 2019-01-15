#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
namespace filesys = boost::filesystem;
using namespace std;

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

namespace utils {
  void printCounter (int position, std::string name) {
    printf ("\r%3d :::  %s", position, name.c_str());
    fflush (stdout);
  }
  /**
   * Bar progress draw in terminal 
   */
  void printProgress (double percentage, std::string name) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad,  "");
    fflush (stdout);
  }
  /**
   * It works with file types
   */
  namespace file {
    bool isImage (string file) {
      const char *re = ".*\\.(jpg|png|gif|tiff)";
      const boost::regex my_filter(re, boost::regex::icase);
      boost::smatch what;
      return boost::regex_match(file, what, my_filter);
    }
    bool isValidFolder (string file) {
      const char *re = ".*\\$RECYCLE\\.BIN.*";
      const boost::regex my_filter(re, boost::regex::icase);
      boost::smatch what;
      return !boost::regex_match(file, what, my_filter);
    }
    string getName (string filePath, bool withExtension = false) {
      filesys::path pathObj(filePath);
      // Check if file name is required without extension
      if(withExtension == false) {
        // Check if file has stem i.e. filename without extension
        if(pathObj.has_stem()) {
          // return the stem (file name without extension) from path object
          return pathObj.stem().string();
        }
        return "";
      } else {
        // return the file name with extension from path object
        return pathObj.filename().string();
      }
    }

    string getExtension(const string& name) {
      if(name.find_last_of(".") != string::npos)
        return name.substr(name.find_last_of(".")+1);
      return "";
    } 
  }
  
  string toUpperCase(string str) {
    //change each element of the string to upper case
   for(unsigned int i=0;i<str.length();i++) {
      str[i] = toupper(str[i]);
   }
   return str;//return the converted string
  }
  string toLowerCase(string str) {
  //change each element of the string to lower case
   for(unsigned int i=0;i<str.length();i++)
   {
      str[i] = tolower(str[i]);
   }
   return str;//return the converted string
  }

  int filesize(const char* filename) {
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return in.tellg(); 
  }
}

#endif