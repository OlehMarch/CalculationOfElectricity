// RateView.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "RateView.h"
#include "afxdialogex.h"
#include "clocale"


// диалоговое окно CRateView

IMPLEMENT_DYNAMIC(CRateView, CDialog)

CRateView::CRateView(CWnd* pParent /*=NULL*/)
	: CDialog(CRateView::IDD, pParent)
	, static_dayRate_v(_T(""))
	, static_dayRateMore100_v(_T(""))
	, static_nightPercent_v(_T(""))
	, static_kWh_v(_T(""))
{

}

CRateView::~CRateView()
{
}

void CRateView::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_DR, static_dayRate_v);
	DDV_MaxChars(pDX, static_dayRate_v, 10);
	DDX_Text(pDX, IDC_STATIC_DRMH, static_dayRateMore100_v);
	DDV_MaxChars(pDX, static_dayRateMore100_v, 10);
	DDX_Text(pDX, IDC_STATIC_NP, static_nightPercent_v);
	DDV_MaxChars(pDX, static_nightPercent_v, 5);
	DDX_Text(pDX, IDC_STATIC_KWH, static_kWh_v);
	DDV_MaxChars(pDX, static_kWh_v, 5);
}


BEGIN_MESSAGE_MAP(CRateView, CDialog)
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(IDOK, &CRateView::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений CRateView


void CRateView::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	//При активации окна выполняется отображение тарифа по умолчанию
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	UpdateData(TRUE);
	
	CStdioFile fileOfRate, defaultRate;
	fileOfRate.Open(_T("pathOfRate.fop"), CFile::modeRead); //считали путь
	CString pathOfRate;
	setlocale(LC_ALL, ".1251");
	fileOfRate.ReadString(pathOfRate);
	setlocale(LC_ALL, "eng");
	fileOfRate.Abort();
	defaultRate.Open(pathOfRate + _T("defaultRate.lor"), CFile::modeRead); //считали тариф
	
	defaultRate.ReadString(static_dayRate_v);
	defaultRate.ReadString(static_dayRateMore100_v);
	defaultRate.Abort();

	CStdioFile settings;
	if (settings.Open(_T("additionalRateSettings.lor"), CFile::modeReadWrite) == NULL) {
		settings.Open(_T("additionalRateSettings.lor"), CFile::modeCreate | CFile::modeWrite);
		CString str;
		static_kWh_v = _T("100");
		static_nightPercent_v = _T("50");
		str = static_kWh_v + _T("\n") + static_nightPercent_v;
		settings.WriteString(str);
	}
	else {
		settings.ReadString(static_kWh_v);
		settings.ReadString(static_nightPercent_v);
	}
	settings.Abort();
	
	UpdateData(FALSE);
}


void CRateView::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnOK();
}
