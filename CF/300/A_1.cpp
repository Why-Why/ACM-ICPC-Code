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

char s1[200];
char s2[]="CODEFORCES";
int len1,len2;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>s1;

	len1=strlen(s1);
	len2=strlen(s2);

	int qian=0,hou=0;

	for(qian=0;qian<len1 && qian<len2;++qian)
		if(s1[qian]!=s2[qian])
			break;

	for(hou=0;hou<len2 && hou<len1;++hou)
		if(s1[len1-1-hou]!=s2[len2-1-hou])
			break;
	if(qian+hou>=len2 && len2<=len1)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	
	return 0;
}
