
// Calculation Of Electricity 2Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity 2.h"
#include "Calculation Of Electricity 2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CCalculationOfElectricity2Dlg

float dayRateLessThan150 = 0.3084, dayRateMoreThan150 = 0.4194, nightrate = dayRateMoreThan150 * 0.7;
CFont *font;

CCalculationOfElectricity2Dlg::CCalculationOfElectricity2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculationOfElectricity2Dlg::IDD, pParent)
	, m_stat0(0)
	, m_stat1(0)
	, m_stat2(0)
	, m_edit1(0)
	, m_edit2(0)
	, m_edit3(0)
	, m_edit4(0)
	, m_edit5(0)
	, m_edit6(0)
	, m_stat3(0)
	, m_stat4(0)
	, m_stat5(_T(""))
	, m_stat6(_T(""))
	, m_stat7(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculationOfElectricity2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC0, m_stat0);
	DDX_Text(pDX, IDC_STATIC1, m_stat1);
	DDX_Text(pDX, IDC_STATIC2, m_stat2);
	DDX_Control(pDX, IDC_EDIT5, m_edit1Ctrl);
	DDX_Control(pDX, IDC_EDIT6, m_edit2Ctrl);
	DDX_Control(pDX, IDC_BUTTON4, m_button1Ctrl);
	DDX_Text(pDX, IDC_EDIT5, m_edit1);
	DDX_Text(pDX, IDC_EDIT6, m_edit2);
	DDX_Control(pDX, IDC_SPIN7, m_spin1Ctrl);
	DDX_Control(pDX, IDC_SPIN6, m_spin2Ctrl);
	DDX_Control(pDX, IDC_SPIN1, m_spin3Ctrl);
	DDX_Control(pDX, IDC_SPIN2, m_spin4Ctrl);
	DDX_Control(pDX, IDC_SPIN3, m_spin5Ctrl);
	DDX_Control(pDX, IDC_SPIN4, m_spin6Ctrl);
	DDX_Text(pDX, IDC_EDIT1, m_edit3);
	DDV_MinMaxInt(pDX, m_edit3, 0, 999999);
	DDX_Text(pDX, IDC_EDIT2, m_edit4);
	DDV_MinMaxInt(pDX, m_edit4, 0, 999999);
	DDX_Text(pDX, IDC_EDIT3, m_edit5);
	DDV_MinMaxInt(pDX, m_edit5, 0, 999999);
	DDX_Text(pDX, IDC_EDIT4, m_edit6);
	DDV_MinMaxInt(pDX, m_edit6, 0, 999999);
	DDX_Text(pDX, IDC_STATIC3, m_stat3);
	DDX_Text(pDX, IDC_STATIC4, m_stat4);
	DDX_Control(pDX, IDC_BUTTON2, m_button2Ctrl);
	DDX_Text(pDX, IDC_STATIC5, m_stat5);
	DDX_Text(pDX, IDC_STATIC6, m_stat6);
	DDX_Text(pDX, IDC_STATIC7, m_stat7);
	DDX_Control(pDX, IDC_BUTTON1, m_button3Ctrl);
	DDX_Control(pDX, IDC_STATIC8, m_stat8Ctrl);
	DDX_Control(pDX, IDC_EDIT1, m_edit3Ctrl);
	DDX_Control(pDX, IDC_EDIT2, m_edit4Ctrl);
	DDX_Control(pDX, IDC_EDIT3, m_edit5Ctrl);
	DDX_Control(pDX, IDC_EDIT4, m_edit6Ctrl);
	DDX_Control(pDX, IDC_STATIC9, m_stat9Ctrl);
}

BEGIN_MESSAGE_MAP(CCalculationOfElectricity2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculationOfElectricity2Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculationOfElectricity2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculationOfElectricity2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculationOfElectricity2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculationOfElectricity2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculationOfElectricity2Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// обработчики сообщений CCalculationOfElectricity2Dlg

BOOL CCalculationOfElectricity2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_spin1Ctrl.SetRange(0, 9999);
	m_spin2Ctrl.SetRange(0, 9999);
	m_spin3Ctrl.SetRange(0, 999999);
	m_spin4Ctrl.SetRange(0, 999999);
	m_spin5Ctrl.SetRange(0, 999999);
	m_spin6Ctrl.SetRange(0, 999999);
	m_stat8Ctrl.EnableWindow(0);
	m_stat9Ctrl.EnableWindow(0);

	font = new CFont;
	font->CreateFont(12, 0, 0, 0, FW_MEDIUM, TRUE, TRUE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, L"Verdana");
	m_stat8Ctrl.SetFont(font);
	m_stat9Ctrl.SetFont(font);
	LOGFONT log;
	font->GetLogFont(&log);

	MessageBox(_T("Прежде чем начинать вводить Ваши данные для расчета стоимости электроэнергии, проверьте тариф (\"Просмотр тарифа\") или введите нужный (\"Изменить тариф\")!"), _T("ВНИМАНИЕ!"), MB_OK);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalculationOfElectricity2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCalculationOfElectricity2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCalculationOfElectricity2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculationOfElectricity2Dlg::OnBnClickedButton5()
{
	m_stat8Ctrl.ShowWindow(0);
	m_stat9Ctrl.ShowWindow(0);
	m_edit3Ctrl.EnableWindow();
	m_edit4Ctrl.EnableWindow();
	m_edit5Ctrl.EnableWindow();
	m_edit6Ctrl.EnableWindow();
	m_button3Ctrl.EnableWindow();
	m_stat0 = dayRateLessThan150;
	m_stat1 = dayRateMoreThan150;
	m_stat2 = nightrate;
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricity2Dlg::OnBnClickedButton3()
{
	m_edit1Ctrl.EnableWindow();
	m_edit2Ctrl.EnableWindow();
	m_button1Ctrl.EnableWindow();
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricity2Dlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	dayRateLessThan150 = m_edit1;
	dayRateMoreThan150 = m_edit2;
	m_stat0 = dayRateLessThan150 / 10000;
	m_stat1 = dayRateMoreThan150 / 10000;
	m_stat2 = m_stat1 * 0.7;
	m_edit1Ctrl.EnableWindow(0);
	m_edit2Ctrl.EnableWindow(0);
	m_button1Ctrl.EnableWindow(0);
	UpdateData(FALSE);
	MessageBox((LPCTSTR)m_edit1, _T("123"), MB_OK);
	// TODO: добавьте свой код обработчика уведомлений
}

int daytimeConsOfTheCurMon, daytimeConsOfThePrevMon;
int nighttimeConsOfTheCurMon, nighttimeConsOfThePrevMon;

void CCalculationOfElectricity2Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	daytimeConsOfThePrevMon = m_edit3;
	daytimeConsOfTheCurMon = m_edit5;
	nighttimeConsOfThePrevMon = m_edit4;
	nighttimeConsOfTheCurMon = m_edit6;
	m_stat3 = daytimeConsOfTheCurMon - daytimeConsOfThePrevMon;
	m_stat4 = nighttimeConsOfTheCurMon - nighttimeConsOfThePrevMon;
	if ((m_stat3 < 0) || (m_stat4 < 0)) {
		MessageBox(_T("Разница между показаниями (текуцим и предыдущим) долна быть положительной!"), _T("Ошибка"), MB_OK);
	}
	else {
		m_button2Ctrl.EnableWindow();
		UpdateData(FALSE);
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricity2Dlg::OnBnClickedButton2()
{
	float var1, var2, var3;
	if (m_stat3 > 150) {
		var1 = (m_stat3 - 150) * m_stat1;
		var1 += 150 * m_stat0;
	}
	if (m_stat3 < 150) {
		var1 = m_stat3 * m_stat0;
	}
	var2 = m_stat4 * m_stat2;
	var3 = var1 + var2;
	m_stat5.Format(_T("%.2f"), var1);
	m_stat6.Format(_T("%.2f"), var2);
	m_stat7.Format(_T("%.2f"), var3);
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricity2Dlg::OnBnClickedButton6()
{
	CAboutDlg aboutButton;
	aboutButton.DoModal();
	// TODO: добавьте свой код обработчика уведомлений
}