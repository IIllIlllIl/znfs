###显示test项目的主目录
message(STATUS "Source Dir --test :${CMAKE_SOURCE_DIR}")

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

###生成TEST项目
if(CMAKE_BUILD_TYPE MATCHES "Debug")
file(GLOB C_FILES_IN_UTESTS "${CMAKE_SOURCE_DIR}/tests/utests/*.cc")
set(
      SOURCE_FILES
      ${C_FILES_IN_UTESTS}
      ${CMAKE_SOURCE_DIR}/tests/test.cc
      )
add_executable(utest ${SOURCE_FILES})
add_dependencies(utest proimpl)
target_link_libraries(utest proimpl)
endif()
