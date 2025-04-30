#include <iostream>
using namespace std;

struct Node
{
    Node(int v)
    {
        value = v;
        nodes[0] = nodes[1] = 0;
    }

    int value;
    Node* nodes[2];
};

class BTree
{
public:
    BTree()
    {
        root = NULL;
    }

    ~BTree()
    {
        return;
    }

    bool Find(int val, Node**& p)
    {
        for (p = &root; *p && (*p)->value != val; p = &((*p)->nodes[val > (*p)->value]));
        return *p != 0;
    }

    bool Insert(int val)
    {
        Node** p;
        if (Find(val, p))
        {
            return 0;
        }
        else
        {
            *p = new Node(val);
            return 1;
        }
    }

    bool Remove(int val)
    {
        Node** p;
        if (!Find(val, p))
        {
            return 0;
        }
        else
        {
            
        }
    }

private:
    Node* root;
};

int main()
{
    BTree t;

    return 0;
}