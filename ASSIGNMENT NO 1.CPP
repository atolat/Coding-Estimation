
/****************************************************************
Aim:- Write a menu driven program using C language for following bits:
	1. Addition of matrices
	2.Subtraction of matrices
	3.Muiltplication of matrices
	4. Scalar division
	5.Inverse
****************************************************************/
#include<stdio.h>
#include<conio.h>
#define max 100
void add(int a[max][max],int b[max][max],int r1,int c1,int r2,int c2) ;
void sub(int a[max][max],int b[max][max],int r1,int c1,int r2,int c2);
void mul(int a[max][max],int b[max][max], int r1,int c1,int r2,int c2) ;
void div(int a[max][max],int b[max][max],int r1,int c1,int r2,int c2)  ;
void inverse();
void main()
{
	int a[max][max],b[max][max],ch,r1,r2,c1,c2,i,k,j,sum;
	clrscr();
	printf("Enter size of matrix A:\n");
	printf("Enter no of rows(r1):\n");
	scanf("%d",&r1);
	printf("Enter no of columns(c1):\n");
	scanf("%d",&c1);
	printf("\nEnter matrix A(%d*%d):\n",r1,c1);
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
	printf("Enter size of matrix B:\n");
	printf("Enter no of rows(r2):\n");
	scanf("%d",&r2);
	printf("Enter no of columns(c2):\n");
	scanf("%d",&c2);
	printf("\nEnter matrix B(%d*%d):\n",r2,c2);
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
		scanf("%d",&b[i][j]);
		}
	}
	do
	{
		printf("\n MENU:\n1.Addition\n2.Subtration\n3.Multiplication\n4.Division\n5.Inverse\n6.Exit");
		printf("\nEnter your choice:\t");
		printf("\n\n******************************************\n");
		scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		add(a,b,r1,c1,r2,c2);
		break;
	case 2:
		sub(a,b,r1,c1,r2,c2);
		break;
	case 3:
		mul(a,b,r1,c1,r2,c2);
		break;
	case 4:
		div(a,b,r1,c1,r2,c2);
		break;
	case 5:
		inverse();
		break;
	}
	}while(ch!=6);
	getch();
}
void add(int a[max][max],int b[max][max],int r1,int c1,int r2,int c2)
{
  int i,j,c[max][max];
  if(r1==r2 && c1==c2)
  {
  printf("\nAddition of matrices is:\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
			c[i][j]=a[i][j]+b[i][j];
			printf("%d \t",c[i][j]);
			}
			printf("\n");
		}
	}
    else
	printf("\naddition operation not valid for this case");
}
void sub(int a[max][max],int b[max][max],int r1,int c1,int r2,int c2)
{
  int i,j,c[max][max];
  if(r1==r2 && c1==c2)
  {
  printf("\nSubtraction of matrices is:\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
			c[i][j]=a[i][j]-b[i][j];
			printf("%d \t",c[i][j]);
			}
			printf("\n");
		}
	}
    else
	printf("\nsubtraction operation not valid for this case");
}
void mul(int a[max][max],int b[max][max],int r1,int c1,int r2,int c2)
{
	int i,j,k,sum,c[max][max];
	if(r1==r2 && c1==c2 || c1==r2)
	{
		for(i=0;i<r1;i++)
		{
			for(k=0;k<r1;k++)
			{
			sum=0;
				for(j=0;j<c1;j++)
				{
					sum=sum+a[i][j]*b[j][k];
				}
				c[i][k]=sum;
			}
		}
		printf("\nMultiplication of matrices is:\n");
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				printf("%d \t",c[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("\nmultiplication operation is not valid for this case");
	}
}
void div(int a[max][max],int b[max][max],int r1,int c1,int r2,int c2)
{

	int i,j,n,c[max][max],k[max][max],op;
	printf("\nEnter scalar factor for division:\t");
	scanf("%d",&n);
	printf("\nWhich matrix do you want for scalar division:\n1.MAT A\n2.MAT B");
	printf("\nEnter your choice:\t");
	scanf("%d",&op);
	switch(op)
	{
	case 1:
		printf("\nScalar division output is:\n");
		for(i=0;i<r1;i++)
		{
		 for(j=0;j<c1;j++)
		  {
		   c[i][j]=a[i][j]/n;
		   printf("%d \t",c[i][j]);
		  }
		printf("\n");
		}
		break;
	case 2:
		printf("\nScalar division output is:\n");
		for(i=0;i<r2;i++)
		{
		 for(j=0;j<c2;j++)
		  {
		   k[i][j]=b[i][j]/n;
		   printf("%d \t",k[i][j]);
		  }
		  printf("/n");
		}
		break;
	default:
		printf("\nenter valid choice:");
		break;
	}
}
void inverse()
{
	int i,j,a[max][max];
	float c[3][3],d,k[max][max];
	printf("\nEnter only 3*3 matrix:");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
	d=c[0][0]*(c[1][1]*c[2][2]-c[1][2]*c[2][1])-c[0][1]*(c[1][0]*c[2][2]-c[2][0]*c[1][2])+c[0][2]*(c[1][0]*c[2][1]-c[2][0]*c[1][1]);
	if(d>0)
	{
	d=d;
	}
	else
	{
	d=-d;
	}
	k[0][0]=c[1][1]*c[2][2]-c[2][1]*c[1][2];
	k[0][1]=-(c[1][0]*c[2][2]-c[2][0]*c[1][2]);
	k[0][2]=c[1][0]*c[2][1]-c[2][0]*c[1][1];
	k[1][0]=-(c[0][1]*c[2][2]-c[2][1]*c[0][2]);
	k[1][1]=c[0][0]*c[2][2]-c[2][0]*c[0][2];
	k[1][2]=-(c[0][0]*c[1][2]-c[2][0]*c[0][1]);
	k[2][0]=c[0][1]*c[1][2]-c[1][1]*c[0][2];
	k[2][1]=-(c[0][0]*c[1][2]-c[1][0]*c[0][2]);
	k[2][2]=c[0][0]*c[1][1]-c[1][0]*c[0][1];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		k[i][j]=k[j][i];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			k[i][j]=k[i][j]/d;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d \t",k[i][j]);
		}
		printf("\n");
	}
}

/*************OUTPUT*************
Enter size of matrix A:
Enter no of rows(r1):
4
Enter no of columns(c1):
3

Enter matrix A(4*3):
4	2	2	3
2	1	3	2
2	2	6	5
Enter size of matrix B:
Enter no of rows(r2):
3
Enter no of columns(c2):
3

Enter matrix B(3*3):
1	2	1
2	2	3
2	3	1

MENU:
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Inverse
6.Exit
Enter your choice:	1

*****************************************
addition operation not valid for this case

MENU:
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Inverse
6.Exit
Enter your choice:3

*****************************************
Multiplication of matrices is:
12	18	12
9	13	10
11	16	11

MENU:
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Inverse
6.Exit
Enter your choice: 	4

******************************************
Enter scalar factor for division:	2

Which matrix do you want for scalar division:
1. MAT A
2. MAT B
Enter your choice: 	1

Scalar division output is:
2	1	1
1	1	0
1	1	1
1	3	2

MENU:
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Inverse
6.Exit
Enter your choice:	6
*/

