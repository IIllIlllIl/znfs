###显示项目主目录
message(STATUS "Source Dir --src :${CMAKE_SOURCE_DIR}")

###引用头文件
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

###创建静态库
set(LIB_PRO_IMPL HelloWorld.cc)

add_library(proimpl STATIC ${LIB_PRO_IMPL})