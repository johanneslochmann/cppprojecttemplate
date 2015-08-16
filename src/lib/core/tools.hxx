#pragma once

#include <core/types.hxx>

BEGIN_PROJECT_NAMESPACE

String join(const StringVector& data, const String& sep = "\n");
String toLowerCase(const String& str);
String replace(const String& str, const String& from, const String& to);

END_PROJECT_NAMESPACE
