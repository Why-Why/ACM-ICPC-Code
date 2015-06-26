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

int cou[30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	char t;
	int ans=0;

	ios::sync_with_stdio(false);

	cin>>N;
	--N;

	for(int i=1;i<=N;++i)
	{
		cin>>t;

		++cou[t-'a'];

		cin>>t;

		if(cou[t-'A']==0)
			++ans;
		else
			--cou[t-'A'];
	}

	cout<<ans<<endl;
	
	return 0;
}
