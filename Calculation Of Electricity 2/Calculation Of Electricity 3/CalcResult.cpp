// CalcResult.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "CalcResult.h"
#include "afxdialogex.h"
#include "clocale"


// диалоговое окно CCalcResult

IMPLEMENT_DYNAMIC(CCalcResult, CDialog)

CCalcResult::CCalcResult(CWnd* pParent /*=NULL*/)
	: CDialog(CCalcResult::IDD, pParent)
	, editBrowse_loadCalcs_v(_T(""))
	, dayDelta(_T(""))
	, nightDelta(_T(""))
	, day(_T(""))
	, night(_T(""))
	, dayMore100(_T(""))
	, nightMore100(_T(""))
	, overall(_T(""))
{

}

CCalcResult::~CCalcResult()
{
}

void CCalcResult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MFCEDITBROWSE2, editBrowse_loadCalcs_v);
	DDX_Control(pDX, IDC_BUTTON3, button_loadCalcs_c);
	DDX_Text(pDX, IDC_STATIC_DAYDELTA, dayDelta);
	DDX_Text(pDX, IDC_STATIC_NIGHTDELTA, nightDelta);
	DDX_Text(pDX, IDC_STATIC_DAY, day);
	DDX_Text(pDX, IDC_STATIC_NIGHT, night);
	DDX_Text(pDX, IDC_STATIC_DAYMORE100, dayMore100);
	DDX_Text(pDX, IDC_STATIC_NIGHTMORE100, nightMore100);
	DDX_Text(pDX, IDC_STATIC_OVERALL, overall);
	DDX_Control(pDX, IDC_MFCEDITBROWSE2, editBrowse_loadCalcs_c);
}


BEGIN_MESSAGE_MAP(CCalcResult, CDialog)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE2, &CCalcResult::OnEnChangeMfceditbrowse2)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalcResult::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalcResult::OnBnClickedButton3)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// обработчики сообщений CCalcResult


void CCalcResult::OnEnChangeMfceditbrowse2()
{
	button_loadCalcs_c.EnableWindow(1);
}


void CCalcResult::OnBnClickedButton1()
{
	exit(0);
}


void CCalcResult::OnBnClickedButton3()
{
	// нопка загрузки расчетов
	UpdateData(TRUE);

	CStdioFile fileOfCalcPath, loadCalcFile;
	CString pathOfCalc;
	fileOfCalcPath.Open(_T("pathOfCalculations.fop"), CFile::modeRead);
	fileOfCalcPath.ReadString(pathOfCalc);
	fileOfCalcPath.Close();
	loadCalcFile.Open(pathOfCalc + editBrowse_loadCalcs_v, CFile::modeRead);
	
	if (editBrowse_loadCalcs_v.Find(_T("Calculation.lor")) != -1) {
		//возвращает -1 если не найдено, а если найдено - индекс начала подстроки

		CStdioFile file;
		file.Open(editBrowse_loadCalcs_v, CFile::modeRead);
		file.ReadString(dayDelta);
		file.ReadString(nightDelta);
		file.ReadString(day);
		file.ReadString(night);
		file.ReadString(dayMore100);
		file.ReadString(nightMore100);
		file.ReadString(overall);
		file.Close();
	}
	else {
		MessageBox(_T("”казан неверный файл!\n‘айл должен быть с рaсширением \"Calculation.lor\""), _T("¬нимание!"), MB_OK);
	}

	UpdateData(FALSE);
}


int CCalcResult::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	//реализаци€ подгрузки данных из файла
	CStdioFile fileOfCalc, lastCalcFile;
	CString pathOfCalc;
	fileOfCalc.Open(_T("pathOfCalculations.fop"), CFile::modeRead);
	setlocale(LC_ALL, ".1251");
	fileOfCalc.ReadString(pathOfCalc);
	setlocale(LC_ALL, "eng");
	fileOfCalc.Close();

	lastCalcFile.Open(pathOfCalc + _T("lastCalculation.lor"), CFile::modeRead);
	lastCalcFile.ReadString(dayDelta);
	lastCalcFile.ReadString(nightDelta);
	lastCalcFile.ReadString(day);
	lastCalcFile.ReadString(night);
	lastCalcFile.ReadString(dayMore100);
	lastCalcFile.ReadString(nightMore100);
	lastCalcFile.ReadString(overall);
	lastCalcFile.Close();

	return 0;
}
