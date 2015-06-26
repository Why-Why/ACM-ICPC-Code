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

struct state
{
	long long x,y;

	bool operator < (const state &a) const
	{
		if(x==a.x)
			return y<a.y;
		return x<a.x;
	}
};

state sta[200005];
int n;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;

	scanf("%d",&n);

	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a,&b);
		sta[i].x=(long long)a-b;
		sta[i].y=(long long)a+b;
	}

	sort(sta+1,sta+1+n);

	int ans=0;
	int zui=sta[1].x;

	for(int i=1;i<=n;++i)
	{
		if(sta[i].x>=zui)
		{
			++ans;
			zui=sta[i].y;
		}

		if(sta[i].y<zui)
			zui=sta[i].y;
	}

	cout<<ans<<endl;
	
	return 0;
}
