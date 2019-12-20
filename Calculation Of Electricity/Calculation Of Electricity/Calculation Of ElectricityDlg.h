
// Calculation Of ElectricityDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CCalculationOfElectricityDlg
class CCalculationOfElectricityDlg : public CDialogEx
{
// Создание
public:
	CCalculationOfElectricityDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_CALCULATIONOFELECTRICITY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	// DayRate
	float m_stat1;
	// NightRate
	float m_stat2;
	afx_msg void OnBnClickedButton2();
	// DayRate
//	int m_edit1;
	// DayRate
//	int m_edit1DR;
	CEdit m_edit1Ctrl;
	CEdit m_edit2Ctrl;
	CButton m_button1Ctrl;
//	afx_msg void OnEnChangeEdit1();
	int m_edit2;
//	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	// DayRate
	int m_edit1;
	afx_msg void OnBnClickedOk();
	// daytime readings of the previous month
	int m_edit3;
	// nighttime readings of the previous month
	int m_edit4;
	// daytime readings of the current month
	int m_edit5;
	// nighttime readings of the current month
	int m_edit6;
	afx_msg void OnEnChangeEdit3();
	// daytime consumation
	int m_stat3;
	// nighttime consumation
	int m_stat4;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit6();
	// daytime value of energy consumption
	float m_stat5;
	// nighttime value of energy consumption
	float m_stat6;
	// total cost of energy consumption
	float m_stat7;
	afx_msg void OnBnClickedButton5();
	CButton m_button2Ctrl;
	float m_stat0;
	afx_msg void OnBnClickedButton6();
	CStatic m_stat7Ctrl;
};
