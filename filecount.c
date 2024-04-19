#include<stdio.h>
int main()
{
	FILE *file;
	char filename[100],ch;
	int lines=0,words=0,characters=0;
	printf("Enter the filename\n");
	scanf("%s",filename);
	file=fopen(filename,"r");
	if(file==NULL)
	{
		printf("File not found\n");
		return 1;
	}
	while((ch=fgetc(file))!=EOF)
	{
		characters++;
		if(ch==' '||ch=='\t'||ch=='\n'||ch=='\r')
		{
			words++;
			if(ch=='\n')
			{
			
			lines++;
			}
		}
	}
		
	fclose(file);
	printf("Character count: %d\n",characters);
	printf("Line count: %d\n",lines);
	printf("Words count: %d\n",words);
}
