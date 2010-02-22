#include "Peg.h"

Peg::Peg(string str,int n)
{
	disk = str;
	for(int i = n; i >= 1;i--)
		discStack.push(i);
}

void Peg::push(int n)
{
	if(discStack.empty() || discStack.top() > n)
		discStack.push(n);
	else
		cerr << "Invalid move!";
}

string Peg::getName ()
{
	return disk;
}