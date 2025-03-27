#include <iostream>
#include "Clase_comparar.h"
#include "ascendente.h"
#include "descendente.h"
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
	long long int arr1[10] = {4,7,5,14,53,21,56,2,0,3};
	Greater asc;
	asc.comparar(arr1, 10);
	descencente desc;
	desc.comparar(arr1, 10);

	return 0;
}