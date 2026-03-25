#include<bits/stdc++.h>
using namespace std;
bool check(unsigned long long n){
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int count=1;
	for(unsigned long long i=3;;i+=2){
		if(check(i)){
			count++;
		}
		if(count==2025){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
