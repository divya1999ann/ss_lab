#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int Available[10],Request[10], Max[10][10], Allocation[10][10],Need[10][10],i,j,Work[10],flag,count=0,count1=0,m,n,k,flag1,c;
	bool Finish[10];
	srand(time(0));
	n=rand()%10+1;
	printf("Total number of processes is %d\n",n);

	m=rand()%10+1;
	printf("Total number of resources is %d\n",m);

	printf("Available\n");

	for(i=0;i<m;i++)
	{
		Available[i]=rand()%10;
		Work[i]=Available[i];
		printf("%d ",Available[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			Max[i][j]=rand()%10;
			label:
			k=rand()%10;
			if(k<=Max[i][j])
				Allocation[i][j]=k;
			else
				goto label;
			Need[i][j]=Max[i][j]-Allocation[i][j];
		}
	}

	printf("\nMaximum\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		printf("%d ",Max[i][j]);
		}
		printf("\n");
	}

	printf("Allocation\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",Allocation[i][j]);
		}
		printf("\n");
	}

	printf("Need\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",Need[i][j]);
		}
		printf("\n");
	}
	printf("Request?(1/0)\n");
	scanf("%d",&c);

	if(c==1)
	{
		flag1=0;
		k=rand()%n;
		printf("Request is made by P%d\n",k);
		printf("Request\n");

		for(i=0;i<m;i++)
		{
			Request[i]=rand()%10;
			printf("%d ",Request[i]);
		}

		for(i=0;i<m;i++)
		{
			if(Request[i]>Need[k][i])
			{
				flag1=1;
				break;
			}
		}
		if(flag1==1)
			printf("Request is greater than need\n");
		else
		{
			for(i=0;i<m;i++)
			{
				if(Request[i]>Available[i])
				{
					flag1=1;
					break;
				}
			}
			if(flag1==1)
				printf("Resources are not available");
			else
			{
				for(i=0;i<m;i++)
				{
					Work[i]-=Request[i];
					Allocation[k][i]+=Request[i];
					Need[k][i]-=Request[i];
				}
			}

		}
	}

	for(i=0;i<n;i++)
	{
		Finish[i]=false;
	}

	while(count!=n)
	{
		for(i=0;i<n;i++)
		{
			flag=1;
			count1+=1;
			if(Finish[i]==false)
			{
				for(j=0;j<m;j++)
				{
					if(Need[i][j]>Work[j])
					{
						flag=0;
					}
				}	
				if(flag==1)
				{
					printf("Need of process P%d is",i);
					for(j=0;j<m;j++)
					{
						printf(" %d ",Need[i][j]);
					}

					printf("\nAnd is less than available resources");
					for(j=0;j<m;j++)
					{
						printf(" %d ",Work[j]);
					}
					printf("\n");
					count+=1;

					for(j=0;j<m;j++)
					{
						Work[j]+=Allocation[i][j];
						Finish[i]=true;
					}
				}
			}
		}
	if(count!=n && count1>n)
	{
		count1=0;
		break;
	}
	}

if(count1==0)
printf("\nUnsafe\n");
}
