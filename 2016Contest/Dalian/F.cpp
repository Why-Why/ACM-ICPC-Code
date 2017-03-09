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
// Created Time  : 2016年11月11日 星期五 22时07分42秒
// File Name     : F.cpp

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

const int mod=1000000007;

int x;

inline bool judge(long long k) {
	if((k*(3+k))/2<=x && ((4+k)*(k+1))/2>x) return 1;
	return 0;
}

long long rem[100000];

long long inv(long long a,long long m) {
	if(a==1) return 1;
	return inv(m%a,m)*(m-m/a)%m;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	rem[1]=1;
	rem[2]=2;
	for(int i=3;i<100000;++i) rem[i]=(rem[i-1]*i)%mod;

	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&x);

		if(x==1) {
			puts("1");
			continue;
		}

		long long k=floor((sqrt(9.0+8.0*x)-3)*0.5);
		if(judge(k)==0) {
			for(int i=k-10;i<k+10;++i)
				if(judge(i)) {
					k=i;
					break;
				}
		}

		long long t=x-(3+k)*k/2;
		long long ans=1;

		if(t==k+1) {
			//for(int i=3;i<=k+1;++i) (ans*=i)%=mod;

			ans=rem[k+1]*inv(2,mod)%mod;			// !!!
			(ans*=(k+3))%=mod;
		}
		else {
			t=k+2-t;
			//for(int i=2;i<t;++i) (ans*=i)%=mod;
			ans*=rem[t-1];
			//for(int i=t+1;i<=k+2;++i) (ans*=i)%=mod;
			if(k+2>=t+1) (ans*=rem[k+2]*inv(rem[t],mod)%mod)%=mod;
		}

		printf("%I64d\n",ans);
	}

	return 0;
}
