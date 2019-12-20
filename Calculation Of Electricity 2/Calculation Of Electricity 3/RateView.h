#pragma once


// диалоговое окно CRateView

class CRateView : public CDialog
{
	DECLARE_DYNAMIC(CRateView)

public:
	CRateView(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CRateView();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString static_dayRate_v;
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	CString static_dayRateMore100_v;
	afx_msg void OnBnClickedOk();
	CString static_nightPercent_v;
	CString static_kWh_v;
};
