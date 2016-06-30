SET(CMAKE_C_COMPILER "c++")

execute_process(COMMAND llvm-config --cxxflags --ldflags --libs core mcjit native OUTPUT_VARIABLE LLVM_CXX_FLAGS)
string(REGEX REPLACE "\n" " " LLVM_CXX_FLAGS "${LLVM_CXX_FLAGS}")

set(CMAKE_CXX_FLAGS "${LLVM_CXX_FLAGS} -O3 -g -w -lcurses -lz -ldl -lpthread")

find_package(BISON)
find_package(FLEX)

BISON_TARGET(MyParser VWSL.y ${CMAKE_CURRENT_BINARY_DIR}/y.tab.c)
FLEX_TARGET(MyScanner VWSL.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    )

add_executable(ISO
    iso_main.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
    )
