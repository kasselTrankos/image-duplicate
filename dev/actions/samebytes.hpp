#ifndef SAMEBYTES_HPP
#define SAMEBYTES_HPP

#include <iostream>
#include <algorithm>
#include <sys/stat.h> 
#include <fcntl.h>
#include <fstream> 
#include "../utils.hpp"
using namespace std;
static char * buffers[3];

namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace same {
      struct bytes_fn {
        template <typename T>
        const vector<T> operator()(vector<T> vi) const {
          cout << "\nPlease wait is comparing files for find duplicates.\n" <<endl;
          vector<T> op;
          double percent = 0.0;
          const int BUFFER_SIZE =(16 * 1024);
          int j = 1;
          int file1;
          int file2;
          bool different;
          for (int i=0; i< vi.size(); i++) {
            j = i + 1;
            percent = (double) i / (vi.size() - 1);
            utils::printProgress(percent, i, vi.size());
            if (j < vi.size()) {
              while (vi[i].size == vi[j].size) {
                int isSame = utils::file::compareBytes(vi[i].Path.string().c_str(), vi[j].Path.string().c_str());
                if (isSame == 1) {
                  vi[i].same = vi[j].Path;
                  op.push_back(vi[i]);
                }
                j++;
              }
            }
            
          }
          cout << "\n found DUPS " << op.size() << endl;
          return op;
        }
      };
      const pipe_closure<same::bytes_fn> bytes = {};
    }
  }
  /// @}
}

#endif