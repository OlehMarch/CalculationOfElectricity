
// Calculation Of Electricity 2.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CCalculationOfElectricity2App:
// � ���������� ������� ������ ��. Calculation Of Electricity 2.cpp
//

class CCalculationOfElectricity2App : public CWinApp
{
public:
	CCalculationOfElectricity2App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CCalculationOfElectricity2App theApp;