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
// Created Time  : 2016年06月11日 星期六 19时04分40秒
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

int N,Q;
int blen;

int val[MaxN],head1[MaxN],head2[MaxN],next1[MaxN],next2[MaxN],cou;

inline void addN(int u) {
	int m,a;
	scanf("%d",&m);

	if(m==0) {
		head1[u]=head2[u]=-1;
		return;
	}

	head1[u]=cou;
	if(m<blen) head2[u]=-1;
	else head2[u]=cou+blen-1;

	for(int i=1;i<=m;++i) {
		scanf("%d",val+cou);
		next1[cou]=cou+1;
		if(i%blen==0) {
			if(i+blen>m) next2[cou]=-1;
			else next2[cou]=cou+blen;
		}
		else next2[cou]=-2;
		++cou;
	}
	next1[cou-1]=-1;
}

void show(int u) {
	cout<<head2[u]<<endl;
	for(int i=head1[u];i!=-1;i=next1[i])
		cout<<i<<' '<<val[i]<<' '<<next2[i]<<endl;
	cout<<endl;
}

inline void change(int a,int b,int c,int d) {
	int *x=find(a,b),*y=find(c,d);
	int t1=*x,t2=*y;

	*x=t2;
	*y=t1;

	swap(head1[a],head1[c]);
	swap(head2[a],head2[c]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	blen=200;
	if(!blen) blen=1;

	for(int i=1;i<=N;++i) addN(i);

	scanf("%d",&Q);
	while(Q--) {
		scanf("%d %d %d %d",&a,&b,&c,&d);
		change(a,b,c,d);
		printf("%d\n",getans());
	}
	
	return 0;
}
