
// Calculation Of Electricity 3.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCalculationOfElectricity3App:
// О реализации данного класса см. Calculation Of Electricity 3.cpp
//

class CCalculationOfElectricity3App : public CWinApp
{
public:
	CCalculationOfElectricity3App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCalculationOfElectricity3App theApp;