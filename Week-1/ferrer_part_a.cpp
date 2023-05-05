#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int a;
    while(cin>>a){
        v.push_back(a);
    }

    int n= v.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i]; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}