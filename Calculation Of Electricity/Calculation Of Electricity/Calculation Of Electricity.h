
// Calculation Of Electricity.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CCalculationOfElectricityApp:
// � ���������� ������� ������ ��. Calculation Of Electricity.cpp
//

class CCalculationOfElectricityApp : public CWinApp
{
public:
	CCalculationOfElectricityApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CCalculationOfElectricityApp theApp;