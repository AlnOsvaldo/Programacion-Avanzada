#include <windows.h>

using namespace std;

#define btn0 0
#define btn1 1
#define btn2 2
#define btn3 3
#define btn4 4
#define btn5 5
#define btn6 6
#define btn7 7
#define btn8 8
#define btn9 9
#define btnMult 10
#define btnDiv 11
#define btnSum 12
#define btnRes 13
#define btnLimpiar 14
#define btnIgual 15
#define btnFact 16

HWND hbtn1, hbtn2, hbtn3, hbtn4, hbtn5, hbtn6, hbtn7, hbtn8, hbtn9, hbtn0, hbtnMult, hbtnDiv, hbtnSum, hbtnRes, hbtnLimpiar, hbtnIgual, hbtnFact;

#define edit 17
HWND hEdit;

// Variables Globales
int LargBot = 40, AnchBot = 40;
long long Num1, Num2;
int Oper;

// Prototipos

// prototipo del callback procedure
LRESULT CALLBACK Otro(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
void Acumular(int n);
int factorial(int n);

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
	WNDCLASSEX wClass;
	ZeroMemory(&wClass,sizeof(WNDCLASSEX));
	wClass.cbClsExtra=NULL;
	wClass.cbSize=sizeof(WNDCLASSEX);
	wClass.cbWndExtra=NULL;
	wClass.hbrBackground=(HBRUSH)COLOR_WINDOW;
	wClass.hCursor=LoadCursor(NULL,IDC_HAND);
	wClass.hIcon=NULL;
	wClass.hIconSm=NULL;
	wClass.hInstance=hInst;
	wClass.lpfnWndProc=(WNDPROC)Otro; // defines el callback procedure
	wClass.lpszClassName="Window Class";
	wClass.lpszMenuName=NULL;
	wClass.style=CS_HREDRAW|CS_VREDRAW;

	if(!RegisterClassEx(&wClass))
	{
		int nResult=GetLastError();
		MessageBox(NULL,
			"Window class creation failed",
			"Window Class Failed",
			MB_ICONERROR);
	}

	HWND hWnd=CreateWindowEx(NULL,
		"Window Class", // Clase previamente definida
		"Calculadora", // Titulo de la ventana
		WS_OVERLAPPEDWINDOW,
		200, // x
		200, // y
		220, // width
		260, // height
		NULL,
		NULL,
		hInst,
		NULL);

	if(!hWnd)
	{
		int nResult=GetLastError();

		MessageBox(NULL,
			"Window creation failed",
			"Window Creation Failed",
			MB_ICONERROR);
	}

	ShowWindow(hWnd,nShowCmd);

	MSG msg;
	ZeroMemory(&msg,sizeof(MSG));

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

// definición del callback procedure
// se va a llamar de la función DispatchMessage
LRESULT CALLBACK Otro(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
	case WM_CREATE: 
		{ 
			// caja de edición
			hEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
				"EDIT", "0", 
				WS_CHILD|WS_VISIBLE|SS_RIGHT, 
				10, 10, 150, 30, 
				hWnd, 
				(HMENU)edit, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn0 = CreateWindowEx(NULL,
				"BUTTON", "0", 
				WS_VISIBLE|WS_CHILD,
				20, 170, AnchBot, LargBot,
				hWnd, (HMENU)btn0, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn1 = CreateWindowEx(NULL,
				"BUTTON", "1", 
				WS_VISIBLE|WS_CHILD,
				20, 130, AnchBot, LargBot,
				hWnd, (HMENU)btn1, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn2 = CreateWindowEx(NULL,
				"BUTTON", "2", 
				WS_VISIBLE|WS_CHILD,
				60, 130, AnchBot, LargBot,
				hWnd, (HMENU)btn2, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn3 = CreateWindowEx(NULL,
				"BUTTON", "3", 
				WS_VISIBLE|WS_CHILD,
				100, 130, AnchBot, LargBot,
				hWnd, (HMENU)btn3, 
				GetModuleHandle(NULL), 
				NULL);
			hbtnSum = CreateWindowEx(NULL,
				"BUTTON", "+", 
				WS_VISIBLE|WS_CHILD,
				140, 130, AnchBot, LargBot,
				hWnd, (HMENU)btnSum, 
				GetModuleHandle(NULL), 
				NULL);
			hbtnIgual = CreateWindowEx(NULL,
				"BUTTON", "=", 
				WS_VISIBLE|WS_CHILD,
				60, 170, AnchBot, LargBot,
				hWnd, (HMENU)btnIgual, 
				GetModuleHandle(NULL), 
				NULL);
			hbtnFact = CreateWindowEx(NULL,
				"BUTTON", "!", 
				WS_VISIBLE|WS_CHILD,
				100, 170, AnchBot, LargBot,
				hWnd, (HMENU)btnFact, 
				GetModuleHandle(NULL), 
				NULL);
			hbtnRes = CreateWindowEx(NULL,
				"BUTTON", "-", 
				WS_VISIBLE|WS_CHILD,
				140, 170, AnchBot, LargBot,
				hWnd, (HMENU)btnRes, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn4 = CreateWindowEx(NULL,
				"BUTTON", "4", 
				WS_VISIBLE|WS_CHILD,
				20, 90, AnchBot, LargBot,
				hWnd, (HMENU)btn4, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn5 = CreateWindowEx(NULL,
				"BUTTON", "5", 
				WS_VISIBLE|WS_CHILD,
				60, 90, AnchBot, LargBot,
				hWnd, (HMENU)btn5, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn6 = CreateWindowEx(NULL,
				"BUTTON", "6", 
				WS_VISIBLE|WS_CHILD,
				100, 90, AnchBot, LargBot,
				hWnd, (HMENU)btn6, 
				GetModuleHandle(NULL), 
				NULL);
			hbtnMult = CreateWindowEx(NULL,
				"BUTTON", "*", 
				WS_VISIBLE|WS_CHILD,
				140, 90, AnchBot, LargBot,
				hWnd, (HMENU)btnMult, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn7 = CreateWindowEx(NULL,
				"BUTTON", "7", 
				WS_VISIBLE|WS_CHILD,
				20, 50, AnchBot, LargBot,
				hWnd, (HMENU)btn7, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn8 = CreateWindowEx(NULL,
				"BUTTON", "8", 
				WS_VISIBLE|WS_CHILD,
				60, 50, AnchBot, LargBot,
				hWnd, (HMENU)btn8, 
				GetModuleHandle(NULL), 
				NULL);
			hbtn9 = CreateWindowEx(NULL,
				"BUTTON", "9", 
				WS_VISIBLE|WS_CHILD,
				100, 50, AnchBot, LargBot,
				hWnd, (HMENU)btn9, 
				GetModuleHandle(NULL), 
				NULL);
			hbtnLimpiar = CreateWindowEx(NULL,
				"BUTTON", "CE", 
				WS_VISIBLE|WS_CHILD,
				140, 50, AnchBot, LargBot,
				hWnd, (HMENU)btnLimpiar, 
				GetModuleHandle(NULL), 
				NULL);
			Num1 = 0;
			Num2 = 0;
		}
		break;

	case WM_COMMAND:
		{
			if(LOWORD(wParam)==btnLimpiar) 
			{
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)"0");
				Num1 = 0;
				Num2 = 0;
			}
			if(LOWORD(wParam)==btnFact) 
			{
				Num2 = factorial(Num1);
				Num1 = 0;
				char s_total[50]="0";
				itoa(Num2, s_total, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)s_total);
			}	
			if(LOWORD(wParam)==btnMult) 
			{
				Num2 = Num1;
				Num1 = 0;
				Oper = 1; // Mult
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)"0");
			}	
			if(LOWORD(wParam)==btnSum) 
			{
				Num2 = Num1;
				Num1 = 0;
				Oper = 2; // Sum
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)"0");
			}	
			if(LOWORD(wParam)==btnRes) 
			{
				Num2 = Num1;
				Num1 = 0;
				Oper = 3;  // Rest
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)"0");
			}	
			if(LOWORD(wParam)==btnIgual) 
			{
				long long Resultado = 0;
				switch(Oper)
				{
				case 1:
					Resultado = Num1 * Num2;
					break;
				case 2:
					Resultado = Num1 + Num2;
					break;
				case 3:
					Resultado = Num1 - Num2;
					break;
				}
				Num1 = 0;
				Num2 = 0;
				Oper = 0;
				char s_total[50]="0";
				itoa(Resultado, s_total, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)s_total);
			}	

			if(LOWORD(wParam)==btn0) 
			{
				char Num[50]="0";
				Acumular(0);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn1) 
			{
				char Num[50]="0";
				Acumular(1);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}

			if(LOWORD(wParam)==btn2) 
			{
				char Num[50]="0";
				Acumular(2);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn3) 
			{
				char Num[50]="0";
				Acumular(3);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn4) 
			{
				char Num[50]="0";
				Acumular(4);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn5) 
			{
				char Num[50]="0";
				Acumular(5);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn6) 
			{
				char Num[50]="0";
				Acumular(6);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn7) 
			{
				char Num[50]="0";
				Acumular(7);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn8) 
			{
				char Num[50]="0";
				Acumular(8);
				itoa(Num1, Num, 10);
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}
			if(LOWORD(wParam)==btn9) 
			{
				char Num[50]="0";
				Acumular(9);
				itoa(Num1, Num, 10); // BASE 10
				SendMessage((HWND)hEdit, (UINT) WM_SETTEXT, (WPARAM)1, (LPARAM)&Num);
			}			
		}
		break;
	case WM_LBUTTONDOWN:
		MessageBox(0, "WM_LBUTTONDOWN message.", "Msg", MB_OK);
		return 0;

	case WM_KEYDOWN:
		if( wParam == VK_ESCAPE )
			DestroyWindow(hWnd);
		else
		{
			MessageBox(0, "MENSAJE", "Factorial", MB_OK|MB_ICONASTERISK);
		}
		return 0;
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;
	}

	return DefWindowProc(hWnd,msg,wParam,lParam);
}


// funciones adicionales para otros procesos
int factorial(int n)
{
	if (n==0)
		return 1;
	else
		return n * factorial(n-1);
}

// Función para acumular el número para los cálculos
void Acumular(int n)
{
	Num1 = Num1*10 + n;
}