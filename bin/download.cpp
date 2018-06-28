


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
 
 
 int simulate     (atoi(argv[1])) ;
 int fit          (atoi(argv[2])) ;
 
 
 
 //                                                                                                          simulate    fit
//  cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit("EcalPulseShapes_hlt", "EcalPulseShapes_hlt",  1      ,    2);
 cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit("EcalPulseShapes_hlt", "EcalPulseShapes_hlt",  simulate      ,    fit);

 int argc2 = argc-2;
 char** argv2 = argv; 
 PulseShapeGenerationAndFit.run(argc2, argv2);
 
 std::cout << " done " << std::endl;
 
 //---- generate according to PulseShapeGeneration and fit using PulseShapeFit
 
 //---- generate
 
 
 //---- fit 
 
 
 
 
 
}