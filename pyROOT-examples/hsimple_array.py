#!/usr/bin/env python
# coding: utf-8
# In[1]:
from ROOT import TCanvas, TFile, TProfile, TNtuple, TH1F, TH2F
from ROOT import gROOT, gBenchmark, gRandom, gSystem
from array import array
# In[2]:
hfile = gROOT.FindObject( 'py-hsimple.root' )
if hfile:
   hfile.Close()
hfile = TFile( 'py-hsimple.root', 'RECREATE', 'Demo ROOT file with histograms' )
# In[3]:
hpx    = TH1F( 'hpx', 'This is the px distribution', 100, -4, 4 )
hpxpy  = TH2F( 'hpxpy', 'py vs px', 40, -4, 4, 40, -4, 4 )
hprof  = TProfile( 'hprof', 'Profile of pz versus px', 100, -4, 4, 0, 20 )
ntuple = TNtuple( 'ntuple', 'Demo ntuple', 'px:py:pz:random:i' )
# In[ ]:
# In[4]:
gRandom.SetSeed()
rannor, rndm = gRandom.Rannor, gRandom.Rndm
# In[5]:
_px = array('d', [0])
_py = array('d', [0])

for i in range( 25000 ):
 # Generate random values.
   rannor(_px, _py)
   px, py = _px[0], _py[0]
   pz = px*px + py*py
   random = rndm(1)
 # Fill histograms.
   hpx.Fill(px)
   hpxpy.Fill(px, py)
   hprof.Fill(px, pz)
   ntuple.Fill(px, py, pz, random, i )
c1 = gROOT.FindObject('c1')
if c1:
    c1=0
c1 = TCanvas( 'c1', 'Histogram Example', 200, 10, 700, 500 )
c1.SetFillColor( 42 )
c1.GetFrame().SetFillColor( 21 )
c1.GetFrame().SetBorderSize( 6 )
c1.GetFrame().SetBorderMode( -1 )
hpx.SetFillColor( 48 )
hpx.Draw()
c1.Modified()
c1.Update()
# In[ ]:
# In[7]:
gROOT.GetListOfCanvases().Draw()
# In[7]:
hpx.SetFillColor( 0 )
c1.Modified()
c1.Update()
gROOT.GetListOfCanvases().Draw()
# In[8]:
hpx.SetLineColor(2)
hpx.SetFillColor(6)
hpx.SetFillStyle( 3244 )
c1.Modified()
c1.Update()
gROOT.GetListOfCanvases().Draw()
# In[9]:
c2 = gROOT.FindObject('c2')
if c2:
    c2=0
c2 = TCanvas( 'c2', 'c2', 200, 10, 700, 500 )
hpxpy.Draw()
c2.Modified()
c2.Update()
c2.Draw()
# In[10]:
hpxpy.Draw('CONT')
c2.Modified()
c2.Update()
c2.Draw()
# In[12]:
hpxpy.Draw('COLZ')
c2.Modified()
c2.Update()
c2.Draw()
# In[13]:
hpxpy.Draw('LEGO')
c2.Modified()
c2.Update()
c2.Draw()
# In[14]:
c3 = gROOT.FindObject('c3')
if c3:
    c3=0
c3 = TCanvas( 'c3', 'c3', 200, 10, 700, 500 )
hprof.Draw()
c3.Modified()
c3.Update()
c3.Draw()
# In[15]:
c4 = gROOT.FindObject('c4')
if c4:
    c4=0
c4 = TCanvas( 'c4', 'c4', 200, 10, 700, 500 )
c4.Divide(2,2)
c4.cd(1)
ntuple.Draw("pz:px")
c4.cd(2)
ntuple.Draw("pz:py")
c4.cd(3)
ntuple.Draw("pz:px*px + py*py")
c4.cd(4)
ntuple.Draw("pz:sqrt(px*px + py*py)")
c4.Modified()
c4.Update()
c4.Draw()
# In[16]:
hfile.Write()
# In[ ]:
