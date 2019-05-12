#include <windows.h>
#include <fstream>

// Plantilla 1
// Creada por: MGTI Alejandro Villarreal
// OCT-2014
// WinAPI que al ejecutarse muestra una Ventana Cliente
// Los objetos deben crearse por código
// Aqui no hay diálogos


struct TreeNode{
	int info;
	TreeNode * izq;
	TreeNode * der;
};

TreeNode * raiz = NULL;

int valor1, valor2, result;


LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance,
			HINSTANCE hPrevInstance,
			PSTR cmdLine,
			int showCmd)
	{
	// Define a windows class
	WNDCLASSEX wClass;
	ZeroMemory(&wClass,sizeof(WNDCLASSEX));

	wClass.cbClsExtra=NULL;
	wClass.cbSize=sizeof(WNDCLASSEX);
	wClass.cbWndExtra=NULL;
	wClass.hbrBackground=(HBRUSH)COLOR_WINDOW;
	wClass.hCursor=LoadCursor(NULL,IDC_NO);
	wClass.hIcon=NULL;
	wClass.hIconSm=NULL;
	wClass.hInstance=hInstance;
	wClass.lpfnWndProc=(WNDPROC)WinProc;
	wClass.lpszClassName="Window Class";
	wClass.lpszMenuName=NULL;
	wClass.style=CS_HREDRAW|CS_VREDRAW;
	
	// Register
	RegisterClassEx(&wClass);
	// Or Register and handle error
	if(!RegisterClassEx(&wClass))
	{
		int nResult=GetLastError();
		MessageBox(NULL,
			"Window class creation failed",
			"Window Class Failed",
			MB_ICONERROR);
	}
	// Create
	HWND hWnd = CreateWindowEx(NULL,
		"Window Class",
		"Windows application",
		WS_OVERLAPPEDWINDOW,
		200, // ubicacion X de la posición de la ventana
		200, // ubicacion Y de la posición de la ventana
		640, // tamaño de la ventana, width
		480, // height
		NULL,
		NULL,
		hInstance,
		NULL);
	
	/* Mostrar la ventana */
	ShowWindow(hWnd,showCmd);
	
	// configuración del centro de mensajes
	MSG msg;
	ZeroMemory(&msg,sizeof(MSG));

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

// Esta función es llamada por la función del API DispatchMessage() 

LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
		case WM_CREATE:
		{
			
			return 0;
		}
		break;

		case WM_COMMAND:
		{
			
			return 0;
		}
		break;
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
	}

	return DefWindowProc(hWnd,msg,wParam,lParam);
}
