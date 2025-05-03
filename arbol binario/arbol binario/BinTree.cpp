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
        replace = 0;
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
        else if ((*p)->nodes[0] && (*p)->nodes[1])
        {
            Node** q = REPLACE(p);
            (*p)->value = (*q)->value;
            p = q;
        }
        Node* t = *p;
        *p = (*p)->nodes[(*p)->nodes[0] == 0];
        delete t;
        return 1;
    }



    void print()
    {
        inorder(root);
        cout << endl;
    }

private:
    Node* root;
    bool replace;
    Node** REPLACE(Node** q)
    {
        replace = !replace;
        q = &((*q)->nodes[!replace]);
        while ((*q)->nodes[replace])
        {
            q = &((*q)->nodes[replace]);
        }
        return q;
    }
    void inorder(Node* n)
    {
        if (!n)
        {
            return;
        }
        else
        {
            inorder(n->nodes[0]);
            cout << n->value << " ";
            inorder(n->nodes[1]);
        }
    }
};

int main()
{
    BTree t;
    t.Insert(2);
    t.Insert(5);
    t.Insert(9);
    t.Insert(3);
    t.Insert(10);
    t.print();
    t.Remove(5);
    t.print();
    return 0;
}