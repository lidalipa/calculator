
// MFC_NUM2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCNUM2App:
// Сведения о реализации этого класса: MFC_NUM2.cpp
//

class CMFCNUM2App : public CWinApp
{
public:
	CMFCNUM2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCNUM2App theApp;
