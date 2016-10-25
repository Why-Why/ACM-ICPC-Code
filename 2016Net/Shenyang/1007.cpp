// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2016年09月18日 星期日 13时07分40秒
// File Name     : 1007.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
long long dp[30][1][1][1];

inline long long getans(long long x) {
	char s[30];
	sprintf(s,"%lld",x);

	int len=strlen(s);

	memset(dp,0,sizeof(dp));
	for(int i=0;i<s[0]-'0';++i)
		++dp[0][1][i%2][1];
	++dp[0][0][(s[0]-'0')%2][1];

	for(int i=0;i<len-1;++i) {
		for(int j=0;j<s[i+1]-'0';++j) {
			if(j%2) {
				dp[i+1][1][1][1]+=dp[i][0][0][1]+dp[i][1][0][1];
				dp[i+1][1]
			}
			else {
			}
		}
	}
}

long long dp[20][20];
int num[20];

long long dfs(int dep,int pre,bool e,bool first) {
	cerr<<dep<<' '<<pre<<' '<<e<<endl;
	if(dep==-1) return 1;	/////

	if(!e && dp[dep][pre]!=-1)
		return dp[dep][pre];

	long long ret=0;
	int u=e ? num[dep] : 9;

	for(int i=0;i<=u;++i) {
		if(i%2==0) {
			if(pre==1) ret+=dfs(dep-1,0,i==u && e);
			if(pre==2 || pre==0) ret+=dfs(dep-1,1,i==u && e);
		}
		else {
			if(pre==3) ret+=dfs(dep-1,2,i==u && e);
			if(pre==1 || pre==2) ret+=dfs(dep-1,3,i==u && e);
		}
	}

	if(!e) dp[dep][pre]=ret;

	return ret;
}

long long getans(long long x) {
	memset(dp,-1,sizeof(dp));
	if(x==0) return 1;

	int dep=0;
	while(x) {
		num[dep++]=x%10;
		x/=10;
	}

	for(int i=dep-1;i>=0;--i) cout<<num[i];
	cout<<endl;

	long long ret=dfs(dep-1,0,1);//+dfs(dep-1,1,0)+dfs(dep-1,2,0)+dfs(dep-1,3,0);
	cout<<ret<<endl;
	return ret;
}
*/

long long dp[25][10],dp2[25][10];

long long getnum() {
	dp[1][1]=dp[1][3]=5;
	dp2[1][1]=dp2[1][3]=5;
	dp2[1][1]=4;

	for(int i=2;i<20;++i) {
		for(int j=0;j<10;++j)
			if(j&1) {
				dp[i][2]+=dp[i-1][3];
				dp[i][3]+=dp[i-1][1]+dp[i-1][2];
			}
			else {
				dp[i][0]+=dp[i-1][1];
				dp[i][1]+=dp[i-1][2]+dp[i-1][0];
			}

		for(int j=1;j<10;++j)
			if(j&1) {
				dp2[i][2]+=dp[i-1][3];
				dp2[i][3]+=dp[i-1][1]+dp[i-1][2];
			}
			else {
				dp2[i][0]+=dp[i-1][1];
				dp2[i][1]+=dp[i-1][2]+dp[i-1][0];
			}
	}
}

int num[30];

long long dfs(int dep,int sta) {
	if(dep<0) {
		if(sta==2 || sta==1) return 1;
		else return 0;
	}

	long long ret=0,ok=1,t;

	if(num[dep]&1) {
		if(sta==0) ok=0;
		if(sta==1) t=3;
		if(sta==2) t=3;
		if(sta==3) t=2;
	}
	else {
		if(sta==3) ok=0;
		if(sta==0) t=1;
		if(sta==1) t=0;
		if(sta==2) t=1;
	}

	if(ok) ret+=dfs(dep-1,t);

	for(int i=0;i<num[dep];++i) {
		if(i&1) {
			if(sta==0) continue;
			if(sta==1) t=3;
			if(sta==2) t=3;
			if(sta==3) t=2;

			if(dep) {
				if(t==0) ret+=dp[dep][1];
				if(t==1) ret+=dp[dep][2]+dp[dep][0];
				if(t==2) ret+=dp[dep][1]+dp[dep][2];
				if(t==3) ret+=dp[dep][3];
			}
			else {
				if(t==1 || t==2) ret+=1;
			}
		}
		else {
			if(sta==3) continue;
			if(sta==0) t=1;
			if(sta==1) t=0;
			if(sta==2) t=1;
			
			if(dep) {
				if(t==0) ret+=dp[dep][1];
				if(t==1) ret+=dp[dep][2]+dp[dep][0];
				if(t==2) ret+=dp[dep][1]+dp[dep][2];
				if(t==3) ret+=dp[dep][3];
			}
			else {
				if(t==1 || t==2) ret+=1;
			}
		}
	}

	return ret;
}

long long getans(long long x) {
	if(x==0) return 0;

	if(x<10) {
		int ret=0;
		for(int i=1;i<=x;++i)
			if(i&1);
			else ++ret;
		return ret;
	}

	int dep=0;
	while(x) {
		num[dep++]=x%10;
		x/=10;
	}

	long long ret=0;

	for(int i=1;i<num[dep-1];++i)
		if(i&1) ret+=dp[dep-1][3];
		else ret+=dp[dep-1][0]+dp[dep-1][2];

	for(int i=1;i<dep;++i) ret+=dp2[i][1]+dp2[i][2];

	int t=0;
	if(num[dep-1]&1) t=3;
	else t=1;

	ret+=dfs(dep-2,t);

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	getnum();

	int T,cas=1;
	long long L,R;
	scanf("%d",&T);

	while(T--) {
		scanf("%I64d %I64d",&L,&R);
		--L;

		//cout<<getans(R)-getans(L)<<endl;
		printf("Case #%d: %I64d\n",cas++,getans(R)-getans(L));
	}

	return 0;
}
