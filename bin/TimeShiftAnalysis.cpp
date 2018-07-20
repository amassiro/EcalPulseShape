


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



//---- ROOT
#include "TF1.h"



//---- conddb & time shift
#include "ECALValidation/EcalPulseShape/interface/TimeScan.h"



int main(int argc, char** argv) {
  
 std::cout << "Study the effect of a time shift " << std::endl;

 std::string input_alpha_beta_file_name = (argv[1]) ; //---- data/everycrystal_par.txt
 
 int min_dt     (atoi(argv[2])) ;   //---- in units of delta_time
 int max_dt     (atoi(argv[3])) ;   //---- in units of delta_time

 int delta_time     (atoi(argv[4])) ;  //---- in ps
 
//  TimeScan(std::string input_alpha_beta_file_name, int min_dt, int max_dt, float delta_time)
// cond::TimeScan<EcalPulseShapes> TimeScanAnalyser(input_alpha_beta_file_name, -100, 100, 0.01);  
cond::TimeScan<EcalPulseShapes> TimeScanAnalyser(input_alpha_beta_file_name, min_dt, max_dt, delta_time/1000.);  


 int argc2 = argc-4;
 char** argv2 = argv; 
 std::cout << " *argv2 = " << *argv2 << std::endl;
 std::cout << " argc2  = " << argc2 << std::endl;
 
 TimeScanAnalyser.run(argc2, argv2);
 
 
}




