#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define N 100
int main()
{
	char input[N];
	printf("Enter a command\n");
	scanf("%s",input);
	while(strcmp(input,"stop")!=0)
	{
		int a=fork();
		if(a==-1)
		{
			printf("Fork impossible\n");
			exit(1);
		}
		
		if(a==0)
		{
			printf("a\n");
			if(execlp(input,"",NULL))
			{
				printf("Error exec\n");
				exit(0);
			}
			exit(1);
		}
		wait(0);
		printf("Enter a command\n");
		scanf("%s",input);
	}
}
