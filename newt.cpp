/* c++ program from lecture 2, 
 * the Newton algorithm 
 */

#include<iostream>
#include<cmath>

using namespace std;
int main(int argc, char *argv[]){
  double x;
  cout << "Initial guess:" << endl;
  cin >> x;

  double err, tol = 10e-12, x1;
  int it, maxit = 200;
  
  err = 10; it = 0;

  while (err > tol && it < maxit){
    // cos and sin from cmath
    x1 = x - (x-cos(x))/(1+sin(x));
    err = fabs(x1-x); x = x1; it++;
  }
  if (err <= tol) cout << "Root: " << x << endl;
  else cout << "No conv" << endl;

  return 0;
}
