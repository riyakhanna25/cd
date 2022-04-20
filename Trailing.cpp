

Aim: Write a program in C/C++ or Java to detect the trailing edges of the given set ofproductions of a grammar.

Algorithm:
1.	Start the program.
2.	Get the Set of Productions for the grammar from the user. No redundant & cyclicproductions must be given.
3.	Reverse each input productions and print it.
4.	The conditions to be checked according to the reversed inputs are:Conditions	Inclusions in result
S->Sa	add a
S->Aa	add a, production of A
S->ab	add a
S->AB	Production of A
S->SA	none
S->a	take a
S->SA*	none taken
S->*a	take * leave a
5.	Print the Trailing edges.
6.	Stop the program.

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int vars,terms,i,j,k,m,rep,count,temp=-1;
char var[10],term[10],lead[10][10],trail[10][10];
struct grammar
{	
	int prodno;
	char lhs,rhs[20][20];
}gram[50];
void get()
{
	cout<<"\nTRAILING\n";
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
void trailing()
{
	for(i=0;i<vars;i++)
	{
		for(j=0;j<gram[i].prodno;j++)
		{
			count=0;
			while(gram[i].rhs[j][count]!='\x0')
				count++;
			for(k=0;k<terms;k++)
			{
				if(gram[i].rhs[j][count-1]==term[k])
					trail[i][k]=1;
				else
				{
					if(gram[i].rhs[j][count-2]==term[k])
						trail[i][k]=1;
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
				count=0;
				while(gram[i].rhs[j][count]!='\x0')
					count++;
				for(m=1;m<vars;m++)
				{
					if(gram[i].rhs[j][count-1]==var[m])
						temp=m;
				}
				for(k=0;k<terms;k++)
				{
					if(trail[temp][k]==1)
						trail[i][k]=1;
				}
			}
		}
	}
}
void display()
{
	for(i=0;i<vars;i++)
	{
		cout<<"\nTRAILING("<<gram[i].lhs<<") = ";
		for(j=0;j<terms;j++)
		{
			if(trail[i][j]==1)
				cout<<term[j]<<",";
		}
	}
	cout<<endl;
}
int main()
{

	get();
	trailing();
	display();

}
