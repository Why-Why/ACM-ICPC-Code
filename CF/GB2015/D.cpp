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
// Created Time  : 2015年12月31日 星期四 00时06分08秒
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

const int MaxN=5005;
const int mod=1000000007;

int N;
char s[MaxN];

int dp[MaxN][MaxN]={};
int sum[MaxN][MaxN]={};

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

int wa[MaxN],wb[MaxN],wv[MaxN],ts[MaxN];
int sa[MaxN];

bool cmp(int r[],int a,int b,int l)
{
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void DA(char *s,int n,int m)
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

int dp1[MaxN][20];
int logN[MaxN];
int rank[MaxN],height[MaxN];

void getHeight(char s[],int n,int rank[],int height[])
{
	int k=0,i,j;

	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k ? k-- : 0 , j=sa[rank[i]-1];s[i+k]==s[j+k];++k);

	logN[0]=-1;
	for(int i=1;i<=n;++i) {
		dp1[i][0]=height[i];
		logN[i]=((i&(i-1))==0) ? logN[i-1]+1 : logN[i-1];
	}
	for(int j=1;j<=logN[n];++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			dp1[i][j]=min(dp1[i][j-1],dp1[i+(1<<(j-1))][j-1]);
}

int query(int x,int y) {
	if(x==y) return N;
	x=rank[x];
	y=rank[y];
	if(x>y) swap(x,y);
	++x;

	int k=logN[y-x+1];
	return min(dp1[x][k],dp1[y-(1<<k)+1][k]);
}

inline bool judge(int a,int b,int l) {
	if(a-l+1<0) return 0;
	if(query(a-l+1,b-l+1)>=l) return 0;
	return rank[a-l+1]<rank[b-l+1];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	long long temp;
	scanf("%d %s",&N,s);
	dp[0][0]=1;
	for(int i=0;i<=N;++i) sum[0][i]=1;

	DA(s,N+1,256);
	getHeight(s,N,rank,height);

	for(int i=1;i<=N;++i) {
		for(int j=1;j<=i;++j) {
			if(s[i-j]=='0') dp[i][j]=0;
			else {
				dp[i][j]=sum[i-j][min(j-1,i-j)];
				if(judge(i-j-1,i-1,j)) dp[i][j]=((long long)dp[i][j]+(long long)dp[i-j][j])%mod;
			}
			sum[i][j]=((long long)dp[i][j]+(long long)sum[i][j-1])%mod;
		}
	}

	printf("%d\n",sum[N][N]);
	
	return 0;
}
