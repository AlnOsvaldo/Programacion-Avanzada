BOOL CALLBACK DialogProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Definir variables HWND
	static HWND hObj1 = 0, hObj1 = 0;
	// Definir variables locales
	char usu[11], pas[11];

	switch (msg)
	{
	case WM_INITDIALOG:

		return true;
	case WM_HSCROLL:
		return true;
		
	case WM_VSCROLL:
		return true;
	
	case WM_SIZE:
		return true;
		
	case WM_COMMAND:
		if (HIWORD(wParam) == CBN_SELCHANGE)
		{
			if (LOWORD(wParam) == IDC_GENER)
			{
				
			}
		}
		switch (LOWORD(wParam))
		{
		
		}
		return true;
		// If the dialog was closed (user pressed 'X' button)
		// then terminate the dialog.
	case WM_CLOSE:
		MessageBox(hDlg, "Hasta pronto", "Aviso", MB_OK);
		return true;
	case WM_DESTROY:
		PostQuitMessage(0);
		return true;
	}
	return false;
}