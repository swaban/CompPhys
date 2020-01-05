#include "TF1.h"
#include "Math/DistFunc.h"


void plotGamma() {

   // Note that parameter [0] is called alpha in definition of gamma_pdf or kappa in Wikipedia                                                  
   // Note that parameter [1] is  theta                                                                                                         

   // use range [0,20] as in Wikipedia plot                                                                                                     
   TF1 * f1 = new TF1("f","ROOT::Math::gamma_pdf(x,[0],[1])",0,20);

   f1->SetLineColor(kRed);
   f1->SetParameter(0,1);
   f1->SetParameter(1,2);

   // use DrawClone because we will plot many different copies of same object but with different                                                
   // parameter values                                                                                                                          
   f1->DrawClone();


   // now change parameters and draw at different parameter values                                                                              
   f1->SetLineColor(kGreen);
   f1->SetParameter(0,2);
   f1->DrawClone("SAME");

   f1->SetLineColor(kBlue);
   f1->SetParameter(0,3);
   f1->DrawClone("SAME");

   f1->SetLineColor(kCyan);
   f1->SetParameter(0,5);
   f1->SetParameter(1,1);
   f1->DrawClone("SAME");


   f1->SetLineColor(kOrange);
   f1->SetParameter(0,9);
   f1->SetParameter(1,0.5);
   f1->DrawClone("SAME");


}
