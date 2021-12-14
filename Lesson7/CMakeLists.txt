cmake_minimum_required(VERSION 3.20)
project(Lesson7)

set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)

protobuf_generate_cpp(PROTO_SRC PROTO_HDR lesson7.proto)

add_executable(Lesson7 main.cpp ${PROTO_SRC} ${PROTO_HDR} lesson7.proto)

target_link_libraries(Lesson7 ${PROTOBUF_LIBRARY})
