#pragma once


// ���������� ���� CDatePlaceView

class CDatePlaceView : public CDialog
{
	DECLARE_DYNAMIC(CDatePlaceView)

public:
	CDatePlaceView(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CDatePlaceView();

// ������ ����������� ����
	enum { IDD = IDD_DATAPLACEVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString static_readingsPath;
	CString static_ratesPath;
	CString static_calcsPath;
};
