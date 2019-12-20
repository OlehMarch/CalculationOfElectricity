
// Calculation Of Electricity.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCalculationOfElectricityApp:
// О реализации данного класса см. Calculation Of Electricity.cpp
//

class CCalculationOfElectricityApp : public CWinApp
{
public:
	CCalculationOfElectricityApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCalculationOfElectricityApp theApp;