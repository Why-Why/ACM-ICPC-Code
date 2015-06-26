#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n,m;

	while(~scanf("%d %d",&n,&m))
	{
		printf("%d\n",(m-1)%n);
	}

	return 0;
}
