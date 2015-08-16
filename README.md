# cppprojecttemplate

C++ project template

This is a project template with the following features:

- managed by cmake
- discovers and uses gtest
- discovers and uses clang

- optionally discovers and uses libpqxx via buildsys/FindPqxx.cmake
- optionally discovers and uses sloccount via buildsys/FindSloccount.cmake
- optionally discovers and uses json library via buildsys/Findjson.cmake
- optionally discovers and uses gitsts via buildsys/FindGitstats.cmake
- optionally discovers and uses doxygen

In addition to the usual cmake generated targets these additional targets are provided:

doc:
	run doxygen on the source tree - only enabled if doxygen is found
stat:
	run sloccount on the source tree - only enabled if sloccount is found
gitstats:
	run gitstats on the source tree - only enabled if gitstats is found

