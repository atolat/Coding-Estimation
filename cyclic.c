
/***********************************************************************
Aim:- Implement a (7,4) cyclic code and decode the same
***********************************************************************/
#include<stdio.h>
#include<conio.h>
#include<math.h>
int n,q,k,m[20],g[10],a[10],b[10],c[10],x[10],r[10],s[10],e[10][10];
int s1[10][10],d[20],h[20],t,dmin,c1;
int xor(int a, int b);
void rem();
void decode();
void rem1(int cnt);
void code();
void message();
void bin(int x);

void main()
{
 int i,ptr,flag,ch,ch1;
 clrscr();
 printf("Enter block length(n):\n");
 scanf("%d",&n);		//get block lenght 'n'
 printf("Enter no of msg bits(k):\n");
 scanf("%d",&k);        		//get no of msg bits 'k'
 printf("Cyclic code is:(n,k):%d,%d",n,k);
 q=n-k;                 		//calculate q
 t=pow(2,k);		//calculate all possible combinations
 printf("\nNo of parity bits:%d\n",q);
 printf("Enter the coeff of generator polynomial:\n");
 for(i=0;i<k;i++)
 {
 scanf("%d",&g[i]);    		//get the generator polynomial
 }
 do
 {
 printf("\n------------------------------");
 printf("\nMENU:\n1.Encoding\n2.Decoding\n3.Exit");
 printf("\n------------------------------");
 printf("\nEnter your choice? \t");
 scanf("%d",&ch);     		//get choice
 switch(ch)
 {
 case 1:
	printf("\n\t----------------");
	printf("\n\tEncode: \n\t1.Message bits \n\t2.All combinations\n");
	printf("\n\t----------------");
	printf("\n\tEnter your choice:\t");
	scanf("%d",&ch1);   //get encoding choice
	switch(ch1)
	{
	case 1:
		printf("\n\tEnter coeff of msg polynomial:\n\t");
		for(i=0;i<k;i++)
		{
		scanf("%d",&m[i]);        	//get 'k' bit msg polynomial
		}
		for(i=0;i<n;i++)
		{
		a[i]=m[i];			//zero padding
		}
		printf("\n\tCoeffs of check bit polynomial are:\n\t");
		message();       		//calculate 'q' bit check-bit polynomial
		for(i=0;i<q;i++)
		{
		c[i]=h[i+1];
		printf("%2d",c[i]);   		 //print check bit polynomial
		}
		for(i=0;i<n;i++)		//code word x[i]= msg bits+check bits
		{
		if(i>=k)
		 x[i]=c[i-k];        		//codeword=check bits for i>=k
		else
		x[i]=m[i];          		 //codeword=msg bits else
		}
		printf("\n\tcodeword:\n\t");
		for(i=0;i<n;i++)
		{
		printf("%2d",x[i]); 		 //print 'n' bit code word
		}
		printf("\n\n"); 		//leave space
		break;
     // sub case 1 ends of encoding
	case 2:
		code();			//call code fun.
		c1=dmin-1;           		//dmin>=s+1
		 printf("\n\n------------------------------");
		printf("\nError detecting capability:\t%d",c1);
		t=c1/2;            		 //dmin>=2t+1
		printf("\nError correcting capability:\t%d",t);
		printf("\n\n");
		break;
	}
     //sub case 2 ends of encoding
	break;      				// case 1:"encoding" ends
 case 2:
	decode();				//call decode fun.
	break;				//case 2:"decoding" ends
 }
 }while(ch!=3);	//continue until exit
 getch();
}
int xor(int a, int b)    //xor function
{
 if(a==b)
	return(0);
 else
	return(1);
}
void message()
{
 int i,j;
 for(i=0;i<k;i++)
 {
 b[i]=g[i];			//save gen poly in b[]
 }
 for(i=0;i<n;i++)
 {
 if(i>=k)               		//zero padding to make msg of lenght n
 m[i]=0;               		 //xor with 'x' bit= 'x'
 a[i]=m[i];           		 //save zero padded msg poly in a[]
 }
 rem();              		 // call rem function
}

void rem()
{
 int i,j,cnt=0;
 for(i=0;i<n;i++)       		//calculate no of 0's in a msg bit
 {
 if(a[i]==0)
 cnt++;			//no of zeros=no of bits the msg poly is shifted
 else
 break;
 }
 for(i=0;i<n;i++)
	a[i]= a[i+cnt];
  for(j=cnt;j<=q;j++)
  {
    for(i=0;i<k;i++)
      h[i]=xor(a[i],b[i]);  		//xor msg poly and gen poly
    if(h[1]==0)            		 //check h[1]==0?
    {
	for(i=0;i<k;i++)
	b[i]=0;
    }
    else
    {
	for(i=0;i<k;i++)
	b[i]=g[i];
    }
    for(i=0;i<k-1;i++)
	a[i]=h[i+1];
	a[k-1]=a[k+j];
  }
}
void code()
{
 int p,i,j,f=1;
 for(j=0;j<k;j++)
	f=f*2;
 printf("\nEnter");
 printf("\n----------------------------------------\n msg vector\t codeword \t\td\n----------------------------------------\n");
 for(p=0;p<f;p++)
  {
  d[p]=0;
  for(i=0;i<k;i++)
  scanf("%d",&m[i]);    //get the msg bits
  message();            //check message
  for(i=0;i<q;i++)
  {
   c[i]=h[i+1];
  }
  for(i=0;i<n;i++)
  {
  if(i>=k)
	x[i]=c[i-k];   //codeword=msg bits+check bits
  else
	x[i]=m[i];
  }
  printf("\t");
  for(i=0;i<n;i++)
  {
  if(x[i]==1)          //calculate dmin
  d[p]++;
  printf("%2d",x[i]);
  }
  printf("\t\t%d",d[p]);
  printf("\n");
 }
 dmin=d[1];
 for(i=1;i<f;i++)
 {
  if(d[i]<dmin)
	dmin=d[i];
 }
}
void decode()
{
 int i,j,cnt,flag,ptr;
 for(i=0;i<n;i++)  	//generate the identity error matrix
 {
  for(j=0;j<n;j++)
  {
	if(i==j)
	e[i][j]=1;
	else
	e[i][j]=0;
  }
 }
 for(i=0;i<n;i++)      //generate syndrome matrix
 {
	for(j=0;j<n;j++)
	 a[j]=e[i][j];
	for(j=0;j<k;j++)
	 b[j]=g[j];
	cnt =i;
	if(i<=q)
	rem1(cnt);
	else
	{
		for(j=0;j<k;j++)
		h[j]=e[i][j+q];
	}
	for(j=0;j<q;j++)
	{
	s1[i][j]=h[j+1];
	}
 }
 printf("\n----------------------------------------");
 printf("\nerror pattern\t\tsyndrome");
 printf("\n----------------------------------------");
 for(i=0;i<n;i++)
 {
  printf("\n");
   for(j=0;j<n;j++)
	printf("%2d",e[i][j]);
   printf("\t\t");
   for(j=0;j<q;j++)
	printf("%2d",s1[i][j]);
 }
 printf("\n------------------------------");
 printf("\nenter received codeword\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&r[i]);
 a[i]=r[i];
 }
 for(i=0;i<k;i++)
 {
 b[i]=g[i];
 }
 rem();
 printf("\nCoeff of syndrome polynomial:\n");
 for(i=0;i<q;i++)
 {
 s[i]=h[i+1];
 printf("%2d",s[i]);
 }
 for(i=0;i<n;i++)
 {
	cnt=0;
	for(j=0;j<q;j++)
	{
	if(s1[i][j]==s[j])
	{
	 cnt++;
	 if(cnt==3)
	 {
	 flag = 1;
	 ptr = i;
	 }
	}
	}
 }
 if(flag==1)
 {
 printf("\nerror present at position: %d",ptr+1);
 printf("\nCorrected codeword:\n");
 for(i=0;i<n;i++)
 {
 r[i]=xor(r[i],e[ptr][i]);
 printf("%2d",r[i]);
 }
 }
 else
 printf("\n Correct codeword received");
}
void rem1(int cnt)
{
 int i,j;
 for(i=0;i<n;i++)
  a[i]=a[i+cnt];
   for(j=cnt;j<=q;j++)
  {
    for(i=0;i<k;i++)
      h[i]=xor(a[i],b[i]);  //xor msg poly and gen poly
    if(h[1]==0)             //check xor result==0
    {
	for(i=0;i<k;i++)
	b[i]=0;
    }
    else
    {
	for(i=0;i<k;i++)
	b[i]=g[i];
    }
    for(i=0;i<k-1;i++)
	a[i]=h[i+1];
	a[k-1]=e[cnt][k+j];
  }
}

/*****************OUTPUT**********************
Enter block length(n):
7
Enter no of msg bits(k):
4
Cyclic code is(n,k):7,4
No of parity bits:3
Enter the coeff of generator polynomial:
1 1 0 1

-----------------------------------
MENU:
1.Encoding
2.Decoding
3.Exit
-----------------------------------
Enter your choice?	1

	-------------------
	Encode:
	1.Message bits
	2.All combinations
	-------------------
	Enter your choice:	1

	Enter coeff of msg polynomial:
	1 0 1 0

	Coeff of check bit polynomial are:
	0 0 1
	Codeword:
	1 0 1 0 0 0 1

-----------------------------------
MENU:
1.Encoding
2.Decoding
3.Exit
-----------------------------------
Enter your choice?	1

	-------------------
	Encode:
	1.Message bits
	2.All combinations
	-------------------
	Enter your choice:	2

Enter
-------------------------------------------------
msg vector		codeword		d
-------------------------------------------------
0 0 0 0	            0 0 0 0 0 0 0		0
0 0 0 1	            0 0 0 1 1 0 1		3
0 0 1 0	            0 0 1 0 1 1 1		4
0 0 1 1	            0 0 1 1 0 1 0		3
0 1 0 0	            0 1 0 0 0 1 1		3
0 1 0 1	            0 1 0 1 1 1 0		4
0 1 1 0	            0 1 1 0 1 0 0		3
0 1 1 1	            0 1 1 1 0 0 1		4
1 0 0 0	            1 0 0 0 1 1 0		3
1 0 0 1	            1 0 0 1 0 1 1		4
1 0 1 0	            1 0 1 0 0 0 1		3
1 0 1 1	            1 0 1 1 1 0 0		4
1 1 0 0	            1 1 0 0 1 0 1		4
1 1 0 1	            1 1 0 1 0 0 0		3
1 1 1 0	            1 1 1 0 0 1 0		4
1 1 1 1	            1 1 1 1 1 1 1		7

-----------------------------------
Error detecting capability:	2
Error correcting capability:	1


-----------------------------------
MENU:
1.Encoding
2.Decoding
3.Exit
-----------------------------------
Enter your choice?	2

-----------------------------------
error pattern	syndrome
-----------------------------------
1 0 0 0 0 0 0	1 1 0
0 1 0 0 0 0 0	0 1 1
0 0 1 0 0 0 0	1 1 1
0 0 0 1 0 0 0	1 0 1
0 0 0 0 1 0 0	1 0 0
0 0 0 0 0 1 0	0 1 0
0 0 0 0 0 0 1	0 0 1
-----------------------------------
enter received codeword
1 1 0 1 1 0 1

Coeff of syndrome polynomial:
1 0 1
Error present at position:4
Corrected codeword:
1 1 0 0 1 0 1

-----------------------------------
MENU:
1.Encoding
2.Decoding
3.Exit
-----------------------------------
Enter your choice?	3
*/
