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
// Created Time  : 2016年10月27日 星期四 23时24分57秒
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

const int MaxN=200005;

int N;
long long R,L[MaxN],T[MaxN];

long long ans,rem[MaxN];

void getans() {
	long long time=0,last=0,need,t,tt;

	for(int i=1;i<=N;++i) {
		if(T[i]<L[i]) {
			ans=-1;
			return;
		}

		if(last>=L[i]) {
			last-=L[i];
			time+=L[i];

			continue;
		}

		need=max(0LL,2*L[i]-T[i]);
		need-=last;

		if(need>0) {
			t=(need+R-1)/R;

			if(ans+t<=100000) {
				tt=time+T[i]-need;
				for(int i=1;i<=t;++i,tt+=R) rem[++ans]=tt;
			}
			else ans+=t;

			last=t*R-need;

			time+=T[i];
		}
		else {
			time+=last+(L[i]-last)*2;
			last=0;
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	cin>>N>>R;
	for(int i=1;i<=N;++i) cin>>L[i];
	for(int i=1;i<=N;++i) cin>>T[i];

	getans();

	cout<<ans<<endl;
	if(ans==-1) return 0;
	if(ans<=100000) for(int i=1;i<=ans;++i) cout<<rem[i]<<' ';
	cout<<endl;

	return 0;
}
