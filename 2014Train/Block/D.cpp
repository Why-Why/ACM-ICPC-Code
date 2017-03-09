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
// Created Time  : 2016年03月23日 星期三 23时04分23秒
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

int N,M;
int brem[1000],blen,bcou;
int num[MaxN];

inline int query(int L,int R) {
	int ret=0;
	for(int i=L;i<=R;++i) ret=max(ret,num[i]);
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];
	int a,b;

	while(~scanf("%d %d",&N,&M)) {
		blen=sqrt((double)N);			// !!!
		bcou=(N+blen-1)/blen;
		memset(brem,0,sizeof(brem));	// !!!

		for(int i=1,j=1,p=1;i<=N;++i) {
			scanf("%d",num+i);
			brem[p]=max(brem[p],num[i]);
			++j;
			if(j>blen) {
				j=1;
				++p;
			}
		}

		int ans,x,y;

		while(M--) {
			scanf("%s %d %d",s,&a,&b);
			if(s[0]=='Q') {
				ans=0;
				x=(a-1)/blen+1;
				y=(b-1)/blen+1;
				if(x==y) ans=query(a,b);
				else {
					for(int i=x+1;i<y;++i) ans=max(ans,brem[i]);
					ans=max(query(a,x*blen),ans);
					ans=max(query((y-1)*blen+1,b),ans);
				}
				printf("%d\n",ans);
			}
			else {
				x=(a-1)/blen+1;
				num[a]=b;
				brem[x]=0;
				for(int i=(x-1)*blen+1;i<=N && i<=x*blen;++i) brem[x]=max(brem[x],num[i]);
			}
		}
	}
	
	return 0;
}
