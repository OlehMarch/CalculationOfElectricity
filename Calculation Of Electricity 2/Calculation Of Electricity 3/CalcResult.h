#pragma once
#include "afxwin.h"
#include "afxeditbrowsectrl.h"


// диалоговое окно CCalcResult

class CCalcResult : public CDialog
{
	DECLARE_DYNAMIC(CCalcResult)

public:
	CCalcResult(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CCalcResult();

// Данные диалогового окна
	enum { IDD = IDD_RESULT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString editBrowse_loadCalcs_v;
	CButton button_loadCalcs_c;
	afx_msg void OnEnChangeMfceditbrowse2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	CString dayDelta;
	CString nightDelta;
	CString day;
	CString night;
	CString dayMore100;
	CString nightMore100;
	CString overall;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CMFCEditBrowseCtrl editBrowse_loadCalcs_c;
};
