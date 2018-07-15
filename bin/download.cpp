


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
  
 std::cout << "Download pulse shapes " << std::endl;

 
//  cond::CondDBDumper<EcalPulseShapes> PulseShapeGeneration("EcalPulseShapes_hlt");
//  PulseShapeGeneration.run(argc, argv);
 
 
//  cond::CondDBDumper<EcalPulseShapes> PulseShapeFit("EcalPulseShapes_hlt");
//  PulseShapeFit.run(argc, argv);
 

 std::string name_tag = (argv[1]) ; //---- EcalPulseShapes_Legacy2016_v2
 
 int simulate     (atoi(argv[2])) ;
 int fit          (atoi(argv[3])) ;
 
 int toremove = 0;
 std::string dbname = "-";
 if (argc == 5) {
   //---- db added by hand
   dbname = argv[4];
   toremove +=1;
   std::cout << " dbname = " << dbname << std::endl;
 }
 
 
 
 //                                                                                                          simulate    fit
//  cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit("EcalPulseShapes_hlt", "EcalPulseShapes_hlt",  1      ,    2);
//  cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit("EcalPulseShapes_hlt", "EcalPulseShapes_hlt",  simulate      ,    fit);

//  cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit("EcalPulseShapes_October2017_rereco_v3", "EcalPulseShapes_October2017_rereco_v3",  simulate      ,    fit);
 cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit(name_tag.c_str(), name_tag.c_str(),  simulate      ,    fit,      dbname);
 
 
 int argc2 = argc-3-toremove;
 char** argv2 = argv; 
 std::cout << " *argv2 = " << *argv2 << std::endl;
 std::cout << " argc2  = " << argc2 << std::endl;
 
 PulseShapeGenerationAndFit.run(argc2, argv2);
 
 std::cout << " done " << std::endl;
 
 //---- generate according to PulseShapeGeneration and fit using PulseShapeFit
 
 //---- generate
 
 
 //---- fit 
 
 
 
 
 
}