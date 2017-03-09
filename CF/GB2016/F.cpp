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
// Created Time  : 2017年01月09日 星期一 01时49分59秒
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

int vis[300];
int remC[155],remD[155][5];

void init() {
	memset(vis,0,sizeof(vis));
	memset(remC,0,sizeof(remC));
}

inline void show(char c,int x) {
	printf("%c %d\n",c,x);
	fflush(stdout);
}

inline int ask(int u,int data[]) {
	if(remC[u]) {
		for(int i=1;i<=remC[u];++i) data[i]=remD[u][i];
		return remC[u];
	}

	show('?',u);
	int c;
	scanf("%d",&c);
	remC[u]=c;
	for(int i=1;i<=c;++i) scanf("%d",data+i),remD[u][i]=data[i];
	return c;
}

int bfs(int u) {
	queue <int> que;
	while(!que.empty()) que.pop();
	memset(vis,0,sizeof(vis));

	que.push(u);
	vis[u]=1;

	int data[5],dn;

	while(!que.empty()) {
		u=que.front();
		que.pop();

		dn=ask(u,data);
		if(dn==2) return u;

		for(int i=1;i<=dn;++i)
			if(vis[data[i]]==0) {
				vis[data[i]]=1;
				que.push(data[i]);
			}
	}

	return 1;
}

int runOne(int u,int pre,int dis) {
	if(dis==0) return 0;

	int dn,data[5];
	dn=ask(u,data);

	if(dn==2) return -u;
	if(dn==1) return 1;

	int t;
	if(pre!=data[1]) t=runOne(data[1],u,dis-1);
	else t=runOne(data[2],u,dis-1);

	if(t==0) return 0;
	if(t<0) return t;
	return t+1;
}

inline int getans2(int u,int pre) {
	int dn,data[5];
	int td[5];
	dn=ask(u,data);

	if(data[1]==pre) swap(data[1],data[3]);
	else if(data[2]==pre) swap(data[2],data[3]);

	if(ask(data[1],td)==2) return data[1];
	return data[2];
}

inline int getans4(int u,int pre) {
	int dn,data[5];
	int tn,td[5];
	int rem[4],rcou=0;
	dn=ask(u,data);

	if(data[1]==pre) swap(data[1],data[3]);
	else if(data[2]==pre) swap(data[2],data[3]);

	tn=ask(data[1],td);
	for(int i=1;i<=tn;++i)
		if(td[i]!=u) rem[rcou++]=td[i];

	tn=ask(data[2],td);
	for(int i=1;i<=tn;++i)
		if(td[i]!=u) rem[rcou++]=td[i];

	for(int i=0;i<rcou-1;++i)
		if(ask(rem[i],td)==2) return rem[i];
	return rem[rcou-1];
}

inline int getans8(int u,int pre) {
	int dn,data[5];
	dn=ask(u,data);

	if(data[1]==pre) swap(data[1],data[3]);
	else if(data[2]==pre) swap(data[2],data[3]);

	int t=runOne(data[1],u,3);
	if(t==3) return getans4(data[2],u);			// !!!
	return getans4(data[1],u);
}

inline int getans16(int u,int pre) {
	int dn,data[5];
	dn=ask(u,data);

	if(data[1]==pre) swap(data[1],data[3]);
	else if(data[2]==pre) swap(data[2],data[3]);

	int t=runOne(data[1],u,2);
	if(t==2) return getans8(data[2],u);
	return getans8(data[1],u);
}

int getans() {
	int dn,data[5],u=1;
	int t;
	int tn,tdata[5];
	dn=ask(1,data);

	if(dn==1) {
		u=data[1];
		dn=ask(u,data);
	}
	if(dn==2) return u;

	t=runOne(data[1],u,5);
	if(t<0) return -t;

	int t2=runOne(data[2],u,5);
	if(t2<0) return -t2;

	if(t==1 && t2==1) return getans16(data[3],u);
	if(t==1) return getans16(data[2],u);
	if(t2==1) return getans16(data[1],u);

	if(t==2 && t2==2) return getans8(data[3],u);
	if(t==2) return getans8(data[2],u);
	if(t2==2) return getans8(data[1],u);

	if(t==3 && t2==3) return getans4(data[3],u);
	if(t==3) return getans4(data[2],u);
	if(t2==3) return getans4(data[1],u);

	if(t==4 && t2==4) return getans2(data[3],u);
	if(t==4) return getans2(data[2],u);
	if(t2==4) return getans2(data[1],u);

	return data[3];

	if((t==4 && t2!=2) || (t2==4 && t!=2)) {
		if(t==4 && t2==4) dn=ask(data[3],data);
		else if(t==4) dn=ask(data[2],data);
		else dn=ask(data[1],data);

		for(int i=1;i<=dn;++i)
			if(data[i]!=1) {
				tn=ask(data[i],tdata);
				if(tn==2) return data[i];
				else {
					for(int j=1;j<=dn;++j)
						if(i!=j && data[j]!=1) return data[j];
				}
			}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int h;

	scanf("%d",&T);

	while(T--) {
		init();
		scanf("%d",&h);
		if(h<=6) show('!',bfs(1));
		else show('!',getans());
	}

	return 0;
}
