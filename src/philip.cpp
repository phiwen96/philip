#include "philip.hpp"

constexpr auto mod (Integer auto x, Integer auto y) -> Integer auto
{
    return x % y;
}


static_assert (mod (4, 3) == 1, "");


auto mod (Floating auto x, Floating auto y) -> Floating auto
{
    return std::modf (x, y);
}


#define Concept String
//static_assert (Concept <char const*>, "");
#define Self string
struct Self
{
    char s[10];
    
    auto begin () -> auto*
    {
        return s;
    }
    auto end () -> auto*
    {
        return s + 10;
    }
};
static_assert (Concept <Self>, "");
#undef Self
#undef Concept
