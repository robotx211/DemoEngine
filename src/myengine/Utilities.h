#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include <iostream>

namespace myEngine
{

  //Takes in a string, and a shared_ptr to a vector of strings
  //Fills the vector of strings with the input string split up by whitespace
  void splitStringByWhitespace(std::string _input, std::vector<std::string> &_output);
  void splitStringByChar(std::string _input, char _sC, std::vector<std::string> &_output, bool _spaceBetweenSplitChar = false);

}

#endif // !UTILITIES_H