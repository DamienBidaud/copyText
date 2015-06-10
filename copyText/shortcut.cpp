#include "stdafx.h"
#include "shortcut.h"


shortcut::shortcut()
{
	RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, 0x44);
}


shortcut::~shortcut()
{
	UnregisterHotKey(NULL, 1);
}


void shortcut::getSelectedText(){
	//HWND test = GetForegroundWindow();
	int key_count = 4;
	Sleep(1000);
	OpenClipboard(NULL);
	EmptyClipboard();
	CloseClipboard();
	INPUT* input = new INPUT[key_count];
	for (int i = 0; i < key_count; i++)
	{
		input[i].ki.dwFlags = 0;
		input[i].type = INPUT_KEYBOARD;
	}

	input[0].ki.wVk = VK_CONTROL;
	input[0].ki.wScan = MapVirtualKey(VK_CONTROL, MAPVK_VK_TO_VSC);
	input[1].ki.wVk = 'C'; 
	input[1].ki.wScan = MapVirtualKey('C', MAPVK_VK_TO_VSC);
	input[2].ki.dwFlags = KEYEVENTF_KEYUP;
	input[2].ki.wVk = input[0].ki.wVk;
	input[2].ki.wScan = input[0].ki.wScan;
	input[3].ki.dwFlags = KEYEVENTF_KEYUP;
	input[3].ki.wVk = input[1].ki.wVk;
	input[3].ki.wScan = input[1].ki.wScan;

	if (!SendInput(key_count, (LPINPUT)input, sizeof(INPUT)))
	{
		cout << "end" << endl;
	}
	Sleep(6000);
	if (OpenClipboard(NULL)){
		cout << "Clipboard open" << endl;
		cout << "Clipboard not empty" << endl;
		HANDLE pText = GetClipboardData(CF_TEXT);
		if (pText != NULL){
			LPVOID text = GlobalLock(pText);
			if ((char*)text != nullptr){
				cout << (char*)text;
				cout << "" << endl;
			}
			else{
				cout << "char empty" << endl;
			}
		}
		CloseClipboard();
	}

}