#include <string>
#include <vector>
#include <iostream>

namespace myEngine
{

  //Takes in a string, and a shared_ptr to a vector of strings
  //Fills the vector of strings with the input string split up by whitespace
  void splitStringByWhitespace(std::string _input, std::vector<std::string> &_output)
  {

    _output.clear();

    std::string currString = "";

    for (size_t j = 0; j < _input.size(); j++)
    {

      std::cout << "Index = " << j << "\t";

      if (_input.at(j) == ' ')
      {
        //start new string
        if (currString.size() != 0)
        {
          _output.push_back(currString);

          std::cout << "Saving:" << currString;

          currString = "";
        }

      }
      else
      {
        currString += _input.at(j);

        std::cout << "Adding:" << _input.at(j);

      }

      std::cout << std::endl;

    }

    //save last string?
    if (currString.size() != 0)
    {
      _output.push_back(currString);

      std::cout << "Saving:" << currString << std::endl;

      currString = "";
    }
   
  }

}