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
// Created Time  : 2015年12月04日 星期五 09时11分13秒
// File Name     : B_1.cpp

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

int N;

struct BLOCKS {
	int rem[MaxN];
	int num[MaxN],tot[MaxN];
	int flag[1003],len[1003];
	int blen,bcou;

	void init() {
		blen=(int)sqrt(N);
		bcou=(blen-1+N)/blen;
		for(int i=0;i<=bcou;++i) flag[i]=-1,len[i]=0;
	}

	int pos(int x) {
		return x/blen;
	}

	void fresh(int id) {
		if(flag[id]!=-1) {
			int R=min(id*blen+blen,N),L=id*blen;
			for(int i=L;i<R;++i) rem[i]=flag[id];
			flag[id]=-1;
		}
	}

	void solve(int id) {
		int L=id*blen;
		int R=min(N,L+blen);

		for(int i=L;i<R;++i) num[i]=rem[i];
		sort(num+L,num+R);
		int k=L,tcou=1;
		for(int i=L+1;i<R;++i)
			if(num[i]!=num[i-1]) {
				num[k]=num[i-1];
				tot[k++]=tcou;
				tcou=1;
			}
			else ++tcou;
		num[k]=num[R-1];
		tot[k++]=tcou;

		len[id]=k-L;
	}

	void update(int L,int R,int C) {
		int p1=pos(L),p2=pos(R);
		
		for(int i=p1+1;i<p2;++i) {
			flag[i]=C;
			num[i*blen]=C;
			tot[i*blen]=blen;
			len[i]=1;
		}

		if(p1==p2) {
			fresh(p1);
			for(int i=L;i<=R;++i) rem[i]=C;
			solve(p1);
		}
		else {
			fresh(p1);
			int lim=p1*blen+blen;
			for(int i=L;i<lim;++i) rem[i]=C;
			solve(p1);

			fresh(p2);
			for(int i=p2*blen;i<=R;++i) rem[i]=C;
			solve(p2);
		}
	}

	int find(int id,int C) {
		int L=id*blen;
		int k=lower_bound(num+L,num+L+len[id],C)-num-L;
		
		if(k>=len[id] || k<0 || num[L+k]!=C) return 0;
		return tot[L+k];
	}

	int query(int L,int R,int C) {
		int p1=pos(L),p2=pos(R);
		int ret=0;

		for(int i=p1+1;i<p2;++i) ret+=find(i,C);

		if(p1==p2) {
			fresh(p1);
			for(int i=L;i<=R;++i) if(rem[i]==C) ++ret;
		}
		else {
			fresh(p1);
			int lim=p1*blen+blen;
			for(int i=L;i<lim;++i) if(rem[i]==C) ++ret;

			fresh(p2);
			for(int i=p2*blen;i<=R;++i) if(rem[i]==C) ++ret;
		}

		return ret;
	}

}block;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b,c,d;

	while(~scanf("%d %d",&N,&M)) {
		block.init();
		for(int i=0;i<N;++i) scanf("%d",&block.rem[i]);
		for(int i=0;i<block.bcou;++i) block.solve(i);

		while(M--) {
			scanf("%d %d %d %d",&a,&b,&c,&d);
			if(a==1) block.update(b,c,d);
			else printf("%d\n",block.query(b,c,d));
		}
	}
	
	return 0;
}
