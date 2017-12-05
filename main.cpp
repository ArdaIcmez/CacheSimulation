#include <iostream>
#include <cstdlib>
#include "simulation.h"

int main(int argc, char **argv) {
  //Either read the cache info here and pass it into the simulation, or do it manually inside simulation.
  //Doing it manually will save us redundant coding.
  Simulation *sim = new Simulation();
  sim->start();
  delete sim;
  return EXIT_SUCCESS;
}
