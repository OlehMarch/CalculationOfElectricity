#pragma once


// ���������� ���� CPathOfRates

class CPathOfRates : public CDialog
{
	DECLARE_DYNAMIC(CPathOfRates)

public:
	CPathOfRates(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CPathOfRates();

// ������ ����������� ����
	enum { IDD = IDD_RATEPATH };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString edit_createDirectory_v;
	CString editBrowse_pathOfRatesChange_v;
	afx_msg void OnBnClickedButton1();
};
