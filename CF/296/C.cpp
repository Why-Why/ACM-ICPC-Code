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

multiset <int> Sh1,Sh2,Sw1,Sw2;
multiset <int> ::iterator iter,iter1;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int w,h,n;
	char c[10];
	int t;
	int temp;

	scanf("%d %d %d",&w,&h,&n);

	Sh1.insert(0);
	Sh1.insert(h);
	Sw1.insert(0);
	Sw1.insert(w);

	Sh2.insert(h);
	Sw2.insert(w);

	while(n--)
	{
		scanf("%s %d",c,&t);

		//cout<<*Sh2.rbegin()<<endl;

		if(c[0]=='H')
		{
			Sh1.insert(t);
			iter=Sh1.find(t);
			iter++;
			temp=*iter;
			iter--;
			iter--;
			temp=temp-*iter;

			iter1=Sh2.find(temp);

			Sh2.erase(iter1);
			Sh2.insert(t-*iter);
			iter++;
			iter++;
			Sh2.insert(*iter-t);
		}
		else
		{
			Sw1.insert(t);
			iter=Sw1.find(t);

			iter++;
			temp=*iter;
			iter--;
			iter--;
			temp=temp-*iter;

//			cout<<"@"<<temp<<endl;

			iter1=Sw2.find(temp);

			Sw2.erase(iter1);
			Sw2.insert(t-*iter);
			iter++;
			iter++;
			Sw2.insert(*iter-t);
		}

	//	temp=*Sh2.rbegin();
	//	cout<<temp<<' ';
	//	temp=*Sw2.rbegin();
	//	cout<<temp<<endl;
//		cout<<Sh2.rbegin()<<endl<<Sw2.rbegin()<<endl;

		cout<<((long long)(*Sh2.rbegin()))*(*Sw2.rbegin())<<endl;
	}

	return 0;
}
