#include <gtest/gtest.h>

#include <core/tools.hxx>

PROJECT_NAMESPACE_BEGIN

TEST(tst_tools, toLowerCase) {
    String upper { "FOO BAR" };
    String lower { "bar baz" };
    String mixed { "Cav Cuv" };

    ASSERT_EQ("foo bar", toLowerCase(upper));
    ASSERT_EQ("bar baz", toLowerCase(lower));
    ASSERT_EQ("cav cuv", toLowerCase(mixed));
}

TEST(tst_tools, replace) {
    String msg { "a little lamp" };

    ASSERT_EQ("a big lamp", replace(msg, "little", "big"));
}

PROJECT_NAMESPACE_END
