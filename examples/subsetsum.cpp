/*
  Meet in the middle technique to check if it is possible to create sum of x by choosing numbers in arr.

  - divide arr in half into A and B
  - generate all subset of A and B and store subset sums into S_a and S_b -> sort
  - check if it is possible to choose one element from S_a and S_b st sum=x
  - reduces complexity from O(2^n) to O(2^(n/2))=O(sqrt(2^n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4;
const int arr[N] = {2,4,5,9};
const int x = 10; // 15 for True

vector<int> generate_subset(int l, int r) {
  int n = r-l+1; // length of subarray
  vector<int> sums;

  for (int b=0;b<(1<<n);b++) {
    int sum=0;
    for (int i=0;i<n;i++) {
      if (b&(1<<i)) sum+=arr[l+i];
    }
    sums.push_back(sum);
  }
  return sums;
}

int main() {
  vector<int> sa = generate_subset(0,N/2-1);
  vector<int> sb = generate_subset(N/2,N-1);
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());
  
  // check if we can make sum from s_a and s_b
  // could also use binary search here for sb to find x-i
  for (int i:sa) {
    auto it = find(sb.begin(), sb.end(), x-i);
    if (it!=sb.end()) {
      cout << "True";
      return 0;
    }
  }
  cout << "False";
}
