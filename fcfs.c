#include<stdio.h>
struct process{
	int id,at,bt,tat,wt,ct;
}arr[10];

void read(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter the id,arrival time and burst time of process %d\n",i+1);
		scanf("%d%d%d",&arr[i].id,&arr[i].at,&arr[i].bt);
	}
}

void sort(int n)
{
	struct process p;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j].at>arr[j+1].at)
			{
				p=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=p;
			}
		}
	}
}

void FCFS(int n)
{
	int tbt=0;
	float twt=0,ttat=0;
	arr[0].wt=0;
	arr[0].ct=arr[0].at+arr[0].bt;
	arr[0].tat=arr[0].wt+arr[0].bt;
	ttat+=arr[0].tat;
	tbt+=arr[0].bt;
	for(int i=1;i<n;i++)
	{
		arr[i].wt=tbt-arr[i].at;
		arr[i].tat=arr[i].bt+arr[i].wt;
		arr[i].ct=arr[i].bt+arr[i].wt+arr[i].at;
		tbt+=arr[i].bt;
		ttat+=arr[i].tat;
		twt+=arr[i].wt;
	}
	float avg_wt=twt/n,avg_tat=ttat/n;
	printf("Average waiting time: %f\nAverage turn around time: %f\n",avg_wt,avg_tat);
	
}

int main()
{
	int n;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	read(n);
	sort(n);
	FCFS(n);
	printf("ID\tAT\tBT\tCT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].id,arr[i].at,arr[i].bt,arr[i].ct,arr[i].wt,arr[i].tat);
	}
}
