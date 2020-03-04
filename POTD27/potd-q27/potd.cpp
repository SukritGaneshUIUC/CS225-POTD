// Your code here
#include "potd.h"

string getFortune(const string &s) {
  int x = s.length() % 5;
  switch (x) {
    case 0:
      return "You won a Chrysler PT Cruiser! Doug deMuro will be proud :)";
    case 1:
      return "You're moving to North Korea! Wait ... that's a good thing!?!?";
    case 2:
      return "100% on every class except CS225! That's because you'll get a 110% in 225! Extra credit FTW!";
    case 3:
      return "Your company just went public! #IPOClub";
    case 4:
      return "You'll have the world's 2nd happiest marrige. Who will have the happiest, though? Your future spouse! HA ha ha!";
  }
  return "bad luck ...";

}
