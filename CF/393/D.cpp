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
// Created Time  : 2017年02月06日 星期一 16时36分29秒
// File Name     : D.cpp

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

const int MaxN=5005;
const int mod=1000000007;

long long dp[MaxN][27];
char s[MaxN];
int N;
int jin[30];

inline int add(int a,int b) {
	a+=b;
	if(a>=mod) a-=mod;
	return a;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	scanf("%s",s+1);
	dp[0][26]=1;
	memset(jin,-1,sizeof(jin));

	for(int i=1;i<=N;++i) {

		for(int k=0;k<26;++k) {
			if(jin[k]==i) {
				for(int j=i;j>=1;--j) {
					dp[i][k]=add(dp[i][k],add(dp[j-1][26],mod-dp[j-1][k]));
					if(i==3) cout<<dp[i][k]<<endl;
				}
			}
			else if(jin[k]!=-1) {
				dp[i][k]=add(dp[i][k],(i-jin[k])*(dp[jin[k]][26]+mod-dp[jin[k]][k])%mod);
				dp[i][k]=add(dp[i][k],dp[jin[k]][k]);
			}

			dp[i][26]=add(dp[i][26],dp[i][k]);

			cout<<dp[i][k]<<' ';
		}
		cout<<endl;
		jin[s[i]-'a']=max(jin[s[i]-'a'],i);
	}

	printf("%d\n",(int)dp[N][26]);

	return 0;
}
