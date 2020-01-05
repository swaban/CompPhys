#include "TH1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLine.h"
#include <iostream>

void HistoOperations() { 


   TH1D * h1 = new TH1D("h1","flat histogram",100,0,10);
   for (int i = 0; i < 10000; ++i) { 
      h1->Fill( gRandom->Uniform(0,10) ); 
   }

   TH1D * h2 = new TH1D("h2","gaus histogram",100,0,10);
   for (int i = 0; i < 1000; ++i) { 
      h2->Fill( gRandom->Gaus(5,1) ); 
   }

   TH1D * h3 = new TH1D("h3","flat+gaus histogram",100,0,10);
   h3->Add(h1,h2);

   h3->Draw();


   TH1D * h4 = new TH1D("h4","second flat histogram",100,0,10);
   for (int i = 0; i < 100000; ++i) { 
      h4->Fill( gRandom->Uniform(0,10) ); 
   }

   // renormalize histogram
   //!! VERY IMPORTANT - NEED TO CALL Sumw2() to get right ERRORS!!!
   h4->Sumw2();
   h3->Sumw2();
   h4->Scale(0.1);

   // plot in a new Canvas
   new TCanvas("c2","c2");


  TH1D * h5 = new TH1D("h5","(flat+gaus) histogram - flat histogram",100,0,10);
  h5->Add(h3,h4,1.,-1.);
  h5->Draw("E");

  TLine * line = new TLine(0,0,10,0);
  line->Draw();
   

}
