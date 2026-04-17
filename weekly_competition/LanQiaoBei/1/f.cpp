#include<bits/stdc++.h>
using namespace std;
uint32_t num[100005];
uint32_t _max;
uint32_t pointing_bian[100005];
uint32_t pointed_bian[100005];

void w(__int128 i){
	if(i>=10){
		w(i/10);
	}
	putchar(i%10+'0');
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		uint32_t m;
		cin>>m;
		++num[m];
		_max=max(m,_max);
	}
	__int128 ans=0;
	for(int i=1;i<=_max;++i){
		if(!num[i]){
			continue;
		}
		for(int j=i*2;j<=_max;j+=i){
			if(!num[j]){
				continue;
			}
			pointing_bian[i]+=num[j];
			pointed_bian[j]+=num[i];
		}
		pointing_bian[i]+=num[i]-1;
		pointed_bian[i]+=num[i]-1;
		ans+=pointing_bian[i];
	}
	ans*=ans;
	for(int i=1;i<=_max;++i){
		if(!num[i]){
			continue;
		}
		ans+=(__int128)num[i]*pointing_bian[i];
		ans+=(__int128)num[i]*(num[i]-1);
		ans-=(__int128)num[i]*pointing_bian[i]*pointing_bian[i];
		ans-=(__int128)num[i]*pointed_bian[i]*pointed_bian[i];
		ans-=(__int128)2*num[i]*pointing_bian[i]*pointed_bian[i];
	}
	w(ans);
	
	
	
	return 0;
}
