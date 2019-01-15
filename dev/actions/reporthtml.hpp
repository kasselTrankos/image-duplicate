#ifndef REPORTHTML_HPP
#define REPORTHTML_HPP

#include <iostream>
#include <string>
#include "functional.hpp"
#include <fstream>


using namespace utils;
namespace files {
  /// \addtogroup group-actions
  /// @{
  namespace actions {
    namespace report {
      struct html_fn {
        template <typename T>
        const std::vector<T> operator()(const std::vector<T>& vi) const {
          std::ofstream myfile;
          myfile.open ("report.html");
          myfile << "<!DOCTYPE html><html><head>";
          myfile << "<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css\" integrity=\"sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS\" crossorigin=\"anonymous\">";
          myfile << "<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/js/bootstrap.min.js\" integrity=\"sha384-B0UglyR+jN6CkvvICOB2joaf5I4l3gm9GU6Hc1og6Ls7i6U/mkkaduKaBhlAXv9k\" crossorigin=\"anonymous\"></script>";
          // myfile << "<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" integrity=\"sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u\" crossorigin=\"anonymous\">";
          myfile << "</head><body><ul>"; //starting html
          myfile << "<div class=\"container-fluid\">";
          myfile << "<div class=\"row flex-xl-nowrap\">";
          //add some html content
          //as an example: if you have array of objects featuring the properties name & value, you can print out a new line for each property pairs like this:
          for (int i=0; i< vi.size(); i++) {
            myfile << "<div class=\"card col-md-2\" style=\"width: 18rem;\">";
            myfile << "<img class=\"card-img-top img-thumbnail\" src=\"" << vi[i].Path.string() << "\" alt=\"Original\">";
            // myfile << "<img class=\"card-img-bottom img-thumbnail\" src=\"" << vi[i].same.string() << "\" alt=\"Card image cap\">";
            myfile << "<div class=\"card-body\">";
            // myfile << "<p class=\"card-title\"> Original: " << vi[i].name << "</p>";
            myfile << "<a href=\"" << vi[i].Path.string() << "\" class=\"btn btn-primary\">View</a>";
            myfile << "</div>";
            myfile << "</div>";
              // myfile << "\n<li><img width=\"100\" height=\"100\"  class=\"img-rounded\" src=\"" << vi[i].Path.string() << "\"/></li>";

          }

        //ending html
          myfile << "</div>";
          myfile << "</div>";
          myfile << "</ul></body></html>";
          myfile.close();
          return vi;
        }
      };
      const pipe_closure<report::html_fn> html = {};
    }
  }
  /// @}
}

#endif