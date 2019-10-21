#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	srand(time(0));
	int i,n,init,seektime[10],request[10], total=0;
	n=rand()%10+1;
	printf("Number of requests : %d\n",n);
	printf("Requests\n");
	for(i=0;i<n;i++)
	{
		request[i]=rand()%200;
		printf("%d ",request[i]);
	}
	init=rand()%200;
	printf("\nHead is initially at %d\n",init);
	seektime[0]=abs(init - request[0]);
	for(int i=1;i<n;i++)
	{
		seektime[i]=abs(request[i-1]-request[i]);
	}
	printf("Seektime\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",seektime[i]);
		total+=seektime[i];
	}
	printf("\nTotal time taken : %d\n",total);
}

