#include <windows.h>
#include "resource.h"

using namespace std;

#define BUFFERSIZE 81

// Dialog handle.
HWND ghDlg = 0;

// Dialog window procedure.
BOOL CALLBACK MsgDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Text buffer to be filled with string user entered
	// into edit control.
	char msgText[256];

	// Handles to the combo box controls.
	static HWND hEditBox = 0;
	static HWND hSaveButt = 0;
	static HWND hOpenButt = 0;
	int index = 0;
	switch( msg )
	{
	case WM_INITDIALOG:

		// Controls are child windows to the dialog they lie on.
		// In order to get and send information to and from a
		// control we will need a handle to it. So save a handle
		// to the controls as the dialog is being initialized.
		// Recall that we get a handle to a child control on a
		// dialog box with the GetDlgItem.

		hOpenButt = GetDlgItem(hDlg, IDC_OPEN);
		hSaveButt = GetDlgItem(hDlg, IDC_SAVE);
		hEditBox = GetDlgItem(hDlg, IDC_EDIT);

		return true;
	case WM_COMMAND:
		switch(HIWORD(wParam))
		{
			// User selected a combo box item.
		//case default:
			return true;
		}
		switch(LOWORD(wParam))
		{
			// User pressed the "Open File" button.
		case IDC_OPEN:

			return true;
		case IDC_SAVE:

			
			return true;
		}
		return true;
	case WM_CLOSE:
		DestroyWindow(hDlg);
		return true;
	case WM_DESTROY:
		PostQuitMessage(0);
		return true;
	}
	return false;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd)
{
	// Create the modeless dialog window.
	ghDlg = CreateDialog(
		hInstance, // Application instance.
		MAKEINTRESOURCE(IDD_DIALOG1), // Dialog resource ID.
		0, // Parent window--null for no parent.
		MsgDlgProc); // Dialog window procedure.

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
