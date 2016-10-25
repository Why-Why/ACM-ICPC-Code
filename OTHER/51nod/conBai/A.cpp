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
// Created Time  : 2016年05月20日 星期五 18时18分43秒
// File Name     : A.cpp

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

int a,b,d,n;
int rem[10];
long long rrr[100000];
long long ans;

long long getnum(int r,int n) {
	int ret=0;
	for(int i=1;i<=n;++i) {
		if((a*b+r)%10==d) ++ret;
		r=(a*b+r)/10;
	}
	if(r==d && r) ++ret;
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int r;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d %d",&a,&b,&d,&n);
		ans=0;
		memset(rem,0,sizeof(rem));
		r=0;

		int len,sta;
		long long ddd;
		rrr[0]=0;

		for(int i=1;;++i) {
			if(rem[r]) {
				len=i-rem[r];
				sta=rem[r];
				ddd=rrr[i-1]-rrr[sta-1];
				break;
			}
			rem[r]=i;
			if((a*b+r)%10==d) ++ans;
			rrr[i]=ans;
			r=(a*b+r)/10;
		}

		if(n<sta) printf("%lld\n",getnum(0,n));				// !!!
		else {
			ans=rrr[sta-1];
			n-=sta-1;
			int ttt=n/len;
			ans+=ttt*ddd;
			ans+=getnum(r,n%len);
			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
