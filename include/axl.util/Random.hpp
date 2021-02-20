#pragma once
#include "lib.hpp"

namespace axl {
namespace util {

class AXLUTILCXXAPI Random8
{
    public: typedef unsigned char rand_t;
    public:
        Random8(rand_t seed = 0XFB);
        rand_t random();
        rand_t range(rand_t min, rand_t max);
    public:
        rand_t seed;
    private:
        rand_t m_last;
};

class AXLUTILCXXAPI Random16
{
    public: typedef unsigned short rand_t;
    public:
        Random16(rand_t seed = 0XFFFB);
        rand_t random();
        rand_t range(rand_t min, rand_t max);
    public:
        rand_t seed;
    private:
        rand_t m_last;
};

class AXLUTILCXXAPI Random32
{
    public: typedef unsigned long rand_t;
    public:
        Random32(rand_t seed = 0XFFFFFFFB);
        rand_t random();
        rand_t range(rand_t min, rand_t max);
    public:
        rand_t seed;
    private:
        rand_t m_last;
};

} // axl::util
} // axl
