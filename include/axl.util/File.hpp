#pragma once
#include "lib.hpp"
#include "types.hpp"
#include "String.hpp"
#include "WString.hpp"

namespace axl {
namespace util {

class AXLUTILCXXAPI File
{
	private:
		File();
		~File();
	public:
		static bool exists(const String& filename);
		static size_t getSize(const String& filename);
		static String getStringContent(const String& filename);
		static WString getWStringContent(const String& filename);
};

} // namespace axl.util
} // namespace axl
