#include <gtest/gtest.h>

#include <infrastructure/core/config.hxx>

TEST(tstCoreModule, modulename) {
    ASSERT_EQ("Core", coreModuleName);
}
