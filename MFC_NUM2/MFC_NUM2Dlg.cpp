
// MFC_NUM2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFC_NUM2.h"
#include "MFC_NUM2Dlg.h"
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
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCNUM2Dlg



CMFCNUM2Dlg::CMFCNUM2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_NUM2_DIALOG, pParent)
	, m_1(0)
	, m_2(0)
	, m_3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCNUM2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDX_Text(pDX, IDC_EDIT2, m_2);
	DDX_Text(pDX, IDC_EDIT_RES, m_3);
}

BEGIN_MESSAGE_MAP(CMFCNUM2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CMFCNUM2Dlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_SUB_BUTTON, &CMFCNUM2Dlg::OnBnClickedSubButton)
	ON_BN_CLICKED(IDC_MULTI_BUTTON, &CMFCNUM2Dlg::OnBnClickedMultiButton)
	ON_BN_CLICKED(IDC_DIV_BUTTON, &CMFCNUM2Dlg::OnBnClickedDivButton)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCNUM2Dlg

BOOL CMFCNUM2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CMFCNUM2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCNUM2Dlg::OnPaint()
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
HCURSOR CMFCNUM2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCNUM2Dlg::OnBnClickedAddButton()
{
	UpdateData(TRUE);
	m_3 = m_1 + m_2;
	UpdateData(FALSE);
}


void CMFCNUM2Dlg::OnBnClickedSubButton()
{
	UpdateData(TRUE);
	m_3 = m_1 - m_2;
	UpdateData(FALSE);
}


void CMFCNUM2Dlg::OnBnClickedMultiButton()
{
	UpdateData(TRUE);
	m_3 = m_1 * m_2;
	UpdateData(FALSE);
}


void CMFCNUM2Dlg::OnBnClickedDivButton()
{
	UpdateData(TRUE);
	if (m_2 != 0)
		m_3 = m_1 / m_2;
	else {
		Beep(1000, 500);
		MessageBox(L"Делить на ноль нельзя!", L"Ошибка!");
	}
	UpdateData(FALSE);
}
