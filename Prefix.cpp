Aim: Write a program in C/C++ or Java to generate Intermediate Code (Prefix Expression)from given syntax tree.
Algorithm :

1.	First, reverse the given infix expression.
2.	Scan the characters one by one.
3.	If the character is an operand, copy it to the prefix notation output.
4.	If the character is a closing parenthesis, then push it to the stack.
5.	If the character is an opening parenthesis, pop the elements in the stack until we find the corresponding closing parenthesis.
6.	If the character scanned is an operator

•	If the operator has precedence greater than or equal to the top of the stack, push the operator to the stack.
•	If the operator has precedence lesser than the top of the stack, pop the operator and output it to the prefix notation output and then check the above condition again with the new top of the stack.

7.	After all the characters are scanned, reverse the prefix notation output.



#define SIZE 50 /* Size of Stack */
#include<string.h>
#include<stdio.h>
#include <ctype.h>
char s[SIZE];
int top=-1; 
char push(char elem)
{ /* Function for PUSH operation */
 s[++top]=elem;
}
char pop()
{ /* Function for POP operation */
 return(s[top--]);
}
int pr(char elem)
{ /* Function for precedence */
 switch(elem)
 {
 case '#': return 0;
 case ')': return 1;
 case '+':
 case '-': return 2;
 case '*':
 case '/': return 3;
 }
 return 0;
}
int main()
{ /* Main Program */
 char infx[50],prfx[50],ch,elem;
 int i=0,k=0;
 printf("\nRead the Infix Expression : ");
 scanf("%s",infx);
 push('#');
 strrev(infx);
 while( (ch=infx[i++]) != '\0')
 {
 if( ch == ')')
 push(ch);
 else
 if(isalnum(ch)) 
 prfx[k++]=ch;
 else
 if( ch == '(')
 {
 while( s[top] != ')')
 prfx[k++]=pop();
 elem=pop(); /* Remove ) */
 }
 else
 { /* Operator */
 while( pr(s[top]) >= pr(ch) )
 prfx[k++]=pop();
 push(ch);
 }
 }
 while( s[top] != '#') /* Pop from stack till empty */
 prfx[k++]=pop();
 prfx[k]='\0'; /* Make prfx as valid string */
 strrev(prfx);
 strrev(infx);
 printf("\nGiven Infix Expression: %s\nPrefix Expn: %s\n",infx,prfx);
 return 0;
}
