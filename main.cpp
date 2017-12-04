#include <iostream>
#include <cstdlib>
#include "simulation.h"

int main(int argc, char **argv) {
  Simulation sim = new Simulation();
  sim->start();
  delete sim;
  return EXIT_SUCCESS;
}
