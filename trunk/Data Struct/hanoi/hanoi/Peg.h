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
    string name;
public:
    Peg(string str,int n);
    string getName();
    void push(int n);
    int pop();

};

#endif // PEG_H
