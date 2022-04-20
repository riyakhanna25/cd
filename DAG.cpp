There are three possible scenarios for building a DAG on three address codes:
Case 1 –  x = y op z
Case 2 – x = op y
Case 3  –  x = y
Directed Acyclic Graph for the above cases can be built as follows :
Step 1 – 
If the y operand is not defined, then create a node (y).
If the z operand is not defined, create a node for case(1) as node(z).
Step 2 – 
Create node(OP) for case(1), with node(z) as its right child and node(OP) as its left child (y).
For the case (2), see if there is a node operator (OP) with one child node (y).
Node n will be node(y)  in case (3).
Step 3 – 
Remove x from the list of node identifiers.
Add x to the list of attached identifiers for node n.


#include<iostream>
#include<string>
using namespace std;
int main()
{
	string exp;
	cout<<"Enter the expression: ";
	cin>>exp;
	int j=0,k=0;
	char q;
	for(int i=exp.length()-1;i>1;i--)
	{	
		if(islower(exp[i]) || (exp[i]>=48 && exp[i]<=57))
		{
			cout<<j<<"->"<<exp[i]<<endl;
			j++;
		}
	}
	for(int i=exp.length()-1;i>1;i--)
	{
		if(!(islower(exp[i])|| (exp[i]>=48 && exp[i]<=57)))
		{
			cout<<j<<"->"<<exp[i]<<k<<k+1<<endl;
			j++;
			k+=2;
		}
	}
	cout<<j<<"->"<<exp[0]<<endl;
	j++;
	cout<<j<<"->"<<exp[1]<<j-1<<j-2<<endl;
	return 0;
}
