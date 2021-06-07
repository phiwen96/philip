# Testing library
set (${self} test_${PROJECT_NAME})
# ph_fetch (catch2)
find_package(Catch2 REQUIRED)

file(GLOB_RECURSE HEADER_LIST "include/*.hpp")
file(GLOB SOURCE_LIST *.cpp)

# set (self "test_${name}")
# set (deps )
macro (ph_add_test name)

	add_executable (test_${name} testlib.cpp test_${name}.cpp ${HEADER_LIST})
	# set_target_properties (test_${name} PROPERTIES CXX_STANDARD 17)
	set_target_properties (test_${name} PROPERTIES CLANG_CXX_LANGUAGE_STANDARD 20)

	
	# CLANG_CXX_LANGUAGE_STANDARD
	# PUBLIC $<$<CXX_COMPILER_ID:GNU>:cxx_attributes>
	target_compile_features (test_${name}
		PUBLIC
			cxx_std_20
			cxx_variadic_templates
			cxx_nullptr
			$<$<CXX_COMPILER_ID:GNU>:cxx_attributes>

		PRIVATE
		cxx_std_20
			cxx_lambdas
	)
	target_link_libraries (test_${name} PRIVATE ph::concepts ${PROJECT_NAME} Catch2::Catch2 philip ph::file)
	target_include_directories (test_${name} PRIVATE ../include ph::concepts include philip ph::file)
	ph_precompile (TARGET test_${name} PRIVATE PCH ${std_pch})
	target_sources (test_${name} PRIVATE ../test.hpp)
	file (GLOB test_file ../test.hpp)
	target_compile_definitions (test_${name} PRIVATE TEST_FILE="${test_file}")
	# if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
		set_target_properties(test_${name}          PROPERTIES FOLDER "${PROJECT_NAME}")
	# endif()		
endmacro ()


# add_executable (test_${PROJECT_NAME}_sequence testlib.cpp test_sequence.cpp ${HEADER_LIST})
# add_executable (test_${PROJECT_NAME}_algorithms testlib.cpp test_algorithms.cpp ${HEADER_LIST})

# ph_add_test (algorithms)
# ph_add_test (sequence)
# ph_add_test (allocator)
# ph_add_test (vector)
# ph_add_test (arena)
# ph_add_test (array)
# ph_add_test (pointee)
ph_add_test (philip)

# target_link_libraries (test_${PROJECT_NAME}_algorithms PRIVATE ${PROJECT_NAME} Catch2::Catch2 ph::color)
# target_include_directories (test_${PROJECT_NAME}_algorithms PRIVATE include ph::color)
# ph_precompile (TARGET test_${PROJECT_NAME}_algorithms PRIVATE PCH ${std_pch})

# target_link_libraries (test_${PROJECT_NAME}_sequence PRIVATE ${PROJECT_NAME} Catch2::Catch2 ph::color)
# target_include_directories (test_${PROJECT_NAME}_sequence PRIVATE include ph::color)
# ph_precompile (TARGET test_${PROJECT_NAME}_sequence PRIVATE PCH ${std_pch})

add_test (NAME testtest_${PROJECT_NAME} COMMAND ${self}) 


# if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
#     set_target_properties(test_${PROJECT_NAME}_sequence          PROPERTIES FOLDER "${PROJECT_NAME}")
#     set_target_properties(test_${PROJECT_NAME}_algorithms          PROPERTIES FOLDER "${PROJECT_NAME}")

# else()
#     set_target_properties(test_${PROJECT_NAME}_sequence           PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
#     set_target_properties(test_${PROJECT_NAME}_algorithms          PROPERTIES FOLDER "${PROJECT_NAME}")

# endif()



