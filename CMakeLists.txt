cmake_minimum_required(VERSION 3.8)
project(kokkos-app CUDA)

# Set source files
file(GLOB SRC_FILES Source/*.cpp)

# Find packages required for all builds
find_package(MPI REQUIRED)

# KOKKOS specific macros
add_definitions(-DKOKKOS_DONT_INCLUDE_CORE_CONFIG_H -DKOKKOS_HAVE_SERIAL -DKOKKOS_HAVE_CUDA -DKOKKOS_HAVE_CXX11 -DKOKKOS_HAVE_CUDA_LAMBDA)

# Add user provided source
add_executable(kokkos-app ${SRC_FILES})

# Set compile options
set_property(TARGET kokkos-app PROPERTY CUDA_STANDARD 11)
target_compile_options(kokkos-app PUBLIC -arch=sm_35 -ccbin /usr/bin/g++-5 --expt-extended-lambda --expt-relaxed-constexpr)

# Fetch latest kokkos
include(External/Kokkos/CMakeLists.txt)

# Add kokkos files targeting CUDA
include_directories(${KOKKOS_COMMON_INC})
include_directories(${KOKKOS_CUDA_INC})
set(KOKKOS_SRC_FILES ${KOKKOS_COMMON_SRC} ${KOKKOS_CUDA_SRC})
target_sources(kokkos-app PUBLIC ${KOKKOS_SRC_FILES})

# Force files to compile with NVCC, regardless of extention
SET_SOURCE_FILES_PROPERTIES(${KOKKOS_SRC_FILES} ${SRC_FILES} PROPERTIES LANGUAGE CUDA)

# Add link libraries
target_link_libraries(kokkos-app ${MPI_C_LIBRARIES})
