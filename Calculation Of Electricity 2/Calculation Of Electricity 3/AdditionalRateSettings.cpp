// AdditionalRateSettings.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "AdditionalRateSettings.h"
#include "afxdialogex.h"
#include "MOSFile.h"


// диалоговое окно CAdditionalRateSettings

IMPLEMENT_DYNAMIC(CAdditionalRateSettings, CDialog)

CAdditionalRateSettings::CAdditionalRateSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CAdditionalRateSettings::IDD, pParent)
	, edit_kWh_v(0)
	, edit_nightPercent_v(0)
{

}

CAdditionalRateSettings::~CAdditionalRateSettings()
{
}

void CAdditionalRateSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, spin_kWh_c);
	DDX_Control(pDX, IDC_SPIN2, spin_nightPercent_c);
	DDX_Text(pDX, IDC_EDIT1, edit_kWh_v);
	DDV_MinMaxInt(pDX, edit_kWh_v, 10, 1000);
	DDX_Text(pDX, IDC_EDIT2, edit_nightPercent_v);
	DDV_MinMaxInt(pDX, edit_nightPercent_v, 1, 100);
}


BEGIN_MESSAGE_MAP(CAdditionalRateSettings, CDialog)
	ON_BN_CLICKED(IDOK, &CAdditionalRateSettings::OnBnClickedOk)
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(IDC_BUTTON2, &CAdditionalRateSettings::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAdditionalRateSettings::OnBnClickedButton1)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON3, &CAdditionalRateSettings::OnBnClickedButton3)
END_MESSAGE_MAP()


// обработчики сообщений CAdditionalRateSettings


int s_kWh = 100, s_nightPercent = 50;


void CAdditionalRateSettings::OnBnClickedOk()
{
	UpdateData(1);
	CStdioFile settings;
	CString str;
	settings.Open(_T("additionalRateSettings.lor"), CFile::modeCreate | CFile::modeWrite);
	str.Format(_T("%d\n%d"), edit_kWh_v, edit_nightPercent_v);
	settings.WriteString(str);
	settings.Abort();

	CDialog::OnCancel();
}


void CAdditionalRateSettings::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	
	spin_kWh_c.SetRange(10, 1000);
	spin_nightPercent_c.SetRange(1, 100);
	UpdateData(0);
}


void CAdditionalRateSettings::OnBnClickedButton2()
{
	//Restore defaults
	edit_kWh_v = 100;
	edit_nightPercent_v = 50;
	UpdateData(0);
}


void CAdditionalRateSettings::OnBnClickedButton1()
{
	//Reset
	edit_kWh_v = 10;
	edit_nightPercent_v = 1;
	UpdateData(0);
}


int CAdditionalRateSettings::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;


	return 0;
}


void CAdditionalRateSettings::OnBnClickedButton3()
{
	//Last used values
	
	CStdioFile settings;
	MOSFile *fileName = NULL;

	if (!fileName->FileExists(_T("additionalRateSettings.lor"))) {
		settings.Open(_T("additionalRateSettings.lor"), CFile::modeWrite);
		settings.WriteString(s_kWh + _T("\n") + s_nightPercent);
	}
	else {
		settings.Open(_T("additionalRateSettings.lor"), CFile::modeRead);
		CString str;
		settings.ReadString(str);
		s_kWh = _wtoi(str);
		settings.ReadString(str);
		s_nightPercent = _wtoi(str);
	}
	fileName->~MOSFile();
	settings.Close();

	edit_kWh_v = s_kWh;
	edit_nightPercent_v = s_nightPercent;

	UpdateData(0);
}
