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
// Created Time  : 2015年08月11日 星期二 12时12分09秒
// File Name     : 1005.cpp

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

const int MaxN=1000000;

char s[MaxN];
long long sum;
int t;

long long getsum(char s[],int p)
{
	long long ret=0;

	for(int i=p;s[i];++i)
		ret+=s[i]-'0';

	return ret;
}

int zhuan(char s[],int p,int num)
{
	char ts[100];
	sprintf(ts,"%d",num);

	int ret=0;
	for(ret=p;s[ret];++ret);

	int i;
	for(i=0;ts[i];++i)
		s[ret+i]=ts[i];
	s[ret+i]=0;
	return ret;
}

bool judge()
{
	long long ret=0;

//	cout<<strlen(s)<<endl;

	for(int i=0;s[i];++i)
	{
		ret=ret*10+s[i]-'0';
		ret%=11;

//		cout<<ret<<endl;
	}

	return (ret%11)==0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int p,temp;
	int cas=1;

	while(~scanf("%s %d",s,&t))
	{
		if(s[0]=='-' && t==-1)
			break;

		p=0;
		sum=0;
		for(int i=0;i<t;++i)
		{
			temp=getsum(s,p);
			sum+=temp;
			p=zhuan(s,p,sum);
//			cout<<s<<endl;
		}

		printf("Case #%d: ",cas++);

		if(judge())
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}
