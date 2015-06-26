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

char num[20];
int ans[20][20];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>num;

	int len=strlen(num);
	int maxn=0;

	for(int i=0;i<len;++i)
		maxn=max(maxn,num[i]-'0');

	cout<<maxn<<endl;

	for(int i=0;i<len;++i)
		for(int j=0;j<num[i]-'0';++j)
			ans[j][i]=1;

	int temp;

	for(int i=0;i<maxn;++i,printf(" "))
	{
		temp=0;
		for(int j=0;j<len;++j)
			temp=temp*10+ans[i][j];
		cout<<temp;
	}
	cout<<endl;
	
	return 0;
}
