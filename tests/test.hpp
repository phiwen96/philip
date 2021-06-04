${4 + 2 = 20}
#{elaborate on this one...}

template <int>
struct Foo;

@(type){inline static constexpr int}

$(0 i 3){
    template <>
    struct Foo <${i}>
    {
        ${type} i = ${i};
    };
}
