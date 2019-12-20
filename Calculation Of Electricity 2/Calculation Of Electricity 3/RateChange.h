#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "afxdtctl.h"
#include "ATLComTime.h"


// диалоговое окно CRateChange

class CRateChange : public CDialog
{
	DECLARE_DYNAMIC(CRateChange)

public:
	CRateChange(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CRateChange();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeMfceditbrowse1();
	CButton button_pathOfRate_c;
	afx_msg void OnBnClickedButton2();
	CString editBrowse_rateChange_v;
	CSpinButtonCtrl spin_left_int_c;
	CSpinButtonCtrl spin_left_float_c;
	CSpinButtonCtrl spin_right_int_c;
	CSpinButtonCtrl spin_right_float_c;
	int edit_dayRate_int_v;
	int edit_dayRateMore100_int_v;
	int edit_dayRate_float_v;
	int edit_dayRateMore100_float_v;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	CEdit edit_dayRate_int_c;
	afx_msg void OnBnClickedOk();
	CStatic static_grn_left_c;
	CStatic static_grn_right_c;
	CStatic static_kopek_left_c;
	CStatic static_kopek_right_c;
	CStatic static_comma_left_c;
	CStatic static_comma_right_c;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CStatic static_dateTime_c;
	afx_msg void OnBnClickedButton5();
	CButton button_dateOfRateChange_c;
	CDateTimeCtrl dtp_dateOfRateChange_c;
	COleDateTime dtp_dateOfRateChange_v;
};
