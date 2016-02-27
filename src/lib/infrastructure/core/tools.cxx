#include <infrastructure/core/tools.hxx>

#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/replace.hpp>

PRAM_NS_BEGIN

String join(const StringVector& data, const String& sep) {
    return boost::algorithm::join(data, sep);
}

String toLowerCase(const String &str)
{
    return boost::algorithm::to_lower_copy(str);
}

String replace(const String &str, const String &from, const String &to)
{
    return boost::algorithm::replace_all_copy(str, from, to);
}

PRAM_NS_END
