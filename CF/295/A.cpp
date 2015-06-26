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
	
	int n;
	char s[200];
	bool vis[30];
	int ans=0;

	memset(vis,0,sizeof(vis));

	cin>>n>>s;

	for(int i=0;i<n;++i)
	{
		if(s[i]<='Z')
			s[i]+=32;

		if(vis[s[i]-'a']==0)
		{
			vis[s[i]-'a']=1;
			++ans;
		}
	}

	if(ans==26)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}
