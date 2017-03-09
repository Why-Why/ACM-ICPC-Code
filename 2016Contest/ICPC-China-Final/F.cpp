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
// Created Time  : 2017年02月08日 星期三 01时03分48秒
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

const int MaxN=400000;

int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];
int sa[MaxN];

bool cmp(int r[],int a,int b,int l) {
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(char *s,int n,int m) {
	int i,j,p,*x=wa,*y=wb;

	for(i=0;i<m;++i) ts[i]=0;
	for(i=0;i<n;++i) ++ts[x[i]=s[i]];
	for(i=1;i<m;++i) ts[i]+=ts[i-1];
	for(i=n-1;i>=0;--i) sa[--ts[x[i]]]=i;

	for(j=1,p=1;p<n;j<<=1,m=p) {
		for(p=0,i=n-j;i<n;++i) y[p++]=i;
		for(i=0;i<n;++i) if(sa[i]>=j) y[p++]=sa[i]-j;

		for(i=0;i<n;++i) wv[i]=x[y[i]];
		for(i=0;i<m;++i) ts[i]=0;
		for(i=0;i<n;++i) ++ts[wv[i]];
		for(i=1;i<m;++i) ts[i]+=ts[i-1];
		for(i=n-1;i>=0;--i) sa[--ts[wv[i]]]=y[i];

		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;++i)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
	}
}

void getHeight(char s[],int n,int rank[],int height[]) {
	int k=0,i,j;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? k-- : 0 , j=sa[rank[i]-1];s[i+k]==s[j+k];++k);
}

//////////////////////////////

const int INF=0x3f3f3f3f;

int N;
char s[MaxN];

int rank[MaxN],height[MaxN];

int rans[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		int p=0,rem1;

		for(int i=1;i<=N;++i) {
			scanf("%s",s+p);
			p+=strlen(s+p);
			if(i==1) rem1=p;

			s[p++]=i==1 ? '#' : '@';
		}
		s[p]=0;

		DA(s,p+1,128);
		getHeight(s,p,rank,height);

		int last=INF;
		int ans=INF,rem=-1;

		rans[p]=1;
		for(int i=p-1;i>=1;--i)
			if(sa[i]>=rem1) last=INF;
			else {
				last=min(last,height[i+1]);
				rans[i]=last;
			}

		for(int i=1;i<=p;++i)
			if(sa[i]>=rem1) last=INF;
			else {
				last=min(last,height[i]);
				if(rem1-sa[i]>max(rans[i],last))
					if(ans>max(rans[i],last)) {
						ans=max(rans[i],last);
						rem=i;
					}
			}

		++ans;
		printf("Case #%d: ",cas++);
		if(rem==-1) puts("Impossible");
		else {
			s[sa[rem]+ans]=0;
			puts(s+sa[rem]);
		}
	}

	return 0;
}
