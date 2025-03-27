#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

#ifndef CLASE_COMPARAR_H
#define CLASE_COMPARAR_H

class CLASE_COMPARAR
{
public:

	virtual void comparar(long long int arr[], long long int tam) = 0;
};

#endif // !CLASE_COMPARAR


