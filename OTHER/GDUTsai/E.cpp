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
	
	ios::sync_with_stdio(false);

	int T;
	long long v,d;

	cin>>T;

	while(T--)
	{
		cin>>v>>d;

		if(v*v/10<d)
			cout<<"Retreat\n";
		else
			cout<<"Fire\n";
	}

	return 0;
}
