// PathOfReadings.cpp: ���� ����������
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "PathOfReadings.h"
#include "afxdialogex.h"
#include "clocale"


// ���������� ���� CPathOfReadings

IMPLEMENT_DYNAMIC(CPathOfReadings, CDialog)

CPathOfReadings::CPathOfReadings(CWnd* pParent /*=NULL*/)
	: CDialog(CPathOfReadings::IDD, pParent)
	, editBrowse_pathChange_v(_T(""))
	, edit_nameOfDirectory_v(_T(""))
{

}

CPathOfReadings::~CPathOfReadings()
{
}

void CPathOfReadings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MFCEDITBROWSE2, editBrowse_pathChange_v);
	DDX_Text(pDX, IDC_EDIT1, edit_nameOfDirectory_v);
	DDV_MaxChars(pDX, edit_nameOfDirectory_v, 50);
}


BEGIN_MESSAGE_MAP(CPathOfReadings, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CPathOfReadings::OnBnClickedButton1)
END_MESSAGE_MAP()


// ����������� ��������� CPathOfReadings


void CPathOfReadings::OnBnClickedButton1()
{
	//������ ��������� ����
	UpdateData(TRUE);

	//MessageBox(editBrowse_pathChange_v, _T(""), MB_OK);
	
	CStdioFile fileOfPath;
	fileOfPath.Open(_T("pathOfReadings.fop"), CFile::modeCreate | CFile::modeReadWrite);
	CreateDirectory(editBrowse_pathChange_v + _T("\\") + edit_nameOfDirectory_v, NULL);
	setlocale(LC_ALL, ".1251");
	fileOfPath.WriteString(editBrowse_pathChange_v + _T("\\") + edit_nameOfDirectory_v + _T("\\"));
	setlocale(LC_ALL, "eng");

	if (fileOfPath != NULL) {
		MessageBox(_T("����� ����� �������� ���������\n������� ���������!"), _T("��������!"), MB_OK);
	}
	else {
		MessageBox(_T("����� ����� �������� ���������\n�� ���������! ����������� ������"), _T("��������!"), MB_OK);
	}
	fileOfPath.Abort();

	UpdateData(FALSE);
	CDialog::OnOK();
}
