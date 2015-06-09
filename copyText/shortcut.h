#ifndef SHORTCUT
#define SHORTCUT

#pragma once

#include <Windows.h>
#include <iostream>
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