#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int N, i, j;
	int sum = 0, oldsum = 0;
	printf("Enter N ");
	scanf("%d",&N);
	float a[N][N];
	
	int ok;
	printf("Create matrix by:\n1 - random\n2 - from console ");
	scanf("%d",&ok);
	switch (ok)
	{
		case 1:
			for(i = 0;i < N;i++)
			{
				for(j = 0;j < N;j++)
				{
					a[i][j] = -10 + rand() %20; 
				}
			}
		break;
		case 2:
			for(i = 0;i < N;i++)
			{
				for(j = 0;j < N;j++)
				{
					printf("Enter element: i = %d, j = %d ",i,j);
					scanf("%f",&a[i][j]);
				}
			}
		break;
		default:
			for(i = 0;i < N;i++)
			{
				for(j = 0;j < N;j++)
				{
					a[i][j] = -10 + rand() %20; 
				}
			}
		break;
	}
	
	for(i = 0;i < N;i++)
	{
		for(j = 0;j < N;j++)
		{
			printf("%.2f\t",a[i][j]);
		}
		printf("\n\n");
	}
	
	for(i = 0;i < N;i++)
	{
		sum = 0;
		for(j = 0;j < N;j++)
		{
			sum += a[i][j];
		}
		if(i == 0)
		{
			oldsum = sum;
		}
		if(oldsum != sum)
		{
			printf("This is not a magic square  ");
			return 0;
		}
	}
	
	for(i = 0;i < N;i++)
	{
		sum = 0;
		for(j = 0;j < N;j++)
		{
			sum += a[j][i];
		}
		if(i == 0)
		{
			oldsum = sum;
		}
		if(oldsum != sum)
		{
			printf("This is not a magic square  ");
			return 0;
		}
	}
	sum = 0;
	for(i = 0;i < N;i++)
	{
		sum += a[i][i];
	}
	if(oldsum != sum)
	{
		printf("This is not a magic square  ");
		return 0;
	}
	sum = 0;
	for(i = 0;i < N;i++)
	{
		sum += a[N-i-1][i];
	}
	if(oldsum != sum)
	{
		printf("This is not a magic square  ");
		return 0;
	}
	
	printf("This is a magic square");
	return 0;
}
