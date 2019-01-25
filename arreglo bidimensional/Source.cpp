#include <iostream>
using namespace std;

void main() {
	int m[3][2];
	int fila=0;

	for (int i = 0; i < 2; i++) {
		cout << "Ingresa los numeros de la fila " << i + 1<<endl;
		for (int j = 0; j < 3; j++) {
			cout << "ingresa los numero de la columna " << j + 1<<":";
			cin>> m[j][i];
			cout << " \n";
		}
	}

	for (int i = 0; i < 2; i++) {
		cout << "La suma de la fila " << i + 1 <<"es: ";
		for (int j = 0; j < 3; j++) {

			fila=fila+ m[j][i];
			
		}
		cout << fila<<endl;
		fila = 0;
	}


	system("pause");
}