//#include "testlib.hpp"

#ifdef RUN_CATCH

//#include "test.hpp"
#include <catch2/catch.hpp>
#include <philip/philip.hpp>
#include <ph_file/file.hpp>
#include <philip/common.hpp>
#include <climits>







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
    //    te (t);
}

template <int N>
std::array <int, N> arr {}; // array with N elements, zero-initialized

template<auto N>
constexpr decltype(N) dval = N; // type of dval depends on passed value


auto te3 (Range auto r) -> Number auto
{
    
}

auto te2 (Range auto r) -> Number auto
{
    
}

auto te1 (Range auto r) -> Number auto
{
    
}

auto te0 (Range auto r) -> Number auto
{
    return 4;
}

template <typename T>
concept Operator = requires ()
{
    true;
};


template <typename T>
concept Operand = requires ()
{
    true;
};


auto binary_operation (Operand auto x, Operator auto _, Operand auto y)
{
    
}

//template <char*>
//struct token
//{
//
//};
struct _string
{
    
};

template <char*>
constexpr _string string {};

//template <size_t N>
//token (char const* t) -> token <string<"hej">>;


//template <typename T>
//concept Token = requires ()
//{
//
//};

template <auto&>
constexpr int tok {65};

constexpr auto hash_function (String auto const& str)
{
    
}

EAT ({
    
    compilation
    {
        /// stage 1
        lexing
        {
            string -> list <@token>
        }
        
        <has_value>
        @token
        {
            has_value
        }
        
        /// stage 2
        parsing
        {
            
        }
        
        /// stage 3
        code_generation
        {
            
        }
    }
})
TEST_CASE ("")
{
//    std::cout << tok<"hej"> << std::endl;
    return;
    using namespace std;
    arr<10>[0] = 10;
    cout << arr<10>[0] << endl;
    cout << arr<11>[0] << endl;
    
    cout << dval <12> << endl;
}




auto fs() -> bool{return true;}

TEST_CASE ("begin")
{
    GIVEN ("char []")
    {
        char str[] {"hej"};
        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("char [4]")
    {
        char str[4] {"hej"};
        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("char const*")
    {
        char const* str {"hej"};
        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("std::string")
    {
        std::string str {"hej"};
        REQUIRE (*begin (str) == 'h');
    }
    
    GIVEN ("std::vector")
    {
        std::vector<int> str {1, 2, 3};
        REQUIRE (*begin (str) == 1);
    }
    
    GIVEN ("std::array")
    {
        std::array<int, 3> str {1, 2, 3};
        REQUIRE (*begin (str) == 1);
    }
}

TEST_CASE ("end")
{
    GIVEN ("char []")
    {
        char str[] {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("char [4]")
    {
        char str[4] {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("char const*")
    {
        char const* str {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("int []")
    {
        int str[] {1, 2};
//        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("int [4]")
    {
        int str[4] {1, 2, 3, 4};
//        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("std::string")
    {
        std::string str {"hej"};
        REQUIRE (*(end (str) - 1) == 'j');
    }
    
    GIVEN ("std::vector")
    {
        std::vector<int> str {1, 2, 3};
        REQUIRE (*(end (str) - 1) == 3);
    }
    
    GIVEN ("std::array")
    {
        std::array<int, 3> str {1, 2, 3};
        REQUIRE (*(end (str) - 1) == 3);
    }
}

TEST_CASE ("")
{
    using namespace std;
   

    
//    Function auto f = &fs;

    char* source = ph::file::read (TEST_FILE);
    cout << strlen (source) << endl;

    free (source);
}


#endif
