//Aim:- Implement encoding and decoding of linear block code
#include<stdio.h>
#include<conio.h>
#include<math.h>
void message();
void decode();
int xor(int a,int b)		//xor function
{
 if(a==b)
 return(0);
 else
 return(1);
}
 int p[10][10],g[10][10],h[10][10],e[10][10],s1[10][10],s2[10],r[10],i,j,n,k,t,q;
 int m[10],c[10],w,l=0,d[10],ch;
void main()
{
 clrscr();
 printf("\rEnter block length(n): \n");
 scanf("%d",&n);		//enter block length 'n'
 printf("Enter no of msg bits(k):\n");
 scanf("%d",&k);		//enter no of msg bits 'k'
 t=pow(2,k);		//calculate 2^k
 q=n-k;			//calculate q
 printf("\nTherefore no of parity bits(q) are: \n%d",q);
 printf("\nTherefore linear block code is:\t(%d,%d)",n,k);
 for(i=1;i<=k;i++)		//construct identity matrix [Ik]k*k
 {
  for(j=1;j<=k;j++)
   {
    if(i==j)
    g[i][j]=1;
    else
    g[i][j]=0;
   }
 }
 printf("\nEnter parity matrix transpose:\n");
 for(i=k+1;i<=n;i++)
 {
  for(j=1;j<=k;j++)
  {
   scanf("%d",&g[j][i]);		//get parity matrix
  }
 }
 printf("\nGENERATOR MATRIX IS:-\n");
 for(i=1;i<=k;i++)
 {
  printf("\n");
  for(j=1;j<=n;j++)
  printf("\t%d",g[i][j]);		//[G]=[I]*[P]
 }
 do
 {
 printf("\nMENU: \n1.Encoding \n2.Decoding \n3.Exit");
 printf("\nEnter your choice?");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("\nEnter");
 printf("\n----------------------------------------------\n msg vector\t codeword \t\td\n----------------------------------------------\n");
 for(i=1;i<=t;i++)
  {
  for(j=1;j<=k;j++)
  scanf("%d",&m[j]);		//get all possible msg combinations
  message();		//encode message
  }
 break;			//case 1 ends
 case 2:
	 decode();		//decode message
	 break;		//case 2 ends
 }
 }while(ch!=3);
 getch();
}
void message()
{
 int a,i,j,f,p;
 for(i=1;i<=n;i++)
 {
  c[i]=0;
  for(j=1;j<=k;j++)
  {
   a=m[j]*g[j][i];
   c[i]=xor(c[i],a);		//checkbit[C]=[M][P]
  }
 }
 w=0;
 printf("\t\t");
 for(i=1;i<=n;i++)
 {
  printf("%2d",c[i]);		//print 'n' bit codeword
  if(c[i]==1)			//calculate hamming distance
  w++;
 }
 d[l]=w;
 printf("\t\t %d",w);
 m[j]++;
 printf("\n");
}
void decode()
{
 int i,j,f,a,b,flag=0,cnt=0,pnt;
 int x,y;
 for(i=1,x=k+1;i<=q,x<=n ;i++,x ++)
 {
  for(j=1;j<=k;j++)
  {
   h[j][i]=g[j][x];
  }
 }

 for(i=1;i<=q;i++)
 {
  for(j=k+1;j<=n;j++)

   {  if(i+4==j)
    h[j][i]=1;
    else
    h[j][i]=0;
   }
  }

 for(i=1;i<=n;i++)		//generate error vector table
 {
  for(j=1;j<=n;j++)
  {
   if(i==j)
   e[i][j]=1;
   else
   e[i][j]=0;
  }
 }
 a=0;
 for(f=1;f<=n;f++)		//generate syndrome
 {
  for(i=1;i<=n;i++)
  {
   a=0;
   for(j=1;j<=n;j++)
   {
    b=e[f][j]*h[j][i];
    a=xor(a,b);
    s1[f][i]=a;
   }
  }
 }
 printf("\n--------------------------------");
 printf("\nError pattern           syndrome");
 printf("\n--------------------------------");
 for(i=1;i<=n;i++)
 {
  printf("\n");
  for(j=1;j<=n;j++)
   printf("%2d",e[i][j]);
   printf("\t\t");
  for(j=1;j<=q;j++)
   printf("%2d",s1[i][j]);
   printf("\n");
  }
  for(i=1;i<=q;i++)
  {a=0;
   for(j=1;j<=n;j++)
  {
   b=r[j]*h[j][i];
   a=xor(a,b);
  }
  s2[i]=a;
 }
 printf("\nEnter the Received code:\n");
 for(i=1;i<=n;i++)
 {
  scanf("%d",&r[i]);		//get received codeword
 }
 printf("\n------------------------\n");
 printf("The syndrom of received code is:");
 for(i=1;i<=q;i++)
 printf("%2d",s2[i]);
 for(i=1;i<=q;i++)
 {
  if(s2[i]==1)
  flag=1;
 }
 if(flag==1)
 printf("\nError present in code");
 else
 printf("\nCorrect code received");
 if(flag==1)
 {
  for(i=1;i<=n;i++)
  {
   cnt=0;
   for(j=1;j<=q;j++)
   {
    if(s1[i][j]==s2[j])
    cnt++;
   }
    if(cnt==3)
    {
     pnt=i;
     for(i=1;i<=n;i++)
     r[i]=xor(r[i],e[pnt][i]);
     printf("\nThe correct code is:\n");
     for(i=1;i<=n;i++)
     printf("%2d",r[i]);
     break;
    }
   }
  }
 }

/****************OUTPUT*******************
Enter block length(n):	7
Enter no of msg bits(k):	4
Therefore no of parity bits(q) are:	
3
Therefore linear block code is:	(7,4)
Enter parity matrix transpose:
1 1 1 0
1 1 0 1
1 0 1 1

GENERATOR MATRIX IS:
	1	0	0	0	1	1	1
	0	1	0	0	1	1	0
	0	0	1	0	1	0	1
	0	0	0	1	0	1	1
MENU:
1. Encoding
2. Decoding
3. Exit
Enter your choice? 1

Enter
----------------------------------------------
msg vector         codeword        d
----------------------------------------------
0 0 0 0            0 0 0 0 0 0 0            0
0 0 0 1	     0 0 0 1 0 1 1	 3
0 0 1 0	     0 0 1 0 1 0 1	 3
0 0 1 1	     0 0 1 1 1 1 0	 4
0 1 0 0	     0 1 0 0 1 1 0	 3
0 1 0 1	     0 1 0 1 1 0 1	 4
0 1 1 0	     0 1 1 0 0 1 1	 4
0 1 1 1	     0 1 1 1 0 0 0	 3
1 0 0 0	     1 0 0 0 1 1 1	 4
1 0 0 1	     1 0 0 1 1 0 0	 3
1 0 1 0	     1 0 1 0 0 1 0	 3
1 0 1 1	     1 0 1 1 0 0 1	 4
1 1 0 0	     1 1 0 0 0 0 1	 3
1 1 0 1	     1 1 0 1 0 1 0	 4
1 1 1 0	     1 1 1 0 1 0 0	 4
1 1 1 1	     1 1 1 1 1 1 1	 7

MENU:
1. Encoding
2. Decoding
3. Exit
Enter your choice?

----------------------------------------------------
Error pattern	           syndrome
----------------------------------------------------
1 0 0 0 0 0 0		1 1 1
0 1 0 0 0 0 0		1 1 0
0 0 1 0 0 0 0		1 0 1
0 0 0 1 0 0 0		0 1 1
0 0 0 0 1 0 0		1 0 0
0 0 0 0 0 1 0		0 1 0
0 0 0 0 0 0 1		0 0 1

Enter the Received code:
0 0 0 1 1 0 1

----------------------------------
The syndrome of received code is:110
Error present in code
The correct code is: 
0 1 0 1 1 0 1
Menu:
1.Encoding
2.Decoding
3.Exit
Enter your choice?3
*/
