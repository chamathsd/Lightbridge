#include <string>
#include "sceneparser.h"

namespace lightbridge
{
    bool ParseFile(const std::string &filename)
    {
        if (filename == "-")
        {
            // TODO: handle scene processing from standard input
            return true;
        }
        else
        {
            // TODO: handle scene processing per file
            return false;
        }
    }
}
