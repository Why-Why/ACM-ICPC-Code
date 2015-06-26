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

const char month[15][20]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

bool judge(int x)
{
	if(x%4==0 && x%100)
		return 1;

	if(x%400==0)
		return 1;

	return 0;
}

int getans1(int x)
{
	int a=x/4+1;
	int b=x/100+1;
	int c=x/400+1;

	return a-b+c;
}

int getans(int x,int y)
{
	if(x>y)
		return 0;

	int a=getans1(x-1),b=getans1(y);

	return b-a;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char ms1[20],ms2[20];
	int m1,m2;
	int d1,d2;
	int y1,y2;
	int ans;

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s %d, %d",ms1,&d1,&y1);
		scanf("%s %d, %d",ms2,&d2,&y2);

		for(int i=0;i<12;++i)
		{
			if(strcmp(month[i],ms1)==0)
				m1=i+1;

			if(strcmp(month[i],ms2)==0)
				m2=i+1;
		}

		ans=getans(y1+1,y2-1);

		if(y1==y2 && judge(y1))
		{
			if(m1<=2 && (m2>2 || (m2==2 && d2==29)))
				++ans;
		}
		else
		{
			if(judge(y1) && (m1<2 || (m1==2 && d1<=29)))
				++ans;

			if(judge(y2) && (m2>2 || (m2==2 && d2>=29)))
				++ans;
		}

		printf("Case #%d: ",cas++);
		printf("%d\n",ans);
	}
	
	return 0;
}
