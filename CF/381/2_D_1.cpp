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
// Created Time  : 2016年12月04日 星期日 15时00分55秒
// File Name     : 2_D_1.cpp

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

struct State {
	int p,c,id;

	bool operator < (const State & b) const {
		if(c!=b.c) return c<b.c;
		return p<b.p;
	}

}have[333],need[333];

int N;
int ncou,hcou;
int rem[333][333];

int csum[333],cmax[333];
int maxn,rmax;

State use[333];
int ucou;

inline void addNeed(int a,int b) {
	++ncou;
	need[ncou].p=a;
	need[ncou].c=b;
}

inline void solve(int C) {
	int x=(C-rem[0][C]%C)%C;
	if(rem[0][C]==0) x=C;

	while(x--) addNeed(0,C);

	for(int i=1;i<=cmax[C];++i)
		if(rem[i][C]==0)
			addNeed(i,C);

	if(cmax[C]>maxn) {
		maxn=cmax[C];
		rmax=C;
	}
}

/////////////////////////////////////////////

bool vis[333];
int linker[333];
int uN,vN;
int line[333][333];

bool find(int u) {
	for (int v = 1; v <= vN; ++v)
		if (line[u][v] && !vis[v]) {
			vis[v] = 1;
			if (linker[v] == -1 || find(linker[v])) { linker[v] = u; return 1; }
		}

	return 0;
}

int Hungary() {
	int ret = 0;
	for (int u = 1; u <= uN; ++u) {
		memset(vis, 0, sizeof(vis));
		if (find(u)) ++ret;
	}

	return ret;
}

bool judge() {
	uN=ncou;
	vN=hcou;

	for(int i=1;i<=vN;++i) {
		linker[i]=-1;
		for(int j=1;j<=uN;++j) line[j][i]=0;
	}
	memset(vis,0,sizeof(vis));

	for(int i=1;i<=uN;++i)
		for(int j=1;j<=vN;++j)
			if((have[j].p==N+1 || have[j].p==need[i].p) && (have[j].c==N+1 || have[j].c==need[i].c))
				line[i][j]=1;

	if(Hungary()<uN) return 0;

	for(int i=1;i<=vN;++i)
		if(linker[i]!=-1) {
			use[++ucou]=need[linker[i]];
			use[ucou].id=have[i].id;
		}

	return 1;
}

/////////////////////////////////////////////

int ans[333];
int rans[333][333];

int bP[333],bC[333];

inline void getans(int L,int R) {
	int C=use[L].c;

	int last=L;
	int start;

	rans[0][C]=use[L].id;

	for(int i=L,j=1;i<=R && use[i].p==0;++i,++j) {
		ans[use[i].id]=use[i-1].id;
		if(j%C==0) {
			ans[use[last].id]=use[i].id;
			last=i+1;
		}

		start=i;
	}

	++start;

	last=use[L].id;
	for(int i=start;i<=R;++i)
		if(i==start || use[i].p==use[i-1].p) {
			ans[use[i].id]=last;

			rans[use[i].p][C]=last;
		}
		else {
			last=use[i-1].id;
			ans[use[i].id]=last;

			rans[use[i].p][C]=last;
		}

	last=use[R].id;
	rans[use[R].p+1][C]=last;

}

inline void getans() {
	memset(ans,-1,sizeof(ans));
	memset(rans,0,sizeof(rans));

	sort(use+1,use+ucou+1);
	use[ucou+1].c=-1;

	int last=1;
	for(int i=2;i<=ucou+1;++i)
		if(use[i].c!=use[i-1].c) {
			getans(last,i-1);
			last=i;
		}

	for(int i=1;i<=N;++i) {
		if(ans[i]==-1) {
			//cerr<<"% "<<i<<endl;

			if(bP[i]==N+1 && bC[i]==N+1) ans[i]=i;
			else if(bP[i]!=N+1) {
				if(bP[i]) ans[i]=rans[bP[i]][rmax];
				else ans[i]=i;
			}
			else ans[i]=rans[1][bC[i]];
		}

		printf("%d ",ans[i]);
	}
	puts("");
}

State tuse[333];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s1[100],s2[100];
	int a,b;

	int tttsum=0;

	memset(cmax,-1,sizeof(cmax));

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%s %s",s1,s2);

		if(s1[0]=='?') a=N+1;
		else sscanf(s1,"%d",&a);

		if(s2[0]=='?') b=N+1;
		else sscanf(s2,"%d",&b);

		bP[i]=a;
		bC[i]=b;

		if(a==N+1 || b==N+1) {
			++hcou;
			have[hcou].p=a;
			have[hcou].c=b;
			have[hcou].id=i;

			if(a!=N+1 || b!=N+1)
				++tttsum;
		}
		else {
			++ucou;
			use[ucou].p=a;
			use[ucou].c=b;
			use[ucou].id=i;
		}

		++rem[a][b];
		++csum[b];
		
		if(a!=N+1) cmax[b]=max(cmax[b],a);
	}

	maxn=-1;
	for(int i=1;i<=N;++i)
		if(csum[i])
			solve(i);

	/*
	cout<<ncou<<endl;

	if(cmax[N+1]>maxn)
		for(int i=maxn+1;i<=cmax[N+1];++i)
			addNeed(i,rmax);

	for(int i=1;i<=ncou;++i) {
		cout<<need[i].p<<' '<<need[i].c<<endl;
	}
	*/

	int tncou=ncou;
	int tucou=ucou;

	for(int i=1;i<=ucou;++i) tuse[i]=use[i];

	/*
	if(tttsum==0) {
		if(judge()) getans();
		else puts("-1");

		return 0;
	}
	*/

	for(int i=1;i<=N;++i)
		if(i==1 || csum[i]) {
			ncou=tncou;
			ucou=tucou;

			for(int j=1;j<=ucou;++j) use[j]=tuse[j];

			if(i==1 && csum[1]==0) addNeed(0,1);

			rmax=i;
			if(cmax[N+1]>cmax[i])
				for(int j=max(1,cmax[i]+1);j<=cmax[N+1];++j)
					addNeed(j,rmax);

			if(judge()) {
				getans();
				return 0;
			}
		}

	puts("-1");


	return 0;
}
