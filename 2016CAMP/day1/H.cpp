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
// Created Time  : 2017年02月13日 星期一 09时45分13秒
// File Name     : H.cpp

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

struct MAT {
	long long num[4][4];

	MAT operator * (const MAT & b) const {
		MAT ret;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j) {
				long long t=0;
				for(int k=0;k<4;++k)
					t+=num[i][k]*(long long)b.num[k][j];
				t%=mod;
				ret.num[i][j]=t;
			}
		return ret;
	}
};

int N;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(cin>>N) {
		if(N==1) {
			puts("1");
			continue;
		}

		N-=2;
		MAT base;
		memset(base.num,0,sizeof(base.num));
		base.num[0][0]=3;
		base.num[0][1]=mod-2;
		base.num[0][2]=1;
		base.num[0][3]=mod-1;
		base.num[1][0]=1;
		base.num[2][1]=1;
		base.num[3][2]=1;

		MAT ans;
		memset(ans.num,0,sizeof(ans.num));
		for(int i=0;i<4;++i) ans.num[i][i]=1;

		for(;N;N>>=1,base=base*base)
			if(N&1)
				ans=ans*base;

		printf("%d\n",(int)((36LL*ans.num[3][0]%mod+16LL*ans.num[3][1]%mod+6LL*ans.num[3][2]%mod+2LL*ans.num[3][3]%mod)%mod));
	}

	return 0;
}
