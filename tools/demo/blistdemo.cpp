#include "bdemo/bdemo.h"
#include "bdemo/ostream_helpers.h"
#include <cstdio>
#include <iostream>

int main(int argc, char** argv)
{
    if(argc <= 1) {
        printf("Usage: blistdemo <filepath>\n");
        return 0;
    }

    bdemo::demo_t demo;
    auto result = bdemo::demo_t::parse_from(argv[1], &demo);

    if(result != bdemo::error_code::success) {
        std::cout << "Parsing failed with error " << (int)result << std::endl;
        return 1;
    } else {
        std::cout << demo.m_header;
    }

    return 0;
}
