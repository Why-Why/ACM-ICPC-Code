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
// Created Time  : 2016年09月10日 星期六 15时32分49秒
// File Name     : 1001_1.cpp

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

int minn(int sta,int N) {
	int ret=sta;
	int t;

	for(int i=0;i<N;++i) {
		if(sta&1) t=1;
		else t=0;

		sta>>=1;
		if(t) sta|=(1<<(N-1));

		ret=min(ret,sta);
	}

	return ret;
}

inline bool judge(int sta,int N) {
	for(int i=1;i<N;++i)
		if((sta&(1<<(i-1))) && (sta&(1<<i))) return 0;
	if((sta&(1<<0)) && (sta&(1<<(N-1)))) return 0;

	return 1;
}

long long getans(int N) {
	set <int> rem;

	for(int i=0;i<(1<<N);++i)
		if(judge(i,N)) rem.insert(minn(i,N));

	return rem.size();
}

long long eular(long long n)
{
long long ans = n;
for(int i = 2;i*i <= n;i++)
{
if(n % i == 0)
{
ans -= ans/i;
while(n % i == 0)
n /= i;
}
}
if(n > 1)ans -= ans/n;
return ans;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,N;

	for(int i=2;i<=20;i+=2)
		cout<<i<<' '<<getans(i)<<' '<<eular(i)<<endl;

	return 0;
}
