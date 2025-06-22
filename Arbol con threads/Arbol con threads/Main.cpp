#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include <GL/glut.h>

using namespace std;

struct Node {
	Node(int val) {
		suma = val;
		nodes[0] = NULL;
		nodes[1] = NULL;
	}

	Node(Node* izq, Node* der) {
		nodes[0] = izq;
		nodes[1] = der;
		suma = izq->suma + der->suma;
	}

	int suma;
	vector<int> valores;
	Node* nodes[2];
};

//Funcion para los Threads
void SumaNodos(vector<Node*>& p, vector<Node*>& h, int i)
{
	for (i; i < p.size(); i += 4)
	{
		p[i] = new Node(h[2 * i], h[2 * i + 1]);
	}
}

// ==== VARIABLES PARA GLUT Y DIBUJO ====

int window_width = 1500, window_height = 720;
Node* raiz = nullptr;

struct PosNode {
	Node* nodo;
	float x, y;
};

vector<PosNode> posiciones;

// ==== FUNCIONES PARA ARBOL ====

void InOrder(Node* n) {
	if (!n) return;
	InOrder(n->nodes[0]);
	InOrder(n->nodes[1]);
	cout << n->suma << " ";
}

// ==== FUNCIONES DE DIBUJO ====

void asignarPosiciones(Node* nodo, int profundidad, float& x_actual) {
	if (!nodo) return;

	asignarPosiciones(nodo->nodes[0], profundidad + 1, x_actual);

	float x = x_actual;
	float y = window_height - profundidad * 80;
	posiciones.push_back({ nodo, x, y });
	x_actual += 80;

	asignarPosiciones(nodo->nodes[1], profundidad + 1, x_actual);
}

void drawCircle(float cx, float cy, float r) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; ++i) {
		float theta = i * 3.14159f / 180.0f;
		glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
	}
	glEnd();
}

void drawText(float x, float y, const string& text) {
	glRasterPos2f(x, y);
	for (char c : text)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
}

void drawTree() {
	glColor3f(0, 0, 0);
	for (auto& p : posiciones) {
		Node* nodo = p.nodo;
		float x1 = p.x;
		float y1 = p.y;

		for (int i = 0; i < 2; i++) {
			Node* hijo = nodo->nodes[i];
			if (!hijo) continue;

			for (auto& q : posiciones) {
				if (q.nodo == hijo) {
					glBegin(GL_LINES);
					glVertex2f(x1, y1);
					glVertex2f(q.x, q.y);
					glEnd();
				}
			}
		}
	}

	for (auto& p : posiciones) {
		glColor3f(0.2f, 0.6f, 1.0f);
		drawCircle(p.x, p.y, 20);

		glColor3f(1, 1, 1);
		char buffer[16];
		sprintf_s(buffer, "%d", p.nodo->suma);
		drawText(p.x - 8, p.y - 4, buffer);
	}
}

// ==== GLUT ====

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	posiciones.clear();
	float x_actual = 60;
	asignarPosiciones(raiz, 1, x_actual);

	drawTree();
	glFlush();
}

void reshape(int w, int h) {
	window_width = w;
	window_height = h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void initGL() {
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, window_width, 0, window_height);
	glMatrixMode(GL_MODELVIEW);
}

// ==== MAIN ====

int main(int argc, char** argv) {
	vector<int> data = { 14,41,36,18,25,72,89,100};
	vector<Node*> hojas;

	for (int i = 0; i < data.size(); i++)
		hojas.push_back(new Node(data[i]));

	while (hojas.size() > 1) {
		vector<Node*> nivelarriba(hojas.size() / 2);
		vector<thread> hilos(4);

		for (int i = 0; i < 4; i++)
		{
			hilos[i] = thread(SumaNodos, ref(nivelarriba), ref(hojas), i);
		}

		for (int i = 0; i < 4; i++)
		{
			hilos[i].join();
		}

		hojas = nivelarriba;
	}

	raiz = hojas[0];

	cout << "valores en el arbol (suma): ";
	InOrder(raiz);
	cout << endl;

	// Inicialización de GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(window_width, window_height);
	glutCreateWindow("Árbol Binario - Sumas");

	initGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); // <-- importante
	glutMainLoop();

	return 0;
}