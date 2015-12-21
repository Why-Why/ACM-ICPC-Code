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
// Created Time  : 2015年10月30日 星期五 11时11分00秒
// File Name     : Q_1.cpp

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

// DA算法求后缀数组，复杂度 O(nlogn)。
// 输入：处理后的s，长度n，字符种类数m。
// 输出：sa，height和rank(使用getHeight函数获得)。
// 注意：
// s为原字符串，sa为后缀数组，n为元素个数，m为元素最大值。
// rank[i]表示 s[i~n] 在所有后缀的排名，rank最小值为1，从0到n-1。
// sa[i]表示排名为i的后缀所在的位置，sa[0]是最后补的0，从0到n。
// height[i]表示排名为i和i-1的最长公共前缀，从1到n。
// s从0开始，s[n]=0，0为小于前面所有的一个数，且其余字符均大于0。
// 调用函数为 DA(s,n+1,m);其中m大于最大的那个，getHeight(s,n,rank,height);
// 使用RMQ询问时，需要把后缀通过rank变换，然后再交换为小的在前，然后再把小的加一，两个相等要特判，另外注意是min。

const int MaxN=60000;
const int INF=0x3f3f3f3f;

int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];
int sa[MaxN];
int rank[MaxN],height[MaxN];

bool cmp(int r[],int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(int *s,int n,int m)
{
	int i,j,p,*x=wa,*y=wb;

	for(i=0;i<m;++i) ts[i]=0;
	for(i=0;i<n;++i) ++ts[x[i]=s[i]];
	for(i=1;i<m;++i) ts[i]+=ts[i-1];
	for(i=n-1;i>=0;--i) sa[--ts[x[i]]]=i;

	for(j=1,p=1;p<n;j<<=1,m=p)
	{
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

int dp[MaxN][20];
int logN[MaxN];

void getHeight(int s[],int n,int rank[],int height[])
{
	int k=0,i,j;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? k-- : 0 , j=sa[rank[i]-1];s[i+k]==s[j+k];++k);

	logN[0]=-1;
	for(int i=1;i<=n;++i)
	{
		logN[i]=logN[i-1]+((i&(i-1)) ? 0 : 1);
		dp[i][0]=height[i];
	}
	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int query(int a,int b)
{
	if(a==b) return INF;

	a=rank[a];
	b=rank[b];
	if(a>b) swap(a,b);
	++a;
	int k=logN[b-a+1];
	return min(dp[a][k],dp[b-(1<<k)+1][k]);
}

/////////////////////////////////////////

// Size Balanced Tree。
// 输入：操作insert，erase。
// 输出：find，rank，getKth，preNum，nextNum。
// 注意：先init，然后操作；没有cou，每个节点最多存一个值，可重复，等于的往右边放；可以使用update维护其他东西；对相等时处理会出现问题。
// 原理：符合性质兄弟节点的两个儿子的size都比自己的size小。

struct SBT
{
	int tot,root;
	int size[MaxN],ch[MaxN][2];
	int key[MaxN];

	void init()
	{
		tot=1; root=0; size[0]=0;
		ch[0][0]=ch[0][1]=0;
	}
	void update(int x)
	{
		size[x]=size[ch[x][0]]+size[ch[x][1]]+(x!=0);
	}
	void rotate(int &x,int t)
	{
		int y=ch[x][t];
		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;
		update(x); update(y);
		x=y;
	}
	void maintain(int &x,int t)
	{
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
	void _insert(int &x,int k)
	{
		if(!x)
		{
			x=tot++; key[x]=k; size[x]=1;
			ch[x][0]=ch[x][1]=0;
		}
		else
		{
			++size[x];
			_insert(ch[x][k>=key[x]],k);
			maintain(x,k>=key[x]);
		}
	}
	int _erase(int &x,int k)
	{
		int temp;
		
		--size[x];
		if(k==key[x] || ch[x][k>=key[x]]==0)
		{
			temp=key[x];
			if(!ch[x][0] || !ch[x][1])					// 不能互换位置。
				x=ch[x][0]+ch[x][1];
			else key[x]=_erase(ch[x][0],k+1);			// 小心k+1越界。
		}
		else temp=_erase(ch[x][k>=key[x]],k);
		return temp;
	}
	int nextNum(int k)				// 比k大的最小数，不存在返回INF。		// ???
	{
		int x=root,ret=INF;

		while(x)
		{
			if(key[x]>=k) ret=min(ret,key[x]);
			x=ch[x][key[x]<=k];
		}
		return ret;
	}
	void insert(int k)
	{
		_insert(root,k);
	}
	int erase(int k)
	{
		if(root) return _erase(root,k);
		return 0;
	}
}tree;

////////////////////////////////////////////////

char s[MaxN];
int num[MaxN];
int wei[MaxN];
int N;

int rque[MaxN];

struct OPE1
{
	int id; int a,b;
}opeQ[20010];

struct OPE2
{
	int id; char a; int b; int c;
}opeI[300];

int M1,M2;

////////////////////////////////////

int C[MaxN];

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int d)
{
	while(x<=N) { C[x]+=d; x+=lowbit(x); }
}

int find(int x)
{
	int ans=0,sum=0;
	for(int i=20;i>=0;--i)
	{
		ans+=(1<<i);
		if(ans>N || sum+C[ans]>=x) ans-=(1<<i);
		else sum+=C[ans];
	}
	return ans+1;
}

////////////////////////////////////

void getstr()
{
	int t;

	N=M2+strlen(s);

	tree.init();
	tree.insert(N);
	for(int i=1;i<=N;++i) add(i,1),wei[i]=0;
	wei[0]=0;

	for(int i=M2;i>=1;--i)
	{
		t=find(opeI[i].b+1);
		wei[t-1]=-i;
		opeI[i].c=t-1;
		add(t,-1);
	}

	for(int i=0,j=0;i<N;++i)
		if(wei[i])
		{
			num[i]=opeI[-wei[i]].a;
			tree.insert(i);
		}
		else
		{
			num[i]=s[j++];
			wei[i]=j-1;
			rque[j]=i;
		}
	num[N]=0;
}

int getans(int a,int b)
{
	if(a>=N || b>=N) return 0;

	int x=tree.nextNum(a),y=tree.nextNum(b);
	int t=query(a,b),k=min(x-a,y-b);			// 在这里不能判断a==b！
	if(t<k) return t;
	if(x-a>y-b) return k+getans(a+k,y+1);
	else return k+getans(x+1,b+k);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char ts[5];
	int M;
	int tN;

	scanf("%s",s);
	tN=strlen(s);

	scanf("%d",&M);
	M1=M2=0;
	for(int i=1;i<=M;++i)
	{
		scanf("%s",ts);
		if(ts[0]=='Q')
		{
			opeQ[++M1].id=i;
			scanf("%d %d",&opeQ[M1].a,&opeQ[M1].b);
		}
		else
		{
			opeI[++M2].id=i;
			scanf("%s %d",ts,&opeI[M2].b);

			if(opeI[M2].b>tN+M2-1) opeI[M2].b=tN+M2;
			--opeI[M2].b;
			opeI[M2].a=ts[0];
		}
	}
	getstr();
	DA(num,N+1,128);
	getHeight(num,N,rank,height);

	for(int i=1,p=1;i<=M1;++i)
	{
		while(p<=M2 && opeI[p].id<opeQ[i].id)
		{
			tree.erase(opeI[p].c);
			++p;
		}
		printf("%d\n",getans(rque[opeQ[i].a],rque[opeQ[i].b]));
	}

	return 0;
}
