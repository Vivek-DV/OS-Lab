#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int even_sum=0,odd_sum=0,i;
	pid_t pid=fork();
	if(pid<0)
	{
		printf("Fork failed\n");
		return 1;
	}
	else if(pid==0)
	{
		for(i=2;i<=1000;i+=2)
		{
		even_sum+=i;
		}
		printf("Sum of even numbers: %d\n",even_sum);
	}
	else
	{
		for(i=1;i<=1000;i+=2)
		{
		odd_sum+=i;
		}
		printf("Sum of odd numbers: %d\n",odd_sum);
		wait(NULL);
	}
}
