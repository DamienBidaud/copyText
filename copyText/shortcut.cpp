#include "stdafx.h"
#include "shortcut.h"


shortcut::shortcut()
{
	RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, 0x43);
}


shortcut::~shortcut()
{
}


void shortcut::getSelectedText(){
	HWND test = GetForegroundWindow();
	if (test != nullptr){
		QClipboard *clipboard = QApplication::clipboard();


		QString data = clipboard->text();
		clipboard->clear();

		// Send WM_COPY message to the control with focus
		SAFEARRAY** array;
		TextPattern textpattern;
		SendMessage(test, WM_COPY, 0, 0);
		//SendMessage(fenetre, WM_COPY, WPARAM(0), LPARAM(0));
		QString tel = clipboard->text();
		clipboard->setText(data);
		qDebug() << tel;
	}

}