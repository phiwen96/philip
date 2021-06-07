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
