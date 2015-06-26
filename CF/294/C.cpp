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

int n,m;

void slove()
{
	if(2*n-m<0 || 2*m-n<0)
	{
		cout<<max(min(n,m/2),min(m,n/2));
		cout<<endl;
		return;
	}

	cout<<(int)((n+m)/3.0)<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>n>>m;

	slove();
	
	return 0;
}
