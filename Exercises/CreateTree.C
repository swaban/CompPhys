
// Prefer compiled:
#include "TTree.h"
#include "TFile.h"
#include "TRandom.h"
#include "TMath.h"
#include <vector>

#include "EventData.h"

void CreateTree(ULong64_t numEvents = 200) {
   TFile* f = new TFile("eventdata.root", "RECREATE");
   TTree* tree = new TTree("EventTree", "Tutorial tree");

   EventData* event = new EventData();
   tree->Branch("event", &event);

   Particle p;

   for (ULong64_t i = 0; i < numEvents; ++i) {
      event->Clear();

      // generate event information
      int nParticles = 10 * gRandom->Exp(10.);

      // for every particle in the event generate the particle data 
      for (int ip = 0; ip < nParticles; ++ip) {
         do {
            p.fPosX = gRandom->Gaus(gRandom->PoissonD(0.1), 1.)
               + gRandom->BreitWigner(0.1, 0.1);;
         } while (fabs(p.fPosX) > 10.);
         p.fPosY = gRandom->Gaus(gRandom->PoissonD(0.01), .7);
         p.fPosZ = gRandom->Gaus(gRandom->PoissonD(10), 19.);

         p.fMomentum = gRandom->Exp(12);
         p.fMomentumPhi = gRandom->Uniform(2*TMath::Pi());
         do {
            p.fMomentumEta = gRandom->BreitWigner(0.01, 10.);
         } while (fabs(p.fMomentumEta) > 12.);

         
         event->AddParticle(p);
      }
      event->SetSize();

      tree->Fill();

      if (i % (numEvents/50) == 0) {
         printf("*");
         fflush(stdout);
      }
   }
   printf("\n");
   tree->Write();
   delete f;
}
