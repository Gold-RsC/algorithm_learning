#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932
struct C{
	double _min,_max;
};
vector<C>v;
C make_C(int x,int y,int r){
	double _max=0;
	double _min=PI/2;
	double alpha=atan2(y,x);
	double R=sqrt(x*x+y*y);
	if(r>R){
		return C{0,PI/2};
	}
	double theta=asin(r/R);
	_max=max(_max,alpha+theta);
	_min=min(_min,alpha-theta);
	cout<<r<<" "<<R<<" "<<theta<<endl;
	return C{_min,_max};
}
vector<C> ans;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		int x,y,r;
		cin>>x>>y>>r;
		v.emplace_back(make_C(x,y,r));	
	}
	sort(v.begin(),v.end(),[](const C&a,const C&b){
		if(a._max==b._max){
			return a._max>b._max;
		}
		return a._min>b._min;
	});
	for(const auto&x:v){
		if(ans.empty()){
			ans.emplace_back(x);
		}
		else{
			if(ans.back()._max>=x._max&&ans.back()._min<=x._max){
				ans.back()._min=min(ans.back()._min,x._min);
			}
			else{
				ans.emplace_back(x);
			}
		}
	}
	double p=1.0;
	for(const auto&x:ans){
		p-=(x._max-x._min)*2/PI;
	}
	cout<<fixed<<setprecision(3)<<p<<endl;
	return 0;
}
