Aim: Write a program in C/C++ to implement the shift reduce parsing.

Algorithm:
1.	Start the Process.
2.	Symbols from the input are shifted onto stack until a handle appears on top of the stack.
3.	The Symbols that are the handle on top of the stack are then replaces by the left-hand side of the production (reduced).
4.	If this result in another handle on top of the stack, then another reduction is done, otherwise we go back to shifting.
5.	This combination of shifting input symbols onto the stack and reducing productions when handles appear on the top of the stack continues until all of the input is consumed and the goal symbol is the only thing on the stack - the input is then accepted.
6.	If we reach the end of the input and cannot reduce the stack to the goal symbol, the input is rejected.
7.	Stop the process.




#include <bits/stdc++.h>
using namespace std;
int z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];
void check()
{
    strcpy(ac,"REDUCE TO E -> ");
	for(z = 0; z < c; z++)
	{
	if(stk[z] == '4')
		{
                           printf("%s4", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			printf("\n$%s\t%s$\t", stk, a);
		}
	}
for(z = 0; z < c - 2; z++)
	{
                if(stk[z] == '2' && stk[z + 1] == 'E' &&
	        stk[z + 2] == '2')
		{
			printf("%s2E2", ac);
			stk[z] = 'E';
			stk[z + 1] = '\0';
			stk[z + 2] = '\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
		}
		for(z = 0; z < c - 2; z++)
	{
	if(stk[z] == '3' && stk[z + 1] == 'E' &&
	stk[z + 2] == '3')
		{
			printf("%s3E3", ac);
			stk[z]='E';
			stk[z + 1]='\0';
			stk[z + 1]='\0';
			printf("\n$%s\t%s$\t", stk, a);
			i = i - 2;
		}
	}
	return ; 
}
int main()
{
	printf("GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n");	
        strcpy(a,"32423");
	c=strlen(a);
	strcpy(act,"SHIFT");
	printf("\nstack \t input \t action");
	printf("\n$\t%s$\t", a);
	for(i = 0; j < c; i++, j++)
	{
		printf("%s", act);
		stk[i] = a[j];	
		stk[i + 1] = '\0';
		a[j]=' ';
printf("\n$%s\t%s$\t", stk, a);
check();
	}
	check();
	if(stk[0] == 'E' && stk[1] == '\0')
		printf("Accept\n");
	else 
                   printf("Reject\n");
}
