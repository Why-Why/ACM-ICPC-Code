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
// Created Time  : 2016年10月03日 星期一 12时52分27秒
// File Name     : C.cpp

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

const long long MaxNode=2000000;

long long zhuan[256];

struct Trie {
	long long next[MaxNode][57];
	long long val[MaxNode];
	long long Tcou,root;

	long long newNode() {
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou]=0;

		return Tcou;
	}

	void init() {
		Tcou=-1;
		root=newNode();
	}

	bool insert(char s[],long long v) {
		long long p=0;

		for(long long i=0;s[i];++i) {
			if(next[p][zhuan[s[i]]]==0)
				next[p][zhuan[s[i]]]=newNode();
			p=next[p][zhuan[s[i]]];
		}

		if(val[p]) return 0;
		val[p]=v;
		return 1;
	}

	long long erase(char s[]) {
		long long p=0;

		for(long long i=0;s[i];++i) {
			if(next[p][zhuan[s[i]]]==0)
				return 0;

			p=next[p][zhuan[s[i]]];
		}

		long long ret=val[p];
		val[p]=0;
		return ret;
	}
}tree;

char name[70003][23];
long long ttt;

/////////////////////////////////

// Size Balanced Tree。
// 输入：操作insert，erase。
// 输出：find，rank，getKth，preNum，nextNum。
// 注意：先init，然后操作；没有cou，每个节点最多存一个值，可重复，等于的往右边放；可以使用update维护其他东西；对相等时处理会出现问题。
// 原理：符合性质兄弟节点的两个儿子的size都比自己的size小。

const long long MaxN=500000;
const long long INF=0x3f3f3f3f;

struct SBT {
	long long tot,root;
	long long size[MaxN],ch[MaxN][2];
	long long key[MaxN];
	long long val[MaxN];

	void init() {
		tot=1; root=0; size[0]=0;
		ch[0][0]=ch[0][1]=0;
	}

	void update(long long x) {
		size[x]=size[ch[x][0]]+size[ch[x][1]]+(x!=0);
	}

	void rotate(long long &x,long long t) {
		long long y=ch[x][t];
		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x); update(y);
		x=y;
	}

	void maintain(long long &x,long long t) {
		if(size[ch[ch[x][t]][t]]>size[ch[x][1-t]]) rotate(x,t);
		else if(size[ch[ch[x][t]][1-t]]>size[ch[x][1-t]])
		{
			rotate(ch[x][t],1-t); rotate(x,t);
		}
		else return;

		maintain(ch[x][0],0);
		maintain(ch[x][1],1);
		maintain(x,0);
		maintain(x,1);
	}

	void _insert(long long &x,long long k,long long v) {
		if(!x) {
			x=tot++; key[x]=k; size[x]=1;
			ch[x][0]=ch[x][1]=0;

			val[x]=v;
		}
		else {
			++size[x];
			_insert(ch[x][k>=key[x]],k,v);
			maintain(x,k>=key[x]);
		}
	}

	long long _erase(long long &x,long long k) {
		long long temp;
		
		--size[x];
		if(k==key[x] || ch[x][k>=key[x]]==0) {
			temp=key[x];
			if(!ch[x][0] || !ch[x][1])					// 不能互换位置。
				x=ch[x][0]+ch[x][1];
			else key[x]=_erase(ch[x][0],k+1);			// 小心k+1越界。
		}
		else temp=_erase(ch[x][k>=key[x]],k);
		return temp;
	}

	long long rank(long long k) {				// 小于等于k的个数。  ！！！
		long long x=root,ret=0;

		while(x) {
			if(k>=key[x]) ret+=size[ch[x][0]]+1;
			x=ch[x][k>=key[x]];
		}
		return ret;
	}

	long long getKth(long long k,long long &kkk) {				// 找第K大，如果不存在返回0。
		long long x=root;

		while(x) {
			if(k<=size[ch[x][0]]) x=ch[x][0];
			else {
				k-=size[ch[x][0]]+1;
				if(k) x=ch[x][1];
				else {
					kkk=key[x];
					return val[x];
				}
			}
		}
		return 0;
	}

	void insert(long long k,long long id) {
		_insert(root,k,id);
	}

	long long erase(long long k) {
		if(root) return _erase(root,k);
		return 0;
	}
}rem;

long long cou;

/*
inline void add(char s[],long long v,long long id) {
	rem.insert(v,id);

	long long t=rem.rank(v);

	if(t>(cou+1)/5) {
		prlong longf("%s is not working now.\n",s);
		if((cou+1)/5>(cou/5))
			prlong longf("%s is working hard now.\n",name[rem.getKth((cou+1)/5)]);
	}
	else {
		prlong longf("%s is working hard now.\n",s);
		if((cou+1)/5==cou/5)
			prlong longf("%s is not working now.\n",name[rem.getKth((cou+1)/5+1)]);
	}

	//rem.insert(v,id);
	++cou;
}

inline void erase(char s[],long long v) {
	long long t=rem.rank(v);

	if(t<=cou/5) {
		if((cou-1)/5==cou/5)
			prlong longf("%s is working hard now.\n",name[rem.getKth(cou/5+1)]);
	}
	else {
		if((cou-1)/5!=cou/5)
			prlong longf("%s is not working now.\n",name[rem.getKth(cou/5)]);
	}

	rem.erase(v);
	--cou;
}
*/

/////////////////////////////////

const long long base=1000000;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long t;
	long long N;
	char s1[30],s2[30];

	t=0;
	for(long long i='a';i<='z';++i) zhuan[i]=t++;
	for(long long i='A';i<='Z';++i) zhuan[i]=t++;

	tree.init();
	rem.init();

	scanf("%lld",&N);
	cou=N;

	while(N--) {
		scanf("%s %lld",name[++ttt],&t);
		tree.insert(name[ttt],t*base+ttt);

		rem.insert(-(t*base+ttt),ttt);
	}

	long long r1,r2;
	long long k1,k2;

	scanf("%lld",&N);
	while(N--) {
		if(cou<=4) r1=0;
		else r1=rem.getKth(cou/5,k1);
		r2=rem.getKth(cou/5+1,k2);

		long long tt;

		scanf("%s",s1);
		if(s1[0]=='+') {
			scanf("%s %lld",name[++ttt],&t);
			tree.insert(name[ttt],t*base+ttt);

			//add(name[ttt],-(t*base+ttt),ttt);
			rem.insert(-(t*base+ttt),ttt);
			++cou;

			t=rem.rank(-(t*base+ttt));
			if(t<=cou/5) printf("%s is working hard now.\n",name[ttt]);
			else printf("%s is not working now.\n",name[ttt]);
		}
		else {
			scanf("%s",s2);
			tt=tree.erase(s2);

			//if(tt==0) continue;				//

			//erase(s2,-tt);
			rem.erase(-tt);
			--cou;
		}

		if(r1) {
			if(s1[0]=='-' && -tt==k1);
			else {
				t=rem.rank(k1);
				if(t>cou/5) printf("%s is not working now.\n",name[r1]);
			}
		}

		if(s1[0]=='-' && -tt==k2);
		else {
			t=rem.rank(k2);
			if(t<=cou/5) printf("%s is working hard now.\n",name[r2]);
		}

		//puts("################");
	}

	return 0;
}
