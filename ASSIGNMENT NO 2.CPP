
/*************************************************************
Aim:-Implement of algorithm for determination of various entropies &
	mutual information of a given channel. Test various type of channel
	such as:
	a)Noise free channel
	b)deterministic channel
	c)binary symmetric channel
	d)noisy channel
***************************************************************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void loseless(int r, int c, float a[25][25]);
void deterministic(int r, int c, float a[25][25]);
void noiseless(int r, int c, float a[25][25]);
void bsc(int r, int c, float a[25][25]);
void main()
{
 clrscr();
 int ch;
 do
 {
 printf("\nMENU:\n1. Test for type of channel\n2. Determine entropies\n3. Exit");	
 printf("\nEnter your choice?\t");		//Accept user choice
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:			//Test for different tyoes of channels
	clrscr();
	int r,c,i,j;
	float a[25][25];
	printf("\nenter no of rows:");		//Get no of rows of channel matrix
	scanf("%d",&r);
	printf("\nenter no of columns:");	//Get no of cols of channel matrix
	scanf("%d",&c);
	printf("\nenter channel matrix(%d,%d)",r,c); //Get the channel matrix
	for(i=1;i<=r;i++)
	  for(j=1;j<=c;j++)
	   {
	    scanf("%f",&a[i][j]);
	   }
	printf("\n*******TESTING*********\n");
	loseless(r,c,a);			//test for loseless channel
	deterministic(r,c,a);			//test for determinstic channel
	noiseless(r,c,a);			//test for noiseless channel
	bsc(r,c,a);				//test for bsc channel
	break;				//case 1 ends
 case 2:			//Calculate entropies	
	clrscr();
	float p,m[10],e[10][10],f[10][10],y[10];
	printf("\nEnter no of inputs:\t");		//get no of inputs
	scanf("%f",&p);
	printf("\nEnter input probabilities p[x]:\n"); //get i/p probabilities
	for(i=1;i<=p;i++)
		scanf("%f",&m[i]);
	printf("\nEnter conditional probability matrix p[y/x]:\n");
	for(i=1;i<=p;i++)
	 for(j=1;j<=p;j++)
	 {
	 scanf("%f",&e[i][j]);		//get conditional matrix
	 }
	 printf("\nJoint probability matrix p[y,x] is:\n");
	 for(i=1;i<=p;i++)
	 {
	  for(j=1;j<=p;j++)
	  {
	   f[i][j]=e[i][j]*m[i];		//joint prob matrix= cond matrix*i/p prob matrix
	   printf("%f\t",f[i][j]);
	  }
	  printf("\n");
	 }
	printf("\nThe output probabilites p[y] are:\n");
	for(i=1;i<=p;i++)
	{
	y[i]=0;
	for(j=1;j<=p;j++)
	{
	 y[i]=y[i]+f[j][i];			//generate the o/p prob matrix
	}
	}
	for(i=1;i<=p;i++)
	{
	printf("%f\t",y[i]);
	}
	float sum,h,h1,s=0,g,d;
	for(i=1;i<=p;i++)
	sum=sum+m[i]*((log(1/m[i]))/log(2));	//calculate i/p entropy
	h=sum;
	printf("\nEntropy of input h[x] is:\t %f",h);
	sum=0;
	for(i=1;i<=p;i++)
	sum=sum+y[i]*((log(1/y[i]))/log(2));	//calculate o/p entropy
	h1=sum;
	printf("\n\nEntropy of output h[y] is:\t %f",h1);
	sum=0;
	for(i=1;i<=p;i++)
	{
	 for(j=1;j<=p;j++)
	 {
	  g=e[i][j];
	  sum=sum+f[i][j]*((log(1/g))/log(2));	//calulate cond entropy
	 }
	}
	s=sum;
	printf("\n\n Entrophy of conditional prob. matrix h[y/x] is: \t%f",s);
	d= h-s;				//calaculate channel information
	printf("\nEntrophy of info channel I[x,y] is:\t %f",d);
	break;
 }
 }while(ch!=3);
 getch();
}
void loseless(int r, int c, float a[25][25])
{
 int i,j;
 float ct=0,q=0;
 for(i=1;i<=c;i++)
  {
  for(j=1;j<=r;j++)
  {
  if(a[j][i]!=0)	//check whether element is non zero?
  ct++;		//if non zero, increment count
  }
  if(ct==1)		//for each col no of non zero elements=1
  {
  ct=0;	
  q++;		// if yes inc q
  }
  }
  if(q==c)		//no of non zero elements= no of columns
  printf("\nThis is loseless channel");
  else
  printf("\nThis is not a loseless channel");
}
void deterministic(int r, int c, float a[25][25])
{

 int i,j;
 float ct=0,q=0;
 for(i=1;i<=r;i++)
  {
  for(j=1;j<=c;j++)
  {
  if(a[i][j]!=0)	//check whether element is non zero?
  ct++;		//if non zero, increment count
  }
  if(ct==1)		//for each row no of non zero elements=1
  {
  ct=0;
  q++;		// if yes inc q
  }
  }
  if(q==r)		//no of non zero elements= no of rows
  printf("\nThis is deterministic channel");
  else
  printf("\nThis is not a deterministic channel");
}
void noiseless(int r, int c, float a[25][25])
{
 int i,j;
 float ct=0,q=0;
 if(r==c)		//check for symmetrical matrix?
  {
  for(i=1;i<=r;i++)
  {
  for(j=1;j<=c;j++)
  {
  if(i==j)		//check for identity matrix
  {
  if(a[i][j]!=0)
  ct++;
  }
  }
  if(ct==1)
  {
  ct=0;
  q++;
  }
  }
  if(q==r)
  printf("\nThis is noiseless channel");
  else
  printf("\nThis is not a noiseless channel");
  }
  else
  printf("\nThis is not a noiseless channel");
}
void bsc(int r, int c, float a[25][25])
{
 int i,j;
 float ct=0,q=0;
 if(r==2 & c==2)	//check for bsc 2 i/p's & 2 o/p's
  {
  for(i=1;i<=r;i++)
  {
   for(j=1;j<=c;j++)
   {
   ct=ct+a[i][j];	//add all elements in a row
   {
    if(ct==1)	//addition of rowwise elements==1
    {
    ct=0;
    q++;
    }
  }
  }
  }
  if(q==2)
	printf("\nThis is a BST channel");
  else
	printf("\nThis is not a BST channel");
  }
  else		//if not a 2*2 matrix display "not BSC channel"
	printf("\nThis is not a BST channel");
}

/***************OUTPUT*******************
MENU:
1. Test for type of channel
2. Determine entropies
3. Exit
Enter your  choice?		1

enter no of rows: 3
enter no of columns:5
enter channel matrix(3,5)
0.75	0.25	0	0	0
0	0	0.666	0.333	0
0	0	0	0	1
***********TESTING************
This is loseless channel
This is not a determinstic channel
This is not a noisless channel
This is not a BST channel

MENU:
1. Test for type of channel
2. Determine entropies
3. Exit
Enter your  choice?		1

enter no of rows:5
enter no of columns:5
enter channel matrix(5,5 )
1	0	0	0	0
0	1	0	0	0
0	0	1	0	0
0	0	0	1	0
0	0	0	0	1
***********TESTING************
This is loseless channel
This is deterministic channel
This is noiselss channel
This is not a BST channel

MENU:
1. Test for type of channel
2. Determine entropies
3. Exit
Enter your  choice?		2
------------------------------------------------------------------------
Enter no of inputs:	2
Enter input probabilites p[x]:
0.5	0.5

Enter conditional probability matrix p[y/x]:
0.7	0.3
0.4	0.6

Joint probability matrix p[y,x] is:
0.350000		0.150000
0.200000		0.300000

The output probabiliyes p[y] are:
0.550000		0.450000

Entropy of input h[x] is:	1.000000

Entropy of output h[y]is:	0.992774

Entropy of conditional prob. matrix h[y/x] is:	0.926121

Entropy of info channel I[x,y] is:		0.073879

MENU:
1. Test for type of channel
2. Determine entropies
3. Exit
Enter your  choice?		3
*/