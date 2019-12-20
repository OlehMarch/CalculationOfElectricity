
// Calculation Of Electricity 2Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// диалоговое окно CCalculationOfElectricity2Dlg
class CCalculationOfElectricity2Dlg : public CDialogEx
{
// Создание
public:
	CCalculationOfElectricity2Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_CALCULATIONOFELECTRICITY2_DIALOG };

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
	float m_stat0;
	float m_stat1;
	float m_stat2;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	CEdit m_edit1Ctrl;
	CEdit m_edit2Ctrl;
	CButton m_button1Ctrl;
	int m_edit1;
	int m_edit2;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButton4();
	CSpinButtonCtrl m_spin1Ctrl;
	CSpinButtonCtrl m_spin2Ctrl;
	CSpinButtonCtrl m_spin3Ctrl;
	CSpinButtonCtrl m_spin4Ctrl;
	CSpinButtonCtrl m_spin5Ctrl;
	CSpinButtonCtrl m_spin6Ctrl;
	int m_edit3;
	int m_edit4;
	int m_edit5;
	int m_edit6;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	int m_stat3;
	int m_stat4;
	CButton m_button2Ctrl;
	afx_msg void OnBnClickedButton2();
	CString m_stat5;
	CString m_stat6;
	CString m_stat7;
	CButton m_button3Ctrl;
	afx_msg void OnBnClickedButton6();
	CStatic m_stat8Ctrl;
	CEdit m_edit3Ctrl;
	CEdit m_edit4Ctrl;
	CEdit m_edit5Ctrl;
	CEdit m_edit6Ctrl;
	CStatic m_stat9Ctrl;
};
