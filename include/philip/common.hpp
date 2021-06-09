#pragma once


#define EXPAND(...) __VA_ARGS__
#define EAT(...)
#define forward(x) std::forward <decltype (x)> (x)
#define EQUAL(...) = __VA_ARGS__ ;
#define NAME(...) __VA_ARGS__ EQUAL
#define TYPE(...)  __VA_ARGS__ NAME
//#define cexpr(...) inline static constexpr TYPE (__VA_ARGS__)

#define cexpr inline static constexpr 

#define let(...) TYPE (__VA_ARGS__)



