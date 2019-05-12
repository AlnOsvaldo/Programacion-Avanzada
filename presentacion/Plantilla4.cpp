#include <windows.h>
#include <mmsystem.h>
#include "resource.h"

// Plantilla 4
// Creada por: MGTI Alejandro Villarreal
// OCT-2014
// WinAPI que al ejecutarse directamente abre una ventana cliente
// La ventana cliente tiene un Menú
// Al dar clic a una opción del menú abre un diálogo


// For dialog and menu resource.
// Store handles to the main window and application
// instance globally.
HWND ghMainWnd = 0;
HINSTANCE ghAppInst = 0;
HMENU ghMenu = 0;

// Define a window procedure for the dialog box:
// A dialog box is a kind of window, and as such we need to
// define a window procedure for it.
BOOL CALLBACK AboutDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
		// A WM_INITDIALOG message is sent right before the
		// dialog is displayed. This gives you a chance to
		// initialize any dialog related variables. For an
		// About Box, we do not need to do any initialization

		// so we just return true.
	case WM_INITDIALOG:
		return true;
		// We learned in the last chapter that a WM_COMMAND
		// message is sent when the user selects a menu item
		// from the menu. In addition to that, a WM_COMMAND
		// message is also sent when the user presses a
		// button control.
	case WM_COMMAND:
		// The low 16-bits of the wParam stores the resource
		// ID of the button control the user pressed. So from
		// that information, we can determine which button was
		// pressed.
		switch(LOWORD(wParam))
		{
			// Did the user press the OK button (resource ID = IDOK)?
			// If so, close the dialog box.
		case IDOK:
			MessageBox(0,"hola","ejemplo",MB_OKCANCEL|MB_ICONQUESTION);
			return true;
		case IDCANCEL:
			EndDialog(
				hDlg, // Handle to dialog to end.
				0); // Return code--generally always zero.
			return true;
		}
		break;
	}
	return false;
}

// Step 1: Define and implement the window procedure.
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
	case WM_COMMAND:
		switch( LOWORD(wParam) )
		{
		case ID_ARCHIVO_SALIR:
			DestroyWindow(ghMainWnd);
			return 0;
			// User click the “About” menu item?
		case ID_AYUDA_ACERCADE:
			//unsigned int t0 = (unsigned int)timeGetTime();
			LOGBRUSH lb;
			lb.lbStyle = BS_SOLID;
			lb.lbColor = RGB(64, 226, 163);
			HBRUSH blueBrush = CreateBrushIndirect(&lb);
			DialogBox(
				ghAppInst, // Application instance.
				MAKEINTRESOURCE(IDD_DIALOG1), // Dialog resource ID.
				hWnd, // Parent window of dialog box.
				AboutDlgProc); // Ptr to dialog box window procedure.
			return 0;
		}
		return 0;
		// Handle destroy window message.
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	// Forward any other messages we didn't handle to the
	// default window procedure.
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// WinMain: Entry point for a Windows application.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd)
{
	// Save handle to application instance.
	ghAppInst = hInstance;
	// Step 2: Fill out a WNDCLASS instance.
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = ghAppInst;
	wc.hIcon = ::LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = ::LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = "MyWndClassName";
	// Step 3: Register the WNDCLASS instance with Windows.
	RegisterClass( &wc );
	// Step 4: Create the window, and save handle in globla
	// window handle variable ghMainWnd.
	ghMenu = LoadMenu(ghAppInst, MAKEINTRESOURCE(IDR_MENU1));
	ghMainWnd = ::CreateWindow("MyWndClassName", "About Box",
		WS_OVERLAPPEDWINDOW, 0, 0, 540, 380, 0, ghMenu,
		ghAppInst, 0);
	if(ghMainWnd == 0)
	{
		::MessageBox(0, "CreateWindow - Failed", 0, 0);
		return false;
	}
	// Step 5: Show and update the window.
	ShowWindow(ghMainWnd, showCmd);
	UpdateWindow(ghMainWnd);
	// Step 6: Enter the message loop and don't quit until
	// a WM_QUIT message is received.
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while( GetMessage(&msg, 0, 0, 0) )
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	// Return exit code back to operating system.
	return (int)msg.wParam;
}
