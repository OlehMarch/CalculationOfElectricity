// PathOfRates.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "PathOfRates.h"
#include "afxdialogex.h"
#include "clocale"


// диалоговое окно CPathOfRates

IMPLEMENT_DYNAMIC(CPathOfRates, CDialog)

CPathOfRates::CPathOfRates(CWnd* pParent /*=NULL*/)
	: CDialog(CPathOfRates::IDD, pParent)
	, edit_createDirectory_v(_T(""))
	, editBrowse_pathOfRatesChange_v(_T(""))
{

}

CPathOfRates::~CPathOfRates()
{
}

void CPathOfRates::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit_createDirectory_v);
	DDV_MaxChars(pDX, edit_createDirectory_v, 50);
	DDX_Text(pDX, IDC_MFCEDITBROWSE2, editBrowse_pathOfRatesChange_v);
}


BEGIN_MESSAGE_MAP(CPathOfRates, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CPathOfRates::OnBnClickedButton1)
END_MESSAGE_MAP()


// обработчики сообщений CPathOfRates


void CPathOfRates::OnBnClickedButton1()
{
	//Кнопка изменения пути
	UpdateData(TRUE);

	CStdioFile fileOfRate;
	fileOfRate.Open(_T("pathOfRate.fop"), CFile::modeCreate | CFile::modeReadWrite);
	CreateDirectory(editBrowse_pathOfRatesChange_v + _T("\\") + edit_createDirectory_v, NULL);
	setlocale(LC_ALL, ".1251");
	fileOfRate.WriteString(editBrowse_pathOfRatesChange_v + _T("\\") + edit_createDirectory_v + _T("\\"));
	setlocale(LC_ALL, "eng");

	if (fileOfRate != NULL) {
		MessageBox(_T("Смена места хранения тарифов\nуспешно завершена!"), _T("Внимание!"), MB_OK);
		CStdioFile defaultRate;
		defaultRate.Open(editBrowse_pathOfRatesChange_v + _T("\\") + edit_createDirectory_v + _T("\\defaultRate.lor"), CFile::modeCreate | CFile::modeReadWrite);
		defaultRate.WriteString(_T("0.4560\n"));
		defaultRate.WriteString(_T("0.7890"));
		defaultRate.Abort();
	}
	else {
		MessageBox(_T("Смена места хранения тарифов\nне выполнена! Неизвестная ошибка."), _T("Внимание!"), MB_OK);
	}
	fileOfRate.Abort();

	UpdateData(FALSE);
	CDialog::OnOK();
}
