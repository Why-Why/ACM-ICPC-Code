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

const int MaxN=100010;

int tree[20][MaxN];
int toleft[20][MaxN];
int sorted[MaxN];

void init()
{
	for(int i=0;i<20;++i)
		toleft[i][0]=0;
}

void build(int L,int R,int dep)
{
	if(L==R)
		return;

	int mid=(L+R)>>1;
	int same=mid-L+1;

	for(int i=L;i<=R;++i)			// i=l 不是 one
		if(tree[dep][i]<sorted[mid])
			--same;

	int lp=L,rp=mid+1;

	for(int i=L;i<=R;++i)
	{
		if(tree[dep][i]<sorted[mid])
			tree[dep+1][lp++]=tree[dep][i];
		else if(tree[dep][i]==sorted[mid] && same>0)
		{
			tree[dep+1][lp++]=tree[dep][i];
			--same;
		}
		else
			tree[dep+1][rp++]=tree[dep][i];

		toleft[dep][i]=toleft[dep][L-1]+lp-L;
	}

	build(L,mid,dep+1);
	build(mid+1,R,dep+1);
}

int query(int ql,int qr,int k,int L,int R,int dep)
{
	if(ql==qr)
		return tree[dep][ql];

	int mid=(L+R)>>1;
	int cou=toleft[dep][qr]-toleft[dep][ql-1];

	if(cou>=k)
	{
		int newl=L+toleft[dep][ql-1]-toleft[dep][L-1];
		int newr=newl+cou-1;

		return query(newl,newr,k,L,mid,dep+1);
	}
	else
	{
		int newr=qr+toleft[dep][R]-toleft[dep][qr];
		int newl=newr-(qr-ql-cou);

		return query(newl,newr,k-cou,mid+1,R,dep+1);
	}
}

int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M,a,b,c;

	init();

	scanf("%d %d",&N,&M);

	for(int i=1;i<=N;++i)
	{
		scanf("%d",&tree[0][i]);
		sorted[i]=tree[0][i];
	}

	sort(sorted+1,sorted+N+1);
	build(1,N,0);

	while(M--)
	{
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",query(a,b,c,1,N,0));
	}
	
	return 0;
}
