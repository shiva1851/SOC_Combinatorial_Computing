#include<bits/stdc++.h>
using namespace std;
int q(int n, int k){
	if (n==0) return 1;  
	if (k==0) return 0;
	if(k==1) return 1;
	if(n<0) return 0;
	return q(n,k-1)+q(n-k,k);
}

int r(int n, int k){
	if (k==0 && n==0) return 1;
	if (k==0 && n>0) return 0;
	if(k==1) return 1;
	if(n<0 || k<0) return 0;
	return r(n-k,k)+r(n,k-1);
	}


int main(){
	int n,k;
	cin>>n>>k;
	cout<<q(n,k)<<" "<<r(n,k);
}