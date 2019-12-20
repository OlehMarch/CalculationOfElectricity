
// Calculation Of Electricity 3Dlg.h : файл заголовка
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxeditbrowsectrl.h"
#include "ATLComTime.h"
#include "afxdtctl.h"
#include "PathOfReadings.h"
#include "RateView.h"
#include "RateChange.h"
#include "PathOfRates.h"
#include "CalcResult.h"
#include "PathOfCalc.h"
#include "AdditionalRateSettings.h"
#include "DatePlaceView.h" //Data must be
#include "clocale"
#include "MOSFile.h"


// диалоговое окно CCalculationOfElectricity3Dlg
class CCalculationOfElectricity3Dlg : public CDialogEx
{
// Создание
public:
	CCalculationOfElectricity3Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_CALCULATIONOFELECTRICITY3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAbout();
	CSpinButtonCtrl spin_left_t11_c;
	CSpinButtonCtrl spin_left_t12_c;
	CSpinButtonCtrl spin_right_t11_c;
	CSpinButtonCtrl spin_right_t12_c;
	int edit_left_t11_v;
	int edit_left_t12_v;
	int edit_right_t11_v;
	int edit_right_t12_v;
	afx_msg void OnBnClickedButton1();
	CButton button_calculation_c;
	CEdit edit_right_t11_c;
	CEdit edit_right_t12_c;
	CEdit edit_left_t11_c;
	CEdit edit_left_t12_c;
	afx_msg void ResetPath();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString editBrowse_v;
	afx_msg void SetNewPath();
	afx_msg void OnEnChangeMfceditbrowse2();
	CButton button_path_c;
	afx_msg void RateView();
	afx_msg void ResetRate();
	afx_msg void RateChange();
	afx_msg void ResetRatePath();
	afx_msg void SetNewRatePath();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	CButton button_reset_c;
	CMFCEditBrowseCtrl editBrawse_path_c;
	afx_msg void ResetCalcPath();
	afx_msg void SetNewCalcPath();
	afx_msg void AdditionalRateSettings();
	COleDateTime dtp_dateChange_v;
	CDateTimeCtrl dtp_dateChange_c;
	CButton button_dateChange_c;
	afx_msg void OnBnClickedButton4();
	CStatic static_date_c;
	CButton button_back_c;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnViewOfDataPlace();
	void showHideElements(bool hide);
};
