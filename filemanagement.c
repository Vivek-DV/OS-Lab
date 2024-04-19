#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define NUM_FILES 3
int files[NUM_FILES];
void cleanup()
{
	for(int i=0;i<NUM_FILES;i++)
	{
		if(files[i]!=-1)
		{
			close(files[i]);
		}
	}
}

int main()
{
	files[0]=open("file1.txt",O_RDONLY);
	files[1]=open("file2.txt",O_WRONLY|O_CREATE|O_TRUNC,S_IRUSR|S_IWUSR);
	files[2]=open("file3.txt",O_WRONLY|O_CREATE|O_TRUNC,S_IRUSR|S_IWUSR);
	for(int i=0;i<NUM_FILES;i++)
	{
		if(files[i]==-1)
		{
			printf("Error opening file\n");
			cleanup();
			exit(1);
		}
	}
	atexit(cleanup);
}
