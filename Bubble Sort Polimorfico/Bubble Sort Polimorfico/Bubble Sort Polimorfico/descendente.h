#include <iostream>
#include <chrono>
#include "Clase_comparar.h"

using namespace std;
using namespace chrono;

class Less : public CLASE_COMPARAR
{
public:

	bool comparar(long long int a, long long int b) const override
	{
		return a < b;
	}
};
