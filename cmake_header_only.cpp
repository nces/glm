// Ref: https://cmake.org/pipermail/cmake-developers/2015-July/025657.html
static void __cmake_header_only()
{
	// using the workaround of generating a dummy cpp file and
	// use a static library instead of an interface library ... ugly hack, but
	// allows to populate msvc / xcode / qtcreator projects ...
}
