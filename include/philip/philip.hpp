#pragma once
#include "common.hpp"
#include <ph_concepts/concepts.hpp>


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



auto read_file (const char* path) -> char*
{
    FILE* file = fopen (path, "rb");
    
    if (file == NULL)
    {
        fprintf (stderr, "Could not open file because of existance or access rights\"%s\".\n", path);
        exit (74);
    }
    
    // we seek to the very end using fseek()
    fseek (file, 0L, SEEK_END);
    
    // we call ftell() which tells us how many bytes we are from the start of the file
    size_t fileSize = ftell (file);
    rewind (file);
    
    char* buffer = (char*) malloc (fileSize + 1);
    
    if (buffer == NULL)
    {
        fprintf (stderr, "Not enough memory to read \"%s\".\n", path);
        exit (74);
    }
    
    
    size_t bytesRead = fread (buffer, sizeof (char), fileSize, file);
    
    if (bytesRead < fileSize)
    {
        fprintf (stderr, "Could not read file \"%s\".\n", path);
        exit (74);
    }
    
    buffer [bytesRead] = '\0';
    
    fclose (file);
    return buffer;
}


template <typename T>
concept String = requires (T& str)
{
    {*str.begin ()} -> convertible_to <char>;
    {*str.end ()} -> convertible_to <char>;
};
