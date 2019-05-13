#include <iostream>
#include <math.h>


using namespace std;

//estructura que tiene todo lo que ocupa una matrizz
struct matriz
{
	int id;
	int filas;
	int columnas;
	double elementos[10][10];
	matriz *sig;
};

//variables globales
float pi = 3.1516;
double angulo=35;
double x, y, z;
matriz *ultimo,*inicio=0,*aux,*auxoperacion,*matrizA,*matrizB;
matriz rotacionx, rotaciony, rotacionz,punto, quaternions;
int opc;
int ids = 1;

//prot funciones sec

//agrega los datos de la matriz
void agregamatriz();
//agrega a una lista de matrices
void agregalista();
//muestra la lista de matrices
void mostrar();
//suma una matriz A+B
void suma();
//resto una matriz A-B
void resta();
//multiplica A*B
void multiplicacion();
//rotar un punto con respecto a un plano 
void rotacion();
//rotacion de matriz cuaterniones
void quaternion();
//matriz por punto para traslacion etc
void matrixpunto();

//funcion princ
void main() {
	{
	{
		rotacionx.elementos[0][0] = 1;
		rotacionx.elementos[0][1] = 0;
		rotacionx.elementos[0][2] = 0;
		rotacionx.elementos[0][3] = 0;//
		rotacionx.elementos[1][0] = 0;
		rotacionx.elementos[1][1] = cos(angulo*pi / 180);
		rotacionx.elementos[1][2] = -sin(angulo*pi / 180);
		rotacionx.elementos[1][3] = 0;//
		rotacionx.elementos[2][0] = 0;
		rotacionx.elementos[2][1] = sin(angulo*pi / 180);
		rotacionx.elementos[2][2] = cos(angulo*pi / 180);
		rotacionx.elementos[2][3] = 0;//
		rotacionx.elementos[3][0] = 0;
		rotacionx.elementos[3][1] = 0;
		rotacionx.elementos[3][2] = 0;
		rotacionx.elementos[3][3] = 1;//
	}
	{
		rotaciony.elementos[0][0] = cos(angulo*pi / 180);
		rotaciony.elementos[0][1] = 0;
		rotaciony.elementos[0][2] = sin(angulo*pi / 180);
		rotaciony.elementos[0][3] = 0;//
		rotaciony.elementos[1][0] = 0;
		rotaciony.elementos[1][1] = 1;
		rotaciony.elementos[1][2] = 0;
		rotaciony.elementos[1][3] = 0;//
		rotaciony.elementos[2][0] = -sin(angulo*pi / 180);
		rotaciony.elementos[2][1] = 0;
		rotaciony.elementos[2][2] = cos(angulo*pi / 180);
		rotaciony.elementos[2][3] = 0;//
		rotaciony.elementos[3][0] = 0;
		rotaciony.elementos[3][1] = 0;
		rotaciony.elementos[3][2] = 0;
		rotaciony.elementos[3][3] = 1;//
	}
	{
		rotacionz.elementos[0][0] = cos(angulo*pi / 180);
		rotacionz.elementos[0][1] = sin(angulo*pi / 180);
		rotacionz.elementos[0][2] = 0;
		rotacionz.elementos[0][3] = 0;//
		rotacionz.elementos[1][0] = sin(angulo*pi / 180);
		rotacionz.elementos[1][1] = cos(angulo*pi / 180);
		rotacionz.elementos[1][2] = 0;
		rotacionz.elementos[1][3] = 0;//
		rotacionz.elementos[2][0] = 0;
		rotacionz.elementos[2][1] = 0;
		rotacionz.elementos[2][2] = 1;
		rotacionz.elementos[2][3] = 0;//
		rotacionz.elementos[3][0] = 0;
		rotacionz.elementos[3][1] = 0;
		rotacionz.elementos[3][2] = 0;
		rotacionz.elementos[3][3] = 1;//
	}

	rotacionx.columnas = 4;
	rotacionx.filas = 4;

	rotaciony.columnas = 4;
	rotaciony.filas = 4;

	rotacionz.columnas = 4;
	rotacionz.filas = 4;
}

	bool fab = 1;
	while (fab)
	{
		system("cls");
		cout << "1.Ingresar una matriz\n2.Muestra las matrices\n3.Suma\n4.Resta\n5.Multiplicacion\n6.Rotacion de un punto\n7.Matriz cuaternion\n8.Matriz por punto\n9.Salir";
		cout << "\nOpcion: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			agregamatriz();
			break;
		case 2:
			system("CLS");
			mostrar();
			cout << "\n";
			system("PAUSE");
			break;
		case 3:
			system("CLS");
			suma();
			break;
		case 4:
			system("CLS");
			resta();
			break;
		case 5:
			system("CLS");
			multiplicacion();
			break;
		case 6:
			system("CLS");
			rotacion();
			break;
		case 7:
			system("CLS");
			quaternion();
			break;
		case 8:
			system("CLS");
			matrixpunto();
			break;
		case 9:
			fab = 0;
			break;
		default:
			break;
		}
	}
}

//funciones sec
void agregamatriz() {
	
	system("cls");
	aux = new matriz;

	

	cout << "Ingrese las filas: ";
	while (1) {
		cin >> aux->filas;
		if (aux->filas > 0) {
			break;
		}
		else {
			cout << "Ingrese un numero de filas correcto";
		}
	}
	cout << "Ingrese las columnas: ";
	while (1) {
	cin >> aux->columnas;
	if (aux->columnas > 0) {
		break;
	}
	else {
		cout << "Ingrese un numero de columnas correcto";
	}
}


	for (int i = 0; i < aux->filas; i++) {
		for (int j = 0; j < aux->columnas; j++) {
			system("cls");
			cout << "Ingrese el elemnto[" << i + 1 << "][" << j + 1 << "]:";
			cin>>aux->elementos[i][j];
		}
	}
	system("cls");
	cout << "La matriz es:";

	for (int i = 0; i < aux->filas; i++) {
		cout << endl;
		for (int j = 0; j < aux->columnas; j++) {
			cout << "["<< aux->elementos[i][j] <<"]";
		}
	}
	agregalista();
	cout << "\n";
	system("Pause");
}
void agregalista() {
	aux->id = ids;
	ids++;

	if (inicio == 0) {
		inicio = aux;
		ultimo = aux;
		aux->sig = 0;
	}
	else {
		ultimo->sig = aux;
		ultimo = aux;
		aux->sig = 0;
	}
}
void mostrar() {
	aux = inicio;
	
	while (aux != 0) {
		cout << endl;
		cout << "La matriz " << aux->id << " es:\n";
		for (int i = 0; i < aux->filas; i++) {
			cout << endl;
			for (int j = 0; j < aux->columnas; j++) {
				cout << "[" << aux->elementos[i][j] << "]";
			}
		}
		aux=aux->sig;
	}
	
}
void suma() {


	if (inicio != 0) {
		int A, B;
		system("CLS");
		cout << "Se realizara A+B\n";
		mostrar();
		cout << " selecciona A:";
		cin >> A;
		mostrar();
		system("CLS");
		cout << " selecciona B:";
		cin >> B;

		aux = inicio;
		while (aux!=0)
		{
			if (aux->id == A) {
				matrizA = aux;
			}
			aux = aux->sig;
		}

		aux = inicio;
		while (aux != 0)
		{
			if (aux->id == B) {
				matrizB = aux;
			}
			aux = aux->sig;
		}
		if (matrizA->filas == matrizB->filas && matrizA->columnas == matrizB->columnas) {
			system("CLS");
			cout << "La matriz resultante es:";
			aux = new matriz;
			aux->columnas = matrizA->columnas;
			aux->filas = matrizA->filas;
			for (int i = 0; i < matrizA->filas; i++) {
				cout << endl;
				for (int j = 0; j < matrizA->columnas; j++) {
					aux->elementos[i][j]=matrizA->elementos[i][j]+ matrizB->elementos[i][j];
					cout << "[" << aux->elementos[i][j] << "]";
				}
			}
			agregalista();
			cout << "\n";
			cout << "Se guardo en la lista de matrices";
			cout << "\n";
			system("Pause");
		}
		else {
			cout << "Las dimensiones de la matriz A no son las mismas que las dimensiones de la matriz B";
			system("Pause");
		}
		
	}
	else
	{
		cout << "No hay matrices que operar";
		system("Pause");
	}
}
void resta() {


	if (inicio != 0) {
		int A, B;
		system("CLS");
		cout << "Se realizara A-B\n";
		mostrar();
		cout << " selecciona A:";
		cin >> A;
		system("CLS");
		mostrar();
		cout << " selecciona B:";
		cin >> B;

		aux = inicio;
		while (aux != 0)
		{
			if (aux->id == A) {
				matrizA = aux;
			}
			aux = aux->sig;
		}

		aux = inicio;
		while (aux != 0)
		{
			if (aux->id == B) {
				matrizB = aux;
			}
			aux = aux->sig;
		}
		if (matrizA->filas == matrizB->filas && matrizA->columnas == matrizB->columnas) {
			system("CLS");
			cout << "La matriz resultante es:";
			aux = new matriz;
			aux->columnas = matrizA->columnas;
			aux->filas = matrizA->filas;
			for (int i = 0; i < matrizA->filas; i++) {
				cout << endl;
				for (int j = 0; j < matrizA->columnas; j++) {
					aux->elementos[i][j] = matrizA->elementos[i][j] - matrizB->elementos[i][j];
					cout << "[" << aux->elementos[i][j] << "]";
				}
			}
			agregalista();
			cout << "\n";
			cout << "Se guardo en la lista de matrices";
			cout << "\n";
			system("Pause");
		}
		else {
			cout << "Las dimensiones de la matriz A no son las mismas que las dimensiones de la matriz B";
			system("Pause");
		}

	}
	else
	{
		cout << "No hay matrices que operar";
		system("Pause");
	}
}
void multiplicacion() {


	if (inicio != 0) {
		int A, B;
		system("CLS");
		cout << "Se realizara A*B\n";
		mostrar();
		cout << " selecciona A:";
		cin >> A;
		system("CLS");
		mostrar();
		cout << " selecciona B:";
		cin >> B;

		aux = inicio;
		while (aux != 0)
		{
			if (aux->id == A) {
				matrizA = aux;
			}
			aux = aux->sig;
		}

		aux = inicio;
		while (aux != 0)
		{
			if (aux->id == B) {
				matrizB = aux;
			}
			aux = aux->sig;
		}
		if (matrizA->filas == matrizB->columnas ) {
			system("CLS");
			cout << "La matriz resultante es:";
			aux = new matriz;
			aux->columnas = matrizA->columnas;
			aux->filas = matrizA->filas;

			for (int i = 0; i <matrizA->filas; i++) {
				for (int j = 0; j <matrizB->columnas; j++) {
					aux->elementos[i][j] = 0;
					for (int k = 0; k < matrizA->columnas; k++) {
						aux->elementos[i][j] = aux->elementos[i][j] + matrizA->elementos[i][k] * matrizB->elementos[k][j];
					}
				}
			}
			aux->filas = matrizA->filas;
			aux->columnas = matrizB->columnas;

			cout << "\n";
			for (int i = 0; i < aux->filas; i++) {
				cout << endl;
				for (int j = 0; j < aux->columnas; j++) {
					cout << "[" << aux->elementos[i][j] << "]";
				}
			}
			

			agregalista();
			cout << "\n";
			cout << "Se guardo en la lista de matrices";
			cout << "\n";
			system("Pause");
		}
		else {
			cout << "Las filas de A no son las mismas que las columnas de B";
			system("Pause");
		}

	}
	else
	{
		cout << "No hay matrices que operar";
		system("Pause");
	}
}
void rotacion() {
	cout << "Ingresa el punto (x, y, z)\nx:";
	cin >> x;
	cout << "y:";
	cin >> y;
	cout << "z:";
	cin >> z;
	{
		punto.filas = 4;
		punto.columnas = 4;
		punto.elementos[0][0] = 1;
		punto.elementos[0][1] = 0;
		punto.elementos[0][2] = 0;
		punto.elementos[0][3] = x;//
		punto.elementos[1][0] = 0;
		punto.elementos[1][1] = 1;
		punto.elementos[1][2] = 0;
		punto.elementos[1][3] = y;//
		punto.elementos[2][0] = 0;
		punto.elementos[2][1] = 0;
		punto.elementos[2][2] = 1;
		punto.elementos[2][3] = z;//
		punto.elementos[3][0] = 0;
		punto.elementos[3][1] = 0;
		punto.elementos[3][2] = 0;
		punto.elementos[3][3] = 1;//
	}
	matrizB =&punto;
	system("CLS");
	cout << "Seleccione respecto a que plano rotara\n1.X\n2.Y\n3.Z\nOpcion:";
	cin >> opc;
	switch (opc)
	{
	case 1:
		matrizA = &rotacionx;
		break;
	case 2:
		matrizA = &rotaciony;
		break;
	case 3:
		matrizA = &rotacionz;
		break;
	default:
		break;
	}

	cout << "Ingrese el angulo con el que se rotara:";
	cin >> angulo;
	if (matrizA->filas == matrizB->columnas) {
		system("CLS");
		cout << "La matriz resultante es:";
		aux = new matriz;
		aux->columnas = matrizA->columnas;
		aux->filas = matrizA->filas;

		for (int i = 0; i < matrizA->filas; i++) {
			for (int j = 0; j < matrizB->columnas; j++) {
				aux->elementos[i][j] = 0;
				for (int k = 0; k < matrizA->columnas; k++) {
					aux->elementos[i][j] = aux->elementos[i][j] + matrizA->elementos[i][k] * matrizB->elementos[k][j];
				}
			}
		}
		aux->filas = matrizA->filas;
		aux->columnas = matrizB->columnas;

		cout << "\n";
		for (int i = 0; i < aux->filas; i++) {
			cout << endl;
			for (int j = 0; j < aux->columnas; j++) {
				cout << "[" << aux->elementos[i][j] << "]";
			}
		}


		agregalista();
		cout << "\n";
		cout << "Se guardo en la lista de matrices";
		cout << "\n";
		system("Pause");
	}
}
void quaternion() {
	double vx, vy, vz;
	double u;
	cout << "Ingrese el punto (x,y,z)\nx:";
	cin >> x;
	cout << "y:";
	cin >> y;
	cout << "z:";
	cin >> z;
	system("CLS");
	cout << "Ingrese el vector: <a,b,c>\na:";
	cin >> vx;
	cout << "b:";
	cin >> vy;
	cout << "c:";
	cin >> vz;
	system("CLS");
	cout << "Ingrese el angulo:";
	cin >> angulo;
	angulo = angulo / 2;
	angulo = (angulo*pi / 180);
	//normalizar
	u = sqrt((vx*vx) + (vy*vy) + (vz*vz));
	vx = vx / u;
	vy = vy / u;
	vz = vz / u;
	//reciclar-preparar quaternion
	u = cos(angulo);
	//quaternion
	vx = vx * (angulo);
	vy = vy * (angulo);
	vz = vz * (angulo);
	//matrizquat
	{

		quaternions.columnas = 3;
		quaternions.filas = 3;
		quaternions.elementos[0][0] = 1 - (2 * pow(vy, 2)) - (2 * pow(vz, 2));
		quaternions.elementos[0][1] = (2 * vx * vy) - (2 * u * vz);
		quaternions.elementos[0][2] = (2 * vx * vz) + (2 * u * vy);

		quaternions.elementos[1][0] = (2 * vx * vy) + (2 * u * vz);
		quaternions.elementos[1][1] = 1 - (2 * vx * vx) - (2 * vz * vz);
		quaternions.elementos[1][2] = (2 * vy * vz) - (2 * u * vx);

		quaternions.elementos[2][0] = (2 * vx * vz) - (2 * u * vy);
		quaternions.elementos[2][1] = (2 * vy * vz) + (2 * u * vx);
		quaternions.elementos[2][2] = 1 - (2 * pow(vx, 2)) - (2 * pow(vy, 2));
	}

	matrizA = &quaternions;

	matriz matripunt;
	matripunt.columnas = 1;
	matripunt.filas = 3;
	matripunt.elementos[0][0] = x;
	matripunt.elementos[1][0] = y;
	matripunt.elementos[2][0] = z;

	matrizB = &matripunt;
	aux = new matriz;

	cout << "Los puntos rotados por vector son:";

	for (int i = 0; i < matrizA->filas; i++) {
		for (int j = 0; j < matrizB->columnas; j++) {
			aux->elementos[i][j] = 0;
			for (int k = 0; k < matrizA->columnas; k++) {
				aux->elementos[i][j] = aux->elementos[i][j] + matrizA->elementos[i][k] * matrizB->elementos[k][j];
			}
		}
	}
	aux->filas = matrizA->filas;
	aux->columnas = matrizB->columnas;

	cout << "\n";
	for (int i = 0; i < aux->filas; i++) {
		cout << endl;
		for (int j = 0; j < aux->columnas; j++) {
			cout << "[" << aux->elementos[i][j] << "]";
		}
	}

	agregalista();
	cout << "\n";
	cout << "Se guardo en la lista de matrices";
	cout << "\n";
	system("Pause");
}
void matrixpunto() {
	cout << "Selecciona la Matriz compuesta:";
	mostrar();
	
	cin >> opc;
	cout << "Ingrese el punto (x,y,z)\nx:";
	cin >> x;
	cout << "y:";
	cin >> y;
	cout << "z:";
	cin >> z;

	matriz matripunt;
	matripunt.columnas = 1;
	matripunt.filas = 4;
	matripunt.elementos[0][0] = x;
	matripunt.elementos[1][0] = y;
	matripunt.elementos[2][0] = z;
	matripunt.elementos[3][0] = 1;

	matrizB = &matripunt;

	aux = new matriz;
	aux = inicio;
	while (aux != 0)
	{
		if (aux->id == opc) {
			matrizA = aux;
		}
		aux = aux->sig;
	}
	if (matrizA->columnas == matrizB->filas) {
		cout << "El punto transformado es:";
		aux = new matriz;
		for (int i = 0; i < matrizA->filas; i++) {
			for (int j = 0; j < matrizB->columnas; j++) {
				aux->elementos[i][j] = 0;
				for (int k = 0; k < matrizA->columnas; k++) {
					aux->elementos[i][j] = aux->elementos[i][j] + matrizA->elementos[i][k] * matrizB->elementos[k][j];
				}
			}
		}
		aux->filas = matrizA->filas;
		aux->columnas = matrizB->columnas;

		cout << "\n";
		for (int i = 0; i < aux->filas; i++) {
			cout << endl;
			for (int j = 0; j < aux->columnas; j++) {
				cout << "[" << aux->elementos[i][j] << "]";
			}
		}
		system("PAUSE");
	}
	else {
		cout << "No se puede multiplicar esa matriz por el punto";
	}
}