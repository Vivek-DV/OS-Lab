#include<stdio.h>
#define b 3
#define a 5
//a is MAX_P
//b is MAX_R
int need[a][b];
int avail[b];
int allo[a][b];
int finish[a];

int isSafe()
{
	int work[b];
	for(int i=0;i<b;i++)
		work[i]=avail[i];
		
	for(int i=0;i<a;i++){
		if(finish[i]==0){
			int j;
			for(j=0;j<b;j++){
				if(need[i][j]>work[j])
					break;
			}
			if(j==b){
				for(int k=0;k<b;k++)
					work[k]+=allo[i][k];
				finish[i]=1;
				i=-1;	
			}
		}
	}
	
	for(int i=0;i<a;i++){
		if(finish[i]==0)
			return 0;
	}
	return 1;	
}

int main(){
	int i,j;
	printf("Enter the allocation matrix:\n");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%d",&allo[i][j]);
		}
	}
	
	printf("Enter the need matrix:\n");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			scanf("%d",&need[i][j]);
		}
	}
	
	printf("Enter the available matrix:\n");
	for(i=0;i<b;i++)
	{
		scanf("%d",&avail[i]);
	}
	
	if(isSafe()==1)
	{
		printf("System in safe state.\n");
	}
	else
	{
		printf("System in unsafe state.\n");
	}
	return 0;
}
