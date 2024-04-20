#include<stdio.h>
#include<stdlib.h>
int partitions[10];

void firstfit(int p_size,int p)
{
	int flag=0;
	for(int i=0;i<p;i++)
	{
		if(partitions[i]>=p_size)
		{
			printf("Process size %d - partition  %d\n",p_size,partitions[i]);
			partitions[i]-=p_size;
			flag=1;
			break;
		}
		else
			continue;
	}
	if(flag==0)
	{
		printf("Unable to allocate memory\n");
	}
}

void bestfit(int p_size,int p)
{
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<p-i-1;j++)
		{
			if(partitions[j]>partitions[j+1]){
				int p=partitions[j];
				partitions[j]=partitions[j+1];
				partitions[j+1]=p;
			}
		}
	}
	int flag=0;
	for(int i=0;i<p;i++)
	{
		if(partitions[i]>=p_size)
		{
			printf("Process size %d - partition  %d\n",p_size,partitions[i]);
			partitions[i]-=p_size;
			flag=1;
			break;
		}
		else
			continue;
	}
	if(flag==0)
	{
		printf("Unable to allocate memory\n");
	}
}
void worstfit(int p_size,int p)
{
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<p-i-1;j++)
		{
			if(partitions[j]<partitions[j+1]){
				int p=partitions[j];
				partitions[j]=partitions[j+1];
				partitions[j+1]=p;
			}
		}
	}
	int flag=0;
	for(int i=0;i<p;i++)
	{
		if(partitions[i]>=p_size)
		{
			printf("Process size %d - partition  %d\n",p_size,partitions[i]);
			partitions[i]-=p_size;
			flag=1;
			break;
		}
		else
			continue;
	}
	if(flag==0)
	{
		printf("Unable to allocate memory\n");
	}
}

int main()
{
	int c,n,p,val;
	do{
		printf("Enter\n1.First fit\n2.Best fit\n3.Worst fit\n4.Exit\n");
		scanf("%d",&c);
		if(c==4)
			break;
		printf("No. of partitions :");
		scanf("%d",&n);
		printf("Enter the partitions\n");
		for(int i=0;i<n;i++)
		{
			scanf("%d",&partitions[i]);
		}
		printf("No. of process :");
		scanf("%d",&p);
		
		switch(c)
		{
			case 1:
				for(int i=0;i<n;i++)
				{
					scanf("%d",&val);
					firstfit(val,p);
				}
				break;
			case 2:
				for(int i=0;i<n;i++)
				{
					scanf("%d",&val);
					bestfit(val,p);
				}
				break;
			case 3:
				for(int i=0;i<n;i++)
				{
					scanf("%d",&val);
					worstfit(val,p);
				}
				break;
		}
	}while(c!=4);
}
	
