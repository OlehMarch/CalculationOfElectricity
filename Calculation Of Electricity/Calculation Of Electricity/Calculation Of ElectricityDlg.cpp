
// Calculation Of ElectricityDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Calculation Of Electricity.h"
#include "Calculation Of ElectricityDlg.h"
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


// диалоговое окно CCalculationOfElectricityDlg

float dayRateLessThan150 = 0.3084, dayRateMoreThan150 = 0.4194, nightrate = dayRateMoreThan150 * 0.7;

CCalculationOfElectricityDlg::CCalculationOfElectricityDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculationOfElectricityDlg::IDD, pParent)
	, m_stat1(0)
	, m_stat2(0)
	, m_edit2(0)
	, m_edit1(0)
	, m_edit3(0)
	, m_edit4(0)
	, m_edit5(0)
	, m_edit6(0)
	, m_stat3(0)
	, m_stat4(0)
	, m_stat5(0)
	, m_stat6(0)
	, m_stat7(0)
	, m_stat0(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculationOfElectricityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC1, m_stat1);
	DDX_Text(pDX, IDC_STATIC2, m_stat2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1Ctrl);
	DDX_Control(pDX, IDC_EDIT2, m_edit2Ctrl);
	DDX_Control(pDX, IDC_BUTTON3, m_button1Ctrl);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDX_Text(pDX, IDC_EDIT5, m_edit5);
	DDX_Text(pDX, IDC_EDIT6, m_edit6);
	DDX_Text(pDX, IDC_STATIC3, m_stat3);
	DDX_Text(pDX, IDC_STATIC4, m_stat4);
	DDX_Text(pDX, IDC_STATIC5, m_stat5);
	DDX_Text(pDX, IDC_STATIC6, m_stat6);
	DDX_Text(pDX, IDC_STATIC7, m_stat7);
	DDX_Control(pDX, IDC_BUTTON5, m_button2Ctrl);
	DDX_Text(pDX, IDC_STATIC0, m_stat0);
	DDX_Control(pDX, IDC_STATIC7, m_stat7Ctrl);
}

BEGIN_MESSAGE_MAP(CCalculationOfElectricityDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculationOfElectricityDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculationOfElectricityDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculationOfElectricityDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculationOfElectricityDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CCalculationOfElectricityDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &CCalculationOfElectricityDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT3, &CCalculationOfElectricityDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT5, &CCalculationOfElectricityDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculationOfElectricityDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT4, &CCalculationOfElectricityDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT6, &CCalculationOfElectricityDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculationOfElectricityDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculationOfElectricityDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// обработчики сообщений CCalculationOfElectricityDlg

BOOL CCalculationOfElectricityDlg::OnInitDialog()
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

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalculationOfElectricityDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculationOfElectricityDlg::OnPaint()
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
HCURSOR CCalculationOfElectricityDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculationOfElectricityDlg::OnBnClickedButton1()
{
	m_stat1 = dayRateLessThan150;
	m_stat0 = dayRateMoreThan150;
	m_stat2 = nightrate;
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricityDlg::OnBnClickedButton2()
{
	m_edit1Ctrl.EnableWindow();
	m_edit2Ctrl.EnableWindow();
	m_button1Ctrl.EnableWindow();
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricityDlg::OnEnChangeEdit1()
{
	UpdateData(TRUE);
	dayRateLessThan150 = m_edit1;
	UpdateData(FALSE);
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCalculationOfElectricityDlg::OnEnChangeEdit2()
{
	UpdateData(TRUE);
	dayRateMoreThan150 = m_edit2;
	UpdateData(FALSE);
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCalculationOfElectricityDlg::OnBnClickedButton3()
{
	m_stat1 = dayRateLessThan150 / 10000;
	m_stat0 = dayRateMoreThan150 / 10000;
	m_stat2 = m_stat0 * 0.7;
	m_edit1Ctrl.EnableWindow(0);
	m_edit2Ctrl.EnableWindow(0);
	m_button1Ctrl.EnableWindow(0);
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricityDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}

int daytimeConsOfTheCurMon, daytimeConsOfThePrevMon;

void CCalculationOfElectricityDlg::OnEnChangeEdit3()
{
	UpdateData(TRUE);
	daytimeConsOfThePrevMon = m_edit3;
	UpdateData(FALSE);
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCalculationOfElectricityDlg::OnEnChangeEdit5()
{
	UpdateData(TRUE);
	daytimeConsOfTheCurMon = m_edit5;
	UpdateData(FALSE);
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

int nighttimeConsOfTheCurMon, nighttimeConsOfThePrevMon;

void CCalculationOfElectricityDlg::OnEnChangeEdit4()
{
	UpdateData(TRUE);
	nighttimeConsOfThePrevMon = m_edit4;
	UpdateData(FALSE);
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCalculationOfElectricityDlg::OnEnChangeEdit6()
{
	UpdateData(TRUE);
	nighttimeConsOfTheCurMon = m_edit6;
	UpdateData(FALSE);
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCalculationOfElectricityDlg::OnBnClickedButton4()
{
	m_stat3 = daytimeConsOfTheCurMon - daytimeConsOfThePrevMon;
	m_stat4 = nighttimeConsOfTheCurMon - nighttimeConsOfThePrevMon;
	if ((m_stat3 < 0) || (m_stat4 < 0)) {
		MessageBox(_T("Разница между показаниями (текуцим и предыдущим) долна быть положительной!"), _T("Ошибка"), MB_OK);
	}
	else {
		m_button2Ctrl.EnableWindow(1);
		UpdateData(FALSE);
	}
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricityDlg::OnBnClickedButton5()
{
	if (m_stat3 > 150) {
		m_stat5 = (m_stat3 - 150) * m_stat0;
		m_stat5 += 150 * m_stat1;
	}
	if (m_stat3 < 150) {
		m_stat5 = m_stat3 * m_stat1;
	}
	m_stat6 = m_stat4 * m_stat2;
	m_stat7 = m_stat5 + m_stat6;
	UpdateData(FALSE);
	// TODO: добавьте свой код обработчика уведомлений
}


void CCalculationOfElectricityDlg::OnBnClickedButton6()
{
	CAboutDlg aboutButton;
	aboutButton.DoModal();
	// TODO: добавьте свой код обработчика уведомлений
}
