#include <iostream>
#include <queue>
using namespace std;


class CSortedQueue
{
public:
    int descendente(int a, int b)
    {
        return a <= b;
    }
    void pushx(int x);
    void popx();
    int frontx();
    void remx(int x);
    void printx();
    queue<int> q;
};

void CSortedQueue::pushx(int x)
{
    if (q.empty())
    {
        q.push(x);
        q.front() = x;
        q.back() = x;
    }
    else
    {
        if(x > q.front())
        {
            int temp = q.front();
            q.push(x);
            q.pop();
            q.push(temp);
        }
        else
        {
            q.push(x);
        }
    }
}

void CSortedQueue::popx()
{}

int CSortedQueue::frontx()
{   
    return q.back();
    
}

void CSortedQueue::remx(int x)
{}

void CSortedQueue::printx()
{
    int i = q.size();

    for (int j = 1; j <= i; j++)
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        q.push(temp);
    }
    cout << endl;
}

int main()
{
    CSortedQueue sq;
    sq.pushx(40); sq.printx();
    sq.pushx(23); sq.printx();
    sq.pushx(51); sq.printx();
    sq.pushx(12); sq.printx();
    sq.pushx(30); sq.printx();
    sq.pushx(5);  sq.printx();
    sq.pushx(40); sq.printx();
    sq.pushx(18); sq.printx();
    
    sq.remx(40);  sq.printx();
    sq.remx(23);  sq.printx();
    sq.remx(12);  sq.printx();
    sq.remx(5);  sq.printx();

    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    std::cout<<"\nfront => "<<sq.frontx(); sq.popx();
    cout << "\n";
    sq.printx();
}

