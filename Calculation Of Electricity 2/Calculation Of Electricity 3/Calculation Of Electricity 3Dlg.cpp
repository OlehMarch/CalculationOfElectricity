
// Calculation Of Electricity 3Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Calculation Of Electricity 3.h"
#include "Calculation Of Electricity 3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCalcResult calcResult;


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CCalculationOfElectricity3Dlg



CCalculationOfElectricity3Dlg::CCalculationOfElectricity3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculationOfElectricity3Dlg::IDD, pParent)
	, edit_left_t11_v(0)
	, edit_left_t12_v(0)
	, edit_right_t11_v(0)
	, edit_right_t12_v(0)
	, editBrowse_v(_T(""))
	, dtp_dateChange_v(COleDateTime::GetCurrentTime())
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculationOfElectricity3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, spin_left_t11_c);
	DDX_Control(pDX, IDC_SPIN2, spin_left_t12_c);
	DDX_Control(pDX, IDC_SPIN3, spin_right_t11_c);
	DDX_Control(pDX, IDC_SPIN4, spin_right_t12_c);
	DDX_Text(pDX, IDC_EDIT1, edit_left_t11_v);
	DDV_MinMaxInt(pDX, edit_left_t11_v, 0, 999999);
	DDX_Text(pDX, IDC_EDIT2, edit_left_t12_v);
	DDV_MinMaxInt(pDX, edit_left_t12_v, 0, 999999);
	DDX_Text(pDX, IDC_EDIT3, edit_right_t11_v);
	DDV_MinMaxInt(pDX, edit_right_t11_v, 0, 999999);
	DDX_Text(pDX, IDC_EDIT4, edit_right_t12_v);
	DDV_MinMaxInt(pDX, edit_right_t12_v, 0, 999999);
	DDX_Control(pDX, IDC_BUTTON1, button_calculation_c);
	DDX_Control(pDX, IDC_EDIT3, edit_right_t11_c);
	DDX_Control(pDX, IDC_EDIT4, edit_right_t12_c);
	DDX_Control(pDX, IDC_EDIT1, edit_left_t11_c);
	DDX_Control(pDX, IDC_EDIT2, edit_left_t12_c);
	DDX_Text(pDX, IDC_MFCEDITBROWSE2, editBrowse_v);
	DDX_Control(pDX, IDC_BUTTON3, button_path_c);
	DDX_Control(pDX, IDC_BUTTON2, button_reset_c);
	DDX_Control(pDX, IDC_MFCEDITBROWSE2, editBrawse_path_c);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, dtp_dateChange_v);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, dtp_dateChange_c);
	DDX_Control(pDX, IDC_BUTTON4, button_dateChange_c);
	DDX_Control(pDX, IDC_STATIC_DATE, static_date_c);
	DDX_Control(pDX, IDC_BUTTON6, button_back_c);
}

BEGIN_MESSAGE_MAP(CCalculationOfElectricity3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32773, &CCalculationOfElectricity3Dlg::OnAbout)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculationOfElectricity3Dlg::OnBnClickedButton1)
	ON_COMMAND(ID_32776, &CCalculationOfElectricity3Dlg::ResetPath)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculationOfElectricity3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculationOfElectricity3Dlg::OnBnClickedButton3)
	ON_COMMAND(ID_32775, &CCalculationOfElectricity3Dlg::SetNewPath)
	ON_EN_CHANGE(IDC_MFCEDITBROWSE2, &CCalculationOfElectricity3Dlg::OnEnChangeMfceditbrowse2)
	ON_COMMAND(ID_32771, &CCalculationOfElectricity3Dlg::RateView)
	ON_COMMAND(ID_32777, &CCalculationOfElectricity3Dlg::ResetRate)
	ON_COMMAND(ID_32772, &CCalculationOfElectricity3Dlg::RateChange)
	ON_COMMAND(ID_32779, &CCalculationOfElectricity3Dlg::ResetRatePath)
	ON_COMMAND(ID_32778, &CCalculationOfElectricity3Dlg::SetNewRatePath)
	ON_COMMAND(ID_32781, &CCalculationOfElectricity3Dlg::ResetCalcPath)
	ON_COMMAND(ID_32780, &CCalculationOfElectricity3Dlg::SetNewCalcPath)
	ON_COMMAND(ID_32782, &CCalculationOfElectricity3Dlg::AdditionalRateSettings)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculationOfElectricity3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculationOfElectricity3Dlg::OnBnClickedButton6)
	ON_COMMAND(ID_32783, &CCalculationOfElectricity3Dlg::OnViewOfDataPlace)
END_MESSAGE_MAP()


// ����������� ��������� CCalculationOfElectricity3Dlg

BOOL CCalculationOfElectricity3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
	spin_left_t11_c.SetRange(0, 999999);
	spin_left_t12_c.SetRange(0, 999999);
	spin_right_t11_c.SetRange(0, 999999);
	spin_right_t12_c.SetRange(0, 999999);

	edit_left_t11_c.SetFocus();

	CFont *font;
	font = new CFont;
	font->CreateFont(13, 0, 0, 0, FW_MEDIUM, TRUE, TRUE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, L"Verdana");
	static_date_c.SetFont(font);

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CCalculationOfElectricity3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CCalculationOfElectricity3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CCalculationOfElectricity3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculationOfElectricity3Dlg::OnAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}


CString path = _T("Readings\\");
CString pathOfRate = _T("Rates\\");
CString pathOfCalc = _T("Calculations\\");
int dayDelta, nightDelta, overallDelta;
float day, night, dayMore100, nightMore100, overall;
float dayDelta_percent, nightDelta_percent;
int kWh, nightPercent;
bool dateTime = false;


CString readingsFormat(int readings) {
	
	CString formattedReadings = NULL, nullAdder = _T("");
	if ((readings < 1000) && (readings != 0)) {
		int counter = 0;
		for (int value = readings; value > 0; value /= 10, counter++) {}
		for (int i = 0; i < 4 - counter; ++i) {
			nullAdder += _T("0");
		}
	}
	else if (readings == 0) {
		nullAdder = _T("000");
	}
	formattedReadings.Format(nullAdder + _T("%d\n"), readings);

	return formattedReadings;

}


float readingsMore_IsUseless(float readingsMore) {
	if (readingsMore < 0) {
		return 0;
	}
	return readingsMore;
}


void Calculation(int right_t11, int left_t11, int right_t12, int left_t12) {
	
	//������
	dayDelta = right_t11 - left_t11;
	nightDelta = right_t12 - left_t12;
	overallDelta = dayDelta + nightDelta;
	dayDelta_percent = (float)dayDelta / (float)overallDelta;
	nightDelta_percent = (float)nightDelta / (float)overallDelta;
	day = dayDelta_percent * kWh; //��� ������
	night = nightDelta_percent * kWh; //��� ������
	dayMore100 = dayDelta - day; //��� ������
	dayMore100 = readingsMore_IsUseless(dayMore100);
	nightMore100 = nightDelta - night; //��� ������
	nightMore100 = readingsMore_IsUseless(nightMore100);
	//��������� �������
	CStdioFile rates;
	CString dayRate, dayRateMore100;
	rates.Open(pathOfRate + _T("defaultRate.lor"), CFile::modeRead);
	rates.ReadString(dayRate);
	rates.ReadString(dayRateMore100);
	rates.Abort();
	//������ � ������ �������
	day *= _wtof(dayRate); 		//_wtof() - CString to float
	night *= _wtof(dayRate) * nightPercent / 100;
	dayMore100 *= _wtof(dayRateMore100);
	nightMore100 *= _wtof(dayRateMore100) * nightPercent / 100;
	overall = day + night + dayMore100 + nightMore100;

}


void readMeCreation() {

	//�������� readMe
	setlocale(LC_ALL, ".1251");
	CStdioFile readmeReadings, readmeRates, readmeCalcs;
	readmeReadings.Open(path + _T("ReadMe.txt"), CFile::modeCreate | CFile::modeWrite);
	readmeReadings.WriteString(_T("������ ������ - ������� ��������� �� ���������� �����\n������ ������ - ������� ��������� �� ������� �����\n������ ������ - ������ ��������� �� ���������� �����\n��������� ������ - ������ ��������� �� ������� �����"));
	readmeReadings.Close();
	readmeRates.Open(pathOfRate + _T("ReadMe.txt"), CFile::modeCreate | CFile::modeWrite);
	readmeRates.WriteString(_T("������ ������ - ����� �� 100 ���\n������ ������ - ����� ����� 100 ���"));
	readmeRates.Close();
	readmeCalcs.Open(pathOfCalc + _T("ReadMe.txt"), CFile::modeCreate | CFile::modeWrite);
	readmeCalcs.WriteString(_T("������ ������ - ������ ������� ���������\n������ ������ - ������ ������ ���������\n������ ������ - ��������� ������� ��������� �� 100 ���\n��������� ������ - ��������� ������ ��������� �� 100 ���\n����� ������ - ��������� ������� ��������� ����� 100 ���\n������ ������ - ��������� ������ ��������� ����� 100 ���\n������� ������ - ����� ���������"));
	readmeCalcs.Close();
	setlocale(LC_ALL, "eng");

}


void CCalculationOfElectricity3Dlg::showHideElements(bool hide) {
	
	//����������� ��� �������� ��������� ����������� ����
	int value1, value2;
	if (hide) {
		value1 = 5;
		value2 = 0;
	}
	else {
		value1 = 0;
		value2 = 5;
	}

	//SW_SHOW === 5 & SW_HIDE === 0
	edit_left_t11_c.ShowWindow(value2);
	edit_right_t11_c.ShowWindow(value2);
	edit_left_t12_c.ShowWindow(value2);
	edit_right_t12_c.ShowWindow(value2);
	spin_left_t11_c.ShowWindow(value2);
	spin_left_t12_c.ShowWindow(value2);
	spin_right_t11_c.ShowWindow(value2);
	spin_right_t12_c.ShowWindow(value2);
	editBrawse_path_c.ShowWindow(value2);
	button_calculation_c.ShowWindow(value2);
	button_path_c.ShowWindow(value2);
	button_reset_c.ShowWindow(value2);
	button_dateChange_c.ShowWindow(value2);
	dtp_dateChange_c.ShowWindow(0);
	calcResult.ShowWindow(value1);
	button_back_c.ShowWindow(value1);

}


void CCalculationOfElectricity3Dlg::OnBnClickedButton1()
{
	//������ ������� �������
	UpdateData(TRUE);

	if (((edit_right_t11_v - edit_left_t11_v) < 0) || ((edit_right_t12_v - edit_left_t12_v) < 0)) {
		MessageBox(_T("������� ����� �����������\n	 (������� � ����������) \n������ ���� �������������!"), _T("������"), MB_OK);
	}
	else {
		//�������� �� ������� ����� ���� ���������� 
		CStdioFile fileOfPath;
		if (fileOfPath.Open(_T("pathOfReadings.fop"), CFile::modeReadWrite) == NULL) {
			ResetPath();
		}
		else {
			setlocale(LC_ALL, ".1251");
			fileOfPath.ReadString(path);
			setlocale(LC_ALL, "eng");
		}
		fileOfPath.Abort();

		//�������� ����� ����� ����
		CString time;
		MOSFile *mosFile = NULL;
		time = mosFile->logNameCreationByDate(dateTime, dtp_dateChange_v);
		mosFile->~MOSFile();

		CStdioFile file;
		file.Open(path + time + _T(".lor"), CFile::modeCreate | CFile::modeWrite);
		file.WriteString(readingsFormat(edit_left_t11_v));
		file.WriteString(readingsFormat(edit_right_t11_v));
		file.WriteString(readingsFormat(edit_left_t12_v));
		file.WriteString(readingsFormat(edit_right_t12_v));
		file.Abort();

		//��������� ���� ���� � �������, � ���� ��� ���, ������� �����
		CStdioFile fileOfRate;
		if (fileOfRate.Open(_T("pathOfRate.fop"), CFile::modeReadWrite) == NULL) {
			ResetRatePath();
			ResetRate();
		}
		else {
			setlocale(LC_ALL, ".1251");
			fileOfRate.ReadString(pathOfRate);
			setlocale(LC_ALL, "eng");
		}
		fileOfRate.Abort();

		//�������������� ��������� ������
		CStdioFile settings;
		CString str = NULL;
		if (settings.Open(_T("additionalRateSettings.lor"), CFile::modeReadWrite) == NULL) {
			settings.Open(_T("additionalRateSettings.lor"), CFile::modeCreate | CFile::modeWrite);
			str = _T("");
			str.Format(_T("%d\n%d"), 100, 50);
			settings.WriteString(str);
		}
		else {
			str = _T("");
			settings.ReadString(str);
			kWh = _wtoi(str);
			settings.ReadString(str);
			nightPercent = _wtoi(str);
		}
		settings.Abort();
		
		//������
		Calculation(edit_right_t11_v, edit_left_t11_v, edit_right_t12_v, edit_left_t12_v);

		//��������� ���� ���� � ��������
		CStdioFile fileOfCalc;
		if (fileOfCalc.Open(_T("pathOfCalculations.fop"), CFile::modeReadWrite) == NULL) {
			ResetCalcPath();
		}
		else {
			setlocale(LC_ALL, ".1251");
			fileOfCalc.ReadString(pathOfCalc);
			setlocale(LC_ALL, "eng");
		}
		fileOfCalc.Abort();
		
		//�������� ����� ����� ����
		CStdioFile calcFile, lastCalcFile;
		mosFile = NULL;
		time = mosFile->logNameCreationByDate(dateTime, dtp_dateChange_v);
		mosFile->~MOSFile();
		calcFile.Open(pathOfCalc + time + _T(" Calculation.lor"), CFile::modeCreate | CFile::modeWrite);
		str = _T("");
		str.Format(_T("%d\n%d\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f"), dayDelta, nightDelta, day, night, dayMore100, nightMore100, overall);
		calcFile.WriteString(str);
		calcFile.Abort();
		lastCalcFile.Open(pathOfCalc + _T("lastCalculation.lor"), CFile::modeCreate | CFile::modeWrite);
		lastCalcFile.WriteString(str);
		lastCalcFile.Abort();
	}
	
	//�������� ���� ��� ����������� � ������� ��������� ���������
	calcResult.Create(IDD_RESULT, this);
	showHideElements(TRUE);

	//�������� ReadMe
	readMeCreation();

	UpdateData(FALSE);
}


void CCalculationOfElectricity3Dlg::ResetPath()
{
	path = _T("Readings\\");
	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath); //�������� ������� ����������
	CreateDirectory((CString) NPath + _T("\\") + path , NULL);
	CStdioFile fileOfPath;
	fileOfPath.Open(_T("pathOfReadings.fop"), CFile::modeCreate | CFile::modeReadWrite);
	fileOfPath.WriteString(path);
	fileOfPath.Close();
	MessageBox(_T("����� �������� ������ � �����������\n���� ����������� �� ���������!"), _T("��������!"), MB_OK);
}


void CCalculationOfElectricity3Dlg::SetNewPath()
{
	CPathOfReadings dlg;
	dlg.DoModal();
}


void CCalculationOfElectricity3Dlg::ResetRate()
{
	CStdioFile defaultRate;
	defaultRate.Open(pathOfRate + _T("defaultRate.lor"), CFile::modeCreate | CFile::modeReadWrite);
	defaultRate.WriteString(_T("0.4560\n"));
	defaultRate.WriteString(_T("0.7890"));
	defaultRate.Close();
	CStdioFile settings;
	settings.Open(_T("additionalRateSettings.lor"), CFile::modeCreate | CFile::modeReadWrite);
	settings.WriteString(_T("100\n50"));
	settings.Close();
	MessageBox(_T("�������������� ������� ��\n��������� ��������� �������!"), _T("��������!"), MB_OK);
}


void CCalculationOfElectricity3Dlg::ResetRatePath()
{
	pathOfRate = _T("Rates\\");
	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath); //�������� ������� ����������
	CreateDirectory((CString)NPath + _T("\\") + pathOfRate, NULL);
	CStdioFile fileOfRate;
	fileOfRate.Open(_T("pathOfRate.fop"), CFile::modeCreate | CFile::modeReadWrite);
	fileOfRate.WriteString(pathOfRate);
	fileOfRate.Close();
	MessageBox(_T("����� �������� ������ � ��������\n���� ����������� �� ���������!"), _T("��������!"), MB_OK);
}


void CCalculationOfElectricity3Dlg::SetNewRatePath()
{
	CPathOfRates dlg;
	dlg.DoModal();
}


void CCalculationOfElectricity3Dlg::RateView()
{
	CStdioFile fileOfRatePath;
	if (fileOfRatePath.Open(_T("pathOfRate.fop"), CFile::modeRead) == NULL) {
		ResetRatePath();
		ResetRate();
	}
	fileOfRatePath.Abort();
	CRateView dlg;
	dlg.DoModal();
}


void CCalculationOfElectricity3Dlg::RateChange()
{
	CRateChange dlg;
	dlg.DoModal();
}


void CCalculationOfElectricity3Dlg::ResetCalcPath()
{
	pathOfCalc = _T("Calculations\\");
	TCHAR NPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath); //�������� ������� ����������
	CreateDirectory((CString)NPath + _T("\\") + pathOfCalc, NULL);
	CStdioFile fileOfCalc;
	fileOfCalc.Open(_T("pathOfCalculations.fop"), CFile::modeCreate | CFile::modeReadWrite);
	fileOfCalc.WriteString(pathOfCalc);
	fileOfCalc.Close();
	MessageBox(_T("����� �������� ������ � ���������\n���� ����������� �� ���������!"), _T("��������!"), MB_OK);
}


void CCalculationOfElectricity3Dlg::SetNewCalcPath()
{
	CPathOfCalc dlg;
	dlg.DoModal();
}


void CCalculationOfElectricity3Dlg::AdditionalRateSettings()
{
	CAdditionalRateSettings dlg;
	dlg.DoModal();
}


void CCalculationOfElectricity3Dlg::OnViewOfDataPlace()
{
	//�������� ���� �������� ������
	CDatePlaceView dlg;
	dlg.DoModal();
}


void CCalculationOfElectricity3Dlg::OnBnClickedButton2()
{
	//������ ������ ���������
	UpdateData(TRUE);
	edit_left_t11_v = 0;
	edit_left_t12_v = 0;
	edit_right_t11_v = 0;
	edit_right_t12_v = 0;
	UpdateData(FALSE);
}


void CCalculationOfElectricity3Dlg::OnBnClickedButton3()
{
	//������ �������� ���������
	UpdateData(TRUE);

	if (editBrowse_v.Find(_T(".lor")) != -1) {
		//���������� -1 ���� �� �������, � ���� ������� - ������ ������ ���������
		
		CString t11, t12;
		CStdioFile file;
		file.Open(editBrowse_v, CFile::modeRead);
		file.ReadString(t11);
		file.ReadString(t11);
		file.ReadString(t12);
		file.ReadString(t12);
		edit_left_t11_v = _ttoi(t11);
		edit_left_t12_v = _ttoi(t12);
		edit_right_t11_v = edit_left_t11_v;
		edit_right_t12_v = edit_left_t12_v;
		file.Close();
	}
	else {
		MessageBox(_T("������ �������� ����!\n���� ������ ���� � �a��������� \".lor\""), _T("��������!"), MB_OK);
	}
	
	UpdateData(FALSE);
}


void CCalculationOfElectricity3Dlg::OnEnChangeMfceditbrowse2()
{
	//���� ������ ����� ��� �������� ���������
	button_path_c.EnableWindow(1);
}


void CCalculationOfElectricity3Dlg::OnBnClickedButton4()
{
	//date change
	UpdateData(1);

	button_dateChange_c.ShowWindow(SW_HIDE);
	dtp_dateChange_c.ShowWindow(SW_SHOW);
	dateTime = true;

	UpdateData(0);
}


void CCalculationOfElectricity3Dlg::OnBnClickedButton6()
{
	//back button
	showHideElements(FALSE);
	calcResult.DestroyWindow();
	dateTime = false;
}

