#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *file1,*file2;
	char fileA[100],fileB[100];
	printf("Enter the filenames\n");
	scanf("%s%s",fileA,fileB);
	file1=fopen(fileA,"r");
	file2=fopen(fileB,"r");
	if(file1==NULL||file2==NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	int line_num=0;
	char line1[100],line2[100];
	while(fgets(line1,sizeof(line1),file1)!=NULL&&fgets(line2,sizeof(line2),file2)!=NULL)
	{
		line_num++;
		if(strcmp(line1,line2)!=0)
		{
		printf("Difference at line %d\n",line_num);
		printf("File1: %s\n",line1);
		printf("File2: %s\n",line2);
		}
	}
	while(fgets(line1,sizeof(line1),file1)!=NULL)
	{
		printf("Extra line in file1\n");
		printf("File1: %s",line1);
	}
	while(fgets(line2,sizeof(line2),file2)!=NULL)
	{
		printf("Extra line in file2\n");
		printf("File2: %s",line2);
	}
	fclose(file1);
	fclose(file2);
}
