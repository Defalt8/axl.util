#pragma once
#include <stddef.h>
#include "lib.hpp"

namespace axl {
namespace utils {

class String
{
	public:
		typedef char char_t;
	public:
		String(size_t length = 0U);
		String(const char_t* cstring);
		String(const char_t* cstring, size_t length, size_t offset = 0U);
		String(const String& tocopy);
		String(const String& tocopy, size_t length, size_t offset = 0U);
		#if (__cplusplus >= 201103)
		String(String&& tomove);
		#endif
		~String();
	public:
		#if (__cplusplus >= 201103)
		String& operator=(String&& tomove);
		#endif
		String& operator=(const String& tocopy);
		String& operator=(const char_t* cstring);
	public:
		const char_t& operator[](size_t index) const;
		char_t& operator[](size_t index);
		String operator+(const String& rhs) const;
		String operator+(const char_t* rhs) const;
		String& operator+=(const String& rhs);
		String& operator+=(const char_t* rhs);
	public:
		bool operator==(const String& rhs) const;
		bool operator!=(const String& rhs) const;
		bool operator>=(const String& rhs) const;
		bool operator<=(const String& rhs) const;
		bool operator>(const String& rhs) const;
		bool operator<(const String& rhs) const;
	public:
		size_t length() const;
		size_t length(bool check);
		size_t size() const;
		bool isNull() const;
		const char_t* cstr() const;
		char_t* str();
	public:
		void destroy();
		bool resize(size_t new_length);
		String& append(const String& toappend);
		String& append(const String& toappend, size_t length, size_t offset = 0U);
		String& append(const char_t* cstring);
		String& append(const char_t* cstring, size_t length, size_t offset = 0U);
		String substring(size_t length, size_t offset = 0U) const;
		String reverse() const;
		String toUpper() const;
		String toLower() const;
	public:
		static size_t scLength(const char_t* cstr, size_t max=-1);
		static char_t* scCopy(const char_t* cstrsrc, char_t* cstrdest, size_t length, size_t srcoffset = 0U, size_t destoffset = 0U);
	public:
		bool is_sensitive;
	private:
		char_t* m_array;
		size_t m_length;
		size_t m_size;
	public:
		const static char_t*const NullCStr;
		static char_t*const NullStr;
		const static char_t NullChar;
	friend class WString;
};

} // namespace axl.utils
} // namespace axl