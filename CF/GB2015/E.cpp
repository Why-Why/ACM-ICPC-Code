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
// Created Time  : 2015年12月31日 星期四 00时42分08秒
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

const int MaxN=200005;

int N;

int num[10];
int t[MaxN];

int biao[10],sum[10];
int p[10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	scanf("%d %d %d",num+1,num+2,num+3);
	for(int i=1;i<=N;++i) scanf("%d",t+i);
	sort(t+1,t+N+1);
	sort(num+1,num+4);
	sum[1]=num[1];
	sum[2]=num[2];
	sum[3]=num[3];
	sum[4]=num[1]+num[2];
	sum[5]=num[1]+num[3];
	sum[6]=num[2]+num[3];

	if(num[1]+num[2]+num[3]<t[N]) {
		puts("-1");
		return 0;
	}

	for(int i=1;i<=6;++i) p[i]=biao[i]=upper_bound(t+1,t+N+1,sum[i])-t-1;

	int ans=0;
	ans+=N-biao[6];

	ans+=biao[6]-biao[5];
	p[1]-=(biao[6]-biao[5]);
	p[1]=max(p[1],0);

	ans+=biao[5]-biao[4];
	p[2]-=(biao[5]-biao[4]);
	if(p[2]<biao[1]) {
		p[1]-=(biao[1]-p[2]);
		p[2]=biao[1];
	}
	p[1]=max(p[1],0);

	if(num[1]+num[2]<num[3]) {
		int tans=0;

		tans+=biao[3]-biao[2];
		p[2]-=(biao[3]-biao[2]);
		p[1]-=(biao[3]-biao[2]);
		if(p[2]<biao[1]) {
			p[1]-=(biao[1]-p[2]);
			p[2]=biao[1];
		}
		p[1]=max(p[1],0);

		if(p[2]==biao[1]) {
			tans+=(p[1]+2)/3;
		}
		else {
			tans+=(p[2]-biao[1]+1)/2;
			p[1]-=(p[2]-biao[1]+1)/2;
			if((p[2]-biao[1])%2==1) {
				--p[1];
			}
			if(p[1]>0) tans+=(p[1]+2)/3;
		}

		int dans=0;

		dans+=biao[3]-biao[4];
		p[4]-=biao[3]-biao[4];

		if(p[4]<biao[2]) {
			p[2]-=biao[2]-p[4];
			p[1]-=biao[2]-p[4];
			p[4]=biao[2];

			if(p[2]<biao[1]) {
				p[1]-=biao[1]-p[2];
				p[2]=biao[1];
			}
			p[1]=max(p[1],0);
		}

		dans+=p[4]-biao[2];
		p[2]-=p[4]-biao[2];
		p[1]-=p[4]-biao[2];
		if(p[2]<biao[1]) {
			p[1]-=biao[1]-p[2];
			p[2]=biao[1];
		}
		p[1]=max(p[1],0);

		if(p[2]==biao[1]) {
			dans+=(p[1]+2)/3;
		}
		else {
			dans+=(p[2]-biao[1]+1)/2;
			p[1]-=(p[2]-biao[1]+1)/2;
			if((p[2]-biao[1])%2==1) {
				--p[1];
			}
			if(p[1]>0) dans+=(p[1]+2)/3;
		}

		ans+=max(tans,dans);
	}
	else {
		ans+=biao[4]-biao[3];
		p[3]-=(biao[4]-biao[3]);
		if(p[3]<biao[2]) {
			p[2]-=(biao[2]-p[3]);
			p[3]=biao[2];
			if(p[2]<biao[1]) {
				p[1]-=(biao[1]-p[2]);
				p[2]=biao[1];
			}
		}
    
		p[1]=max(p[1],0);
    
		ans+=p[3]-biao[2];
		p[2]-=(p[3]-biao[2]);
		p[1]-=(p[3]-biao[2]);
		if(p[2]<biao[1]) {
			p[1]-=(biao[1]-p[2]);
			p[2]=biao[1];
		}
    
		p[1]=max(p[1],0);
    
		if(p[2]==biao[1]) {
			ans+=(p[1]+2)/3;
		}
		else {
			ans+=(p[2]-biao[1]+1)/2;
			p[1]-=(p[2]-biao[1]+1)/2;
			if((p[2]-biao[1])%2==1) {
				--p[1];
			}
			if(p[1]>0) ans+=(p[1]+2)/3;
		}
	}

	printf("%d\n",ans);

	return 0;
}
