#include <gtest/gtest.h>

#include <infrastructure/core/uuid.hxx>

TEST(tstUuid, ctor) {
    auto id = Uuid();

    ASSERT_TRUE(id.isValid());
}

TEST(tstUuid, stringCtor) {
    auto id = Uuid(String("00c31b44-2869-11e5-998d-db68525c093a"));

    ASSERT_TRUE(id.isValid());
}

TEST(tstUuid, operatorEqual) {
    auto id = Uuid(String("00c31b44-2869-11e5-998d-db68525c093a"));
    auto id2 = Uuid(String("00c31b44-2869-11e5-998d-db68525c093a"));

    ASSERT_EQ(id, id2);
    ASSERT_EQ(id, id);
}

TEST(tstUuid, operatorDifferent) {
    auto id = Uuid(String("00c31b44-2869-11e5-998d-db68525c093a"));
    auto id2 = Uuid(String("e8651826-2869-11e5-a064-576682e8124a"));

    ASSERT_NE(id, id2);
}

TEST(tstUuid, asMapKey) {
    std::map<Uuid, String> a_map;
}

TEST(tstUuid, toString) {
    auto id = Uuid(String("00c31b44-2869-11e5-998d-db68525c093a"));

    ASSERT_EQ("00c31b44-2869-11e5-998d-db68525c093a", id.toString());
}

TEST(tstUuid, outStreamOperator) {
    auto id = Uuid(String("00c31b44-2869-11e5-998d-db68525c093a"));

    StringStream s;

    s << id;

    ASSERT_EQ("00c31b44-2869-11e5-998d-db68525c093a", s.str());
}
