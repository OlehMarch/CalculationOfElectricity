
// Calculation Of Electricity 3.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CCalculationOfElectricity3App:
// � ���������� ������� ������ ��. Calculation Of Electricity 3.cpp
//

class CCalculationOfElectricity3App : public CWinApp
{
public:
	CCalculationOfElectricity3App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CCalculationOfElectricity3App theApp;