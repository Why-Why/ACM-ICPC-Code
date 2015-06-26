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

char haab[25][20]={"", "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"};
char tzo[25][20]={"","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

char s[20];

int change(char s[])
{
	for(int i=1;i<=18;++i)
		if(strcmp(s,haab[i])==0)
			return i;

	return 19;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c,A,B,C;
	long long s1,s2;
	int N;

	scanf("%d",&N);
	printf("%d\n",N);

	while(N--)
	{
		scanf("%d %s",&a,s);
		scanf("%s %d",s,&c);
		b=change(s);

	//	cout<<b<<' '<<s<<endl;

		s2=c*365LL+(b-1)*20+a+1;
		C=(s2-1)/260LL;
		
		s2%=260;

		if(!s2)
			s2=260;

		A=(s2-1)%13+1;
		B=(s2-1)%20+1;

		printf("%d %s %d\n",A,tzo[B],C);
	}
	
	return 0;
}
