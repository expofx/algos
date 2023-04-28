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
  // a=qb+r where gcd(a,b)=gcd(b,r)
  q = a/b;
  r = a%b;
  if (r==0) return b; // get previous remainder
  a = b; b = r; // update
  // cout << a << " " << b << "\n";
  gcd(a,b);
}

int main() {
  cin >> a>>b;
  cout << gcd(max(a,b),min(a,b));
}
