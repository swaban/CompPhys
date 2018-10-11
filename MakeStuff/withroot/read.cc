#define read_cxx
#include "util.h"
#include "init.h"
#include "read.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {
  util();
  init();
  cout << "Hello World!" << endl;
  TH1D *hist = new TH1D("hist","hist",10,-10,10);
  return 0; 
}
