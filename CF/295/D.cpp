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

const int mod=1000000000+9;
const int MaxM=100005;

typedef pair<int,int> pii;
map <pii,int> Map;
map <pii,int>::iterator iter;
set <int> Set;
int cou[MaxM];
int x[MaxM],y[MaxM];
bool vis[MaxM];
int xia[MaxM][3];
int shang[MaxM][3];

bool judge(int num)
{
	for(int i=0;i<3;++i)
		if(shang[num][i]!=0 && vis[shang[num][i]]==0 && cou[shang[num][i]]==1)
			return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int M;
	int a,b;
	long long ret=0;

	scanf("%d",&M);

	for(int i=1;i<=M;++i)
	{
		scanf("%d %d",&a,&b);
		x[i]=a;
		y[i]=b;
		Map.insert(pair<pii,int>(pii(a,b),i));
	}

	for(int i=1;i<=M;++i)
	{
		iter=Map.find(pii(x[i]-1,y[i]+1));

		if(iter!=Map.end())
		{
			++cou[iter->second];
			shang[i][0]=iter->second;
		}

		iter=Map.find(pii(x[i],y[i]+1));

		if(iter!=Map.end())
		{
			++cou[iter->second];
			shang[i][1]=iter->second;
		}

		iter=Map.find(pii(x[i]+1,y[i]+1));

		if(iter!=Map.end())
		{
			++cou[iter->second];
			shang[i][2]=iter->second;
		}

		iter=Map.find(pii(x[i]-1,y[i]-1));

		if(iter!=Map.end())
			xia[i][0]=iter->second;

		iter=Map.find(pii(x[i],y[i]-1));

		if(iter!=Map.end())
			xia[i][1]=iter->second;

		iter=Map.find(pii(x[i]+1,y[i]-1));

		if(iter!=Map.end())
			xia[i][2]=iter->second;
	}

	for(int i=1;i<=M;++i)
		if(judge(i))
			Set.insert(i);

	int temp;

	for(int i=1;i<=M;++i)
	{
		if(i&1)
			temp=*Set.rbegin();
		else
			temp=*Set.begin();

		ret=(ret*M+temp-1)%mod;

		Set.erase(temp);
		vis[temp]=1;

		for(int j=0;j<3;++j)
			if(shang[temp][j] && vis[shang[temp][j]]==0 && cou[shang[temp][j]])
				--cou[shang[temp][j]];

		for(int j=0;j<3;++j)
			if(xia[temp][j] && vis[xia[temp][j]]==0 && judge(xia[temp][j]))
				Set.insert(xia[temp][j]);

		for(int j=0;j<3;++j)
			if(shang[temp][j] && vis[shang[temp][j]]==0)
				for(int k=0;k<3;++k)
					if(xia[shang[temp][j]][k] && vis[xia[shang[temp][j]][k]]==0)
						if(judge(xia[shang[temp][j]][k]))
							Set.insert(xia[shang[temp][j]][k]);
						else
							Set.erase(xia[shang[temp][j]][k]);
	}

	cout<<ret<<endl;
	
	return 0;
}
