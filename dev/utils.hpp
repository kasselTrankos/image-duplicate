#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <sys/stat.h> 
#include <fcntl.h>
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
  void printProgress (double percentage, int current, int total) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf ("\r%d of %d %3d%% [%.*s%*s]",current, total, val, lpad, PBSTR, rpad,  "");
    fflush (stdout);
  }
  /**
   * It works with file types
   */
  namespace file {
    int compareBytes(const char *name1, const char *name2) {  
      int ret=0;    // 0=Matching
      int N = 10000;
      char buf2[N];
      char buf1[N];
      FILE *fp1, *fp2;
      int c1,c2;

      fp1 = fopen(name1,"rb");
      fp2 = fopen(name2,"rb");
      if(fp1==NULL || fp2==NULL) {
        return(-1);    // Unable to open files
      }
      do {
        size_t r1 = fread(buf1, 1, N, fp1);
        size_t r2 = fread(buf2, 1, N, fp2);

        if (r1 != r2 || memcmp(buf1, buf2, r1)) {
          fclose(fp1);  
          fclose(fp2);  
          return 0;
        }
      } while (!feof(fp1) || !feof(fp2));
      fclose(fp1);  
      fclose(fp2);  
      return 1;  
    }
    bool isImage (string file) {
      const char *re = ".*\\.(jpg|png|gif|tiff)";
      const boost::regex my_filter(re, boost::regex::icase);
      boost::smatch what;
      return boost::regex_match(file, what, my_filter);
    }
    bool isValidFolder (string file) {
      const char *re = ".*\\$RECYCLE\\.BIN.*|\\.Trash.*";
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
}

#endif