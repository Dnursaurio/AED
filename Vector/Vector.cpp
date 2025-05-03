#include <iostream>

using namespace std;

template <class O>
void print(O arr[], int tam)
{
	for (O* i = arr + 0; i <= arr + tam - 1; i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template <class T>
class Cvector
{
public:
	Cvector(T tamano):tam(tamano)
	{
		//ahora mi puntero ptr apunta al primer elemento del arreglo
		ptr = new T[tam];
		
	}
	void PushFront(T valor)
	{
		if (ctrlfront == nullptr)
		{
			ctrlfront = ptr;
			*ctrlfront = valor;
		}
		else if (ctrlfront < ptr + tam - 1)
		{
			for (T* p = ptr + tam - 1; p >= ptr; p--)
			{
				T* q = p - 1;
				*p = *q;
			}
			ctrlfront++;
			*ptr = valor;
			print<int>(ptr, tam);
		}
		//expancion (fue dificil por eso los comentarios)
		else
		{
			//creo el array nuevo
			int ntam = tam * 2;
			T* ptr1 = new T[ntam];
			//copiar elementos del array anterior
			pegador = ptr1 + 1;
			for (copiador = ptr; copiador <= ptr + tam - 1; copiador++)
			{
				*pegador = *copiador;
				pegador++;
			}
			ctrlfront = pegador - 1;
			delete[] ptr;
			//actualizo tam para nuevas expanciones
			tam = ntam;
			ptr = ptr1;
			*ptr = valor;
			print<int>(ptr, ntam);
		}
	}
	void PopFront(T& valor)
	{
		for (T* terminator = ptr;terminator <= ptr + tam - 1;terminator++)
		{
			T* t_001 = terminator + 1;
			*terminator = *t_001;
		}
		ctrlfront--;
		print<int>(ptr, tam);
		if (ctrlfront == ptr)
		{
			ctrlfront = nullptr;
		}
	}
	void PushBack(T valor)
	{
		if (ctrlfront < ptr + tam - 1)
		{
			T* helpback = ctrlfront + 1;
			*helpback = valor;
			ctrlfront++;
			print<int>(ptr, tam);
		}
		else
		{
			//creo el array nuevo
			int ntam = tam * 2;
			T* ptr1 = new T[ntam];
			//copiar elementos del array anterior
			pegador = ptr1;
			for (copiador = ptr; copiador <= ptr + tam - 1; copiador++)
			{
				*pegador = *copiador;
				pegador++;
			}
			ctrlfront = pegador - 1;
			delete[] ptr;
			//actualizo tam para nuevas expanciones
			tam = ntam;
			ptr = ptr1;
			T* helpback = ctrlfront + 1;
			*helpback = valor;
			ctrlfront++;
			print<int>(ptr, ntam);
		}
	}
	void PopBack(T& valor)
	{
		if (ctrlfront > ptr)
		{
			*ctrlfront = 0; // el 0 es solo simbolico
			ctrlfront--;
			print<int>(ptr, tam);
		}
		else
		{
			ctrlfront = NULL;
			print<int>(ptr, tam);
		}
	}
	//void operator [](T& index);
private:
	T* ptr;
	T* ctrlfront = nullptr;
	T* copiador = NULL;
	T* pegador = NULL;
	int tam;
};
int main()
{
	/*aca mi tamaño se hace 10
	tam = 10, entonces mi arreglo tiene tamaño 10*/
	cout << "-------------Vector-------------" << endl;
	Cvector <int> V1{ 10 };
	int terminated_front;
	int terminated_back;
	cout << "Iniciando vector con PushFront ..." << endl;
	V1.PushFront(1);
	V1.PushFront(2);
	V1.PushFront(4);
	V1.PushFront(5);
	V1.PushFront(15);
	V1.PushFront(19);
	V1.PushFront(123);
	V1.PushFront(40);
	V1.PushFront(32);
	V1.PushFront(54);
	cout << "Expandiendo vector con PushFront ..." << endl;
	V1.PushFront(4);
	V1.PushFront(35);
	cout << "Eliminando elemento con PopFront ..." << endl;
	V1.PopFront(terminated_front);
	V1.PopFront(terminated_front);
	V1.PopFront(terminated_front);
	V1.PopFront(terminated_front);
	V1.PushBack(16);
	V1.PushBack(34);
	V1.PushBack(38);
	V1.PushBack(44);
	V1.PushBack(346);
	V1.PushBack(36);
	V1.PushBack(67);
	V1.PushBack(68);
	V1.PushBack(60);
	V1.PushBack(90);
	V1.PushBack(696);
	V1.PushBack(43);
	V1.PushBack(62);
	V1.PopBack(terminated_back);
	return 0;
}