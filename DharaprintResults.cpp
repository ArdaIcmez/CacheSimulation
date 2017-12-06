#include <iostream>
#include <iomanip>
#include <vector>
int main(void) {

  //Prints: Metrics Total Instrn Data Read Write Misc
  std::cout<<"Metrics                      Total           Instrn           Data            \
Read           Write            Misc\n";
  std::cout<<"-----------------            ------          ------          ------          -\
-----          ------          ------\n";

  //Prep for Demand Fetches Line
  double noTotal;
  double noInstrn = instrSt.hit;
  double noData;
  double noRead = readSt.hit;
  double noWrite = writeSt.hit;
  double noMisc = miscSt.hit;
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
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  //Prints: Fraction of Total
  std::cout<<" Fraction of Total ";
  for(std::vector<double>::iterator it = demandFetches.begin(); it!=demandFetches.end(); ++i\
t) {
    std::cout<<"          "<<std::setw(6)<<std::fixed<<std::setprecision(4)<<*it/noTotal;
  }
  std::cout<<std::endl<<std::endl;

  //Prep for Demand Misses Line
  std::vector<double> demandMisses;
  double noTotalM;
  double noInstrnM = instrSt.compMiss + instrSt.confMiss + instrSt.capMiss;
  double noDataM;
  double noReadM = readSt.compMiss + readSt.confMiss + readSt.capMiss;
  double noWriteM = writeSt.compMiss + writeSt.confMiss + writeSt.capMiss;
  double noMiscM = miscSt.compMiss + miscSt.confMiss + miscSt.capMiss;
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
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  //Prints: Demand miss rate
  std::cout<<" Demand Miss Rate  ";
  for(std::vector<double>::iterator it = demandMisses.begin(); it!=demandMisses.end(); ++it)\
 {
    std::cout<<"          "<<std::setw(6)<<std::fixed<<std::setprecision(4)<<*it/noTotal;
  }
  std::cout<<std::endl;

  //Prep for Compulsory Misses Line
  std::vector<double> CoMisses;
  double noTotalCoM;
  double noInstrnCoM = instrSt.compMiss;
  double noDataCoM;
  double noReadCoM = readSt.compMiss;
  double noWriteCoM = writeSt.compMiss;
  double noMiscCoM = miscSt.compMiss;
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
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  //Prep for Capacity Misses
  std::vector<double> CaMisses;
  double noTotalCaM;
  double noInstrnCaM = instrSt.capMiss;
  double noDataCaM;
  double noReadCaM = readSt.capMiss;
  double noWriteCaM = writeSt.capMiss;
  double noMiscCaM = miscSt.capMiss;
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
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  //Prep for Conflict Misses
  std::vector<double> ConMisses;
  double noTotalConM;
  double noInstrnConM = instrSt.confMiss;
  double noDataConM;
  double noReadConM = readSt.confMiss;
  double noWriteConM = writeSt.confMiss;
  double noMiscConM = miscSt.confMiss;
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
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  return 0;
}

