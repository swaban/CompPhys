#include "TRandom.h"
#include "TFile.h"
#include "TTree.h"

void SimpleTree(const char * filename= "tree.root") {

   TTree data("tree","Example TTree");
   double x, y, z, t;
   data.Branch("x",&x,"x/D");
   data.Branch("y",&y,"y/D");
   data.Branch("z",&z,"z/D");
   data.Branch("t",&t,"t/D");

// fill it with random data                                                                                                   
   for (int i = 0; i<10000; ++i) {
      x = gRandom->Uniform(-10,10);
      y = gRandom->Gaus(0,5);
      z = gRandom->Exp(10);
      t = gRandom->Landau(0,2);

      data.Fill();
   }
// write in a file                                                                                                            
   TFile f(filename,"RECREATE");
   data.Write();
   f.Close();

}
