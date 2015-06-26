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

unsigned long long jie[60];

int rem[20];
int N;

unsigned long long getans()
{
	unsigned long long ret=0;

	for(int i=1;i<=13;++i)
	{
		for(int j=1;j<rem[i];++j)
			for(int k=j+1;k<=rem[i];++l)
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	jie[0]=1;

	for(int i=1;i<=58;++i)
		jie[i]=jie[i-1]*i;

	int T,cas=1;
	char s[10];
	unsigned long long ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		memset(rem,0,sizeof(rem));

		for(int i=1;i<=N;++i)
		{
			scanf("%s",s);

			if(s[0]>='2' && s[0]<='9')
				++rem[s[0]-'0'];
			else if(s[0]=='A')
				++rem[1];
			else if(s[0]=='T')
				++rem[10];
			else if(s[0]=='J')
				++rem[11];
			else if(s[0]=='Q')
				++rem[12];
			else if(s[0]=='K')
				++rem[13];
		}

		ans=1;

		for(int i=1;i<=N;++i)
			ans=ans*i;

		ans-=getans();

		printf("Case #%d: ",cas++);
		cout<<ans<<endl;
	}
	
	return 0;
}
