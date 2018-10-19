
/**********************************************************
AIM:- Implementation of algorithm for
generation and evalution of variable length source coding using
Huffman coding and decoding
********************************************************/
#include<stdio.h>
#include<conio.h>
void main()
{
char r;
int  i,j,flag,k,n,y,h[10][10],a[10],m,l;
float sum,c[10][10],b[10][10],pos[10][10],x;
do
{
clrscr();
b1:printf("Enter no of symbols(k):\t ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
	c[i][j]=2;
	}
}
//input
printf("Enter probabilities p(k):\n");
for(i=0;i<n;i++)
{
scanf("%f",&b[i][0]);
}
sum=0.0;
for(i=0;i<n;i++)
	sum=sum+b[i][0];
if(sum=!1.0)
{
	printf("please enter correct probabilities\n");
	goto b1;
}

//for descending order
for(i=0;i<n;i++)
{
	for(j=0;j<n-1;j++)
	{
		if(b[j+1][0]>b[j][0])
		{
		x=b[j][0];
		b[j][0]=b[j+1][0];
		b[j+1][0]=x;
		}
	}
}
for(i=0;i<n-1;i++)
{
	x=b[n-i-1][i]+b[n-i-2][i];
	c[n-i-1][i]=1;
	c[n-i-2][i]=0;
	for(j=0;j<n-i;j++)
	{
		if(b[j][i]>=x)
		{
			b[j][i+1]=b[j][i];
			pos[j][i]=j;
			flag=1;
		}
		else
		{
			b[j][i+1]=x;
			pos[n-i-1][i]=j;
			pos[n-i-2][i]=j;
			flag=0;
			break;
		}
	}
	if(flag==0)
	{
		for(k=j;k<n-2-i;k++)
		{
			b[k+1][i+1]=b[k][i];
			pos[k][i]=k+1;
		}
	}
}
for(i=0;i<n;i++)
{
	y=i;
	for(j=0;j<n;j++)
	{
		h[i][j]=c[y][j];
		y=pos[y][j];
	}
}
printf("Huffman coded data\n");
for(i=0;i<n;i++)
{
	printf("%f=",b[i][0]);
	for(j=n-1;j>=0;j--)
	{
		if(h[i][j]!=2)
			printf("%d",h[i][j]);
	}
	printf("\n");
}

printf("\n-----------------\nDecoding\n-----------------\n");
printf("Enter no of bits:\n");
scanf("%d",&m);
printf("Enter bits:\n");
for(i=0;i<m;i++)
{
	scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
	k=0;
	for(j=n-1;j>=0;j--)
	{
		if(a[k]==0)
			l=1;
		else
			l=0;
		if(h[i][j]==a[k])
		{
			k++;
		}
		if(h[i][j]==l)
			k--;
	}
	if(k==m)
	{
		printf("Decoded symbol:%f\n",b[i][0]);
		break;
	}
}
printf("\nDo you want to continue?(y/n):\n");
scanf("%c",&r);
}while(r=='y');
getch();
}

/**********OUTPUT**************
Enter no of symbols(k):	7
Enter probabilities p(k):
0.2
0.2
0.1
0.1
0.1
0.1
0.1
0.1

Huffman coded data
0.200000=01
0.200000=000
0.100000=110
0.100000=111
0.100000=100
0.100000=101
0.100000=0010
0.100000=0011

-----------------
Decoding
-----------------
Enter no of bits:
3
Enter bits:
1 0 1
Decoded symbol:0.100000

Do you want to continue?(y/n):
n
*/
















                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

