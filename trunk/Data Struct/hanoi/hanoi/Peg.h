#ifndef PEG_H
#define PEG_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Peg
{
private:
    stack<int> discStack;
    string disk;
	void push(int n);

public:
    Peg(string str,int n);
    string getName();
    
};

#endif // PEG_H
