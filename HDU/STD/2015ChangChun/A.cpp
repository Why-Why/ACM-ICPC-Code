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
// Created Time  : 2015年11月01日 星期日 12时00分13秒
// File Name     : A.cpp

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

const long long v[15]={0,1,5,10,20,50,100,200,500,1000,2000};
const int bei[15]={0,5,10,10,20,100,100,200,1000,2000,2000};
const int yong[15]={0,5,2,1,1,2,1,1,2,2,1};

int p;
int c[15];
long long tot;
long long tsum[15];

int ans;

bool dfs(int dis,int use,int d)
{
	cout<<dis<<' '<<use<<' '<<d<<endl;

	if(!dis) { ans=max(ans,use); return 1; }
	if(d>10) return 0;
	if(tsum[d]<dis) return 0;
//	if((dis+v[d]-1)/v[d]+use<=ans) return 0;

	int t=dis%bei[d];
	if(t%v[d]) return 0;
	t/=v[d];

	if(t>c[d]) return 0;
	int tc=c[d]-t;
	use+=t;
	dis-=t*v[d];

	int temp=yong[d];
	int ddd=temp*v[d];

	for(int i=min(dis/ddd,tc/temp);i>=0;--i)
		if(dfs(dis-i*ddd,use+i*temp,d+1)) return 1;
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&p);
		tot=0;
		for(int i=1;i<=10;++i) scanf("%d",c+i);
		for(int i=10;i>=1;--i)
		{
			tot+=v[i]*c[i];
			tsum[i]=tot;
		}

		ans=-1;
		dfs(p,0,1);

		printf("%d\n",ans);
	}
	
	return 0;
}
