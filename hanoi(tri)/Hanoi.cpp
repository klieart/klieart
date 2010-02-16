#include "Hanoi.h"

int main ()
{
    int n;
    cin >> n;
    Hanoi hanoi(n);
    hanoi.runHanoi();
    cout << "Moves: "<< hanoi.getCount() << endl;
    cout << "Time:  "<< hanoi.getTime() << endl;
	_getch();
    return 0;
}

Hanoi::Hanoi(int n)
{
    pegs = new Peg*[5];
    pegs[0] = new Peg("STRT",n);
    pegs[1] = new Peg("AUX1",0);
    pegs[2] = new Peg("DEST",0);
    pegs[3] = new Peg("AUX2",0);
    pegs[4] = new Peg("AUX3",0);

    count = 0;
    discNum = n;
}

double Hanoi::getTime ()
{
    return difftime(endTime,startTime);
}

void Hanoi::doRecurse(const int from,const int to,const int n)
{
    if (n == 1)
        move (from, to, n);
    else if (n > 1)
    {
        int destNext = (to+1)%5;
        int destMinus = (to+4)%5;
        doRecurse(from, to,n-1);
        move(from, destMinus,n);
        doRecurse(to, destNext, n-1);
        move(destMinus, to, n);
        doRecurse(destNext, to, n-1);
    }
}

void Hanoi::move(int from, int to, int discSize)
{
    cout << "move disc with size " << discSize
         << " from " << pegs[from]->getName()
         << " to " << pegs[to]->getName() << endl;
    count++;
	// Check reverse:
//    for (int i = from; i != to; (i++)%5)
//    {
//        int nextpeck = (i+1)%5;
////        cout << "move disc with size " << discSize << " from " << pegs[i]->getName()
////             << " to " << pegs[nextpeck]->getName() << endl;
//
//        int popDisc = pegs[i]->pop();
//
//        if(discSize == popDisc)
//            pegs[nextpeck]->push(popDisc);
//        else
//            cerr << "wrong disc size " << popDisc << " "
//                    << discSize
//                    << endl;
//
//        count++;
//    }
}

int Hanoi::getCount()
{
    return count;
}

void Hanoi::runHanoi()
{
    startTime = time(NULL);
    doRecurse(0,2,discNum);
    endTime = time(NULL);

}