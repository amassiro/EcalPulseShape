


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


double alphabeta(double* x, double*p){
  
  double fitval;
  
  if( ( 1+(x[0]-p[1]) / (p[2]*p[3]) ) > 0. ){
    fitval = p[0] * pow(1 + (x[0]-p[1]) / (p[2]*p[3]) , p[2] ) * exp ( - (x[0]-p[1]) / p[3]);
  }else{
    fitval = 0;
  }
  
  return fitval;
  
}



int main(int argc, char** argv) {
  
 std::cout << "create tag in DB changing time shift " << std::endl;

 //---- crate pulse shapes from text file Alpha, Beta, A, t0
 //  data/everycrystal_par.txt
 
 TF1 *function_alphabeta = new TF1("function_alphabeta", alphabeta, -11, 236, 4);
 
 function_alphabeta->SetParName(0, "A");
 function_alphabeta->SetParName(1, "t_0");
 function_alphabeta->SetParName(2, "alpha");
 function_alphabeta->SetParName(3, "beta");
 
 
 int NMAX = 10;
 float dt = 100.; //---- ps
 
 //---- loop over time shifts
 for (int itime = 0; itime < NMAX ; itime++) {
   //---- save a new tag for each time shift
   
 
 }
 
 
 
 
 
 
 
}




