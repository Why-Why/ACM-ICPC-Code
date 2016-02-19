#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

bool judge(char *name)
{
	int rem=-1;
	for(int i=0;name[i];++i)
		if(name[i]=='.')
			rem=i;

	if(rem==-1)
		return 0;

	if(strcmp("c",name+rem+1) && strcmp("cpp",name+rem+1) && strcmp("h",name+rem+1))
		return 0;

	return 1;
}

int count_file(char *name,int &num)
{
	if(judge(name)==0) return 0;

	cout<<name<<" : ";
	++num;

	freopen(name,"r",stdin);
	int t;
	int ret=0;

	while((t=getchar())!=-1)
		if(t=='\n')
			++ret;

	cout<<ret<<endl;
	fclose(stdin);
	return ret;
}

int count_dir(char *path,int &num)
{
	DIR *d;
	struct dirent * file;
	struct stat sb;
	char ts[256];
	int ret=0;

	if(!(d=opendir(path)))
	{
		cerr<<"Error Opendir "<<path<<endl;
		return 0;
	}

	while((file=readdir(d))!=0)
	{
		if(file->d_name[0]=='.')
			continue;
		strcpy(ts,path);
		strcat(ts,"/");
		strcat(ts,file->d_name);

		if(stat(ts,&sb)<0) continue;

		if(S_ISDIR(sb.st_mode))
			ret+=count_dir(ts,num);
		else
			ret+=count_file(ts,num);
	}

	return ret;
}

int main(int argc,char **argv)
{
	if(argc<2)
	{
		cout<<"Please give a paht.\n";
		return 1;
	}

	cout<<endl;
	int num=0;
	int ans=count_dir(argv[1],num);

	cout<<endl;
	cout<<"File number: "<<num<<endl;
	cout<<"Line number: "<<ans<<endl<<endl;

	return 0;
}
