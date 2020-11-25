#pragma once
#include <axl.util/lib.hpp>

const char* libType(axl::util::lib::LibraryType type)
{
	switch (type)
	{
		case axl::util::lib::LT_SHARED: return "SHARED";
		default:
		case axl::util::lib::LT_STATIC: return "STATIC";
	}
}

const char* buildType(axl::util::lib::BuildType type)
{
	switch (type)
	{
		case axl::util::lib::BT_DEBUG: return "Debug";
		case axl::util::lib::BT_RELEASE: return "Release";
		default:
		case axl::util::lib::BT_OTHER: return "Other";
	}
}