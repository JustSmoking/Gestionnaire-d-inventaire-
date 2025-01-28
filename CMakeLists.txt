cmake_minimum_required(3.10)

project(Gestionnaire-d-inventaire)

set(CMAKE_CXX_STANDARD 23)

add_executable(main main.cpp Inventory.cpp Inventory.h)