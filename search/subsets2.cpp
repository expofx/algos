/*
  Generate subset using bitstrings.

  - each bitstring (ex. 11010) represents whether the ith element should be included (1 or 0)
  - convention is to go from R to L (right most bit is 0th element)

*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;

// integers from 0 to n-1
int n;

void generate_subset() {
  for (int b=0;b<(1<<n);b++) { // generates bitstrings from 0-2^n
    vector<int> subset;
    for (int i=0;i<n;i++) {
      if (b&(1<<i)) subset.push_back(i); // "plucks out" the ith bit
    }
    for (int s:subset) cout << s;
    cout << "\n";
  }
}

// substrings
string str;

void generate_subset2() {
  for (int b=0;b<(1<<str.length());b++) { // for each bitstring, generate subset
    string curr="";
    for (int i=0;i<str.length();i++) {
      if (b&(1<<i)) curr+=str[i]; // gets ith letter
    }
    cout << curr << "\n";
  }
}

int main() {
  n=3;
  generate_subset();
  str="abcde";
  generate_subset2();
}
