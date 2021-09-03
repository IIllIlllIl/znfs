###显示项目主目录
message(STATUS "Source Dir --release-src :${CMAKE_SOURCE_DIR}")

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

###生成RELEASE项目
if(CMAKE_BUILD_TYPE MATCHES "Release")
file(GLOB C_FILES_IN_RELEASE_SRC "${CMAKE_SOURCE_DIR}/release-src/*.cc")
set(
      SOURCE_FILES
      ${C_FILES_IN_RELEASE_SRC}
      ${CMAKE_SOURCE_DIR}/release-src/main.cc
      )
add_executable(release-src ${SOURCE_FILES})
add_dependencies(release-src proimpl)
target_link_libraries(release-src proimpl)
endif()