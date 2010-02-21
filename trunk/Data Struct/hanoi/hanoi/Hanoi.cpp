#include "Hanoi.h"

int main ()
{
	int n;
	cout << "Enter number of pegs: ";
	cin >> n;

	cout << "\n" << "  Running..." << endl;
    Hanoi hanoi(n);
    hanoi.runHanoi();
	cout << "  Done" << "\n" << endl;

    cout << "Moves: " << hanoi.getMoves() << endl;
	cout << "Time: " << hanoi.getTime() << " sec" << endl;
	
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

    moves = 0;
    discNum = n;
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

void Hanoi::move(int from, int to, int size)
{
	cout << " Disk " << size << ": "
		 << pegs[from]->getName() << " -> " << pegs[to]->getName() << endl;
    moves++;
}

void Hanoi::runHanoi()
{
    qTimer.Start();
    doRecurse(0,2,discNum);
    qTimer.End();
}

int Hanoi::getMoves()
{
    return moves;
}

double Hanoi::getTime()
{
	return qTimer.GetTimeInSeconds();
}


