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
// Created Time  : 2017年02月28日 星期二 22时25分23秒
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

const int MaxN=10000007;

char s[MaxN];
char ts[MaxN];
int remf[MaxN],trem[MaxN];

inline bool isV(char c) {
	if(c>='a' && c<='z') return 1;
	if(c>='A' && c<='Z') return 1;
	if(c=='-') return 1;
	return 0;
}

inline int findK(int L,int R) {
	for(int i=L;i<=R;++i)
		if(s[i]!=' ') {
			if(s[i]=='(') return i;
			return -1;
		}
	return -1;
}

inline int isLam(int L,int R) {
	const char lam[]="lambda";

	for(int i=0;i<6;++i)
		if(s[L+i]!=lam[i]) return -1;
	if(s[L+6]!=' ' && s[L+6]!='(') return -1;

	return findK(L+6,R);
}

inline int findLam(int L,int R) {
	for(int i=L;i<=R;++i)
		if(s[i]!=' ') {
			if(s[i]=='l') return isLam(i,R);
			return -1;
		}
	return -1;
}

inline int findJ(int L,int R) {
	for(int i=L+1;i<=R;++i)
		if(s[i]==' ' && isV(s[i-1])) return i;
	return -1;
}

inline string getS(int L,int R) {
	char ts[111];
	int tcou=0;
	bool ok=0;

	for(int i=L;i<=R;++i)
		if(s[i]!=' ') {
			ts[tcou++]=s[i];
			ok=1;
		}
		else if(ok) break;

	ts[tcou]=0;
	return string(ts);
}

inline void merge(set <string> &a,const set <string> &b) {
	set <string> ::iterator iter;

	for(iter=b.begin();iter!=b.end();++iter)
		a.insert(*iter);
}

set <string> getans(int L,int R) {
	if(R<L) return set<string>();

	int t=findK(L,R);
	set <string> ret;
	ret.clear();

	if(t==-1) {
		ret.insert(getS(L,R));
		return ret;
	}

	int t2=findLam(t+1,remf[t]-1);

	if(t2!=-1) {
		string tmp=getS(t2+1,remf[t2]-1);
		ret=getans(remf[t2]+1,remf[t]-1);
		ret.erase(tmp);
		return ret;
	}
	else {
		int t3=findK(t+1,remf[t]-1);

		if(t3==-1) {
			int t4=findJ(t+1,remf[t]-1);
			ret=getans(t+1,t4-1);
			merge(ret,getans(t4+1,remf[t]-1));
		}
		else {
			ret=getans(t3,remf[t3]);
			merge(ret,getans(remf[t3]+1,remf[t]-1));
		}

		return ret;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d\n",&T);			// why not getchar() ?
	//getchar();

	while(T--) {
		//gets(s);			// ????????
		cin.getline(s,10000007);

		int t=0;
		for(int i=0;s[i];++i)
			if(s[i]=='(') {
				trem[t]=i;
				++t;
			}
			else if(s[i]==')') {
				--t;
				remf[i]=trem[t];
				remf[trem[t]]=i;
			}

		set <string> ans=getans(0,strlen(s)-1);
		set <string> ::iterator iter;

		printf("Case #%d:",cas++);
		for(iter=ans.begin();iter!=ans.end();++iter)
			printf(" %s",iter->c_str());
		if(ans.size()==0) putchar(' ');
		puts("");
	}

	return 0;
}
