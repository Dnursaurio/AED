#include <iostream>
#include <queue>
#include <GL/glut.h>
#include <cmath>
#include <set>
using namespace std;
set<int> bordeNodes;

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
    BTree() {
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
        else {
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

    void izquierda(Node* n) 
    {
        
        if (n->nodes[0])
        {
            izquierda(n->nodes[0]);
            cout << n->value << " ";
        }
    }

    void derecha(Node* n) {

        if (n->nodes[1])
        {
            derecha(n->nodes[1]);
            cout << n->value << " ";
        }
    }

    void base(Node* n) 
    {
        if (!n)
        {
            return;
        }

        base(n->nodes[0]);
        base(n->nodes[1]);

        if (!n->nodes[0] && !n->nodes[1]) 
        {
            cout << n->value << " ";
            return;
        }
    }

    void borde(Node* n) 
    {
        cout << root->value << " ";
        izquierda(n->nodes[0]);
        derecha(n->nodes[1]);
        base(n);
    }

    void print_InOrder() 
    {
        inorder(root);
        cout << endl;
    }

    void print_izq() 
    {
        izquierda(root);
        cout << endl;
    }

    void print_der() 
    {
        derecha(root);
        cout << endl;
    }

    void print_base() 
    {
        base(root);
        cout << endl;
    }

    void print_borde() 
    {
        borde(root);
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

// ---------- OpenGL Drawing ----------

BTree tree;

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; ++i) {
        float angle = 2.0f * 3.1415926f * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void recolectarBorde(Node* n) {
    if (!n) return;
    bordeNodes.insert(n->value);

    // Izquierda, derecha y base adaptados para insertar en bordeNodes
    // Aquí copiamos la lógica de tu función borde, pero insertando en el set en lugar de imprimir
    auto izquierdaCollect = [](Node* node, auto& self) -> void {
        if (!node || (!node->nodes[0] && !node->nodes[1])) return;
        bordeNodes.insert(node->value);
        if (node->nodes[0]) self(node->nodes[0], self);
        else self(node->nodes[1], self);
        };

    auto derechaCollect = [](Node* node, auto& self) -> void {
        if (!node || (!node->nodes[0] && !node->nodes[1])) return;
        if (node->nodes[1]) self(node->nodes[1], self);
        else self(node->nodes[0], self);
        bordeNodes.insert(node->value);
        };

    auto baseCollect = [](Node* node, auto& self) -> void {
        if (!node) return;
        self(node->nodes[0], self);
        self(node->nodes[1], self);
        if (!node->nodes[0] && !node->nodes[1]) {
            bordeNodes.insert(node->value);
        }
        };

    izquierdaCollect(n->nodes[0], izquierdaCollect);
    derechaCollect(n->nodes[1], derechaCollect);
    baseCollect(n, baseCollect);
}

void dibujarNodo(Node* nodo, float x, float y, float dx, float dy) {
    if (!nodo) return;

    char buffer[10];
    sprintf_s(buffer, "%d", nodo->value);

    // Cambia el color si el nodo está en el borde
    if (bordeNodes.count(nodo->value)) {
        glColor3f(1.0f, 0.5f, 0.0f); // naranja por ejemplo para borde
    }
    else {
        glColor3f(0.6f, 0.8f, 1.0f); // azul para nodos normales
    }

    drawCircle(x, y, 0.04f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawText(x - 0.01f * strlen(buffer), y - 0.01f, buffer);

    for (int i = 0; i < 2; ++i) {
        float childX = x + dx * (i == 0 ? -1 : 1);
        float childY = y - dy;
        glColor3f(0, 1, 0);
        glBegin(GL_LINES);
        glVertex2f(x, y - 0.04f);
        if (nodo->nodes[i]) {
            glVertex2f(childX, childY + 0.04f);
        }
        else {
            glVertex2f(childX, childY);
        }
        glEnd();

        if (nodo->nodes[i]) {
            dibujarNodo(nodo->nodes[i], childX, childY, dx * 0.5f, dy);
        }
        else {
            glColor3f(1, 0, 0);
            drawText(childX - 0.02f, childY, "_");
        }
    }
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    dibujarNodo(tree.getRoot(), 0.0f, 0.9f, 0.3f, 0.15f);
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

// ---------- Main ----------

int main(int argc, char** argv) {
    tree.Insert(18);
    tree.Insert(5);
    tree.Insert(25);
    tree.Insert(2);
    tree.Insert(9);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(10);
    tree.Insert(23);
    tree.Insert(30);
    tree.Insert(21);
    tree.Insert(24);
    tree.Insert(29);
    tree.Insert(31);
    tree.Insert(8);
    tree.Insert(6);
    tree.Insert(0);
    tree.Insert(4);

    cout << "Exploracion InOrder" << endl;
    tree.print_InOrder();
    cout << "Hallando la izquierda del arbol" << endl;
    tree.print_izq();
    cout << "Hallando la derecha del arbol" << endl;
    tree.print_der();
    cout << "Hallando la base del arbol" << endl;
    tree.print_base();
    cout << "Hallando el borde del arbol" << endl;
    tree.print_borde();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Arbol Binario con GLUT");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0.3, 0.3, 0.3, 0);
    recolectarBorde(tree.getRoot());
    glutMainLoop();

    return 0;
}
