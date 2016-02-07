#pragma once

#include <vector>

namespace SDLopenGL
{

    class IOManager
    {
    public:
        static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
    };

}