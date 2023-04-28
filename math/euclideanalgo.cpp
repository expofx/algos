/*
  Euclidean algo for finding gcd

  - idea is that if a factor divides a and b, it will also divide the difference
  gcd(a,b) = gcd(a-b,b)
  - faster euclidean idea is that if a factor divides a and b, it also divides r (since a-qb=r)
  gcd(a,b) = gcd(b,r)

  We can keep replacing the larger number with the remainder
*/

#include <iostream>
using namespace std;

int a,b,q,r;

int gcd(int a, int b) {
  if (b==0) return a; // gcd(a,0)=a
  // cout << b << " " << a%b << "\n";
  r = gcd(b,a%b); // last non-0 remainder is gcd
  return r;
}

int main() {
  cin >> a>>b;
  cout << gcd(max(a,b),min(a,b));
}
