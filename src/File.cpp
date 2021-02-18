#include <cstdio>
#include <axl.util/File.hpp>

namespace axl {
namespace util {

bool File::exists(const String& filename)
{
	FILE* file = (FILE*)0;
#	ifdef __STDC_WANT_SECURE_LIB__
		fopen_s(&file, filename.cstr(), "r");
#	else
		file = fopen(filename.cstr(), "r");
#	endif
	if(file)
	{
		fclose(file);
		return true;
	}
	return false;
}

size_t File::getSize(const String& filename)
{
	size_t file_size = 0;
	FILE* file = (FILE*)0;
#	ifdef __STDC_WANT_SECURE_LIB__
		fopen_s(&file, filename.cstr(), "r");
#	else
		file = fopen(filename.cstr(), "r");
#	endif
	if(file)
	{
		fseek(file, 0, SEEK_END);
		file_size = (size_t)ftell(file);
		fclose(file);
	}
	return file_size;
}

String File::getStringContent(const String& filename)
{
	String content;
	FILE* file = (FILE*)0;
#	ifdef __STDC_WANT_SECURE_LIB__
		fopen_s(&file, filename.cstr(), "r");
#	else
		file = fopen(filename.cstr(), "r");
#	endif
	if(file)
	{
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		fseek(file, 0, SEEK_SET);
		if(content.resize(size))
		{
			size_t read_size = fread(content.str(), sizeof(String::char_t), size, file);
			content[read_size] = '\0';
			content.length(true);
		}
		fclose(file);
	}
	return content;
}

WString File::getWStringContent(const String& filename)
{
	WString content;
	FILE* file = (FILE*)0;
#	ifdef __STDC_WANT_SECURE_LIB__
		fopen_s(&file, filename.cstr(), "r");
#	else
		file = fopen(filename.cstr(), "r");
#	endif
	if(file)
	{
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		fseek(file, 0, SEEK_SET);
		if(content.resize(size))
		{
			size_t read_size = 0;
			int c;
			while((c = fgetc(file)) != EOF)
			{
				content[read_size++] = (WString::char_t)c;
			}
			content[read_size] = L'\0';
			content.length(true);
		}
		fclose(file);
	}
	return content;
}

} // namespace axl.util
} // namespace axl
