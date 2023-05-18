/*
  Chinese remainder theorem for solving system of linear congruences
  1. Check if mods are relatively prime (TODO)
    a. If not get rid of common factor or see if it has no soln
  2. Multiply by Mk (product of all other mods besides mk), its inverse, and a_k (residual mod mk)
    a. Get inverse using extended euclidean
  3. Sum and simplify (mod M)

  Input: a1(mod m1), a2(mod m2), ... an(mod mn)
  Output: x=r(mod M)

  Usage: g++ -o crt.out chinese_remainder.cpp extended_euclidean.cpp && ./crt.out
*/

#include "extended_euclidean.h"
#include <iostream>

using namespace std;

void crt(int a[], int m[]) {
  int size = sizeof(m) / sizeof(m[0]);
  int M = 1;
  for (int i=0; i<=size; i++) {
    M*=m[i];
  }

  int sum = 0;
  for (int i=0; i<=size; i++) {
    int Mk = M/m[i];
    int Mk_inv = modular_inverse(Mk,m[i]);
    sum += Mk * Mk_inv * a[i];
  }

  cout << "x = " << sum%M << "(mod " << M << ")";
}

int main() {
  int a[] = {2,3,2};
  int m[] = {3,5,7};

  crt(a,m);
}