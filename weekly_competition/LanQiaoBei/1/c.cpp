#include<bits/stdc++.h>
using namespace std;
// 1:red 0:black 

bool w(int n,uint64_t k){
	if(n==1){
		return true;
	}
	if(w(n-1,(k+1)/2)){
		return k&1;
	}
	return !(k&1);
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int m;
		uint64_t k;
		cin>>m>>k;
		std::cout<<(w(m,k)?"RED\n":"BLACK\n");
	}
	return 0;
}
