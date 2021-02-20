
#include <axl.util/Random.hpp>

namespace axl {
namespace util {

////////////
// Random8

Random8::Random8(Random8::rand_t seed) :
    m_last(0),
    seed(seed)
{}

Random8::rand_t Random8::random()
{
    return (m_last = 0x67 * m_last + seed);
}

Random8::rand_t Random8::range(Random8::rand_t min, Random8::rand_t max)
{
    if(min >= max) return -1;
    const rand_t range = (max - min + 1);
    return min + (random() % range);
}

////////////
// Random16

Random16::Random16(Random16::rand_t seed) :
    m_last(0),
    seed(seed)
{}

Random16::rand_t Random16::random()
{
    return (m_last = (0xF69B * m_last + seed));
}

Random16::rand_t Random16::range(Random16::rand_t min, Random16::rand_t max)
{
    return min + (random() % (max - min + 1));
}

////////////
// Random32

Random32::Random32(Random32::rand_t seed) :
    m_last(0),
    seed(seed)
{}

Random32::rand_t Random32::random()
{
    return (m_last = (0xF69FF69B * m_last + seed));
}

Random32::rand_t Random32::range(Random32::rand_t min, Random32::rand_t max)
{
    return min + (random() % (max - min + 1));
}

} // axl::util
} // axl
