#include<iostream>
#include<cstring>

using namespace std;

long long getans(long long h,long long n,bool type)
{
	if(h==0)
		return 1;
	if((1LL<<(h-1))>=n)
	{
		if(type==0)
			return getans(h-1,n,1)+1;
		else
			return (1LL<<h)-1+1+getans(h-1,n,1);
	}
	else
	{
		if(type==0)
			return (1LL<<h)-1+1+getans(h-1,n-(1LL<<(h-1)),0);
		else
			return 1LL+getans(h-1,n-(1LL<<(h-1)),0);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	long long h,n;

	cin>>h>>n;

	cout<<getans(h,n,0)-1<<endl;

	return 0;
}
