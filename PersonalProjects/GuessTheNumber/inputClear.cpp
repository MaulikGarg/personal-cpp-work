#include "inputClear.h"
#include <iostream>
#include <limits> // for std::numeric_limits

namespace inputclear
{
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // returns true if std::cin has unextracted input on the current line, false otherwise
    bool hasUnextractedInput()
    {
        return !std::cin.eof() && std::cin.peek() != '\n';
    }
}
