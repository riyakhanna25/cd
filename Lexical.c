Aim: Write a program in C/C++ to implement a lexical analyzer.

Algorithm:
1.	Start
2.	Get the input expression from the user.
3.	Store the keywords and operators.
4.	Perform analysis of the tokens based on the ASCII values. 5.
ASCII Range	TOKEN TYPE
97-122		Keyword else identifier 48-57	Constant else operator
Greater than 12	Symbol

6.	Print the token types.
7.	Stop




#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
void main()
{
char
key[11][10]={"for","while","do","then","else","break","switch","case","if","continue"};
char oper[13]={'+','-','*','/','%','&','<','>','=',';',':','!'};
char a[20],b[20],c[20];
int i,j,l,m,k,flag;
printf("Enter the expression: ");
gets(a);
i=0;
while(a[i])
{
flag=0;
j=0;
l=0;
b[0]='\0';
if((toascii(a[i]>=97))&&(toascii(a[i]<=122)))
{
if((toascii(a[i+1]>=97))&&(toascii(a[i+1]<=122)))
{
while((toascii(a[i]>=97))&&(toascii(a[i]<=122)))
{
b[j]=a[i];
j++; i++;
}
b[j]='\0';
}
else
{
b[j]=a[i];
i++;
b[j+1]='\0';
}
for(k=0;k<=9;k++)
{
if(strcmpi(b,key[k])==0)
{
flag=1;
break;
}
}
if(flag==1)
printf("\n %s is the keyword",b);
else
printf("\n %s is the identifier",b);
}
else if((toascii(a[i]>=48))&&(toascii(a[i]<=57)))
{
if((toascii(a[i+1]>=48))&&(toascii(a[i+1]<=57)))
{
while((toascii(a[i]>=48))&&(toascii(a[i]<=57)))
{
c[l]=a[i];
l++; i++;
}
}
else
{
c[l]=a[i];
i++;l++;
}
c[l]='\0';
printf("\n %s is the constant",c);
}
else
{
for(m=0;m<13;m++)
{
if(a[i]==oper[m])
{
printf("\n %c is the operator",a[i]);
break;
}
}
if(m>=13)
printf("\n %c is the symbol",a[i]);
i++;
}
}
}
