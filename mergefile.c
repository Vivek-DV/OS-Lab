#include<stdio.h>
#include<stdlib.h>

void merge(int num,char filename[][100],char* output){
	FILE* Output=fopen(output,"w");
	if(Output==NULL){
		printf("Error opening file\n");
		exit(1);
	}
	for(int i=0;i<num;i++)
	{
	FILE* input=fopen(filename[i],"r");
	if(input==NULL)
	{
	printf("Error opening file: %s\n",filename[i]);
	continue;
	}
	
	char ch;
	while((ch=fgetc(input))!=EOF)
	{
		fputc(ch,Output);
	}
	fclose(input);
	}
	fclose(Output);
}

int main(){
	int num;
	printf("Enter number of files\n");
	scanf("%d",&num);
	char filename[num][100];
	for(int i=0;i<num;i++)
	{
		printf("Enter filenames\n");
		scanf("%s",filename[i]);
	}
	char output[100];
	printf("Enter the output filename\n");
	scanf("%s",output);
	merge(num,filename,output);
	printf("Successfully merged into %s\n",output);
}