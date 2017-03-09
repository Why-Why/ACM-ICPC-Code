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
// Created Time  : 2015年09月13日 星期日 11时29分37秒
// File Name     : 1006.cpp

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

const int MaxN=200004;

char s[MaxN];
int num1[MaxN],num2[MaxN];
int ans1[MaxN],ans2[MaxN];
int N;

int MinRepre(int len,int s[])
{
	for(int i=0;i<len;++i)		// 预处理。
		s[len+i]=s[i];
	s[len+len]=1;
	
	int i=0,j=1,k;
	
	while(i<len && j<len)
	{
		k=0;

		while(s[i+k]==s[j+k] && k<len)
			++k;

		if(k==len)
			return min(i,j);

		if(s[i+k]>s[j+k])
			i=max(j+1,i+k+1);
		else
			j=max(i+1,j+k+1);
	}

	return min(i,j);
}

void getans(int ans[],int x,int num[])
{
	for(int i=0;i<N;++i)
		ans[i]=num[x+i];
	ans[N]=1;
}

bool bijiao(int ans1[],int ans2[],int t1,int t2)
{
	for(int i=0;i<N;++i)
		if(ans1[i]!=ans2[i])
			return ans1[i]<ans2[i];

	t2=N-1-t2;
	if(t1<=t2)
		return 1;
	else return 0;
	return 1;
}

int next1[MaxN];

void KMP_pre(int m,int s[])
{
	int i=0,j=-1;

	next1[0]=-1;

	while(i<m)
	{
		while(j!=-1 && s[i]!=s[j])
			j=next1[j];

		++i;
		++j;

		next1[i]=j;
	}
}

int KMP(int n,int s1[],int m,int s2[])
{
	int i=0,j=0;
	int ret=-1;

	KMP_pre(m,s2);

	while(i<n)
	{
		while(j!=-1 && s1[i]!=s2[j])
			j=next1[j];

		++i;
		++j;

		if(j>=m)
		{
			ret=max(ret,i-m);
			j=next1[j];
		}
	}

	return ret;
}

int getzuihou(int ans[],int num[])
{
	return KMP(N+N-1,num,N,ans);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int t1,t2;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);
		scanf("%s",s);

		for(int i=0;i<N;++i)
		{
			num1[i]=-((s[i]-'a'+1));
			num2[i]=-((s[N-1-i]-'a'+1));
		}

		t1=MinRepre(N,num1);
		t2=MinRepre(N,num2);

		getans(ans1,t1,num1);
		getans(ans2,t2,num2);

		t2=getzuihou(ans2,num2);

		if(bijiao(ans1,ans2,t1,t2))
			printf("%d 0\n",t1+1);
		else printf("%d 1\n",N-t2);
	}
	
	return 0;
}
