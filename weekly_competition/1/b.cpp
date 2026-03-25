#include<bits/stdc++.h>
using namespace std;
int n;
uint64_t S;
vector<pair<uint64_t,int>> v;
vector<pair<uint64_t,int>>gold_num;
int main(){
	cin>>n>>S;
	for(int i=0;i<n;++i){
		int p,c;
		cin>>p>>c;
		v.emplace_back(make_pair(p,c));
	}
	sort(v.begin(),v.end(),[](const pair<uint64_t,int>&a,const pair<uint64_t,int>&b){
		if(a.second!=b.second){
			return a.second>b.second;
		}
		return a.first>b.first;
	});
	for(auto&x:v){
		if(gold_num.empty()){
			gold_num.emplace_back(x);
		}
		else{
			if(gold_num.back().second==x.second){
				gold_num.back().first+=x.first;
			}
			else{
				gold_num.emplace_back(make_pair(gold_num.back().first+x.first,x.second));
			}
		}
	}
	uint64_t ans=0;
	for(int day=gold_num[0].second,i=0;day>0;--day){
		if(i+1<gold_num.size()&&day==gold_num[i+1].second){
			++i;
		}
		ans+=min(S,gold_num[i].first);
	}
	cout<<ans<<endl;
	return 0;
}
