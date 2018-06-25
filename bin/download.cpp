


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
 
 
 cond::CondDBDumper<EcalPulseShapes> PulseShapeGenerationAndFit("EcalPulseShapes_hlt", "EcalPulseShapes_hlt");
 PulseShapeGenerationAndFit.run(argc, argv);
 
 
 
 //---- generate according to PulseShapeGeneration and fit using PulseShapeFit
 
 //---- generate
 
 
 //---- fit 
 
 
 
 
 
}