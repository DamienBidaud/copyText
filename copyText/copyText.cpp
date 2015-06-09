// copyText.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "shortcut.h"

int _tmain(int argc, _TCHAR* argv[])
{
	shortcut s;
	MSG msg;



	while (GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		if (msg.message == WM_HOTKEY){
			if (msg.wParam == 1){
				s.getSelectedText();
			}
		}
	}
	return 0;
}

