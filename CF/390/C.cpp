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
// Created Time  : 2017年01月08日 星期日 13时25分21秒
// File Name     : C.cpp

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

int N,M;
string name[111],text[111];
string ans[111];
char s[20000];
bool dp[111][111];
int sum[111];

inline int getID(string & t) {
	for(int i=1;i<=N;++i)
		if(name[i]==t) return i;
	return -1;
}

inline bool judge(string & a,string & b) {
	int p=0;
	while((p=a.find(b,p))!=string::npos) {
		++p;
		if(p-2>=0 && isalnum(a[p-2])) continue;
		if(p-1+b.size()<a.size() && isalnum(a[p-1+b.size()])) continue;
		return 1;
	}
	return 0;
}

inline bool getans() {
	memset(dp,0,sizeof(dp));

	int t;

	for(int i=1;i<=M;++i) {
		sum[i]=0;
		if(ans[i][0]!='?') {
			t=getID(ans[i]);
			if(dp[i-1][t]==0 || sum[i-1]>1) dp[i][t]=1,sum[i]=1;
		}
		else {
			for(int j=1;j<=N;++j)
				if((dp[i-1][j]==0 || sum[i-1]>1) && judge(text[i],name[j])==0) {
					dp[i][j]=1;
					++sum[i];			// !!!
				}
		}

		if(sum[i]==0) return 0;
	}

	int last=-1;

	for(int i=M;i>=1;--i) {
		for(int j=1;j<=N;++j)
			if(j!=last && dp[i][j]) {
				ans[i]=name[j];
				last=j;
				break;
			}
	}

	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	cin>>T;

	while(T--) {
		cin>>N;
		for(int i=1;i<=N;++i) cin>>name[i];
		cin>>M;
		cin.getline(s,2000);
		for(int i=1;i<=M;++i) {
			cin.getline(s,2000);
			for(int j=0;s[j];++j)
				if(s[j]==':') {
					s[j]=0;
					ans[i]=s;
					text[i]=s+j+1;
					break;
				}
		}

		if(getans()) for(int i=1;i<=M;++i) cout<<ans[i]<<":"<<text[i]<<endl;
		else cout<<"Impossible\n";
	}

	return 0;
}
