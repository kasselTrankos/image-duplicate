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

int FileCompareByte(const char *name1, const char *name2)  
{  
    int ret=0;    // 0=Matching
    // char buf1;
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
            utils::printProgress(percent, vi[j].Path.string());
            while (vi[i].size == vi[j].size) {
              // cout << "compare " << vi[i].Path << " with " << vi[j].Path << endl;
              int isSame = FileCompareByte(vi[i].Path.string().c_str(), vi[j].Path.string().c_str());
              if (isSame == 1) {
                vi[i].same = vi[j].Path;
                op.push_back(vi[i]);
              }
              j++;
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