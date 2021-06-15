#pragma once
#include "lib.hpp"
#include "types.hpp"
#include "String.hpp"
#include "WString.hpp"
#include "ds/List.hpp"

namespace axl {
namespace util {

class AXLUTILCXXAPI Directory
{
	public:
		enum DirItemType
		{
			DIT_UNSPECIFIED = 0,
			DIT_DIRECTORY = 1,
			DIT_FILE = 2,
		};
		struct DirItem
		{
			axl::util::WString name;
			DirItemType type;
			DirItem(axl::util::WString name = L"", DirItemType type = DIT_UNSPECIFIED);
		};
	public:
		static bool exists(const axl::util::WString& path);
		static bool isDirectory(const axl::util::WString& path);
		static bool isFile(const axl::util::WString& path);
		static axl::util::WString extractParent(const axl::util::WString& path, size_t count = 1);
		static axl::util::ds::UniList<DirItem> getDirItems(const axl::util::WString& path, int filter = 3, size_t max_items = -1);
		Directory() = delete;
		~Directory() = delete;
};

} // namespace axl.util
} // namespace axl
