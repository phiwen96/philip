//#include "testlib.hpp"

#ifdef RUN_CATCH

//#include "test.hpp"
#include <catch2/catch.hpp>
#include <philip/philip.hpp>
#include <ph_file/file.hpp>







auto fun = [] (Number auto x) {std::cout << x << std::endl;};



TEST_CASE ("for_each")
{
    return;
    GIVEN ("vector")
    {
        std::vector <int> in {1, 2, 3};
        for_each (in, fun);
    }
    
    GIVEN ("string")
    {
        std::string in {"hej"};
        for_each (in, fun);
    }
    
    GIVEN ("char const*")
    {
        char const* in {"hej"};
//        for_each (in, fun);
    }
}


#define Self Test
struct Self
{
    
//    Self () = delete;
    Self () {}
    Self (Self &&) = delete;
    Self (Self const&) = delete;
    
    Self& operator= (Self &&) = delete;
    Self& operator= (Self const&) = delete;
};
#undef Self

auto te (auto&& x) {std::cout << std::is_same_v <decltype (x), Test &> << std::endl;}

TEST_CASE ("")
{
    Test const  t;
    te (t);
}


TEST_CASE ("")
{
    using namespace std;
    cout << __cplusplus << endl;
    
    char* source = ph::file::read (TEST_FILE);
//    cout << source << endl;
    free (source);
}


#endif
