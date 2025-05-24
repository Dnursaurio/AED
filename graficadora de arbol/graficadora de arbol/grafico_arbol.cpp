#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <glut.h>
#include <sstream>

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

    void altura_arbol(Node* n, int l, int& L)
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
        return max(l, r) + 1;
    }

    void InOrderStack(Node* n)
    {
        stack<pair<Node*, int>>s;
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

    void Borde_Arbol(Node* n)
    {

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

    Node* getRoot()
    {
        return root;
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

// -------------- Código OpenGL y GLUT para graficar el árbol -----------------

BTree tree;

// Dibuja un círculo centrado en (x, y) con radio r
void drawCircle(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f, 0.6f, 0.8f); // Azul celeste
    glVertex2f(x, y);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * 3.1415926f * i / 100;
        float dx = r * cosf(angle);
        float dy = r * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();

    // Borde negro
    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * 3.1415926f * i / 100;
        float dx = r * cosf(angle);
        float dy = r * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Dibuja texto centrado en (x, y)
void drawText(float x, float y, const string& text) {
    glColor3f(0, 0, 0);
    glRasterPos2f(x - 4 * text.size() / 2, y - 4);
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

// Dibuja el árbol recursivamente
void drawNode(Node* node, float x, float y, float hSpacing, float vSpacing) {
    if (!node) return;

    // Dibuja el nodo actual
    drawCircle(x, y, 20);
    drawText(x, y, to_string(node->value));

    // Dibuja la conexión y nodo izquierdo o NULL
    if (node->nodes[0]) {
        glColor3f(0, 0, 0);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(x, y - 20);
        glVertex2f(x - hSpacing, y - vSpacing + 20);
        glEnd();
        drawNode(node->nodes[0], x - hSpacing, y - vSpacing, hSpacing / 1.5f, vSpacing);
    }
    else {
        glColor3f(1, 0, 0); // rojo para NULL
        glRasterPos2f(x - hSpacing - 10, y - vSpacing + 5);
        const char* nullText = "NULL";
        for (int i = 0; nullText[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, nullText[i]);
        }
    }

    // Dibuja la conexión y nodo derecho o NULL
    if (node->nodes[1]) {
        glColor3f(0, 0, 0);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(x, y - 20);
        glVertex2f(x + hSpacing, y - vSpacing + 20);
        glEnd();
        drawNode(node->nodes[1], x + hSpacing, y - vSpacing, hSpacing / 1.5f, vSpacing);
    }
    else {
        glColor3f(1, 0, 0);
        glRasterPos2f(x + hSpacing - 10, y - vSpacing + 5);
        const char* nullText = "NULL";
        for (int i = 0; nullText[i] != '\0'; i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, nullText[i]);
        }
    }
}

int windowWidth = 840;
int windowHeight = 600;

void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float startX = windowWidth / 2.0f;
    float startY = windowHeight - 50;

    drawNode(tree.getRoot(), startX, startY, 160, 80);

    glFlush();
}

int main(int argc, char** argv) {
    // Inserta valores de ejemplo en el árbol
    tree.Insert(16);
    tree.Insert(17);
    tree.Insert(9);
    tree.Insert(3);
    tree.Insert(10);
    tree.Insert(1);
    tree.Insert(4);
    tree.Insert(2);
    tree.Insert(0);
    tree.Insert(20);
    tree.Insert(22);
    tree.Insert(21);
    tree.Insert(5);
    tree.Insert(8);
    tree.Insert(7);
    cout << "Exploracion InOrder" << endl;
    tree.print_InOrder();
    cout << "Exploracion PreOrder" << endl;
    tree.print_PreOrder();
    cout << "Exploracion PostOrder" << endl;
    tree.print_PostOrder();
    cout << "Exploracion Reverse" << endl;
    tree.print_Reverse();
    cout << "Exploracion por niveles" << endl;
    tree.print_level();
    cout << "Hallando la altura del arbol" << endl;
    tree.print_altura();
    cout << "Hallando la altura del arbol de manera alternativa" << endl;
    tree.print_alter_altura();

    // Inicialización de GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(840, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Graficadora de Cuela");
    glClearColor(0.3, 0.3, 0.3, 0); // Fondo blanco

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
