#pragma once
#include "afxwin.h"


// ���������� ���� CPathOfCalc

class CPathOfCalc : public CDialog
{
	DECLARE_DYNAMIC(CPathOfCalc)

public:
	CPathOfCalc(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CPathOfCalc();

// ������ ����������� ����
	enum { IDD = IDD_CALCPATHCHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString editBrowse_pathOfCalc_v;
	CString edit_newFolder_v;
	afx_msg void OnBnClickedButton1();
};
