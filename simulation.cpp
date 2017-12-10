#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "simulation.h"
#include <iomanip>

void Simulation::analyseAdd(int type, int status, int level) {
  //type is the type of instruction, status is the result of hit or miss
  switch (type) {
  case 0 :
    readSt[level].addResult(status);
    break;
  case 1:
    writeSt[level].addResult(status);
    break;
  case 2:
    instrSt[level].addResult(status);
    break;
  default:
    miscSt[level].addResult(status);
    break;
    }
}

void Simulation::printResult() {
  size_t noLoop = 1;
  if (!l2.empty()) {
    noLoop++;
  }
for(size_t i = 0; i <noLoop; i++) {
Stats instrSt_t = instrSt[i];
Stats readSt_t = readSt[i]; 
Stats writeSt_t = writeSt[i];
Stats miscSt_t = miscSt[i];   
//Prints: Metrics Total Instrn Data Read Write Misc
  std::cout<<"Metrics                      Total           Instrn           Data            \
Read           Write            Misc\n";
  std::cout<<"-----------------            ------          ------          ------          -\
-----          ------          ------\n";
  //Prep for Demand Fetches Line
  double noTotal;
  double noInstrn = instrSt_t.total;
  double noData;
  double noRead = readSt_t.total;
  double noWrite = writeSt_t.total;
  double noMisc = miscSt_t.total;
  noData = noRead + noWrite;
  noTotal = noInstrn + noData;
  std::vector<double> demandFetches;
  demandFetches.push_back(noTotal);
  demandFetches.push_back(noInstrn);
  demandFetches.push_back(noData);
  demandFetches.push_back(noRead);
  demandFetches.push_back(noWrite);
  demandFetches.push_back(noMisc);
 //Prints: Demand Fetches
  std::cout<<"Demand Feteches    ";
  for(std::vector<double>::iterator it = demandFetches.begin(); it!=demandFetches.end(); ++i\
t) {
    std::cout<<"     "<<std::setw(11)<<*it;
  }
  std::cout<<std::endl;
  //Prints: Fraction of Total
  std::cout<<" Fraction of Total ";
  for(std::vector<double>::iterator it = demandFetches.begin(); it!=demandFetches.end(); ++i\
t) {
    std::cout<<"     "<<std::setw(11)<<std::fixed<<std::setprecision(4)<<*it/noTotal;
  }
  std::cout<<std::endl<<std::endl;
  //Prep for Demand Misses Line
  std::vector<double> demandMisses;
  double noTotalM;
  double noInstrnM = instrSt_t.compMiss + instrSt_t.confMiss + instrSt_t.capMiss;
  double noDataM;
  double noReadM = readSt_t.compMiss + readSt_t.confMiss + readSt_t.capMiss;
  double noWriteM = writeSt_t.compMiss + writeSt_t.confMiss + writeSt_t.capMiss;
  double noMiscM = miscSt_t.compMiss + miscSt_t.confMiss + miscSt_t.capMiss;
  noDataM = noReadM + noWriteM;
  noTotalM = noDataM + noInstrnM;
  demandMisses.push_back(noTotalM);
  demandMisses.push_back(noInstrnM);
  demandMisses.push_back(noDataM);
  demandMisses.push_back(noReadM);
  demandMisses.push_back(noWriteM);
  demandMisses.push_back(noMiscM);
  //Prints: Demand Misses
  std::cout<<"Demand Misses      "<<std::setprecision(0);
  for(std::vector<double>::iterator it = demandMisses.begin(); it!=demandMisses.end(); ++it)\
 {
    std::cout<<"     "<<std::setw(11)<<*it;
  }
  std::cout<<std::endl;
  //Prints: Demand miss rate
  std::cout<<" Demand Miss Rate  ";
  for(std::vector<double>::iterator it = demandMisses.begin(); it!=demandMisses.end(); ++it) \
    {
   std::cout<<"     "<<std::setw(11)<<std::fixed<<std::setprecision(4)<<*it/noTotal;
    }
  std::cout<<std::endl;
  //Prep for Compulsory Misses Line
  std::vector<double> CoMisses;
  double noTotalCoM;
  double noInstrnCoM = instrSt_t.compMiss;
  double noDataCoM;
  double noReadCoM = readSt_t.compMiss;
  double noWriteCoM = writeSt_t.compMiss;
  double noMiscCoM = miscSt_t.compMiss;
  noDataCoM = noReadCoM + noWriteCoM;
  noTotalCoM = noInstrnCoM + noDataCoM;
  CoMisses.push_back(noTotalCoM);
  CoMisses.push_back(noInstrnCoM);
  CoMisses.push_back(noDataCoM);
  CoMisses.push_back(noReadCoM);
  CoMisses.push_back(noWriteCoM);
  CoMisses.push_back(noMiscCoM);
  std::cout<<"  Compulsory Misses"<<std::setprecision(0);
  for(std::vector<double>::iterator it = CoMisses.begin(); it!=CoMisses.end(); ++it) {
    std::cout<<"     "<<std::setw(11)<<*it;
  }
  std::cout<<std::endl;
  //Prep for Capacity Misses
  std::vector<double> CaMisses;
  double noTotalCaM;
  double noInstrnCaM = instrSt_t.capMiss;
  double noDataCaM;
  double noReadCaM = readSt_t.capMiss;
  double noWriteCaM = writeSt_t.capMiss;
  double noMiscCaM = miscSt_t.capMiss;
  noDataCaM = noReadCaM + noWriteCaM;
  noTotalCaM = noInstrnCaM + noDataCaM;
  CaMisses.push_back(noTotalCaM);
  CaMisses.push_back(noInstrnCaM);
  CaMisses.push_back(noDataCaM);
  CaMisses.push_back(noReadCaM);
  CaMisses.push_back(noWriteCaM);
  CaMisses.push_back(noMiscCaM);
  std::cout<<"  Capacity Misses  "<<std::setprecision(0);
  for(std::vector<double>::iterator it = CaMisses.begin(); it!=CaMisses.end(); ++it) {
    std::cout<<"     "<<std::setw(11)<<*it;
  }
  std::cout<<std::endl;
  //Prep for Conflict Misses
  std::vector<double> ConMisses;
  double noTotalConM;
  double noInstrnConM = instrSt_t.confMiss;
  double noDataConM;
  double noReadConM = readSt_t.confMiss;
  double noWriteConM = writeSt_t.confMiss;
  double noMiscConM = miscSt_t.confMiss;
  noDataConM = noReadConM + noWriteConM;
  noTotalConM = noInstrnConM + noDataConM;
  ConMisses.push_back(noTotalConM);
  ConMisses.push_back(noInstrnConM);
  ConMisses.push_back(noDataConM);
  ConMisses.push_back(noReadConM);
  ConMisses.push_back(noWriteConM);
  ConMisses.push_back(noMiscConM);
  //Print Conflict Misses Line
  std::cout<<"  Conflict Misses  "<<std::setprecision(0);
  for(std::vector<double>::iterator it = ConMisses.begin(); it!=ConMisses.end(); ++it) {
    std::cout<<"     "<<std::setw(11)<<*it;
  }
  std::cout<<std::endl; 
  // Print that result with numbers like the one in website, calculating stuff should be straightforward
 }
}

void Simulation::assignCaches(Cache ** c1, Cache ** c2, int type) {
  /*
    First cache is always instruction, second cache is always data
*/
  *c2 = NULL;
  if (type == 2) {
    *c1 = &(l1[0]);
    if (l2.size() > 0) {
      *c2 = &(l2[0]);
    }
  } else {
    if (l1.size() > 1) {
      *c1 = (&l1[1]);
    } else {
      *c1 = (&l1[0]);
    }
    if (l2.size() > 1) {
      *c2 = (&l2[1]);
    } else if (l2.size() > 0) {
      *c2 = (&l2[0]);
    }
  }
}

void Simulation::assignFACaches(Cache ** c1, Cache ** c2, int type) {
  /*
    First cache is always instruction, second cache is always data
*/
  *c2 = NULL;
  if (type == 2) {
    *c1 = &(faL1[0]);
    if (faL2.size() > 0) {
      *c2 = &(faL2[0]);
    }
  } else {
    if (faL1.size() > 1) {
      *c1 = (&faL1[1]);
    } else {
      *c1 = (&faL1[0]);
    }
    if (faL2.size() > 1) {
      *c2 = (&faL2[1]);
    } else if (faL2.size() > 0) {
      *c2 = (&faL2[0]);
    }
  }
}

void Simulation::formCaches(std::vector<std::string> caches) {
  std::vector<std::string>::iterator it;
  size_t cacheSize = 0;
  size_t lineSize = 0;
  bool aWrite = false;
  for (it = caches.begin(); it != caches.end(); ++it) {
    if (*it == "YES") {
      classifyMisses = true;
      continue;
    }
    std::stringstream ss;
    std::string cacheStr = *it;
    size_t sizePos = cacheStr.find("S");
    size_t linePos = cacheStr.find("P");
    ss << cacheStr.substr(sizePos+1, linePos - sizePos -1);
    ss << " ";
    ss << cacheStr.substr(linePos+1);
    ss >> cacheSize;
    ss >> lineSize;
    if (cacheStr[4] == 'W') {
      aWrite = true;
    }
    if (cacheStr[0] == '1') {
      Cache c(1, cacheSize, lineSize, cacheStr[2]-'0',cacheStr[3], aWrite, cacheStr[1]);
      l1.push_back(c);
      if (classifyMisses) {
	Cache c(1, cacheSize, lineSize, 0, cacheStr[3], aWrite, cacheStr[1]);
	faL1.push_back(c);
      }
    } else if(cacheStr[0] == '2') {
      Cache c(2, cacheSize, lineSize, cacheStr[2]-'0',cacheStr[3], aWrite, cacheStr[1]);
      l2.push_back(c);
      if (classifyMisses) {
	Cache c(2, cacheSize, lineSize, 0, cacheStr[3], aWrite, cacheStr[1]);
	faL2.push_back(c);
      }
    }
  }
}

void Simulation::start(char *filename) {
  // Go in a loop to read file, and call required functions
  std::ifstream ifs(filename);
  if (ifs.is_open()) {
    std::string line;
    std::string line2;
    Cache *c1;
    Cache *c2;
    Cache *fac1 = NULL;
    Cache *fac2 = NULL;
    while (ifs.good()) {
      std::getline(ifs, line);
      if (line.length() == 0){
	continue;
      }      
      int type = line[0] - '0';
      int type2 = type;
      line = line.substr(2);  // get the hex address
      line2 = line;
      //Call get caches to get the ones that are gonna be processed
      assignCaches(&c1,&c2,type);
      //Get the result of checkHit of that cache
      int result = c1->checkHit(line,type);
      if (c1->isDirty && c2 != NULL) {
	std::stringstream ss ;
	ss << (c1->dirtyAddress).substr(0,2);
	c1->dirtyAddress = (c1->dirtyAddress).substr(2);
	int dType;
	ss >> dType;
	int resc2 = c2->checkHit(c1->dirtyAddress,dType);	
	analyseAdd(dType,resc2,1);
	c1->isDirty = false;
      }
      if (result != HIT && c2 != NULL) {
	int resc2 = c2->checkHit(line,type);
	analyseAdd(type,resc2,1);
      }
      analyseAdd(type,result,0);

      if (classifyMisses) {
	assignFACaches(&fac1, &fac2, type2);
	int fares1 = fac1->checkHit(line2,type2);
	if (fac1->isDirty && fac2 != NULL) {
	  std::stringstream sss ;
	  sss << (fac1->dirtyAddress).substr(0,2);
	  fac1->dirtyAddress = (fac1->dirtyAddress).substr(2);
	  int dType;
	  sss >> dType;
	  analyseAdd(dType,fac2->checkHit(fac1->dirtyAddress,dType),3);
	  fac1->isDirty = false;
	}
	if (fares1 != HIT && fac2 != NULL) {
	  int resc2 = fac2->checkHit(line2,type2);
	  analyseAdd(type2,resc2,3);
	}
	analyseAdd(type2,fares1,2);
      }
      
    }
    if (classifyMisses) {
      instrSt[0].capMiss = instrSt[0].confMiss - (instrSt[2].hit - instrSt[0].hit);
      instrSt[0].confMiss = (instrSt[2].hit - instrSt[0].hit);
      readSt[0].capMiss = readSt[0].confMiss - (readSt[2].hit - readSt[0].hit);
      readSt[0].confMiss = (readSt[2].hit - readSt[0].hit);
      writeSt[0].capMiss = writeSt[0].confMiss - (writeSt[2].hit - writeSt[0].hit);
      writeSt[0].confMiss = (writeSt[2].hit - writeSt[0].hit);
      miscSt[0].capMiss = miscSt[0].confMiss - (miscSt[2].hit - miscSt[0].hit);
      miscSt[0].confMiss += (miscSt[2].hit - miscSt[0].hit);
      
      instrSt[1].capMiss = instrSt[1].confMiss - (instrSt[3].hit - instrSt[1].hit);
      instrSt[1].confMiss = (instrSt[3].hit - instrSt[1].hit);
      readSt[1].capMiss = readSt[1].confMiss - (readSt[2].hit - readSt[1].hit);
      readSt[1].confMiss = (readSt[3].hit - readSt[1].hit);
      writeSt[1].capMiss = writeSt[1].confMiss - (writeSt[3].hit - writeSt[1].hit);
      writeSt[1].confMiss = (writeSt[3].hit - writeSt[1].hit);
      miscSt[1].capMiss = miscSt[1].confMiss - (miscSt[3].hit - miscSt[1].hit);
      miscSt[1].confMiss += (miscSt[3].hit - miscSt[1].hit);
      
    }
  } else {
    std::cerr << "Couldn't open the test file!" << std::endl;
    exit(EXIT_FAILURE);
  }
}
