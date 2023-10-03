#include "gtest/gtest.h"
#include "steampipe_plugin/plugin.h"
#include "ob_plugin/plugin.h"

TEST(version_test, Works)
{
    EXPECT_EQ(getOBVersionCode(), 1);
    EXPECT_EQ(getSteampipeVersionCode(), 0);
}
