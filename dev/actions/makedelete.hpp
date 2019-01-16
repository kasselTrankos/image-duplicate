#ifndef MAKEDELETION__HPP
#define MAKEDELETION__HPP

#include <string>
#include <iostream>
#include "functional.hpp"
#include <stdio.h>
#include <thread>
#include <chrono>

using namespace utils;

void a (string file) {
  std::string images = "feh -g 400x900 \"";
  images +=file;// "/media/vera/24D3-4DEA/06-12-08_190.jpg";
  images +="\"";
  system(images.c_str());
}
void b (string file) {
  std::string images1 ="feh -w -g 200x200  \"";
  images1 += file; //"/media/vera/24D3-4DEA/21deabrilparqmolinos/IMG_9809.JPG";
  images1 +="\"";
  system(images1.c_str());
}
void c (string file1, string file2) {
  std::string input;
  std::cout << "\n Wich delete:\n\t(1) delete first\n\t(2) delete second\n\t(3) delete both\n\t(0) delete none" << std::endl;

  std::getline(std::cin, input);
  if(input=="1" || input=="3") {
    remove (file1);
  } else if(input == "2" || input=="3") {
    remove (file2);
  }
              
}
#define NUM_THREADS 3
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace make {
      struct deletion_fn {
        template <typename T>
        const std::vector<T> operator()(const std::vector<T>& vi) const {
          for (int i=0; i< vi.size(); i++) {
            std::ifstream file(vi[i].Path.string());
            std::ifstream file1(vi[i].same.string());
            if(file && file1) {
              std::thread t[NUM_THREADS];
              // load the image
              int rc;
              int rc1;
              t[0] = std::thread(a, vi[i].Path.string());
              std::this_thread::sleep_for(std::chrono::milliseconds(100));
              t[1] = std::thread(b, vi[i].same.string());
              t[2] = std::thread(c, vi[i].Path.string(), vi[i].same.string());
              t[1].join();
              t[0].join();
              t[2].join();
              // std::string images = "feh -g 400x400 \"";
              // images += vi[i].Path.string();
              // images +="\"";
              // images +=" && feh -g 400x400  \"";
              // images += vi[i].same.string();
              // images +="\"";
              // // std::cout << images << std::endl;
              // system(images.c_str() );
              // std::string deletes =""
            }
          }
          return vi;
        }
      };
      const pipe_closure<make::deletion_fn> deletion = {};
    }
  }
  /// @}
}

#endif