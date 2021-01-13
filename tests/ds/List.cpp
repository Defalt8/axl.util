#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../Assert.hpp"
#include "../lib.hpp"
#include <axl.util/ds/List.hpp>
#include <axl.util/uc/Tracer.hpp>

#ifdef AXUTIL_BUILD
#	error("AXUTIL_BUILD defined!")
#endif

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	using namespace axl;
	using namespace axl::util;
	printf("axl.util - version %u.%u.%u -- %s %s --- [List] test.\n", lib::VERSION.major, lib::VERSION.minor, lib::VERSION.patch, libType(lib::LIBRARY_TYPE), buildType(lib::BUILD_TYPE));
	puts("----------------------------------------");
	{ // UniList
		using namespace axl::util::ds;
		{
			UniList<int> unilist;
			Assertv(unilist.isEmpty(), verbose);
			Assertv(unilist.insertLast(5), verbose);
			Assertv(!unilist.isEmpty(), verbose);
			Assertv(unilist.insertLast(6), verbose);
			Assertv(!unilist.isEmpty(), verbose);
			Assertv(unilist.insertLast(7), verbose);
			Assertv(!unilist.isEmpty(), verbose);
			Assertv(unilist.removeFirst() == 5, verbose);
			Assertv(!unilist.isEmpty(), verbose);
			Assertv(unilist.removeFirst() == 6, verbose);
			Assertv(!unilist.isEmpty(), verbose);
			Assertv(unilist.removeFirst() == 7, verbose);
			Assertv(unilist.isEmpty(), verbose);
			Assertv(unilist.removeFirst() == 0, verbose);
			Assertv(unilist.isEmpty(), verbose);
		}
		{ // insertFirst
			UniList<int> unilist;
			int i;
			for(i = 1; i <= 5; ++i)
				if(!unilist.insertFirst(i)) break;;
			Assertv(i == 6, verbose);
			Assertv(!unilist.isEmpty(), verbose);
			Assertv(!unilist.begin().isNull(), verbose);
			Assertv(!unilist.last().isNull(), verbose);
			int counter = 6;
			for(UniList<int>::Iterator it = unilist.begin(); it != unilist.end() || !it.isNull(); ++it)
			{
				Assertv(*it == --counter, verbose);
			}
			counter = 6;
			for(UniList<int>::Iterator it = unilist.begin(); it != unilist.end() || !it.isNull(); it++)
			{
				Assertv(*it == --counter, verbose);
			}
		}
		{ // insertLast
			UniList<int> unilist;
			int i;
			for(i = 1; i <= 5; ++i)
				if(!unilist.insertLast(i)) break;;
			Assertv(i == 6, verbose);
			Assertv(!unilist.isEmpty(), verbose);
			Assertv(!unilist.begin().isNull(), verbose);
			Assertv(!unilist.last().isNull(), verbose);
			int counter = 0;
			for(UniList<int>::Iterator it = unilist.begin(); it != unilist.end() || !it.isNull(); ++it)
			{
				Assertv(*it == ++counter, verbose);
			}
			counter = 0;
			for(UniList<int>::Iterator it = unilist.begin(); it != unilist.end() || !it.isNull(); it++)
			{
				Assertv(*it == ++counter, verbose);
			}
		}
		{ // removeFirst
			UniList<int> unilist;
			int i;
			for(i = 1; i <= 5; ++i)
				if(!unilist.insertLast(i)) break;;
			Assertv(i == 6, verbose);
			int counter = 0;
			while(!unilist.isEmpty())
			{
				Assertv(++counter == unilist.removeFirst(), verbose);
			}
		}
		{ // removeAll
			UniList<int> unilist;
			int i;
			for(i = 1; i <= 5; ++i)
				if(!unilist.insertLast(i)) break;;
			Assertv(i == 6, verbose);
			Assertv(!unilist.isEmpty(), verbose);
			unilist.removeAll();
			Assertv(unilist.isEmpty(), verbose);
			Assertv(unilist.begin().isNull(), verbose);
			Assertv(unilist.last().isNull(), verbose);
		}
		{ // Tracer
			using namespace axl::util::uc;
			Tracer::Reset();
			Assertv(Tracer::TOP == 0, verbose);
			Assertv(Tracer::ACTIVE == 0, verbose);
			{
				UniList<Tracer> unilist;
				Assertv(Tracer::TOP == 0, verbose);
				Assertv(Tracer::ACTIVE == 0, verbose);
				Assertv(unilist.isEmpty(), verbose);
				Assertv(unilist.begin().isNull(), verbose);
				Assertv(unilist.last().isNull(), verbose);
				int i;
				for(i = 1; i <= 5; ++i)
					unilist.insertLast(i);
				Assertv(i == 6, verbose);
				Assertv(Tracer::TOP == 5, verbose);
				Assertv(Tracer::ACTIVE == 5, verbose);
				int counter = 0;
				for(UniList<Tracer>::Iterator it = unilist.begin(); it != unilist.end() || !it.isNull(); ++it)
				{
					Assertv(it->value == ++counter, verbose);
				}
			}
			Assertv(Tracer::TOP == 5, verbose);
			Assertv(Tracer::ACTIVE == 0, verbose);
			Tracer::Reset();
		}
	}
	if(Assert::_num_failed_tests > 0 || verbose) puts("----------------------------------------");
	printf("# %d Failed!\n", Assert::_num_failed_tests);
	return Assert::_num_failed_tests;
}