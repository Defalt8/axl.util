#include <cstdlib>
#if defined(WIN32) || defined(_WIN32)
#	include <Windows.h>
#	include <tchar.h>
#endif
#include <axl.util/Directory.hpp>

namespace axl {
namespace util {

bool Directory::exists(const axl::util::WString& path)
{
#	if defined(WIN32) || defined(_WIN32)
	WIN32_FIND_DATAW ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	if (path.length() > MAX_PATH) return false;
	hFind = FindFirstFileW(path.cwstr(), &ffd);
	if (INVALID_HANDLE_VALUE == hFind) return false;
	FindClose(hFind);
	return true;
#	else
	return false;
#	endif
}

bool Directory::isDirectory(const axl::util::WString& path)
{
#	if defined(WIN32) || defined(_WIN32)
	WIN32_FIND_DATAW ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	if (path.length() > MAX_PATH) return false;
	hFind = FindFirstFileW(path.cwstr(), &ffd);
	if (INVALID_HANDLE_VALUE == hFind) return false;
	FindClose(hFind);
	return ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
#	else
	return false;
#	endif
}

bool Directory::isFile(const axl::util::WString& path)
{
#	if defined(WIN32) || defined(_WIN32)
	WIN32_FIND_DATAW ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	if (path.length() > MAX_PATH) return false;
	hFind = FindFirstFileW(path.cwstr(), &ffd);
	if (INVALID_HANDLE_VALUE == hFind) return false;
	FindClose(hFind);
	return !(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY);
#	else
	return false;
#	endif
}

axl::util::WString Directory::extractParent(const axl::util::WString& path, size_t count)
{
	size_t token_index = -1;
	for(size_t i=path.length(); i>0; --i)
	{
		size_t I = i-1;
		if(path[I] == L'/' || path[I] == L'\\')
		{
			token_index = I;
			if(--count == 0)
				break;
		}
	}
	if(token_index == -1)
		return path;
	else if(count != 0)
		return axl::util::WString();
	return axl::util::WString(path, token_index == 0 ? 1 : token_index);
}

axl::util::ds::UniList<Directory::DirItem> Directory::getDirItems(const axl::util::WString& _path, int filter, size_t max_items)
{
	axl::util::ds::UniList<Directory::DirItem> dir_items;
#	if defined(WIN32) || defined(_WIN32)
	if(max_items == 0) return dir_items;
	WIN32_FIND_DATAW ffd = {};
	size_t found = 0;
	axl::util::WString path(_path);
	HANDLE hFind = INVALID_HANDLE_VALUE;
	if (path.length() > (MAX_PATH - 3)) return dir_items;
	if(path.length() > 0 && (path[path.length()-1] == L'\\' || path[path.length()-1] == L'/'))
		path.append(L"*");
	else
		path.append(L"/*");
	hFind = FindFirstFileW(path.cwstr(), &ffd);
	if (INVALID_HANDLE_VALUE == hFind) return dir_items;
	do
	{
		if(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if(!(filter & DIT_DIRECTORY)) continue;
			if(WString::scwEquals(ffd.cFileName, L".") || WString::scwEquals(ffd.cFileName, L"..")) continue;
			dir_items.insertLast(DirItem(ffd.cFileName, DIT_DIRECTORY));
			++found;
		}
		else
		{
			if(!(filter & DIT_FILE)) continue;
			dir_items.insertLast(DirItem(ffd.cFileName, DIT_FILE));
			++found;
		}
	} while (found < max_items && FindNextFileW(hFind, &ffd) != 0);
	FindClose(hFind);
#	endif
	return dir_items;
}

////
//
//

Directory::DirItem::DirItem(axl::util::WString name, DirItemType type) :
	name(name),
	type(type)
{}

} // namespace axl.util
} // namespace axl
