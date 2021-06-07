#pragma once


#define EXPAND(...) __VA_ARGS__
#define EAT(...)
#define forward(x) std::forward <decltype (x)> (x)
