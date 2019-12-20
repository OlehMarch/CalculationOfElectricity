// PathOfCalc.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "PathOfCalc.h"
#include "afxdialogex.h"
#include "clocale"


// диалоговое окно CPathOfCalc

IMPLEMENT_DYNAMIC(CPathOfCalc, CDialog)

CPathOfCalc::CPathOfCalc(CWnd* pParent /*=NULL*/)
	: CDialog(CPathOfCalc::IDD, pParent)
	, editBrowse_pathOfCalc_v(_T(""))
	, edit_newFolder_v(_T(""))
{

}

CPathOfCalc::~CPathOfCalc()
{
}

void CPathOfCalc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, edit_newFolder_v);
	DDX_Text(pDX, IDC_MFCEDITBROWSE2, editBrowse_pathOfCalc_v);
	DDX_Text(pDX, IDC_EDIT1, edit_newFolder_v);
	DDV_MaxChars(pDX, edit_newFolder_v, 50);
}


BEGIN_MESSAGE_MAP(CPathOfCalc, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CPathOfCalc::OnBnClickedButton1)
END_MESSAGE_MAP()


// обработчики сообщений CPathOfCalc


void CPathOfCalc::OnBnClickedButton1()
{
	//Кнопка изменения пути
	UpdateData(TRUE);

	CStdioFile fileOfCalc;
	fileOfCalc.Open(_T("pathOfCalculations.fop"), CFile::modeCreate | CFile::modeReadWrite);
	CreateDirectory(editBrowse_pathOfCalc_v + _T("\\") + edit_newFolder_v, NULL);
	setlocale(LC_ALL, ".1251");
	fileOfCalc.WriteString(editBrowse_pathOfCalc_v + _T("\\") + edit_newFolder_v + _T("\\"));
	setlocale(LC_ALL, "eng");

	if (fileOfCalc != NULL) {
		MessageBox(_T("Смена места хранения расчетов\nуспешно завершена!"), _T("Внимание!"), MB_OK);
	}
	else {
		MessageBox(_T("Смена места хранения тарифов\nне выполнена! Неизвестная ошибка."), _T("Внимание!"), MB_OK);
	}
	fileOfCalc.Abort();

	UpdateData(FALSE);
	CDialog::OnOK();
}
