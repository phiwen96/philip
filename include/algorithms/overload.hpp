#pragma once




template <typename... T>
struct overload : T...
{

    using T::operator()...;
    
    constexpr overload () = default;
    constexpr overload (T... t) : T {t}... {}
};
