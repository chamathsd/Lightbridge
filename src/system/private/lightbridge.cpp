#include "sceneparser.h"

#include <vector>
#include <iostream>

using namespace lightbridge;

int main(int argc, char *argv[])
{
    // TODO: set up render options class
    std::vector<std::string> sceneFiles;

    // TODO: process command-line args into sceneFiles

    // Initialize scene description
    if (sceneFiles.size() != 0)
    {
        ParseFile("-");
    }
    else
    {
        for (const std::string &file : sceneFiles)
        {
            if (!ParseFile(file))
            {
                // TODO: handle error through Error class
                std::cout << "Error: cannot yet handle scene files" << std::endl;
            }
        }
    }

    // TODO: cleanup scene elements
	return 0;
}
