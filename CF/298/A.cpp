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

int n;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;

	scanf("%d",&n);

	if(n==1 || n==2)
		cout<<1<<endl<<1<<endl;
	else if(n==3)
		cout<<2<<endl<<1<<' '<<3<<endl;
	else
	{
		cout<<n<<endl;
		
		temp=n;

		cout<<2;

		if(n&1)
		{
			for(int i=n-1;i>2;i-=2)
				cout<<' '<<i;

			for(int i=1;i<=n;i+=2)
				cout<<' '<<i;

			cout<<endl;
		}
		else
		{
			for(int i=n;i>2;i-=2)
				cout<<' '<<i;
			for(int i=1;i<=n;i+=2)
				cout<<' '<<i;

			cout<<endl;
		}
	}
	
	return 0;
}
