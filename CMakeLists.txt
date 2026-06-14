cmake_minimum_required(VERSION 3.16)

project(
    cpp_multithreaded_http_server
    VERSION 1.0
    DESCRIPTION "Multithreaded HTTP/1.1 Server in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenSSL REQUIRED)

# The executable definition matching your repository paths
add_executable(server
    httpserver/server.cc
    internal/headers/headers.cc
    internal/requests/request.cc
    internal/response/response.cc
    internal/server_services/server_services.cc
)

# Corrected include paths to use 3rd-party-library
target_include_directories(server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party-library
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/requests
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/response
    ${CMAKE_CURRENT_SOURCE_DIR}/internal/server_services)

target_compile_options(server PRIVATE
    -Wall
    -Wextra
    -pthread
)

target_link_libraries(server PRIVATE
    OpenSSL::SSL
    OpenSSL::Crypto
)
