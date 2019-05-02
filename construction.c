#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void construction(int m, int p, int q, int r, float *input, float **T, float **V)
{
	int i,j;
	float sum;
	printf("p=%d,q=%d,r=%d\n",p,q,r);
	for(i=0;i<m;i++)
		T[i][p-1]=input[i];
	if(p==q)
	{
		for(i=0;i<m;i++)
		{
			sum=0;
			for(j=0;j<q;j++)
				sum=sum+T[i][j];
			sum=sum/q;
			V[i][r-1]=sum;
		}
	}

}
