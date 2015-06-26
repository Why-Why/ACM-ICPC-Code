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

int v1,v2,t,d;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>v1>>v2>>t>>d;

	long long ans=v1+v2;

	for(int i=2;i<t;++i)
		ans+=min(d*(t-i)+v2,d*(i-1)+v1);

	cout<<ans<<endl;
	
	return 0;
}
