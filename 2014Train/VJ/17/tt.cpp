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

	int cou=0;
	int a=12345678;

	while(cou<=100000000)
	{
		++cou;
		a=(a+1)%(a-1);
	}

	cout<<(double)clock()/CLOCKS_PER_SEC<<endl;

	cout<<cou<<endl;
	
	return 0;
}
