#include "TFile.h"
#include "TH1.h"
#include "TRandom.h"

void histogramWrite() { 

   TFile f("histogram.root","RECREATE");

   TH1D * h1 = new TH1D("h1","h1",100,0,10); 

   //solution (uncomment this line) 
   //h1->SetDirectory(0); 


   for (int i = 0; i < 10000; ++i) 
      h1->Fill(gRandom->Exp(5) ); 

   h1->Fit("expo");

   
   h1->Draw();

   f.Write("h1"); 
   f.Close();
}
