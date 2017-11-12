// DemoMSDDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DemoMSD.h"
#include "DemoMSDDlg.h"

//#include <windows.h>
#include <process.h> // for _beginthreadex()
#include <stdlib.h> // malloc , free

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMSDDlg dialog

static CWnd*	pMainDlg;
static HANDLE	hMsd;
static bool		bMsdTerminate = false;

unsigned int __stdcall MSD_Proc(LPVOID lParam);
void	 ShowMessage(char* msg);


CDemoMSDDlg::CDemoMSDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemoMSDDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoMSDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemoMSDDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_Btn_Exit, &CDemoMSDDlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_Btn_Init, &CDemoMSDDlg::OnBnClickedBtnInit)
	ON_BN_CLICKED(IDC_Btn_Home, &CDemoMSDDlg::OnBnClickedBtnHome)
	ON_BN_CLICKED(IDC_Btn_Move, &CDemoMSDDlg::OnBnClickedBtnMove)
END_MESSAGE_MAP()


// CDemoMSDDlg message handlers

BOOL CDemoMSDDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	{
		pMainDlg = this;
		hMsd = (HANDLE)_beginthreadex(
					NULL,						// void *security
					0,							// unsigned stack_size
					MSD_Proc,					// unsigned ( __stdcall *start_address )( void * )
					NULL,						// void *arglist
					0,							// unsigned initflag
					NULL);						// unsigned *thrdaddr
		bMsdTerminate = false;

		ProcessBodyStateChange(STAIR_1, PROCESS_Stand_By_State);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemoMSDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDemoMSDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CDemoMSDDlg::OnBnClickedBtnInit()
{
	// TODO: Add your control notification handler code here
	ShowMessage("Init App");
}

void CDemoMSDDlg::OnBnClickedBtnHome()
{
	// TODO: Add your control notification handler code here
	ShowMessage("Doing Home...");
}

void CDemoMSDDlg::OnBnClickedBtnMove()
{
	// TODO: Add your control notification handler code here
	ShowMessage("Aixs Moving...");
}

void CDemoMSDDlg::OnBnClickedBtnExit()
{
	// TODO: Add your control notification handler code here
	bMsdTerminate = true;
	CloseHandle(hMsd);

	PostQuitMessage(0);
	CDialog::OnClose();
}

void ShowMessage(char* msg)
{
	pMainDlg->SetDlgItemText(IDC_Edit_Msg, msg);
}


unsigned int __stdcall MSD_Proc(LPVOID lParam)
{
	ShowMessage("MSD Start");
	while(!bMsdTerminate)
	{
		Sleep(1);
	}
	return 1;
}