// https://www.pramp.com/challenge/jKoA5GAVy9Sr9jGBjzN4
#include <iostream>
#include <cmath>

using namespace std;

double root(double x, unsigned int n) 
{
  // your code goes here
  double lower_bound = 0;
  double upper_bound = x;
  double approx = (lower_bound + upper_bound) / 2;

  while (approx - lower_bound < 0.001){
    if (pow(approx, n) < x){
      upper_bound = approx;
    }
    else if (pow(approx, n > x)){
      lower_bound = approx;
    }
    else{
      break;
    }
    approx = (lower_bound + upper_bound) / 2;
  }

  return approx;
}