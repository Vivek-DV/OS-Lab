#include<stdio.h>
#include<string.h>
#include<dirent.h>

void listFiles(char *basePath)
{
	char path[1000];
	struct dirent *dp;
	DIR *dir=opendir(basePath);
	if(!dir)
	{
		return;
	}
	while((dp=readdir(dir))!=NULL)
	{
		if((strcmp(dp->d_name,".")!=0)&&(strcmp(dp->d_name,"..")!=0))
		{
			printf("Files:\n");
			printf("%s\n",dp->d_name);
			strcpy(path,basePath);
			strcat(path,"");
			strcat(path,dp->d_name);
			listFiles(path);
		}
	}
	closedir(dir);
}

int main()
{
	char path[1000];
	printf("Enter the path to files: \n");
	scanf("%s",path);
	listFiles(path);
}
