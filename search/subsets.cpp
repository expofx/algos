/*
  Generates all subsets using recursion.

  - there will be 2^n subsets since for each element we choose to leave in or out
  - another way of thinking about it: rows of pascal triangle add up to 2^n (first choose 1 element, then 2, then 3...)

 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// integer subsets from 0 to n-1
vector<int> subset;
int n;

void search(int k=0) {
  if (k==n) { // process subset
    for (int s:subset) {cout << s;}
    cout << "\n";
  }
  else {
    search(k+1); // don't include k
    subset.push_back(k);
    search(k+1); // include k
    subset.pop_back();
  }
}

// substrings
string str;

void search2(int k=0, string curr="") {
  if (k==str.length()) { cout << curr << "\n"; }
  else {
    search2(k+1, curr+str[k]);
    search2(k+1, curr);
  }
}

int main() {
  n=3; // test n
  search();
  str="abcde"; // test string
  search2();
}
