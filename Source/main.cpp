#include <iostream>
#include <Kokkos_Core.hpp>

int main(int argc, char **argv) {
  Kokkos::initialize(argc, argv);

  std::cout<<"Hello!\n";

  Kokkos::finalize();
  return 0;
}
