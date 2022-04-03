#include "Utils.h"

#include <algorithm>

namespace Utils
{

    std::string ToLower(std::string str)
    {
        /*for(char& c: str)
        {
            c = std::tolower(c);
        }*/

        std::transform(std::begin(str), std::end(str), std::begin(str),
        [](unsigned char c) {return std::tolower(c);} );

        return str;
    }

}