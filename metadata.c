#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main()
{
	char file_name[100];
	struct stat filestat;
	printf("Enter the file name\n");
	scanf("%s",file_name);
	if(stat(file_name,&filestat)<0)
	{
		printf("Error\n");
		exit(1);
	}
	printf("\nFilesize: %ld bytes\n",filestat.st_size);
	printf("Permissions\n");
	if(filestat.st_mode&R_OK)
		printf("Read");
		
	if(filestat.st_mode&W_OK)
	{
		printf("Write");
	}	
	
	if(filestat.st_mode&X_OK)
	{
		printf("Exexcute\n");
	}
	printf("\n");
	printf("Creation time: %s",ctime(&filestat.st_ctime));
	printf("Modification time: %s",ctime(&filestat.st_mtime));
	printf("Last access time: %s",ctime(&filestat.st_atime));
}