#pragma once
#include "afxcmn.h"


// диалоговое окно CAdditionalRateSettings

class CAdditionalRateSettings : public CDialog
{
	DECLARE_DYNAMIC(CAdditionalRateSettings)

public:
	CAdditionalRateSettings(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CAdditionalRateSettings();

// Данные диалогового окна
	enum { IDD = IDD_ADDITIONALRSTESETTINGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CSpinButtonCtrl spin_kWh_c;
	CSpinButtonCtrl spin_nightPercent_c;
	int edit_kWh_v;
	int edit_nightPercent_v;
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton3();
};
