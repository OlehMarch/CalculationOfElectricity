// DatePlaceView.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "DatePlaceView.h"
#include "afxdialogex.h"
#include "MOSFile.h"
#include "clocale"


// диалоговое окно CDatePlaceView

IMPLEMENT_DYNAMIC(CDatePlaceView, CDialog)

CDatePlaceView::CDatePlaceView(CWnd* pParent /*=NULL*/)
	: CDialog(CDatePlaceView::IDD, pParent)
	, static_readingsPath(_T(""))
	, static_ratesPath(_T(""))
	, static_calcsPath(_T(""))
{

}

CDatePlaceView::~CDatePlaceView()
{
}

void CDatePlaceView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_READINGS, static_readingsPath);
	DDX_Text(pDX, IDC_STATIC_RATES, static_ratesPath);
	DDX_Text(pDX, IDC_STATIC_CALCS, static_calcsPath);
}


BEGIN_MESSAGE_MAP(CDatePlaceView, CDialog)
	ON_BN_CLICKED(IDOK, &CDatePlaceView::OnBnClickedOk)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// обработчики сообщений CDatePlaceView


void CDatePlaceView::OnBnClickedOk()
{
	CDialog::OnOK();
}


CString loadPath(LPCTSTR nameOfFile) {
	
	MOSFile *fileName = NULL;
	CString path;
	CStdioFile fileOfPath;

	if (fileName->FileExists(nameOfFile)) {
		fileOfPath.Open(nameOfFile, CFile::modeReadWrite);
		setlocale(LC_ALL, ".1251");
		fileOfPath.ReadString(path);
		setlocale(LC_ALL, "eng");
		fileOfPath.Close();
		if (path.Find(_T(":\\")) == -1) {
			TCHAR NPath[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, NPath);
			path = _T("\\") + path;
			path = NPath + path;
		}
		return path;
	}
	else {
		return _T("	Путь не найден!");
	}

}


int CDatePlaceView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	static_readingsPath = loadPath(_T("pathOfReadings.fop"));
	static_ratesPath = loadPath(_T("pathOfRate.fop"));
	static_calcsPath = loadPath(_T("pathOfCalculations.fop"));

	return 0;
}
