


//---- std include ----
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream> 



//---- conddb
#include "ECALValidation/EcalPulseShape/interface/CondDBDumper.h"




int main(int argc, char** argv) {
  
 std::cout << "Scan all a tag of pulse shapes " << std::endl;

 std::string name_tag = (argv[1]) ; //---- EcalPulseShapes_Legacy2016_v2
 int max_iov = atoi(argv[2]) ; //---- 
 
 //                                                                                                          simulate    fit
 
 int toremove = 0;
 std::string dbname = "-";
 if (argc == 4) {
   //---- db added by hand
   dbname = argv[3];
   toremove +=1;
 }
 
 std::cout << " name_tag = " << name_tag << std::endl;
 std::cout << " max_iov  = " << max_iov << std::endl;
 
 int argc2 = argc-2-toremove;
 char** argv2 = argv; 
 
 
 
 cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit(name_tag, max_iov, dbname);  
 
 //---- generate according to PulseShapeGeneration and fit using PulseShapeFit
 //---- generate
 //---- fit 
   
 PulseShapeGenerationAndFit.run(argc2, argv2);
 
 std::cout << " done " << std::endl;
 
 
}