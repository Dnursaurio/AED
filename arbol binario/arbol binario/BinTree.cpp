#include <iostream>
#include <queue>
#include <stack>
#include <minmax.h>
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
    
    void altura_arbol(Node* n, int l, int & L)
    {
        if (!n)
        {
            return;
        }
        if (l > L)
        {
            L = l;
        }
        altura_arbol(n->nodes[0], l + 1, L);
        cout << n->value << " en el nivel " << l << endl;
        altura_arbol(n->nodes[1], l + 1, L);
    }

    void Reverse(Node* n)
    {
        if (!n)
        {
            return;
        }
        else
        {
            Reverse(n->nodes[1]);
            cout << n->value << " ";
            Reverse(n->nodes[0]);
        }
    }

    void PreOrder(Node* n)
    {
        if (!n)
        {
            return;
        }
        else
        {
            cout << n->value << " ";
            PreOrder(n->nodes[0]);
            PreOrder(n->nodes[1]);
        }
    }

    void PostOrder(Node* n)
    {
        if (!n)
        {
            return;
        }
        else
        {
            PostOrder(n->nodes[0]);
            PostOrder(n->nodes[1]);
            cout << n->value << " ";
        }
    }

    void level(Node* n)
    {
        queue<Node*>q;
        q.push(n);
        while (!q.empty())
        {
            n = q.front();
            cout << n->value << " ";
            if (n->nodes[0])
            {
                q.push(n->nodes[0]);
            }
            if (n->nodes[1])
            {
                q.push(n->nodes[1]);
            }
            q.pop();
        } 
    }

    int que_tan_alto_soy(Node* n)
    {
        if (!n)
        {
            return 0;
        }
        int l = que_tan_alto_soy(n->nodes[0]);
        int r = que_tan_alto_soy(n->nodes[1]);
        cout << n->value << " ";
        //return ((l>r)?l:r)+1;
        return max(l, r) + 1;
    }
        
    void InOrderStack(Node* n)
    {
        stack<pair<Node*,int>>s;
        s.push(make_pair(n, 0));
        while (!s.empty())
        {
            auto x = s.top();
            switch (x.second)
            {
            case  0:
                if (n->nodes[0])
                {
                    s.push(make_pair(n->nodes[0], 0));
                }
                x.second += 1;
                s.push(make_pair(n, 0));
            case 1:
                cout << n->value << " ";
                x.second += 1;
                return;
            case 2:
                if (n->nodes[1])
                {
                    s.push(make_pair(n->nodes[1], 0));
                }
                x.second += 1;
            case 3:
                s.pop();
            }
        }
    }

    void print_InOrder()
    {
        inorder(root);
        cout << endl;
    }

    void print_PreOrder()
    {
        PreOrder(root);
        cout << endl;
    }

    void print_PostOrder()
    {
        PostOrder(root);
        cout << endl;
    }

    void print_Reverse()
    {
        Reverse(root);
        cout << endl;
    }

    void print_level()
    {
        level(root);
        cout << endl;
    }

    void print_altura()
    {
        int L = 0;
        altura_arbol(root, 0, L);
        cout << endl;
    }

    void print_alter_altura()
    {
        int L = 0;
        que_tan_alto_soy(root);
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
};

int main()
{
    BTree t;
    t.Insert(2);
    t.Insert(5);
    t.Insert(9);
    t.Insert(3);
    t.Insert(10);
    t.Insert(1);
    cout << "Exploracion InOrder" << endl;
    t.print_InOrder();
    cout << "Exploracion PreOrder" << endl;
    t.print_PreOrder();
    cout << "Exploracion PostOrder" << endl;
    t.print_PostOrder();
    cout << "Exploracion Reverse" << endl;
    t.print_Reverse();
    cout << "Exploracion por niveles" << endl;
    t.print_level();
    cout << "Hallando la altura del arbol" << endl;
    t.print_altura(); 
    cout << "Hallando la altura del arbol de manera alternativa" << endl;
    t.print_alter_altura();
    return 0;
}