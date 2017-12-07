#include <iostream>
#include <iomanip>
#include <vector>
int main(void) {
for(size_t = 0; i < 2; i++) {
Stats instrnSt_t = instrSt[i];
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
  double noInstrn = instrSt_t.hit;
  double noData;
  double noRead = readSt_t.hit;
  double noWrite = writeSt_t.hit;
  double noMisc = miscSt_t.hit;
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
    std::cout<<"          "<<std::setw(6)<<*it;
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
    std::cout<<"          "<<std::setw(6)<<*it;
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
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  return 0;
}

