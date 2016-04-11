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

double eps=1e-10;
double PI=atan2(1.0,1.0)*4.0;

int sgn(double x)
{
	if(fabs(x)<eps)
		return 0;

	if(x<0)
		return -1;

	return 1;
}

struct state
{
	double ang;
	int id;

	bool operator < (const state &b) const
	{
		return sgn(ang-b.ang)<0;
	}
};

state sta[4000];
int N;
double X[4000],Y[4000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int cou;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			cin>>X[i]>>Y[i];

		printf("Case #%d:\n",cas++);

		for(int i=1;i<=N;++i)
		{
			cou=0;

			for(int j=1;j<=N;++j)
				if(i!=j)
				{
					sta[cou].ang=atan2(Y[j]-Y[i],X[j]-X[i]);
					sta[cou++].id=1;
				}

			sort(sta,sta+cou);

			int k=1;
			for(int i=1;i<cou;++i)
				if(sgn(sta[i].ang-sta[i-1].ang)!=0)
				{
					sta[k++]=sta[i];
				}
				else
				{
					sta[k].id++;
				}

			cou=k;

			int p1=0,p2=1,tp;
			int s1=0,s2=0;
			int ans=10000;
			double base=0;

			for(int i=0;i<cou;++i)
				cout<<sta[i].ang<<' '<<sta[i].id<<endl;

			for(p1=0;p1<cou;++p1)
			{
				while(sgn(base+sta[p2].ang-sta[p1].ang-PI)<0)
				{
					s1+=sta[p2].id;
					++p2;

					if(p2>=cou)
					{
						p2%=cou;
						base=PI+PI;
					}
				}

				if(sgn(base+sta[p2].ang-sta[p1].ang-PI)==0)
				{
					s2=N-1-s1-sta[p1].id-sta[p2].id;
				}
				else
					s2=N-1-s1-sta[p1].id;

				ans=min(ans,s1);
				ans=min(ans,s2);
			}

			cout<<ans<<endl;
		}
	}
	
	return 0;
}
