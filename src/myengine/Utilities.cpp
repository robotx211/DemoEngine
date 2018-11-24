#include "Utilities.h"

namespace myEngine
{

  void splitStringByWhitespace(std::string _input, std::vector<std::string> &_output)
  {

    splitStringByChar(_input, ' ', _output);

  }

  void splitStringByChar(std::string _input, char _sC, std::vector<std::string> &_output, bool _spaceBetweenSplitChar)
  {

    _output.clear();

    std::string currString = "";

    for (size_t j = 0; j < _input.size(); j++)
    {

      if (_input.at(j) == _sC)
      {

        if (currString.size() != 0)
        {
          _output.push_back(currString);

          currString = "";
        }
        else if (currString.size() == 0)
        {

          if (_spaceBetweenSplitChar == true)
          {
            currString += " ";

            _output.push_back(currString);
          }

        }

      }
      else
      {
        currString += _input.at(j);
      }

    }

    //save last string?
    if (currString.size() != 0)
    {
      _output.push_back(currString);

      currString = "";
    }

  }


}