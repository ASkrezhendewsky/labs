#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	int n, i, maxIndx, minIndx;
	float sum = 0.0, nsum = 0.0, min , max;
	
	printf("Enter n ");
	scanf("%d",&n);
	//float a[n];
	
	float *a;
	if (!(a=(float*)calloc(n,sizeof(float)))) 
	{
		puts("Not enough memory"); 
		getch();
		return; 
	}
	
	for(i = 0;i < n;i++)
	{
		*(a+i) = (-10 + rand() % 20)/10.0; 
	}
	for(i = 0;i < n;i++)
	{
		printf("*(a+%d) = %f\n",i,*(a+i));
		if(*(a+i) < 0)
		{
			nsum += *(a+i);
		}
	}
	
	for(i = 0;i < n;i++)
	{
		if(*(a+i) < min || i == 0)
		{
			min = *(a+i);
			minIndx = i;
		}
	}
	
	for(i = 0;i < n;i++)
	{
		if(*(a+i) > max || i == 0)
		{
			max = *(a+i);
			maxIndx = i;
		}
	}
	if(maxIndx < minIndx)
	{
		for(i = maxIndx;i < minIndx;i++)
		{
			sum += *(a+i);
		}
		printf("sum = %f\n",sum);
	}
	else
	{
		printf("Iposible colculate sum because maxIndx > minIndx\n");
	}

	
	printf("nsum = %f",nsum);
	
	
	free(a);
	return 0;
}
