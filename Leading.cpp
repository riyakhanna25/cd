Aim: Write a program in C/C++ to detect the leading edges of the given set of productionsof a grammar.

Algorithm:
1.	Start the program.
2.	Get the Set of Productions for the grammar from the user. No redundant & cyclicproductions must be given.
3.	The conditions to be checked are:
Conditions	Inclusions in resultS-
>Sa	add a
S->Aa	add a, production of A
S->ab	add a
S->AB	Production of A
S->SA	none
S->a	take a
S->SA*	none taken
S->*a	take * leave a
4.	Print the Leading edges.
5.	Stop the program.



#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int vars,terms,i,j,k,m,rep,count,temp=-1;
char var[10],term[10],lead[10][10];
struct grammar
{	
	int prodno;
	char lhs,rhs[20][20];
}gram[50];
void get()
{
	cout<<"\nLEADING\n";
	cout<<"\nEnter the no. of variables : ";
	cin>>vars;
	cout<<"\nEnter the variables : \n";
	for(i=0;i<vars;i++)
	{
		cin>>gram[i].lhs;
		var[i]=gram[i].lhs;
	}
	cout<<"\nEnter the no. of terminals : ";
	cin>>terms;
	cout<<"\nEnter the terminals : ";
	for(j=0;j<terms;j++)
		cin>>term[j];
	cout<<"\nPRODUCTION DETAILS\n";
	for(i=0;i<vars;i++)
	{
		cout<<"\nEnter the no. of production of "<<gram[i].lhs<<":";
		cin>>gram[i].prodno;
		for(j=0;j<gram[i].prodno;j++)
		{
			cout<<gram[i].lhs<<"->";
			cin>>gram[i].rhs[j];
		}
	}
}
void leading()
{
	for(i=0;i<vars;i++)
	{
		for(j=0;j<gram[i].prodno;j++)
		{
			for(k=0;k<terms;k++)
			{
				if(gram[i].rhs[j][0]==term[k])
					lead[i][k]=1;
				else
				{
					if(gram[i].rhs[j][1]==term[k])
						lead[i][k]=1;
				}
			}
		}
	}
	for(rep=0;rep<vars;rep++)
	{
		for(i=0;i<vars;i++)
		{
			for(j=0;j<gram[i].prodno;j++)
			{
				for(m=1;m<vars;m++)
				{
					if(gram[i].rhs[j][0]==var[m])
					{
						temp=m;
						goto out;
					}
				}
				out:
				for(k=0;k<terms;k++)
				{
					if(lead[temp][k]==1)
						lead[i][k]=1;
				}
			}
		}
	}
}

void display()
{
	for(i=0;i<vars;i++)
	{
		cout<<"\nLEADING("<<gram[i].lhs<<") = ";
		for(j=0;j<terms;j++)
		{
			if(lead[i][j]==1)
				cout<<term[j]<<",";
		}
	}
	cout<<endl;
}
int main()
{

	get();
	leading();
	display();

}
