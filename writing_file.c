#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *fptr1,*fptr2;
  char file1name[100],c,file2name[100];
  printf("enter the filename to open for reading\n");
  scanf("%s",file1name);
  fptr1=fopen(file1name,"r");
  if(fptr1==NULL)
  {
    printf("cannot open file %s\n",file1name);
    exit(0);
  }
    printf("enter the filename to open for writing \n");
    scanf("%s",file2name);
    fptr2=fopen(file2name,"w");
    if(fptr2==NULL)
	{
		printf("Can't open the file %s\n",file2name);
		exit (0);
	}
	c=fgetc(fptr1);
	while(c!=EOF)
	{
		fputc(c,fptr2);
		c=fgetc(fptr1);
	}
	printf("Successfully wrote the contents to '%s' from '%s'\n",file2name,file1name);
	
	if(ferror(fptr1))
	{
		printf("Error reading from source file\n");
	}
	if(ferror(fptr2))
	{
		printf("Error writing to source file\n");
	}
	fclose(fptr1);
	fclose(fptr2);
}
