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
// Created Time  : 2016年03月17日 星期四 22时26分25秒
// File Name     : F_test.cpp

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

char data[10][5]={"0000","0022","0003","0020","0100","0111","0023","0122","0120","0113"};
char data_1[10][5];

const int rr1[4]={0,5,2,7};
const int rr2[4]={1,4,3,6};

int fa[10];
int mufa[10];

int find(int x,int *fa) {
	if(fa[x]==x) return x;
	fa[x]=find(fa[x],fa);
	return fa[x];
}

void merge(int a,int b,int *fa) {
	fa[find(a,fa)]=find(b,fa);
}

int rans[11][11][5];

inline bool judge(char s[],char s1[],char s2[],int st) {
	for(int i=0;i<4;++i) fa[i]=s1[i]-'0';
	for(int i=4;i<8;++i) fa[i]=s2[i-4]-'0';

	for(int i=0;i<4;++i) mufa[i]=s[i]-'0';

	if(st&1) merge(1,4,fa);
	if(st&2) merge(3,6,fa);

	int trem[10];
	for(int i=0;i<8;++i) trem[i]=find(i,fa);

	for(int i=0;i<4;++i) {
		bool flag=0;
		for(int j=0;j<4;++j)
			if(trem[rr2[i]]==trem[rr1[j]]) flag=1;
		if(flag==0) return 0;
	}

	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j) {
			if((trem[rr1[i]]==trem[rr1[j]]) && find(i,mufa)!=find(j,mufa)) return 0;
			if((trem[rr1[i]]!=trem[rr1[j]]) && find(i,mufa)==find(j,mufa)) return 0;
		}

	return 1;
}

void getans(int u) {
	memest(rans,0,sizeof(rans));
	cout<<u<<endl;
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			for(int k=1;k<4;++k)
				if(judge(data[u],data[i],data_1[j],k)) {
					cout<<i<<' '<<j<<' '<<k<<endl;
				}
	cout<<"##########\n";
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);


	for(int i=0;i<10;++i)
		for(int j=0;j<5;++j) data_1[i][j]=data[i][j]+4;

	for(int i=0;i<10;++i)
		getans(i);
	
	return 0;
}
