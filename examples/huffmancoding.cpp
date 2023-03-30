/*
  Greedy algorithm for Huffman coding (finding the most optimal binary encoding of each letter to minimize length of total string)

  - Get count of each character
  - Use priority queue to keep combining 2 nodes with smallest weights and replace with sum of weights
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Node {
  char data;
  int freq;
  Node *left, *right;

  Node(char data, int freq) { // constructor
    left = right = NULL;
    this->data = data;
    this->freq = freq;
  }
};

struct cmp {
  bool operator()(Node *l, Node *r) { // cmp()
    return (l->freq > r->freq); // greater vals at the end
  }
};

void print(Node* node, string s="") {
  if (!(node->left) && !(node->right)) { // leaf node
    cout << node->data << ": " << s << "\n";
    return;
  }
  print(node->left, s+"0");
  print(node->right, s+"1");
}

int main() {
  string text = "AABACDACA";

  // get counts
  map<char,int> freq;
  for (char c:text) {
    if (freq.count(c)>0) freq[c]++;
    else freq[c]=1;
  }
  //print
  // for (const auto& elem : freq) cout << elem.first << " " << elem.second << "\n";

  // add to min heap
  priority_queue<Node*, vector<Node*>, cmp> q; 
  for (auto& f:freq) {
    q.push(new Node(f.first, f.second));
  }

  // pop two lowest elements and combine
  Node *left, *right, *top;
  while (q.size()!=1) {
    left = q.top(); q.pop();
    right = q.top(); q.pop();
    
    top = new Node(left->data+right->data, left->freq+right->freq);
    top->left = left;
    top->right = right;

    q.push(top);
  }

  // print codes
  print(q.top());
}
