
// Calculation Of Electricity 2.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCalculationOfElectricity2App:
// О реализации данного класса см. Calculation Of Electricity 2.cpp
//

class CCalculationOfElectricity2App : public CWinApp
{
public:
	CCalculationOfElectricity2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCalculationOfElectricity2App theApp;