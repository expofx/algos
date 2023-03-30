/*
  Generic binary search algorithm for finding element in array.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n,t; // num elements, target
  cin >> n >> t;

  vector<int> arr(n);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  
  // binary search
  int lo=0,hi=n-1;
  while (lo<=hi) {
    int mid = lo+(hi-lo)/2;
    if (arr[mid] == t) {
      cout << mid; // return index
      break;
    }
    if (arr[mid] < t) {
      lo = mid+1; // search upper half
    }
    else {
      hi = mid-1; // search lower half
    }
  }
}
