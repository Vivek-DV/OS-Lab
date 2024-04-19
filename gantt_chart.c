#include<stdio.h>

struct process{
	int id,at,bt,ct,tat;
}p[10];

void read(int n)
{
	for(int i=0;i<n;i++)
	{
		printf("Enter ID, AT and BT of process %d\n",i+1);
		scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
	}
}

void printGcFCFS(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				struct process p1=p[j];
				p[j]=p[j+1];
				p[j+1]=p1;
			}
		}
	}

	int current=p[0].at;
	printf("Gantt chart for FCFS\n");
	printf("|");
	for(int i=0;i<n;i++)
	{
		printf(" P%d |",p[i].id);
		p[i].ct=current;
		current+=p[i].bt;
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d    ",p[i].ct);
	}
	printf("%d",current);
	printf("\n");
}

void printGcSJF(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].bt>p[j+1].bt)
			{
				struct process p1=p[j];
				p[j]=p[j+1];
				p[j+1]=p1;
			}
		}
	}
	
	int current=p[0].at;
	printf("Gantt chart for SJF\n");
	printf("|");
	for(int i=0;i<n;i++)
	{
		printf(" P%d |",p[i].id);
		p[i].ct=current;
		current+=p[i].bt;
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d    ",p[i].ct);
	}
	printf("%d",current);
	printf("\n");
}													

int main()
{
	int n;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	read(n);
	printGcFCFS(n);
	printGcSJF(n);
}