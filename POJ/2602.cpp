#include <stdio.h>

int a[1000006],b[1000006];
char s[1000006];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
	{
		getchar();
		a[i]=getchar()-'0';
		getchar();
		b[i]=getchar()-'0';
	}

	for(int i=N;i>=1;--i)
	{
		a[i]+=b[i];

		if(a[i]>=10)
		{
			a[i]-=10;
			++a[i-1];
		}

		s[i]=a[i]+'0';
	}

	puts(s+1);
	
	return 0;
}
