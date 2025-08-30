#ifndef MY_LIB_H
#define MY_LIB_H
#include <iostream>
#include <string>

/*prints a basic error message on the screen and exits the program*/
void printError(const std::string& msg) {
  std::cerr << "\n"
            << std::string(msg.length(), '-') + "\n" + msg + "\n" +
                   std::string(msg.length(), '-') + "\n";
  exit(1);
}

#endif
