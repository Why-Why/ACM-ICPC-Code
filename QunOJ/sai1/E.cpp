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

int N,M,R;
int tx[200],ty[200];
int px[200],py[200];

inline long long abs1(long long x)
{
	if(x<0)
		return -x;
	return x;
}

int getans()
{
	int ret=0;
	bool ok;
	long long dx,dy,x0,y0;
	long double t1,t2;

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
		{
			if(i==j)
				continue;

			ok=1;
			for(int k=0;k<M;++k)
			{
				dx=tx[i]-tx[j];
				dy=ty[i]-ty[j];
				x0=px[k];
				y0=py[k];

				t1=abs1(dy*x0-dx*y0+dx*ty[j]-dy*tx[j]);
				t2=R*sqrt(double(dx*dx+dy*dy));

				if(t1<=t2)
				{
					ok=0;
					break;
				}
			}

			if(ok)
				++ret;
		}

	return ret/2-N;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d",&N,&M,&R))
	{
		for(int i=0;i<N;++i)
			scanf("%d %d",&tx[i],&ty[i]);
		for(int i=0;i<M;++i)
			scanf("%d %d",&px[i],&py[i]);

		printf("%d\n",getans());
	}
	
	return 0;
}
