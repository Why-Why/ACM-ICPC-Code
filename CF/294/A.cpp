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

const char c[7]={'q','r','b','n','p','k','.'};
const int f[7]={9,5,3,3,1,0,0};

char map1[10][10];

void slove()
{
	int w=0,b=0;
	int temp;

	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
		{
			temp=0;
			for(int k=0;k<7;++k)
				if(map1[i][j]==c[k] || map1[i][j]+32==c[k])
				{
					temp=f[k];
					break;
				}

			if(map1[i][j]>='A' && map1[i][j]<='Z')
				w+=temp;
			else
				b+=temp;
		}

	if(w>b)
		cout<<"White\n";
	else if(w==b)
		cout<<"Draw\n";
	else
		cout<<"Black\n";
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
			cin>>map1[i][j];

	slove();
	
	return 0;
}
