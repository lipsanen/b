#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace patterns
{
    struct PatternWrapper
    {
        std::string name;
        std::vector<uint8_t> bytes; // The pattern in bytes
        std::vector<bool> mask; // The vector mask

        size_t length() const { return bytes.size(); }
        bool match(const uint8_t* memory) const;
    };

    struct PatternContainer
    {
        std::vector<PatternWrapper> patterns;
        PatternContainer(std::initializer_list<std::string> patternInit);
    };

	struct MatchedPattern
	{
		uintptr_t ptr;
		size_t ptnIndex;
	};

	struct ModulePatternData
	{
		char MD5[16]; // MD5 hash for the module
		std::vector<MatchedPattern> matchedPatterns;
	};
}
