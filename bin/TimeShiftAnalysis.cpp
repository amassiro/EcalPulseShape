


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

 std::string input_alpha_beta_file_name = "data/everycrystal_par.txt";
 
 
//  TimeScan(std::string input_alpha_beta_file_name, int min_dt, int max_dt, float delta_time)
 cond::TimeScan<EcalPulseShapes> TimeScanAnalyser(input_alpha_beta_file_name, -2, 2, 1);  
 
}




