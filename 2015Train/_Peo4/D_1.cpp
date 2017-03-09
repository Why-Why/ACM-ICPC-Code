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
// Created Time  : 2015年09月25日 星期五 19时40分31秒
// File Name     : D_1.cpp

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

int ans[52][52][5005];
int flag=1;
char s[55];
int sum=0;

inline int zhuan(char c)
{
	switch(c)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
	}
}

bool judge(int L,int R,int num)
{
	if(num>sum) return 0;
	if(L==R) return num==zhuan(s[L]);
	int & xxx=ans[L][R][num];
	if(xxx>=flag) return xxx-flag;
	int t=zhuan(s[R]);
	int x=t-num;

	xxx=flag;
	if((x<t && x>0 && judge(L,R-1,x)) || (num-t>=t && judge(L,R-1,num-t)))
	{
		++xxx;
		return 1;
	}
	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	int len;

	while(~scanf("%s",s+1) && s[1]!='0')
	{
		len=strlen(s+1);
		for(int i=1;s[i];++i)
			sum+=zhuan(s[i]);
		printf("Case %d:",cas++);
		for(int i=1;i<=sum;++i)
			if(judge(1,len,i))
				printf(" %d",i);
		puts("");
		flag+=2;
	}
	
	return 0;
}
