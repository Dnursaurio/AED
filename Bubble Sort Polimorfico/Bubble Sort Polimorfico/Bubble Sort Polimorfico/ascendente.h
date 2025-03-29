#include <iostream>
#include "Clase_comparar.h"

using namespace std;

class Greater : public CLASE_COMPARAR 
{
public:
	
	bool comparar(long long int a, long long int b) const override
	{
		return a > b;
	}
};