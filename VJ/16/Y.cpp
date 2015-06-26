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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int p=0;
	long long ans=0;
	char s[]="doge";
	char c;

	while(c=getchar())
	{
		if(c==EOF)
			break;

		if(c>='A' && c<='Z')
			c+=32;

		if(c==s[p])
			++p;
		else
			p=0;

		if(p==4)
		{
			++ans;
			p=0;
		}
	}

	cout<<ans<<endl;
	
	return 0;
}
