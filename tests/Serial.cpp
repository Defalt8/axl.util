#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Assert.hpp"
#include <axl.util/everything.hpp>

class Person : public axl::util::Serial
{
	public:
		Person(const char* p_name = "", axl::util::uint8 p_age = 0, float p_height = 0.0f, float p_weight = 0.0f) :
			axl::util::Serial(),
			name(),
			name_len(0),
			age(p_age),
			height(p_height),
			weight(p_weight)
		{
			name_len = axl::util::String::scLength(p_name);
			name_len = name_len > 35 ? 35 : name_len;
			axl::util::String::scCopy(p_name, name, name_len+1);
			axl::util::Serial::Register(name, 36, 0);
			axl::util::Serial::Register(&name_len, sizeof(name_len), 1);
			axl::util::Serial::Register(&age, sizeof(age), 2);
			axl::util::Serial::Register(&height, sizeof(height), 3);
			axl::util::Serial::Register(&weight, sizeof(weight), 4);
		}
	public:
		char name[36];
		axl::util::size_t name_len;
		axl::util::uint8 age;
		float height;
		float weight;
};

int main(int argc, char *argv[])
{
	bool verbose = argc > 1 && (0 == strcmp(argv[1], "-v") || 0 == strcmp(argv[1], "--verbose"));
	printf("axl.util.Serial test");
	puts("----------------------------------------");
	{
		axl::util::protocol::V0 protocol;
		Person person("Axel Eshetu", 23, 1.83f, 52.2f);
		{
			using namespace axl::util;
			Assertv(String::scEqual(person.name, "Axel Eshetu"), verbose);
			Assertv(person.name_len == 11, verbose);
			Assertv(person.age == 23, verbose);
			Assertv(person.height == 1.83f, verbose);
			Assertv(person.weight == 52.2f, verbose);
		}
		axl::util::ds::Array<axl::util::byte, axl::util::ds::Allocators::Malloc<axl::util::byte>> data = protocol.serialize(person);
		{
			Person p;
			protocol.deserialize(p, data);
			{
				using namespace axl::util;
				Assertv(String::scEqual(p.name, "Axel Eshetu"), verbose);
				Assertv(p.name_len == 11, verbose);
				Assertv(p.age == 23, verbose);
				Assertv(p.height == 1.83f, verbose);
				Assertv(p.weight == 52.2f, verbose);
			}
		}
		int x = 0;
	}
	if(axl::Assert::_num_failed_tests > 0 || verbose) puts("----------------------------------------");
	printf("# %d Failed!\n", axl::Assert::_num_failed_tests);
	return axl::Assert::_num_failed_tests;
}