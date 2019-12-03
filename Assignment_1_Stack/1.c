#include<stdio.h>
void charline();
void chart(int,char[100]);
int main()
{
	charline();
	return 0;
}
void chart(int n,char ch[100])
{	
	int i;
	for(i=0;i<n;i++)
		{
			printf("%s",ch);
		}
}
void charline()
{
	char ch[100],c; 
	int n,i,j,a;
	float b;

	printf("Enter the character to be printed on line\n");
	scanf("%s",&ch);
	printf("Enter the length of line\n");
	scanf("%d",&n);
	
		chart(n,ch);
		printf("\n");
		printf("\tDATA TYPE\tSIZE IN BYTES\t ");
		printf("\n");
		
		chart(n,ch);
		printf("\n");
		printf("\tINTEGER\t\t\t%d\t ",sizeof(a));
		printf("\n");
		
		chart(n,ch);
		printf("\n");
		printf("\tCHARACTER\t\t%d\t ",sizeof(c));
		printf("\n");
		
		chart(n,ch);
		printf("\n");
		printf("\tFLOAT\t\t\t%d\t ",sizeof(b));
		printf("\n");
		
		chart(n,ch);
	
	
}
