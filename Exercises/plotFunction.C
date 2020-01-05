#include "TF1.h"

void plotFunction() {

   TF1 * f1 = new TF1("f1","sin(x)/x",0,10);
   f1->Draw();


   TF1 * fp = new TF1("fp","[0]*sin([1]*x)/x",0,10);
   fp->SetParameters(1,2);
   fp->Draw("same");
   fp->SetLineColor(kBlue);

   // to change axis y margins                                                                                                                  
   // (or invert the order of plotting the functions)                                                                                           
   f1->SetMaximum(2);
   f1->SetMinimum(-2);

   std::cout << "Value of f(x) at x = 1 is       " << fp->Eval(1.) << std::endl; 
   std::cout << "Derivative of f(x) at x = 1 is  " << fp->Derivative(1.) << std::endl; 
   std::cout << "Integral of f(x) in [0,3] is    " << fp->Integral(0,4)  << std::endl;
 
}
