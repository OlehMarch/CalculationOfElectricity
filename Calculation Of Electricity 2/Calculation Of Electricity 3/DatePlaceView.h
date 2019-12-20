#pragma once


// диалоговое окно CDatePlaceView

class CDatePlaceView : public CDialog
{
	DECLARE_DYNAMIC(CDatePlaceView)

public:
	CDatePlaceView(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CDatePlaceView();

// Данные диалогового окна
	enum { IDD = IDD_DATAPLACEVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString static_readingsPath;
	CString static_ratesPath;
	CString static_calcsPath;
};
