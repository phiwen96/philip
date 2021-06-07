

file(GLOB_RECURSE HEADER_LIST "${PROJECT_SOURCE_DIR}/include/*.hpp" *.hpp)
file(GLOB SOURCE_LIST ${PROJECT_SOURCE_DIR}/src/*.cpp)

set (self ${PROJECT_NAME})

add_library (${self} STATIC 
	${SOURCE_LIST}  ${HEADER_LIST} 
)

set_target_properties (${self}
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS YES
)

target_compile_features (${self}
    PUBLIC
        cxx_std_20
        cxx_variadic_templates
        cxx_nullptr
	  $<$<CXX_COMPILER_ID:GNU>:cxx_attributes>
	  
    PRIVATE
        cxx_lambdas
)

file (GLOB CONFIGS ${CMAKE_CURRENT_LIST_DIR}/in/*.hpp)
foreach (file ${CONFIGS})
	get_filename_component (name ${file} NAME)
	configure_file (${file} ${CMAKE_CURRENT_LIST_DIR}/priv/${name} @ONLY)
endforeach ()





# CLANG_CXX_LANGUAGE_STANDARD = c++2a

ph_precompile (TARGET ${self} PUBLIC PCH ${std_pch} ${boost_pch})

add_library (ph::philip ALIAS ${self})
target_link_libraries (${self} PRIVATE ${Boost_LIBRARIES} ph::concepts ph::file ph::hash)
target_include_directories (${self} PUBLIC ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS} ph::concepts ph::file ph::hash)
# target_include_directories (${self} PUBLIC ph::coroutines)
target_compile_features (${self} PUBLIC cxx_std_20)
target_include_directories (${self} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})


set (with_variadics ${CMAKE_CURRENT_SOURCE_DIR})
set (no_variadics   ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${self} 
    PUBLIC
	 $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	 $<INSTALL_INTERFACE:include>

    PRIVATE
       $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/${self}>
       $<INSTALL_INTERFACE:include/${self}>
	 ${CMAKE_CURRENT_LIST_DIR}/priv

    INTERFACE
        "$<$<COMPILE_FEATURES:cxx_variadic_templates>:${with_variadics}>"
        "$<$<NOT:$<COMPILE_FEATURES:cxx_variadic_templates>>:${no_variadics}>"
)





if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
endif()