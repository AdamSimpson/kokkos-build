#include(ExternalProject)
find_package(Git REQUIRED)

#ExternalProject_Add(
#    Kokkos
#    PREFIX ${CMAKE_BINARY_DIR}/kokkos
#    GIT_REPOSITORY https://github.com/kokkos/kokkos.git
#    TIMEOUT 10
#    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
#    CONFIGURE_COMMAND ""
#    BUILD_COMMAND ""
#    INSTALL_COMMAND ""
#    LOG_DOWNLOAD ON
#   )
#ExternalProject_Get_Property(Kokkos source_dir)

set(source_dir ${CMAKE_CURRENT_SOURCE_DIR}/kokkos)

# Common files
set(KOKKOS_COMMON_INC ${source_dir}/core/src ${source_dir}/containers/src ${source_dir}/algorithms/src CACHE INTERNAL "Path to include folder for Kokkos")
set(KOKKOS_COMMON_SRC
                      ${source_dir}/core/src/impl/Kokkos_Core.cpp
                      ${source_dir}/core/src/impl/Kokkos_CPUDiscovery.cpp
                      ${source_dir}/core/src/impl/Kokkos_Error.cpp
                      ${source_dir}/core/src/impl/Kokkos_ExecPolicy.cpp
                      ${source_dir}/core/src/impl/Kokkos_HBWSpace.cpp
                      ${source_dir}/core/src/impl/Kokkos_HostSpace.cpp
                      ${source_dir}/core/src/impl/Kokkos_HostThreadTeam.cpp
                      ${source_dir}/core/src/impl/Kokkos_hwloc.cpp
                      ${source_dir}/core/src/impl/Kokkos_Profiling_Interface.cpp
                      ${source_dir}/core/src/impl/Kokkos_Serial.cpp
                      ${source_dir}/core/src/impl/Kokkos_Serial_Task.cpp
                      ${source_dir}/core/src/impl/Kokkos_SharedAlloc.cpp
                      ${source_dir}/core/src/impl/Kokkos_spinwait.cpp

                      ${source_dir}/containers/src/impl/Kokkos_UnorderedMap_impl.cpp
)

# CUDA specific files
set(KOKKOS_CUDA_SRC
                    ${source_dir}/core/src/Cuda/Kokkos_Cuda_Impl.cpp
                    ${source_dir}/core/src/Cuda/Kokkos_CudaSpace.cpp
                    ${source_dir}/core/src/Cuda/Kokkos_Cuda_Task.cpp
)
set(KOKKOS_CUDA_INC ${source_dir}/core/src/Cuda)

# OpenMP specific files
set(KOKKOS_OMP_SRC 
                   ${source_dir}/core/src/OpenMP/Kokkos_OpenMPexec.cpp
                   ${source_dir}/core/src/OpenMP/Kokkos_OpenMP_Task.cpp
)
set(KOKKOS_OMP_INC ${source_dir}/core/src/OpenMP/)

# Pthread specific files
set(KOKKOS_PTHREAD_SRC
                       ${source_dir}/core/src/Threads/Kokkos_ThreadsExec_base.cpp
                       ${source_dir}/core/src/Threads/Kokkos_ThreadsExec.cpp
)
set(KOKKOS_PTHREAD_INC ${source_dir}/core/src/Threads/)

add_custom_command(OUTPUT ${KOKKOS_COMMON_SRC} ${KOKKOS_CUDA_SRC}
                   COMMAND git clone https://github.com/kokkos/kokkos.git
                   WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                   COMMENT "Fetching KOKKOS"
                   )

