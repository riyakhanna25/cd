Aim: Write a program in C/C++ to generate intermediate code from a given syntax tree statement.

Algorithm:
1.	Start the process.
2.	Input an expression EXP from user.
3.	Process the expression from right hand side to left hand side. 4. FLAG:=0; TOP = -1;
5.	IF EXP = ‘=’ then
i.	IF EXP(index – 1) = 0 then
1.	PRINT EXP element from index to (index – 1) and POP STACK[TOP]. Terminate
 
Else

[EndIF]
 

i.	PRINT Wrong Expression
 
IF an operator is found and FLAG = 0 then
i.	TOP:= TOP + 1
ii.	add to STACK[TOP].
iii.	FLAG:=1
 
Else



[EndIF]
 

i.	pop twice the STACK and result add to the newID(identifier) and PRINT.
ii.	TOP:=TOP-2. Save newID to STACK[TOP]
iii.	FLAG:=0
 
6.	IF an operand is found then
i.	TOP:=TOP+1
ii.	move to STACK [TOP]
iii.	IF TOP > 1 then
1.	pop twice the STACK and result add to the newID(identifier) and PRINT.
2.	TOP:=TOP-2. Save newID to STACK[TOP]
3.	FLAG:=0
[End]
7.	End the process





#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int main()
{
char g,exp[20],stack[20];
int m=0,i,top=-1,flag=0,len,j;
cout<<"\nInput an expression : ";
gets(exp);
cout<<"\nIntermediate code generator\n";
len=strlen(exp);
if(isdigit(exp[len-1]))
{
cout<<"T = inttoreal(";
i=len-1;
while(isdigit(exp[i]))
{
i--;
}
for(j=i+1;j<len;j++)
{
cout<<exp[j];
}
cout<<".0)\n";
exp[i+1]='T';
len=i+2;
}
else
{
cout<<"T = "<<exp[len-1]<<"\n";
exp[len-1]='T';
}
for(i=len-1;i>=0;i--)
{
if(exp[i]=='=')
{
if((i-1)==0)
{
if(isalpha(stack[top]))
{
cout<<exp[i-1]<<" "<<exp[i]<<" "<<stack[top];
}
else
{
cout<<exp[i-1]<<" "<<exp[i]<<" "<<stack[top]<<stack[top-1];
}
break;
}
else
{
cout<<"\nWrong Expression !";
break;
}
}
if(exp[i]=='+'||exp[i]=='/'||exp[i]=='*'||exp[i]=='-'||exp[i]=='%')
{
if(flag==0)
{
flag=1;
top=top+1;
stack[top]=exp[i];
}
else
{
g=char('A' + m);
m++;
cout<<g<<" = "<<stack[top]<<stack[top-1]<<"\n";
stack[top-1]=g;
stack[top]=exp[i];
flag=0;
}
}
else
{
top=top+1;
stack[top]=exp[i];
if(top>1)
{
g=char('A' + m);m++;
cout<<g<<" = "<<stack[top]<<stack[top-1]<<stack[top-2]<<"\n";
top=top-2;
stack[top]=g;
flag=0;
}
}
}
return 0;
}

or
 
 
 #include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
void small();
void dove(int i);
int p[5]={0,1,2,3,4},c=1,i,k,l,m,pi;
char sw[5]={'=','-','+','/','*'},j[20],a[5],b[5],ch[2];
int main()
{
printf("Enter the expression:");
scanf("%s",j);
printf("\tThe Intermediate code is:\n");
small();
}
void dove(int i)
{
a[0]=b[0]='\0';
if(!isdigit(j[i+2])&&!isdigit(j[i-2]))
{
a[0]=j[i-1];
b[0]=j[i+1];
}
if(isdigit(j[i+2])){
a[0]=j[i-1];
b[0]='t';
b[1]=j[i+2];
}
if(isdigit(j[i-2]))
{
b[0]=j[i+1];
a[0]='t';
a[1]=j[i-2];
b[1]='\0';
}
if(isdigit(j[i+2]) &&isdigit(j[i-2]))
{
a[0]='t';
b[0]='t';
a[1]=j[i-2];
b[1]=j[i+2];
sprintf(ch,"%d",c);
j[i+2]=j[i-2]=ch[0];
}
if(j[i]=='*')
printf("\tt%d=%s*%s\n",c,a,b);
if(j[i]=='/')
printf("\tt%d=%s/%s\n",c,a,b);
if(j[i]=='+')
printf("\tt%d=%s+%s\n",c,a,b);if(j[i]=='-')
printf("\tt%d=%s-%s\n",c,a,b);
if(j[i]=='=')
printf("\t%c=t%d",j[i-1],--c);
sprintf(ch,"%d",c);
j[i]=ch[0];
c++;
small();
}
void small()
{
pi=0;l=0;
for(i=0;i<strlen(j);i++)
{
for(m=0;m<5;m++)
if(j[i]==sw[m])
if(pi<=p[m])
{
pi=p[m];
l=1;
k=i;
}
}
if(l==1)
dove(k);
else
exit(0);
}
