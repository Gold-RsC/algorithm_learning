#include<bits/stdc++.h>
using namespace std;

int dp[100010];
int ans;
int last;
int main(){
	string s;
	cin>>s;
	dp[0]=1;
	ans=1;
	for(int i=1;i<s.size();++i){
		if(s[i]==s[i-1]||s[i]==s[i-1]+1){
			dp[i]=dp[i-1]+1;
		}
		else{
			dp[i]=dp[i-1]-dp[last]+2;
			last=i;
		}
		ans+=dp[i];
	}
	cout<<ans<<endl;
	return 0;
}
