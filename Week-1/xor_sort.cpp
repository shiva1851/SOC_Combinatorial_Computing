#include<bits/stdc++.h>
using namespace std;

bool non_dec(int *a, int n){
    int count = 0;
    for(int i = 0; i < (n - 1); i++){
        if(a[i] <= a[i + 1]) count++;
    }

    if(count == (n - 1)){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<pair<int, int>> v;
        while(!non_dec(a, n)){
            for(int i = 0; i < (n - 1); i++){
                if(a[i] > a[i + 1]){
                    a[i] ^= a[i + 1];
                    a[i + 1] ^= a[i];
                    a[i] ^= a[i + 1];
                    v.push_back({i + 1, i + 2});
                }
            }
        }

        cout << v.size() << endl;
        for(auto x : v){
            cout << x.first << " " << x.second << endl;
        }
        for(int i=0; i<n; i++){cout<<a[i]<<" ";}
    }    
}