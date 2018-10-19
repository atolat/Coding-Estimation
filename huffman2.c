
/*************************************************************
AIM:- Implementation of algorithm for generation and
evalution of variable length source coding using
Huffman coding and decoding
***********************************************************/
#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct node
{
char c;
float f;
}node;

void main()
{
	node s[100];
	char ch[100],p,m,l[100],a,r;
	int g,i,j,flag,q,k,cout,y,w,h[100][100],e[10];
	float v,c[100][100],n,b[100][100],z,pos[100][100],x,d;
	do
       {
	clrscr();
	printf("Enter string \n ");
	gets(ch);                   //get the string from user
	n=0.0;
	n=strlen(ch);               //calculate string length
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			c[i][j]=2;
	}
	for(i=0;i<=n;i++)
	l[i]='\0';
	z=-1;
	for(i=0;i<n;i++)
	{
		p=ch[i];
		for(k=0;k<i;k++)
		{
			if(l[k]==p)
				break;
		}
		if(k==i)
		{
			z=z+1;
			l[z]=p;
		}
	}

	m=z+1;
	printf("character\toccurence\tprobabilities\n");
	for(i=0;i<m;i++)
	{
		cout=0.0;
		for(j=0;j<=n;j++)
		{
		       if(l[i]==ch[j])
			       cout=cout+1;
		}
		v=cout/n;
		printf("\n%c\t\t%d\t\t%f",l[i],cout,v);
		s[i].f=v;
		s[i].c=l[i];
	 }

	for(i=0;i<m;i++)
	{
		for(j=0;j<m-1;j++)
		{
			if(s[j].f<s[j+1].f)
			{
				z=s[j].f;
				a=s[j].c;
				s[j].f=s[j+1].f;
				s[j].c=s[j+1].c;
				s[j+1].f=z;
				s[j+1].c=a;

			}
		}
	}
	for(i=0;i<m;i++)
		b[i][0]=s[i].f;
	for(i=0;i<m-1;i++)
	{
		x=b[m-i-1][i]+b[m-i-2][i];
		c[m-i-1][i]=1;
		c[m-i-2][i]=0;
		for(j=0;j<m-i;j++)
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
				pos[m-i-1][i]=j;
				pos[m-i-2][i]=j;
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			for(k=j;k<m-2-i;k++)
			{
				b[k+1][i+1]=b[k][i];
				pos[k][i]=k+1;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		y=i;
		for(j=0;j<m;j++)
		{
			h[i][j]=c[y][j];
			y=pos[y][j];
		}
	}
	printf("\n\n");
	for(i=0;i<m;i++)
	{
		printf("\n%c=",s[i].c);
		for(j=m-1;j>=0;j--)
		{
			if(h[i][j]!=2)
				printf("%d",h[i][j]);
		}
	}
	printf("\n\nDecoding");
	printf("\nenter no of bit\n");
	scanf("%d",&q);
	printf("Enter bits\n");
	for(i=0;i<q;i++)
	{
		scanf("%d",&e[i]);
	}
	for(i=0;i<m;i++)
	{
		k=0;
		for(j=m-1;j>=0;j--)
		{
			if(e[k]==0)
				w=1;
			else
				w=0;
			if(h[i][j]==e[k])
			{
				k++;
			}
			if(h[i][j]==w)
				k--;
		}
		if(k==q)
		{
			printf("character is %c\n",s[i].c);
			break;
		}
	}
	printf("Do you want to continue?(y/n):");
	scanf("%c",&r);
	}while(r=='y');
	getch();
}

/*********OUTPUT************
Enter string:
 signal coding

character    occurence       probabilities
s		1		0.076923
i		2		0.153846
g               2               0.153846
n               2               0.153846
a               1               0.076923
l               1               0.076923
		1               0.076923
c               1               0.076923
o               1               0.076923
d               1               0.076923


i=11
g=010
n=011
s=101
a=1000
l=1001
 =0010
c=0011
o=0000
d=0001


Decoding
enter no of bit
2
Enter bits
1 1
character is i
Do you want to continue?(y/n):
n
*/






