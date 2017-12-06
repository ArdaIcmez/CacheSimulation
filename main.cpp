#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include "simulation.h"

std::string cachify(std::string type,std::string cacheSpecs) {
  std::string cacheStr = type + "-" +cacheSpecs;
  return cacheStr;
}

std::vector<std::string> readCmdline (int argc, char** argv) {
  std::string l1Type = " ";
  std::string l11Specs = " ";
  std::string l12Specs = " ";
  std::string l2Type = " ";
  std::string l21Specs = " ";
  std::string l22Specs = " ";
  int charRead;
  while ((charRead = getopt(argc, argv, "a:b:c:d:e:f:")) != -1) {
    switch (charRead) {
    case 'a' :
      l1Type = optarg;
      break;
    case 'b' :
      l11Specs = optarg;
      break;
    case 'c' :
      l12Specs = optarg;
      break;
    case 'd' :
      l2Type = optarg;
      break;
    case 'e' :
      l21Specs = optarg;
      break;
    case 'f' :
      l22Specs = optarg;
      break;
    default :
      abort();
    }
  }
  std::vector<std::string> caches;
  if (l1Type != " ") {
    if (l1Type == "S") {
      caches.push_back(cachify("1-I",l11Specs));
      caches.push_back(cachify("1-D", l12Specs));
    } else if (l1Type == "U") {
    caches.push_back(cachify("1-U", l11Specs));
    }
  }
  if (l2Type != " ") {
    if (l2Type == "S") {
      caches.push_back(cachify("2-I",l21Specs));
      caches.push_back(cachify("2-D", l22Specs));
    }else if (l2Type == "U") {
      caches.push_back(cachify("2-U", l21Specs));
    }
  }
  return caches;
}

int main(int argc, char **argv) {
  //Either read the cache info here and pass it into the simulation, or do it manually inside simulation.
  //Doing it manually will save us redundant coding.
  //Read from command line
  Simulation *sim = new Simulation();
  sim->formCaches(readCmdline(argc, argv));
  //sim->start(argv[1]);
  delete sim;
  return EXIT_SUCCESS;
}
