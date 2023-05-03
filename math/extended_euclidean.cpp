/*
  Extended Euclidean to find gcd and Bezout's coefficients (ax+by=gcd(a,b))
  https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
  
  - keep track of coeffs x and y

  For each step n>=2, we keep the remainder and compare with the previous remainder (think of it like a,b,r1,r2... conveyor belt, and we have a sliding window to the right, ex. a->b, b->r1 for first step)
  (1) We have: r_(n-2) = r_(n-1)*q+r_n -> r_n = r_(n-2)-q*r_(n-1)
  (2) We want to find: r_n = ax_n+by_n

  Substituting (2) into (1): r_n = (x_(n-2)-x_(n-1))a + (y_(n-2)-x_(n-1))b
  
  Which gives us the general reccurence relation for each var: x_n = x_(n-2) - x_(n-1)*q

  - can work backwards to write gcd(a,b) as linear comb of original a and b
  - general solution of adding/substracting (other term)/gcd makes sense because it is equiv to lcm/a (as gcd*lcm=a*b)
    - essentially, we are adding lcm then subtracting it; lcm = smallest value which a and b can multiply to, so it makes sense that this would be the next solution
*/

#include <iostream>
using namespace std;

int extended_gcd(int a, int b, int &x, int &y) {
  if (b==0) {
    x = 1; // initial values; a = r_0 -> x_0 = 1, y_0 = 0
    y = 0;
    return a;
  }

  // last fxn calls return first, so we are working backwards
  int r = extended_gcd(b, a%b, x, y);
  int t = y;
  y = x-(a/b)*y; // y_n = y_(n-2) - y_(n-1)*q
  x = t;
  // cout << "x: " << x << "y: " << y << "\n";
  return r;
}

/* Useful for solving linear congruence ax=b(mod m)
- multiply both sides by a_bar, modular inverse, to solve for x
- If a and m are relatively prime, there exists x and y s.t. ax+my=1 -> xa=1(mod m) since my=0(mod m) thus x is modular inverse (<- DIFFERENT X THAN SOLUTION)
*/
int modular_inverse(int a, int m) {
  int x,y;
  int gcd = extended_gcd(a, m, x, y);
  if (gcd!=1) return -1; // non-invertible
  return x<0 ? x+m : x; // make positive mod
}

// TODO: solving linear congruence equation; linear diophantine equation; chinese remainder theorem

int main() {
  int a,b,x,y; cin >> a>>b;
  int gcd = extended_gcd(a,b,x,y);
  cout << "Bezout's: " << a << "*" << x << " + " << b << "*" << y << " = " << gcd << "\n";
  cout << "General solution: ("<<x<<"-"<<b/gcd<<"k, "<<y<<"+"<<a/gcd<<"k)";
}
