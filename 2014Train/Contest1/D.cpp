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
// Created Time  : 2015年09月25日 星期五 11时15分27秒
// File Name     : D.cpp

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

char s[MaxN];

bool judge(int L1,int R1,int L2,int R2)
{
	if(R1-L1!=R2-L2) return (R1-L1)>(R2-L2);

	for(int i=L1,j=L2;i<=R1;++i,++j)
		if(s[i]!=s[j]) return s[i]>s[j];
	return 1;
}

int getans(int L,int R)
{
	int ret=0;
	int p;
	for(p=R;p>=L;--p) if(s[p]!='0') break;

	if(judge(L,p-1,p,R)==0) return 1;
	else return getans(L,p-1)+1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%s",s);
	printf("%d\n",getans(0,strlen(s)-1));
	
	return 0;
}
