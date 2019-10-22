
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
void main()
{
srand(time(0));
int n,i,j,initial,loc[10],mov[10],copy[10],temp,index[10],final,k,sum=0;
bool flag[10]={false};

n=rand()%10+1;
printf("total number  %d\n",n);

printf("the locations\n");
for(i=0;i<n;i++)
{
	loc[i]=rand()%150+1;
	copy[i]=loc[i];
	printf("%d  ",loc[i]);
}

for(i=0;i<n-1;i++)
{
	for(j=0;j<n-i-1;j++)
	{
		if(copy[j]>copy[j+1])
		{
			temp=copy[j];
			copy[j]=copy[j+1];
			copy[j+1]=temp;
		}
	}
}

initial=rand()%20+copy[0];
printf("\ninitial position  %d\n",initial);

final=rand()%20+copy[n-1];
printf("\nfinal position %d\n",final);


for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((loc[i]==copy[j])&&(flag[i]==false))
			{
				index[j]=i;
				flag[i]=true;
			}
		}
	}




printf("\n\n");

for(i=0;i<n;i++)
	{
		if((copy[i]<initial)&&(copy[i+1]>initial))
		{
			break;
		}
	}





for(j=i+1;j<n;j++)
{
	k=index[j];
	mov[k]=abs(copy[j]-initial);
	initial=copy[j];
}



k=index[0];
mov[k]=abs(final-initial+copy[0]);
initial=copy[0];


for(j=1;j<=i;j++)
{
	k=index[j];
	mov[k]=abs(copy[j]-initial);
	initial=copy[j];
}

for(i=0;i<n;i++)
{
	printf("%d\t\t%d\n",loc[i],mov[i]);
	sum+=mov[i];
}

printf("Total head movements = %d\n",sum);
}
