
// MFC_NUM2Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCNUM2Dlg
class CMFCNUM2Dlg : public CDialogEx
{
// Создание
public:
	CMFCNUM2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_NUM2_DIALOG };
#endif

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
private:
	double m_1;
	double m_2;
	double m_3;
public:
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedSubButton();
	afx_msg void OnBnClickedMultiButton();
	afx_msg void OnBnClickedDivButton();
};
