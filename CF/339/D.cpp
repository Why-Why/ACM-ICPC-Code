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
// Created Time  : 2016年01月22日 星期五 23时18分25秒
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

const int MaxN=100005;

typedef pair <long long,int> pii;

int N;
long long A,cf,cm,M;
long long sum[MaxN],fsum[MaxN];
pii a[MaxN];

inline long long zhuan(long long a) {
	a=N+1-a;
	return a;
}

long long getnum(int id,long long &cou) {
	cout<<"#####\n";
	cout<<id<<endl;
	long long have=M-a[id].first*(id-1)+sum[id-1];
	if(have<0) return 0;

	if(a[id].first==A) {
		cou=N;
		return N*cf+cm*A;
	}

	long long tsum=A*(N-id)-sum[N]+sum[id];
	cout<<have<<endl;
	cout<<tsum<<endl;
	if(tsum<=have) cou=N-id+min((long long)id,(have-tsum)/(A-a[id].first));
	else cou=zhuan(upper_bound(fsum+1,fsum+zhuan(id),have)-fsum);
	cout<<cou<<endl;

	return cf*cou+cm*a[id].first;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);
	cin>>N>>A>>cf>>cm>>M;
	for(int i=1;i<=N;++i) cin>>a[i].first,a[i].second=i,fsum[N+1-i]=a[i].first;
	sort(a+1,a+N+1);
	sum[0]=fsum[0]=0;
	for(int i=1;i<=N;++i) sum[i]=sum[i-1]+a[i].first,fsum[i]+=fsum[i-1];

	long long ans=0,rem=-1,t,tcou,rcou;
	for(int i=1;i<=N;++i) {
		t=getnum(i,tcou);
		if(t>ans) ans=t,rem=i,rcou=tcou;
	}
	cout<<ans<<endl;
	//show(rem);

	return 0;
}
