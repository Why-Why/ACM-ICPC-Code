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

const double eps=1e-12;

char s[10000];
char wei[10000];
int len;
double flag;
double a,b;

void chuli(int x,int y)
{
	if(x==y)
		return;

	char temp[1000]={0};
	double tn;
	bool have=0;
	int i;

	for(i=x;i<y;++i)
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
		{
			have=1;
			temp[i-x]=0;
			break;
		}
		else
			temp[i-x]=s[i];
	if(temp[0])
		sscanf(temp,"%lf",&tn);
	else
		tn=1;

	if(temp[0]=='-' && temp[1]==0)
		tn=-1;
	if(temp[0]=='+' && temp[1]==0)
		tn=1;

	if(have)
	{
		a+=flag*tn;

		if(wei[0]==0)
		{
			for(int j=i;j<y;++j)
				wei[j-i]=s[j];
			wei[y-i]=0;
		}
	}
	else
		b+=((-flag)*tn);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int last;

	scanf("%d",&T);

	while(T--)
	{
		wei[0]=0;
		a=b=0;
		last=0;
		flag=1;
		scanf("%s",s);

		len=strlen(s);

		for(int i=0;i<len;++i)
			if(s[i]=='+')
			{
				chuli(last,i);
				last=i;
			}
			else if(s[i]=='-')
			{
				chuli(last,i);
				last=i;
			}
			else if(s[i]=='=')
			{
				chuli(last,i);
				flag=-flag;
				last=i+1;
			}

		chuli(last,len);
		double ans=b/a;

		if(fabs(a)<eps)
			ans=0.00000;

		if(ans<=0 && 0.0-ans<eps)
			ans=0;

		printf("%s=",wei);

		if(ans>=0)
			printf("%.3lf\n",ans+eps);
		else
			printf("%.3lf\n",ans-eps);
	}
	
	return 0;
}
