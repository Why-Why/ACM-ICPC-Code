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
// Created Time  : 2016年12月04日 星期日 00时57分36秒
// File Name     : 2_D.cpp

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
	int P,C;
	int id;

	bool operator < (const State & b) const {
		if(C!=b.C) return C<b.C;
		return P<b.P;
	}
};

int N;
State rem[333],remW[333],need[333];
int rcou,wcou,ncou;

int ans[333];

void solve(int L,int R) {
	int C=rem[L].C;
	int znum=0;
	int last,start=R+1;

	for(int i=L;i<=R+1;++i) {
		if(i<=R && rem[i].P==0) {
			++znum;
		}
		else {
			start=i;
			break;
		}
	}

	last=L;
	for(int i=L,j=1;i<start;++i,++j) {
		ans[rem[i].id]=rem[i-1].id;
		if(j%C==0) {
			ans[rem[last].id]=rem[i].id;
			last=i+1;
		}
	}

	int x;
	if(znum<=C) x=C-znum;
	else x=(C-znum%C)%C;

	while(x--) {
		++ncou;
		need[ncou].P=0;
		need[ncou].C=C;
	}

	int p=L;

	for(int i=1;i<=rem[R].P;++i) {
		while(p<=R && rem[p].P<i) ++p;
		if(p>R || rem[p].P>i) {
			++ncou;
			need[ncou].P=i;
			need[ncou].C=C;
		}
	}

	last=rem[L].id;
	for(int i=start;i<=R;++i) {
		if(i==start || rem[i].P==rem[i-1].P)
			ans[rem[i].id]=last;
		else {
			last=rem[i-1].id;
			ans[rem[i].id]=last;
		}
	}
}

void solve() {
	rem[rcou+1].C=-1;
	int last=1;

	for(int i=2;i<=rcou+1;++i)
		if(rem[i].C!=rem[i-1].C) {
			solve(last,i-1);
			last=i;
		}
}

////////////////////////////////

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
	vN=wcou;

	for(int i=1;i<=vN;++i) {
		linker[i]=-1;
		for(int j=1;j<=uN;++j) line[j][i]=0;
	}

	for(int i=1;i<=uN;++i)
		for(int j=1;j<=vN;++j)
			if((remW[j].P==-1 || remW[j].P==need[i].P) && (remW[j].C==-1 || remW[j].C==need[i].C))
				line[i][j]=1;

	if(Hungary()<uN) return 0;

	for(int i=1;i<=vN;++i)
		if(linker[i]!=-1) {
			rem[++rcou]=need[linker[i]];
			rem[rcou].id=remW[i].id;
		}

	return 1;
}

//////////////////////////////////

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s1[1000],s2[1000];

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%s %s",s1,s2);

		if(s1[0]!='?' && s2[0]!='?') {
			++rcou;
			sscanf(s1,"%d",&rem[rcou].P);
			sscanf(s2,"%d",&rem[rcou].C);
			rem[rcou].id=i;
		}
		else {
			++wcou;
			if(s1[0]=='?') remW[wcou].P=-1;
			else sscanf(s1,"%d",&remW[wcou].P);

			if(s2[0]=='?') remW[wcou].C=-1;
			else sscanf(s2,"%d",&remW[wcou].C);

			remW[wcou].id=i;
		}
	}

	sort(rem+1,rem+rcou+1);
	solve();

	if(judge()) {
		sort(rem+1,rem+rcou+1);

		for(int i=1;i<=rcou;++i) cout<<rem[i].P<<' '<<rem[i].C<<' '<<rem[i].id<<endl;

		memset(ans,-1,sizeof(ans));
		solve();

		for(int i=1;i<=N;++i)
			if(ans[i]==-1) printf("%d ",i);
			else printf("%d ",ans[i]);
		puts("");
	}
	else puts("-1");

	return 0;
}
