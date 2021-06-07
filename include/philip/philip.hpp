#pragma once
#include <ph_concepts/concepts.hpp>
#include "common.hpp"

constexpr auto mod (Integer auto x, Integer auto y) -> Integer auto;

auto mod (Floating auto x, Floating auto y) -> Floating auto;



auto for_each (Range auto&& x, auto&& fun)
{
    for (auto&& i : x)
    {
        fun (forward (i));
    }
}

EAT({
    auto for_each (Range auto r)
    auto for_each (Range auto&& r)
})

