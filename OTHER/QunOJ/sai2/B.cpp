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

map <long long,int> sta;
map <long long,int>::iterator ite;
int N;
long long K;
//long long cou[100000];
//int ji;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int temp;
	long long sum;
	int a;

	long long ans=0;

	scanf("%d",&T);

	while(T--)
	{
//		ji=0;
		sum=0;
		ans=0;
		sta.clear();

//		cou[ji]=1;
		sta.insert(pair<long long,int>(0,1));

		scanf("%d %d",&N,&temp);
		K=temp;

		for(int i=1;i<=N;++i)
		{
			scanf("%d",&a);
			sum+=a;

			ite=sta.find(sum%K);

			if(ite!=sta.end())
			{
				ans+=ite->second;
				temp=ite->second+1;
				sta.erase(ite);
				sta.insert(pair<long long,int>(sum%K,temp));
			}
			else
			{
				sta.insert(pair<long long,int>(sum%K,1));
			}
		}

		cout<<ans<<endl;
	}
	
	return 0;
}
