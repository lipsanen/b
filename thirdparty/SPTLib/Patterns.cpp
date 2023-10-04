#include "SPTLib/patterns.hpp"
#include <stdexcept>

using namespace patterns;

static uint8_t PatternHexValue(char c)
{
    if(c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }
    else
    {
        throw std::domain_error("Bad character in pattern, only hex values, question marks and spaces are allowed");
    }
}

bool PatternWrapper::match(const uint8_t* memory) const
{
    for (size_t i = 0; i < bytes.size(); ++i)
        if (mask[i] && memory[i] != bytes[i])
            return false;

    return true;
}

PatternContainer::PatternContainer(std::initializer_list<std::string> patternInit)
{
    if(patternInit.size() % 2 != 0)
    {
        throw std::domain_error("Pattern list must have a multiple of two strings passed to it, name and pattern for each pattern");
    }

    size_t index = 0;
    for(auto& str : patternInit)
    {
        if((index % 2) == 0)
        {
            patterns.push_back(PatternWrapper());
            patterns[index / 2].name = str;
        }
        else
        {
            std::uint8_t currentByte = 0;
            std::size_t bytes = 0;
            bool isMask = true;
            for(char c : str)
            {
                if(std::isspace(c))
                    continue;

                if (c == '?')
                {
                    isMask = false;
                }         
                else if(bytes == 0)
                {
                    currentByte += PatternHexValue(c) << 4;
                }
                else if(bytes == 1)
                {
                    currentByte += PatternHexValue(c);
                }

                ++bytes;

                if(bytes == 2)
                {
                    patterns[index / 2].bytes.push_back(currentByte);
                    patterns[index / 2].mask.push_back(isMask);
                    bytes = 0;
                    currentByte = 0;
                    isMask = true;
                }
            }
        }

        ++index;
    }
}
