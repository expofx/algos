/*
   Generate all permutations using recursion.

   - n! permutations for array of size n
   - each time we call search() it picks a new element to add
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// integer permutations
int n;
vector<int> permutation;
vector<bool> chosen;

void search() {
  if (permutation.size()==n) { // process permutation
    for (int p:permutation) cout << p;
    cout << "\n";
  }
  else {
    for (int i=0;i<n;i++) {
      if (chosen[i]) continue; // already included
      chosen[i] = true;
      permutation.push_back(i);
      search();
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

// string permutations
string str;
string curr;

void search2(string str, string curr, vector<bool> chosen) {
  if (curr.size()==str.length()) { // process permutation
    cout << curr << "\n";
  }
  else {
    for (int i=0;i<str.length();i++) {
      if (chosen[i]) continue;
      chosen[i] = true;
      curr+=str[i];
      search2(str, curr, chosen);
      chosen[i] = false;
      curr.pop_back();
    }
  }
}

int main() {
  n=3;
  chosen.resize(n,false);
  search();

  str="abc";
  chosen.resize(str.length(),false);
  search2(str,"",chosen);

  // or use default c++ library

  // for (int i=0;i<n;i++) {
  //   permutation.push_back(i);
  // }
  // do {
  //   for (int p:permutation) cout << p;
  //   cout << "\n";
  // } while (next_permutation(permutation.begin(), permutation.end()));
}
