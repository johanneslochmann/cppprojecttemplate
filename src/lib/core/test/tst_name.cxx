#include <gtest/gtest.h>

#include <infrastructure/core/name.hxx>

TEST(tstName, ctor) {
	Name n;

	ASSERT_FALSE(n.isValid());
	ASSERT_TRUE(n.value().empty());
}
