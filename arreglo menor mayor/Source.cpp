#include<iostream>
using namespace std;

void main() {
	int m[10];
	int up = 0, down = 0, prom = 0;
	for (int i = 0; i < 10; i++) {
		cout << "Ingresa el numero: ";
		cin >> m[i];
		cout << endl;


		if (m[i] >= up) {
			up = m[i];
		}
		if (m[i] <= down) {
			down = m[i];
		}

		prom = prom + m[i];

	}


	cout << "Los numeros son: \n";
	for (int i = 0; i < 10; i++) {
		cout << m[i] << "\n";

	}
	cout << "El numero mas alto: " << up << "El numero mas bajo: " << down << "El promedio: " << prom / 10;


	system("pause");



}