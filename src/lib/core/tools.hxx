#pragma once

#include <core/types.hxx>

PROJECT_NAMESPACE_BEGIN

String join(const StringVector& data, const String& sep = "\n");
String toLowerCase(const String& str);
String replace(const String& str, const String& from, const String& to);

PROJECT_NAMESPACE_END
