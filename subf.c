#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <lapacke.h>
#include <cblas.h>
#include <svd.h>
#include <matrixmul.h>
#include <xnorm.h>

float subf(int n,int t,int t1, float *input, float **output)
{
	int i,j,l,nnn=t1;
	float sum=0,sum1=0,x,norm;
	printf("t=%d,t1=%d",t,t1);
	if(t==t1)
	{
		float **basis,**u, **s, **v, **s1, **v1, **MMM;
		basis=(float **)malloc(n*sizeof(float *));
		u=(float **)malloc(n*sizeof(float *));
		s=(float **)malloc(n*sizeof(float *));
		v=(float **)malloc(nnn*sizeof(float *));
		for (i=0;i<n;i++)
		{
			basis[i]=(float *)calloc(nnn,sizeof(float));
			u[i]=(float *)calloc(n,sizeof(float));
			s[i]=(float *)calloc(nnn,sizeof(float));
		}
		for(i=0;i<nnn;i++)
			v[i]=(float *)calloc(nnn,sizeof(float));
		for (i=0;i<n;i++)
			for(j=0;j<nnn;j++)
				basis[i][j]=output[i][j];
		svd(n,nnn,basis,u,s,v);


		printf("%d\n",t1);
		s1=(float **)malloc(n*sizeof(float *));
		v1=(float **)malloc(nnn*sizeof(float *));
		MMM=(float **)malloc(n*sizeof(float *));
		for(i=0;i<n;i++)
		{
			s1[i]=(float *)calloc(nnn,sizeof(float));
			MMM[i]=(float *)calloc(nnn,sizeof(float));
		}
		for(i=0;i<nnn;i++)
			v1[i]=(float *)calloc(nnn,sizeof(float));
		for(i=0;i<n;i++)
			for(j=0;j<nnn;j++)
			{
				
				s1[i][j]=s[i][j];
			}
		for (i=0;i<nnn;i++)
			for(j=0;j<nnn;j++)
			{
				
	       			v1[i][j]=v[i][j];
			}
		matrixmul(n,n,nnn,u,s,MMM);
		matrixmul(n,nnn,nnn,MMM,v,basis);

		for (i=0;i<nnn;i++)
			free(v1[i]);
		for(i=0;i<n;i++)
		{
			free(MMM[i]);
			free(s1[i]);
		}
		free(MMM);
		free(v1);
		free(s1);
		for(i=0;i<nnn;i++)
			free(v[i]);
		for(i=0;i<n;i++)
		{
			free(s[i]);
			free(u[i]);
			free(basis[i]);
		}
		free(v);
		free(s);
		free(u);
		free(basis);


	}
	printf("111111\n");
	if(t>t1)
	{
		for(i=0;i<nnn;i++)
		{
			sum=xnorm(input,output,i,n);
			if((i==0 || sum<sum1) && sum>0)
				sum1=sum; 
		}

		norm=sum1;
	
	printf("norm=%e\n",norm);
	}


}


