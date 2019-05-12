#include <windows.h>
#include <string>
#include "resource.h"

// Plantilla 2
// Creada por: MGTI Alejandro Villarreal
// OCT-2014
// WinAPI que al ejecutarse directamente muestra un Dialog
// Sin utilizar Ventana Cliente

using namespace std;

// Dialog handle.
HWND ghDlg = 0;
// Dialog window procedure.
// Prototype
BOOL CALLBACK EditDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR cmdLine, int showCmd)
{
	// Create the modeless dialog window. This program is a pure
	// dialog window application, and the dialog window is the
	// "main" window.
	ghDlg = CreateDialog(
		hInstance, // Application instance.
		MAKEINTRESOURCE(IDD_DIALOG1), // Dialog resource ID.
		0, // Parent window--null for no parent.
		EditDlgProc); // Dialog window procedure.
	// Show the dialog.
	ShowWindow(ghDlg, showCmd);
	// Enter the message loop.
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while( GetMessage( &msg, 0, 0, 0 ) )
	{
		// Is the message a dialog message? If so the function
		// IsDialogMessage will return true and then dispatch
		// the message to the dialog window procedure.
		// Otherwise, we process as the message as normal.
		if( ghDlg == 0 || !IsDialogMessage(ghDlg, &msg ) )
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}

BOOL CALLBACK EditDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Text buffer to be filled with string user entered
	// into edit control.
	char msgText[256];
	// Handle to the edit box control (ID = IDC_MSGTEXT).
	static HWND hEditBox = 0;
	switch( msg )
	{
	case WM_INITDIALOG:
		// Controls are child windows to the dialog they lie on.
		// In order to get and send information to and from a
		// control we will need a handle to it. So save a handle
		// to the edit box control as the dialog is being
		// initialized. Recall that we get a handle to a child
		// control on a dialog box with the GetDlgItem.
		hEditBox = GetDlgItem(hDlg, IDC_MSGTEXT);
		// Set some default text in the edit box.
		SetWindowText(hEditBox, "Enter a message here.");
		return true;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			// Extract the text from the edit box.
			GetWindowText(hEditBox, msgText, 256);
			// Now display the text in the edit box in
			// a message box.
			MessageBox(0, msgText, "Message", MB_OK+MB_ICONQUESTION);
			return true;		
		case IDC_BUTTON:
			SetWindowText(hEditBox, "");
			return true;
		case ID_ARCHIVO_SALIR:
			DestroyWindow(hDlg);
			return true;
		}
		return true;
		// If the dialog was closed (user pressed 'X' button)
		// then terminate the dialog.
	case WM_CLOSE:
		DestroyWindow(hDlg);
		return true;
	case WM_DESTROY:
		PostQuitMessage(0);
		return true;
	}
	return false;
}


