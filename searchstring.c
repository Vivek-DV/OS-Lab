#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *file;
	char filename[100],pattern[100];
	printf("Enter the filename\n");
	scanf("%s",filename);
	printf("Enter the pattern\n");
	scanf("%s",pattern);
	file=fopen(filename,"r");
	if(file==NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	char line[100];
	int line_no=0;
	while(fgets(line,sizeof(line),file)!=NULL)
	{
		line_no++;
		if(strstr(line,pattern)!=NULL)
		{
		printf("Line %d: %s \n",line_no,line);
		}
	}
}
