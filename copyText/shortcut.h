#ifndef SHORTCUT
#define SHORTCUT

#pragma once

#include <Windows.h>
#include <iostream>
#include <Richedit.h>
#include <atlstr.h>
#include <stdio.h> 
#include <conio.h> 
#include <Windowsx.h>
#include <UIAutomation.h>
#include <UIAutomationClient.h>
using namespace std;

#define WM_GETTEXT 0x000D
#define WM_COPY    0x0301

class shortcut
{
public:
	shortcut();
	~shortcut();
	void getSelectedText();
	
};

#endif SHORTCUT