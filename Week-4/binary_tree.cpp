#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//Linked list
struct Node {
    int value;
    Node* prev;
    Node* next;
};
//creating a binary tree
Node* CreateNode(int value){
    Node* newNode= new Node;
    newNode->prev=nullptr;
    newNode->next=nullptr;
    return newNode;
}

//construct a binary tree
Node* binary(const vector<vector<int>> &partition, unordered_map<int, Node*>& nodeMap, int idx){
    if(idx>=partition.size()) {
        return nullptr;
    }
    
    int baseval=partition[idx][0];
    Node* baseNode= CreateNode(baseval);
    nodeMap[baseval]=baseNode;

  if(partition[idx].size()==2){
    int leftChildval=partition[idx][1];
    Node* leftNode= CreateNode(leftChildval);
    nodeMap[leftChildval]=leftNode;
    baseNode->prev=leftNode;
  }

    if(partition[idx].size()==3){
    int leftChildval=partition[idx][1];
    int rightChildval=partition[idx][2];
    Node* leftNode= CreateNode(leftChildval);
    Node* rightNode= CreateNode(rightChildval);
    nodeMap[leftChildval]=leftNode;
    nodeMap[rightChildval]=rightNode;
    baseNode->prev=leftNode;
    baseNode->next=rightNode;
  }

    binary(partition, nodeMap, idx+1);
    return baseNode;
}

void printBinary(Node* baseNode){
  if(baseNode== nullptr){
    return;
  }

  cout<<baseNode->value;
  if(baseNode->prev!=nullptr){
    printBinary(baseNode->prev);
  }
  if(baseNode->next!=nullptr){
    cout<<" ";
    printBinary(baseNode->next);
    cout<<endl;
  }
}
void deleteBinary(Node* base){
  if(base==nullptr)return;
  deleteBinary(base->prev);
  deleteBinary(base->next);
  delete base;

}
int main(){
  int n; cin>>n;
  vector<vector<int>> partition(n);
  for(int i=0; i<n; i++){
    int k; cin>>k;
    partition[i].resize(k);
    for(int j=0; j<k; j++){
      cin>>partition[i][j];
    }
  }

  unordered_map<int, Node*> nodeMap;
  Node* baseNode= binary(partition, nodeMap, 0);
  printBinary(baseNode);
  cout<<endl;
}