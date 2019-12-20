#pragma once


// диалоговое окно CPathOfReadings

class CPathOfReadings : public CDialog
{
	DECLARE_DYNAMIC(CPathOfReadings)

public:
	CPathOfReadings(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CPathOfReadings();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString editBrowse_pathChange_v;
	CString edit_nameOfDirectory_v;
};
