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

const int MaxN=100005;

int num1[MaxN],num2[MaxN],num3[MaxN];
int n;

void slove()
{
	sort(num1,num1+n);
	sort(num2,num2+n-1);
	sort(num3,num3+n-2);

	num2[n]=num3[n-1]=num3[n]=-1;

	for(int i=0;i<n;++i)
		if(num1[i]!=num2[i])
		{
			cout<<num1[i]<<endl;
			break;
		}

	for(int i=0;i<n-1;++i)
		if(num2[i]!=num3[i])
		{
			cout<<num2[i]<<endl;
			break;
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>n;

	for(int i=0;i<n;++i)
		scanf("%d",&num1[i]);
	for(int i=0;i<n-1;++i)
		scanf("%d",&num2[i]);
	for(int i=0;i<n-2;++i)
		scanf("%d",&num3[i]);

	slove();

	return 0;
}
