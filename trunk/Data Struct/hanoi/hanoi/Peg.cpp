#include "Peg.h"

Peg::Peg(string str,int n)
{
    name = str;
    for(int i = n; i >= 1;i--)
        discStack.push(i);
}
string Peg::getName ()
{
    return name;
}
void Peg::push(int n)
{
    if(discStack.empty() || discStack.top() > n)
        discStack.push(n);
    else
        cerr << "invalid disc move";
}
int Peg::pop()
{
    int returnValue = discStack.top();
    discStack.pop();
    return returnValue;
}
