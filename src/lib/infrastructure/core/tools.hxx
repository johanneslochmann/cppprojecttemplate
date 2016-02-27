#pragma once

#include <infrastructure/core/types.hxx>

PRAM_NS_BEGIN

String join(const StringVector& data, const String& sep = "\n");
String toLowerCase(const String& str);
String replace(const String& str, const String& from, const String& to);

PRAM_NS_END
