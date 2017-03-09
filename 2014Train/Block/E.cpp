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
// Created Time  : 2016年03月23日 星期三 23时21分26秒
// File Name     : E.cpp

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

int N,M;
int bcou,blen;
long long brem[MaxN],num[MaxN];
long long bflag[MaxN];

inline void update(int L,int R,int c) {
	for(int i=L;i<=R;++i) num[i]+=c;
}

inline long long query(int L,int R) {
	long long ret=0;
	for(int i=L;i<=R;++i) ret+=num[i];
	return ret;
}

inline void check(int p) {
	if(bflag[p]==0) return;
	for(int i=(p-1)*blen+1;i<=p*blen;++i)
		num[i]+=bflag[p];
	bflag[p]=0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];
	int x,y;
	int a,b,c;

	while(~scanf("%d %d",&N,&M)) {
		blen=sqrt((double)N);
		bcou=(N+blen-1)/blen;
		memset(brem,0,sizeof(brem));
		memset(bflag,0,sizeof(bflag));

		for(int i=1,j=1,p=1;i<=N;++i) {
			scanf("%I64d",num+i);
			brem[p]+=num[i];
			if((++j)>blen) ++p,j=1;
		}

		long long ans;

		while(M--) {
			scanf("%s",s);
			if(s[0]=='Q') {
				ans=0;
				scanf("%d %d",&a,&b);
				x=(a-1)/blen+1;
				y=(b-1)/blen+1;
				if(x==y) { check(x); ans+=query(a,b); }
				else {
					check(x);
					check(y);
					ans+=query(a,x*blen);
					ans+=query((y-1)*blen+1,b);
					for(int i=x+1;i<y;++i) ans+=brem[i];
				}
				printf("%I64d\n",ans);
			}
			else {
				scanf("%d %d %d",&a,&b,&c);
				x=(a-1)/blen+1;
				y=(b-1)/blen+1;
				if(x==y) { brem[x]+=(b-a+1LL)*(long long)c; update(a,b,c); }
				else {
					brem[x]+=(x*blen-a+1LL)*(long long)c;
					update(a,x*blen,c);
					brem[y]+=(b-((y-1)*blen+1)+1LL)*(long long)c;
					update((y-1)*blen+1,b,c);

					for(int i=x+1;i<y;++i) {
						brem[i]+=blen*(long long)c;
						bflag[i]+=c;
					}
				}
			}
		}
	}
	
	return 0;
}
