#include "gtest/gtest.h"
#include "SPTLib/patterns.hpp"

TEST(version_test, Works)
{
    patterns::PatternContainer container(
        {
            "5135",
            "4F ?? 00 ??"
        }
    );

    EXPECT_EQ(container.patterns.size(), 1);
    auto& pattern = container.patterns[0];
    EXPECT_EQ(pattern.name, "5135");
    EXPECT_EQ(pattern.bytes.size(), 4);
    EXPECT_EQ(pattern.bytes[0], 0x4F);
    EXPECT_EQ(pattern.mask[0], true);
    EXPECT_EQ(pattern.mask[1], false);
    EXPECT_EQ(pattern.bytes[2], 0x00);
    EXPECT_EQ(pattern.mask[2], true);
    EXPECT_EQ(pattern.mask[3], false);
}
