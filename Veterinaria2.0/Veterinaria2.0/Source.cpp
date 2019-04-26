#include <Windows.h>
#include"resource.h"


using namespace std;

//estructura
struct nodo {
	nodo *prev;
	char nombre[200];
	char fecha[200];
	char nombrem[200];
	char telefono[200];
	char hora[200];
	char motivo[200];
	char especie[200];
	char costo[200];
	nodo *sig;
};


//cososglobales
nodo *inicio=0, *ultimo=0, _aux;
bool aceptado = 0;
HINSTANCE hInst;
HWND hWnd;
int cont = 0;


//funciones
BOOL CALLBACK Agenda(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK AgregarCita(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Informacion(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK VerCita(HWND, UINT, WPARAM, LPARAM);
void validar(HWND);
void agregar();


int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR cmdLine, int CShow) {
	hInst = hIns;
	hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Agenda);
	ShowWindow(hWnd, CShow);
	UpdateWindow(hWnd);
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
BOOL CALLBACK Agenda(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {


	


	switch (message) {
	case WM_INITDIALOG:
	{
		

	}
		break;




	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_INFORMACION_INFO:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG3), hDlg, Informacion);
			break;
		case IDC_VERCITA:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG4), hDlg, VerCita);
			break;

		case IDC_SALIR1:
			PostQuitMessage(0);
			break;
		case IDC_AGREGACITA:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hDlg, AgregarCita);
			break;
		}
		break;

	default:
		DefWindowProc(hDlg, message, wParam, lParam);
		break;
	}
	return 0;
}
BOOL CALLBACK AgregarCita(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {

	case WM_INITDIALOG:
	{
		static HWND hCboSpc = 0;

		hCboSpc = GetDlgItem(hDlg, IDC_COMBO1);

		SendMessage(hCboSpc, CB_ADDSTRING, 0, (LPARAM)"Perro");
		SendMessage(hCboSpc, CB_ADDSTRING, 0, (LPARAM)"Gato");
		SendMessage(hCboSpc, CB_ADDSTRING, 0, (LPARAM)"Conejo");
		SendMessage(hCboSpc, CB_ADDSTRING, 0, (LPARAM)"Caballo");
		SendMessage(hCboSpc, CB_ADDSTRING, 0, (LPARAM)"Piton");
		SendMessage(hCboSpc, CB_ADDSTRING, 0, (LPARAM)"Anaconda");




		return true; }

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_AGREGAR:
		{
			SendDlgItemMessage(hDlg, IDC_EDIT1, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.nombre);
			SendDlgItemMessage(hDlg, IDC_DATETIMEPICKER1, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.fecha);
			SendDlgItemMessage(hDlg, IDC_EDIT2, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.nombrem);
			SendDlgItemMessage(hDlg, IDC_EDIT3, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.telefono);
			SendDlgItemMessage(hDlg, IDC_DATETIMEPICKER2, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.hora);
			SendDlgItemMessage(hDlg, IDC_COMBO1, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.especie);
			SendDlgItemMessage(hDlg, IDC_EDIT4, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.motivo);
			SendDlgItemMessage(hDlg, IDC_EDIT5, WM_GETTEXT, sizeof(_aux.nombre), (LPARAM)_aux.costo);
			validar(hDlg);
			if (aceptado) {
				SendDlgItemMessage(hDlg, IDC_EDIT1, WM_SETTEXT, sizeof(_aux.nombre), (LPARAM)"");
				SendDlgItemMessage(hDlg, IDC_EDIT2, WM_SETTEXT, sizeof(_aux.nombre), (LPARAM)"");
				SendDlgItemMessage(hDlg, IDC_EDIT3, WM_SETTEXT, sizeof(_aux.nombre), (LPARAM)"");
				SendDlgItemMessage(hDlg, IDC_COMBO1, WM_SETTEXT, sizeof(_aux.nombre), (LPARAM)"");
				SendDlgItemMessage(hDlg, IDC_EDIT4, WM_SETTEXT, sizeof(_aux.nombre), (LPARAM)"");
				SendDlgItemMessage(hDlg, IDC_EDIT5, WM_SETTEXT, sizeof(_aux.nombre), (LPARAM)"");
			}
			break;
		}
		case IDC_SALIR2:

			
			EndDialog(hDlg, 0);
			break;
		}
		break;

	default:
		DefWindowProc(hDlg, message, wParam, lParam);
		break;
	}
	return 0;
}
BOOL CALLBACK Informacion(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_SALIR3:
			EndDialog(hDlg, 0);
			break;
		}
		break;

	default:
		DefWindowProc(hDlg, message, wParam, lParam);
		break;
	}
	return 0;
}
BOOL CALLBACK VerCita(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_SALIR2:
			EndDialog(hDlg, 0);
			break;
		}
		break;

	default:
		DefWindowProc(hDlg, message, wParam, lParam);
		break;
	}
	return 0;
}
void agregar() {

	nodo *aux = new nodo;

	*aux = _aux;

	if (inicio == 0) {
		
		inicio = aux;
		aux->sig = 0;
		ultimo = aux;
	}
	else {
		aux->prev = ultimo;
		ultimo->sig = aux;
		ultimo = aux;
		aux->sig = 0;
	}

	BOOL CALLBACK Agenda(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
}
void validar(HWND hDlg) {

	aceptado = 0;

	int numerotel=0;
	
	for (int i = 0; _aux.telefono[i] != NULL; i++) {
		numerotel++;
	}


	if (!aceptado) {
		if (_aux.nombre[0] != 0) {
			if (numerotel == 8 || numerotel == 10 || numerotel == 12) {
				if (_aux.costo[0] != 0) {
					{
						if (_aux.especie[0] != 0) {
							MessageBox(hDlg, "La consulta se agrego correctamente", "Hurra!", MB_OK | MB_ICONINFORMATION);
							aceptado = 1;
						}
						else {
							MessageBox(hDlg, "Ingrese la especie de la mascota", "Error", MB_OK | MB_ICONERROR);
						}
					}
				}
				else {
					MessageBox(hDlg, "Ingrese el costo de la consulta", "Error", MB_OK | MB_ICONERROR);
				}
				
			}
			else {
				MessageBox(hDlg, "Ingresa numero de telefono valido", "Error", MB_OK | MB_ICONERROR);
			}
		}
		else {
			MessageBox(hDlg, "Ingrese el nombre del dueño", "Error", MB_OK | MB_ICONERROR);
		}





		if (aceptado) {
			agregar();
		}
	}



}
