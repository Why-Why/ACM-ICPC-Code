// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月26日 星期二 14时44分31秒
// File Name     : 1013.cpp

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

char s1[20],s2[20],s3[20];
int light[20],weight[20],even[20];
int temp1[20],temp2[20];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		for(int i=0;i<20;++i)
		{
			even[i]=0;
			light[i]=weight[i]=1;
		}
	
		for(int kkk=0;kkk<3;++kkk)	
		{
			scanf("%s %s %s",s1,s2,s3);

			if(s3[0]=='e')
			{
				for(int i=0;s1[i];++i)
					even[s1[i]-'A']=even[s2[i]-'A']=1;
			}
			else if(s3[0]=='u')
			{
				for(int i=0;i<12;++i)
				{
					temp1[i]=light[i];
					light[i]=0;
					temp2[i]=weight[i];
					weight[i]=0;
				}
    
				for(int i=0;s1[i];++i)
				{
					if(temp1[s1[i]-'A'])
						light[s1[i]-'A']=1;
    
					if(temp2[s2[i]-'A'])
						weight[s2[i]-'A']=1;
				}
			}
			else
			{
				for(int i=0;i<12;++i)
				{
					temp1[i]=light[i];
					light[i]=0;
					temp2[i]=weight[i];
					weight[i]=0;
				}
    
				for(int i=0;s2[i];++i)
				{
					if(temp1[s2[i]-'A'])
						light[s2[i]-'A']=1;
    
					if(temp2[s1[i]-'A'])
						weight[s1[i]-'A']=1;
				}
			}
		}

		int rem1=-1,rem2=-1;

		for(int i=0;i<12;++i)
		{
			if(light[i] && even[i]==0)
			{
				if(rem1==-1)
					rem1=i;
				else
					rem1=-2;
			}

			if(weight[i] && even[i]==0)
			{
				if(rem2==-1)
					rem2=i;
				else
					rem2=-2;
			}
		}

		if(rem2>-1)
			printf("%c is the counterfeit coin and it is light. \n",'A'+rem2);
		else
			printf("%c is the counterfeit coin and it is heavy. \n",'A'+rem1);
	}
	
	return 0;
}
