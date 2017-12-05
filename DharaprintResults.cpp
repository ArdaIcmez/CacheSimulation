#include <iostream>
#include <iomanip>
#include <vector>
int main(void) {
  double noTotal = 10000;
  double noInstrn = 7637;
  double noRead = 1027 ;
  double noWrite = 1336;
  double noData = noRead + noWrite;
  double noMisc = 0;
  /*
  std::cout<<"Metrics                      Total           Instrn           Data            R\
ead           Write            Misc\n";
  std::cout<<"-----------------            ------          ------          ------          --\
----          ------          ------\n";
  std::cout<<"Demand Fetches"<<"               "<<std::setw(6)<<noTotal<<"          "<<std::s\
etw(6)<<noInstrn<<"          "<<std::setw(6)<<noData<<"          "<<std::setw(6)<<noRead<<"  \
        "<<std::setw(6)<<noWrite<<"           "<<std::setw(6)<<noMisc<<std::endl;

  */
  std::vector<double> demandFetches;
  demandFetches.push_back(noTotal);
  demandFetches.push_back(noInstrn);
  demandFetches.push_back(noData);
  demandFetches.push_back(noRead);
  demandFetches.push_back(noWrite);
  demandFetches.push_back(noMisc);

  std::cout<<"Metrics                      Total           Instrn           Data            R\
ead           Write            Misc\n";
    std::cout<<"-----------------            ------          ------          ------          \
------          ------          ------\n";
  std::cout<<"Demand Feteches    ";
  for(std::vector<double>::iterator it = demandFetches.begin(); it!=demandFetches.end(); ++it\
) {
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  std::cout<<" Fraction of Total ";
  for(std::vector<double>::iterator it = demandFetches.begin(); it!=demandFetches.end(); ++it\
) {
    std::cout<<"          "<<std::setw(6)<<std::fixed<<std::setprecision(4)<<*it/noTotal;
  }
  std::cout<<std::endl<<std::endl;

  std::vector<double> demandMisses;
  double noTotalM = 493;
  double noInstrnM = 251;
  double noReadM = 48;
  double noWriteM = 194;
  double noDataM = noReadM + noWriteM;
  double noMiscM = 0;

  demandMisses.push_back(noTotalM);
  demandMisses.push_back(noInstrnM);
  demandMisses.push_back(noDataM);
  demandMisses.push_back(noReadM);
  demandMisses.push_back(noWriteM);
  demandMisses.push_back(noMiscM);

  std::cout<<"Demand Misses      "<<std::setprecision(0);
  for(std::vector<double>::iterator it = demandMisses.begin(); it!=demandMisses.end(); ++it) \
{
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;


  std::cout<<" Demand Miss Rate  ";
  for(std::vector<double>::iterator it = demandMisses.begin(); it!=demandMisses.end(); ++it) \
{
    std::cout<<"          "<<std::setw(6)<<std::fixed<<std::setprecision(4)<<*it/noTotal;
  }
  std::cout<<std::endl;

  std::vector<double> CoMisses;
  double noTotalCoM = 417;
  double noInstrnCoM = 216;
  double noReadCoM = 22;
  double noWriteCoM = 179;
  double noDataCoM = noReadCoM + noWriteCoM;
  double noMiscCoM = 0;

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


  std::vector<double> CaMisses;
  double noTotalCaM = 5;
  double noInstrnCaM = 2;
  double noReadCaM = 1;
  double noWriteCaM = 2;
  double noDataCaM = noReadCaM + noWriteCaM;
  double noMiscCaM = 0;

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

  std::vector<double> ConMisses;
  double noTotalConM = 71;
  double noInstrnConM = 33;
  double noReadConM = 25;
  double noWriteConM = 13;
  double noDataConM = noReadConM + noWriteConM;
  double noMiscConM = 0;

  ConMisses.push_back(noTotalConM);
  ConMisses.push_back(noInstrnConM);
  ConMisses.push_back(noDataConM);
  ConMisses.push_back(noReadConM);
  ConMisses.push_back(noWriteConM);
  ConMisses.push_back(noMiscConM);

  std::cout<<"  Conflict Misses  "<<std::setprecision(0);
  for(std::vector<double>::iterator it = ConMisses.begin(); it!=ConMisses.end(); ++it) {
    std::cout<<"          "<<std::setw(6)<<*it;
  }
  std::cout<<std::endl;

  return 0;
}



