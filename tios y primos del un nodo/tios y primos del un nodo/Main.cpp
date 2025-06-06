#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;

struct Nodo {
	Nodo(int val, int nvl) {
		valor = val;
		nivel = nvl;
		nodes[0] = NULL;
		nodes[1] = NULL;
	}
	int valor;
	int nivel;
	Nodo* nodes[2];
};

struct ARBOL {
	ARBOL() {
		raiz = NULL;
	}
	Nodo* raiz;

	bool Find(int val, Nodo**& p) {
		for (p = &raiz; *p && (*p)->valor != val; p = &(*p)->nodes[val > (*p)->valor]);
		return *p != 0;
	}

	void Insert(int val) {
		Nodo** p;
		if (Find(val, p)) {
			return;
		}
		else {
			int nivel = 0;
			Nodo* padre = raiz;
			while (padre && padre->nodes[val > padre->valor] != nullptr) {
				padre = padre->nodes[val > padre->valor];
			}
			if (*p == raiz) {
				*p = new Nodo(val, 0);
			}
			else {
				*p = new Nodo(val, padre->nivel + 1);
			}
		}
	}

	void InOrder(Nodo* n, int x, Nodo* padre) {
		if (!n) {
			return;
		}
		InOrder(n->nodes[0], x, padre);
		if (n->nivel == x - 1 && n != padre) {
			cout << n->valor << " ";
		}
		if (n->nivel == x && n != padre->nodes[1] && n != padre->nodes[0]) {
			cout << n->valor << " ";
		}
		InOrder(n->nodes[1], x, padre);
	}

	void FAMILIARES(int val) {
		Nodo** p;
		if (!Find(val, p)) {
			return;
		}
		else {
			int nivelactual = (*p)->nivel;
			Nodo* padre = raiz;
			while (padre && padre->nodes[val > padre->valor] != *p) {
				padre = padre->nodes[val > padre->valor];
			}
			InOrder(raiz, nivelactual, padre);
		}
	}
};

// ---------- GRAFICACIÓN GLUT ----------

ARBOL arbol;
int nodoObjetivo = 0;
Nodo* padreNodo = nullptr;
vector<Nodo*> tios;
vector<Nodo*> primos;

int anchoVentana = 800, altoVentana = 600;
int sepX = 40, sepY = 50;

Nodo* buscarPadre(Nodo* raiz, Nodo* hijo) {
	if (!raiz || raiz == hijo) return nullptr;
	if (raiz->nodes[0] == hijo || raiz->nodes[1] == hijo) return raiz;
	if (hijo->valor < raiz->valor)
		return buscarPadre(raiz->nodes[0], hijo);
	else
		return buscarPadre(raiz->nodes[1], hijo);
}

void recolectarTios(Nodo* nodo, int nivel) {
	if (!nodo) return;
	if (nodo->nivel == nivel && nodo != padreNodo) {
		tios.push_back(nodo);
	}
	recolectarTios(nodo->nodes[0], nivel);
	recolectarTios(nodo->nodes[1], nivel);
}

void recolectarPrimos(Nodo* nodo, int nivel) {
	if (!nodo) return;
	if (nodo->nivel == nivel && padreNodo && nodo != padreNodo->nodes[0] && nodo != padreNodo->nodes[1]) {
		primos.push_back(nodo);
	}
	recolectarPrimos(nodo->nodes[0], nivel);
	recolectarPrimos(nodo->nodes[1], nivel);
}

void dibujarNodo(Nodo* nodo, int x, int y) {
	bool esTio = find(tios.begin(), tios.end(), nodo) != tios.end();
	bool esPrimo = find(primos.begin(), primos.end(), nodo) != primos.end();

	if (esTio) glColor3f(1.0, 0.0, 0.0); // rojo
	else if (esPrimo) glColor3f(0.0, 1.0, 0.0); // verde
	else glColor3f(1.0, 1.0, 1.0); // blanco

	glRasterPos2i(x - 5, y + 5);
	char txt[10];
	sprintf_s(txt, "%d", nodo->valor);
	for (char c : txt) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

void dibujarArbol(Nodo* nodo, int x, int y, int offset) {
	if (!nodo) return;

	if (nodo->nodes[0]) {
		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2i(x, y);
		glVertex2i(x - offset, y - sepY);
		glEnd();
		dibujarArbol(nodo->nodes[0], x - offset, y - sepY, offset / 2);
	}
	if (nodo->nodes[1]) {
		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2i(x, y);
		glVertex2i(x + offset, y - sepY);
		glEnd();
		dibujarArbol(nodo->nodes[1], x + offset, y - sepY, offset / 2);
	}

	dibujarNodo(nodo, x, y);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	dibujarArbol(arbol.raiz, anchoVentana / 2, altoVentana - 50, 200);
	glFlush();
}

void initGL() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, anchoVentana, 0, altoVentana);
}

int main(int argc, char** argv) {
	arbol.Insert(60);
	arbol.Insert(93);
	arbol.Insert(50);
	arbol.Insert(40);
	arbol.Insert(55);
	arbol.Insert(89);
	arbol.Insert(95);
	arbol.Insert(94);
	arbol.Insert(96);
	arbol.Insert(91);
	arbol.Insert(87);
	arbol.Insert(57);
	arbol.Insert(52);
	arbol.Insert(41);
	arbol.Insert(39);

	arbol.FAMILIARES(55);

	nodoObjetivo = 55;

	Nodo** ptr;
	if (!arbol.Find(nodoObjetivo, ptr)) {
		cout << "Nodo no encontrado" << endl;
		return 0;
	}

	padreNodo = buscarPadre(arbol.raiz, *ptr);
	if (padreNodo) {
		Nodo* abuelo = buscarPadre(arbol.raiz, padreNodo);
		if (abuelo)
			recolectarTios(arbol.raiz, abuelo->nivel + 1);
	}
	recolectarPrimos(arbol.raiz, (*ptr)->nivel);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(anchoVentana, altoVentana);
	glutCreateWindow("Arbol Binario - Tios en rojo, Primos en verde");
	initGL();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
