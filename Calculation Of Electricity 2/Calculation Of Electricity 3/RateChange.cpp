// RateChange.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "RateChange.h"
#include "AdditionalRateSettings.h"
#include "afxdialogex.h"
#include "clocale"
#include "MOSFile.h"


// диалоговое окно CRateChange

IMPLEMENT_DYNAMIC(CRateChange, CDialog)

CRateChange::CRateChange(CWnd* pParent /*=NULL*/)
	: CDialog(CRateChange::IDD, pParent)
	, editBrowse_rateChange_v(_T(""))
	, edit_dayRate_int_v(0)
	, edit_dayRateMore100_int_v(0)
	, edit_dayRate_float_v(0)
	, edit_dayRateMore100_float_v(0)
	, dtp_dateOfRateChange_v(COleDateTime::GetCurrentTime())
{
}

CRateChange::~CRateChange()
{
}

void CRateChange::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, button_pathOfRate_c);
	DDX_Text(pDX, IDC_MFCEDITBROWSE1, editBrowse_rateChange_v);
	DDX_Control(pDX, IDC_SPIN1, spin_left_int_c);
	DDX_Control(pDX, IDC_SPIN3, spin_left_float_c);
	DDX_Control(pDX, IDC_SPIN5, spin_right_int_c);
	DDX_Control(pDX, IDC_SPIN2, spin_right_float_c);
	DDX_Text(pDX, IDC_EDIT1, edit_dayRate_int_v);
	DDV_MinMaxInt(pDX, edit_dayRate_int_v, 0, 10);
	DDX_Text(pDX, IDC_EDIT5, edit_dayRateMore100_int_v);
	DDV_MinMaxInt(pDX, edit_dayRateMore100_int_v, 0, 10);
	DDX_Text(pDX, IDC_EDIT3, edit_dayRate_float_v);
	DDV_MinMaxInt(pDX, edit_dayRate_float_v, 0, 99999);
	DDX_Text(pDX, IDC_EDIT2, edit_dayRateMore100_float_v);
	DDV_MinMaxInt(pDX, edit_dayRateMore100_float_v, 0, 99999);
	DDX_Control(pDX, IDC_EDIT1, edit_dayRate_int_c);
	DDX_Control(pDX, IDC_STATIC1, static_grn_left_c);
	DDX_Control(pDX, IDC_STATIC3, static_grn_right_c);
	DDX_Control(pDX, IDC_STATIC2, static_kopek_left_c);
	DDX_Control(pDX, IDC_STATIC4, static_kopek_right_c);
	DDX_Control(pDX, IDC_STATIC_C1, static_comma_left_c);
	DDX_Control(pDX, IDC_STATIC_C2, static_comma_right_c);
	DDX_Control(pDX, IDC_STATIC_DATE2, static_dateTime_c);
	DDX_Control(pDX, IDC_BUTTON5, button_dateOfRateChange_c);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, dtp_dateOfRateChange_c);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, dtp_dateOfRateChange_v);
}


BEGIN_MESSAGE_MAP(CRateChange, CDialog)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CRateChange::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRateChange::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CRateChange::OnBnClickedButton1)
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(IDOK, &CRateChange::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CRateChange::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRateChange::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CRateChange::OnBnClickedButton5)
END_MESSAGE_MAP()


// обработчики сообщений CRateChange

void CRateChange::OnEnChangeMfceditbrowse1()
{
	//Поле выбора файла для загрузки тарифов
	button_pathOfRate_c.EnableWindow(1);
}


int sameLengthOfFloatPart(CString rate, int rate_int, int rate_float) {
	//преобразование дневного тарифа для эдит
	
	float temp = _wtof(rate) - (float)rate_int;
	for (int i = 0; i < (int)rate.GetLength() - 2; ++i) {
		temp *= 10;
	}
	rate_float = (int)temp;

	return rate_float;
}


void CRateChange::OnBnClickedButton2()
{
	//кнопка загрузки тарифов
	UpdateData(TRUE);

	if (editBrowse_rateChange_v.Find(_T("Rate.lor")) != -1) {
		//возвращает -1 если не найдено, а если найдено - индекс начала подстроки

		CString dayRate, dayRateMore100;
		int dayRate_int = 0, dayRate_float = 0, dayRateMore100_int = 0, dayRateMore100_float = 0;
		CStdioFile file;
		file.Open(editBrowse_rateChange_v, CFile::modeRead);
		file.ReadString(dayRate);
		file.ReadString(dayRateMore100);
		file.Abort();
		
		//преобразование дневного тарифа меньше 100 кВт для эдит
		dayRate_int = _wtoi(dayRate);
		dayRate_float = sameLengthOfFloatPart(dayRate, dayRate_int, dayRate_float);
		
		//преобразование дневного тарифа больше 100 кВт в эдит
		dayRateMore100_int = _wtoi(dayRateMore100);
		dayRateMore100_float = sameLengthOfFloatPart(dayRateMore100, dayRateMore100_int, dayRateMore100_float);
		
		//Загрузка в форму тарифов
		edit_dayRate_int_v = dayRate_int;
		edit_dayRate_float_v = dayRate_float;
		edit_dayRateMore100_int_v = dayRateMore100_int;
		edit_dayRateMore100_float_v = dayRateMore100_float;
		
	}
	else {
		MessageBox(_T("Указан неверный файл!\nФайл должен быть с рaсширением \"Rate.lor\""), _T("Внимание!"), MB_OK);
	}

	UpdateData(FALSE);
}


void CRateChange::OnBnClickedButton1()
{
	UpdateData(TRUE);
	edit_dayRate_int_v = 0;
	edit_dayRate_float_v = 0;
	edit_dayRateMore100_int_v = 0;
	edit_dayRateMore100_float_v = 0;
	UpdateData(FALSE);
}


void CRateChange::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	UpdateData(TRUE);
	spin_left_int_c.SetRange(0, 10);
	spin_left_float_c.SetRange(0, 9999);
	spin_right_int_c.SetRange(0, 10);
	spin_right_float_c.SetRange(0, 9999);
	edit_dayRate_int_c.SetFocus();
	//Шрифт для подсказки под эдитами
	CFont *font;
	font = new CFont;
	font->CreateFont(13, 0, 0, 0, FW_MEDIUM, TRUE, TRUE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, L"Verdana");
	static_grn_left_c.SetFont(font);
	static_kopek_left_c.SetFont(font);
	static_grn_right_c.SetFont(font);
	static_kopek_right_c.SetFont(font);
	static_dateTime_c.SetFont(font);
	LOGFONT log;
	font->GetLogFont(&log);
	//Шрифт для запятых
	font = new CFont;
	font->CreateFont(40, 0, 0, 0, FW_MEDIUM, TRUE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, NULL);
	static_comma_left_c.SetFont(font);
	static_comma_right_c.SetFont(font);
	font->GetLogFont(&log);
	UpdateData(FALSE);
}


bool dateTimeOfRate = false;

CString floatPartRateFormat(int floatPartOfRate, int intPartOfRate, CString overallRate) {
	
	CString str;
	if ((floatPartOfRate < 1000) && (floatPartOfRate != 0)) {
		int counter = 0;
		for (int value = floatPartOfRate; value > 0; value /= 10, counter++) {}
		for (int i = 0; i < 4 - counter; ++i) {
			str += _T("0");
		}
	}
	else if (floatPartOfRate == 0) {
		str = _T("000");
	}
	overallRate.Format(_T("%d.%d") + str + _T("\n"), intPartOfRate, floatPartOfRate);

	return overallRate;
}


void CRateChange::OnBnClickedOk()
{
	UpdateData(TRUE);
	
	//Проверка на наличие файла пути сохранения 
	CStdioFile fileOfRate;
	CString pathOfRate;
	MOSFile *fileName = NULL;

	if (!fileName->FileExists(_T("pathOfRate.fop"))) {
		pathOfRate = _T("Rates\\");
		TCHAR NPath[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, NPath); //получаем текущую директорию
		CreateDirectory((CString)NPath + _T("\\") + pathOfRate, NULL);
		fileOfRate.Open(_T("pathOfRate.fop"), CFile::modeCreate | CFile::modeReadWrite);
		fileOfRate.WriteString(pathOfRate);
	}
	else {
		fileOfRate.Open(_T("pathOfRate.fop"), CFile::modeRead);
		setlocale(LC_ALL, ".1251");
		fileOfRate.ReadString(pathOfRate);
		setlocale(LC_ALL, "eng");
	}
	fileName->~MOSFile();
	fileOfRate.Abort();
	
	//Создание имени файла лога и запись нового тарифа в файл тарифа по умолчанию
	CStdioFile file, defaultFile;
	CString time, rate;
	
	if (dateTimeOfRate == false) {
		time = CTime::GetCurrentTime().Format("%m-%d-%Y %H-%M-%S");
	}
	else {
		time = dtp_dateOfRateChange_v.Format(_T("%m-%d-%Y"));
	}
	
	file.Open(pathOfRate + time + _T(" Rate.lor"), CFile::modeCreate | CFile::modeWrite);
	defaultFile.Open(pathOfRate + _T("defaultRate.lor"), CFile::modeCreate | CFile::modeWrite);

	rate = floatPartRateFormat(edit_dayRate_float_v, edit_dayRate_int_v, rate);
	file.WriteString(rate);
	defaultFile.WriteString(rate);
	rate = _T("");
	rate = floatPartRateFormat(edit_dayRateMore100_float_v, edit_dayRateMore100_int_v, rate);
	file.WriteString(rate);
	defaultFile.WriteString(rate);

	MessageBox(_T("Тариф успешно изменен!"), _T("Внимание!"), MB_OK);

	file.Abort();
	defaultFile.Abort();

	UpdateData(FALSE);
	CDialog::OnOK();
}


void CRateChange::OnBnClickedButton3()
{
	//доп настройки тарифа
	CAdditionalRateSettings dlg;
	dlg.DoModal();
}


void CRateChange::OnBnClickedButton4()
{
	//загрузка текущуго тарифа
	UpdateData(1);

	CStdioFile fileOfRate;
	CString pathOfRate;
	if (fileOfRate.Open(_T("pathOfRate.fop"), CFile::modeReadWrite) == NULL) {
		MessageBox(_T("Файл с тарифом по умолчанию не найден!"), _T("Внимание!"), MB_OK);
	}
	else {
		setlocale(LC_ALL, ".1251");
		fileOfRate.ReadString(pathOfRate);
		setlocale(LC_ALL, "eng");

		CString dayRate, dayRateMore100;
		int dayRate_int = 0, dayRate_float = 0, dayRateMore100_int = 0, dayRateMore100_float = 0;
		CStdioFile file;
		file.Open(pathOfRate + _T("\\defaultRate.lor"), CFile::modeRead);
		file.ReadString(dayRate);
		file.ReadString(dayRateMore100);
		file.Abort();	

		//преобразование дневного тарифа меньше 100 кВт для эдит
		dayRate_int = _wtoi(dayRate);
		dayRate_float = sameLengthOfFloatPart(dayRate, dayRate_int, dayRate_float);

		//преобразование дневного тарифа больше 100 кВт в эдит
		dayRateMore100_int = _wtoi(dayRateMore100);
		dayRateMore100_float = sameLengthOfFloatPart(dayRateMore100, dayRateMore100_int, dayRateMore100_float);

		//Загрузка в форму тарифов
		edit_dayRate_int_v = dayRate_int;
		edit_dayRate_float_v = dayRate_float;
		edit_dayRateMore100_int_v = dayRateMore100_int;
		edit_dayRateMore100_float_v = dayRateMore100_float;

	}
	fileOfRate.Abort();

	UpdateData(0);
}


void CRateChange::OnBnClickedButton5()
{
	//Date change
	UpdateData(1);

	button_dateOfRateChange_c.ShowWindow(SW_HIDE);
	dtp_dateOfRateChange_c.ShowWindow(SW_SHOW);
	dateTimeOfRate = true;

	UpdateData(0);
}
