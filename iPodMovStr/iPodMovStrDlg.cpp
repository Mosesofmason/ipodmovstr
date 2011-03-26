
// iPodMovStrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "iPodMovStr.h"
#include "iPodMovStrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CiPodMovStrDlg dialog

BEGIN_DHTML_EVENT_MAP(CiPodMovSrtDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



CiPodMovSrtDlg::CiPodMovSrtDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CiPodMovSrtDlg::IDD, CiPodMovSrtDlg::IDH, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CiPodMovSrtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INFOSTATIC, infoStatic);
}

BEGIN_MESSAGE_MAP(CiPodMovSrtDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_SELECTMP4FILE, &CiPodMovSrtDlg::OnBnClickedButtonSelectmp4file)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CiPodMovStrDlg message handlers

BOOL CiPodMovSrtDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CiPodMovSrtDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CiPodMovSrtDlg::OnPaint()
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
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CiPodMovSrtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CiPodMovSrtDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CiPodMovSrtDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}

void CiPodMovSrtDlg::OnBnClickedButtonSelectmp4file()
{
	// TODO: Add your control notification handler code here
	static TCHAR BASED_CODE szMovFilter[] = _T("MP4 File (*.mp4)|*.mp4|M4V File (*.m4v)|*.m4v|Supported Movie File (*.mp4;*.m4v)|*.mp4; *.m4v|All Files (*.*)|*.*||");
	static TCHAR BASED_CODE szStrFilter[] = _T("Sub File (*.srt)|*.srt|Ttxt File (*.ttxt)|*.ttxt|All Files (*.*)|*.*||");


	CString fontFacename = _T("Î¢ÈíÑÅºÚ");
	int fontSize = 12;

	CFileDialog openSrtfileDlg (TRUE, NULL, NULL, 
								OFN_DONTADDTORECENT|OFN_ENABLESIZING|OFN_HIDEREADONLY, 
								szStrFilter,
								NULL, 0, 1);

	CFileDialog openMp4fileDlg (TRUE, NULL, NULL, 
								OFN_DONTADDTORECENT|OFN_ENABLESIZING|OFN_HIDEREADONLY, 
								szMovFilter,
								NULL, 0, 1);

	if (openMp4fileDlg.DoModal() == IDOK)
	{
		szMP4PathName = openMp4fileDlg.GetPathName();
		szMP4FolderPath = openMp4fileDlg.GetFolderPath();
		szMP4FileName = openMp4fileDlg.GetFileName();
		szMP4FileTitle = openMp4fileDlg.GetFileTitle();
			
		szSRTPathName = szMP4FolderPath + _T("\\") + szMP4FileTitle + _T(".srt");
		szSRTFolderPath = szMP4FolderPath;
		szSRTFileName = szMP4FileTitle + _T (".str");
		szSRTFileTitle = szMP4FileTitle;
		szSRTFileExt = _T ("srt");

		CFileFind findStrFile;
		BOOL bWorking = findStrFile.FindFile(szSRTPathName);

		if (!bWorking)
		{
			// TODO: add warning for user to select srt file.
			infoStatic.SetWindowText(_T("Can not fide which *.srt to use automatically, please select a str file"));

			if (openSrtfileDlg.DoModal() == IDOK)
			{
				szSRTPathName = openSrtfileDlg.GetPathName();
				szSRTFolderPath = openSrtfileDlg.GetFolderPath();
				szSRTFileName = openSrtfileDlg.GetFileName();
				szSRTFileTitle = openSrtfileDlg.GetFileTitle();
				szSRTFileExt = openSrtfileDlg.GetFileExt();
			}
		}

		BOOL bIsSrtFile = TRUE;
		if (szSRTFileExt != _T("srt"))
		{
			bIsSrtFile = FALSE;
		}


		infoStatic.SetWindowText(_T("Please select the font name, only size and font name will use, now."));
		// Show the font dialog with 12 point "Yahei" as the 
		// selected font.
		LOGFONT lf;
		memset(&lf, 0, sizeof(LOGFONT));

		CClientDC dc(this);
		lf.lfHeight = -MulDiv(12, dc.GetDeviceCaps(LOGPIXELSY), 72);
		_tcscpy_s(lf.lfFaceName, LF_FACESIZE, _T("Î¢ÈíÑÅºÚ"));

		CFontDialog strFont(&lf);
		if (strFont.DoModal() == IDOK)
		{
			fontSize = strFont.GetSize()/10;
			fontFacename = strFont.GetFaceName();
		}
		
		szSRTPathNameWithOutExt = szSRTFolderPath + _T("\\") + szSRTFileTitle;
		
		switch (Mp4BoxParse (szMP4PathName, szSRTPathNameWithOutExt, fontFacename, fontSize, bIsSrtFile))
		{
			case 0:
				infoStatic.SetWindowText(_T("Subtitle file error. Maybe it is not in UTF-8 encoding"));
				break;
			case 1:
				infoStatic.SetWindowText(_T("Result file error. Check the video format please."));
				break;
			default:
				infoStatic.SetWindowText(_T("Successful!"));
				break;
		}
	}
}


int CiPodMovSrtDlg::Mp4BoxParse(CString szMp4PathName, CString szSRTPathNameWithOutExt, CString fontFacename, int fontSize, BOOL bIsSrtFile = TRUE)
{
	USES_CONVERSION;

	CString srtfontSize;
	int nLen;
	srtfontSize.Format(_T("%i"), fontSize);

	if (bIsSrtFile)
	{
		// generate ttxt file
		CString srtCmdSrt2Ttxt = _T ("cmd.exe /c MP4Box -ttxt \"") + szSRTPathNameWithOutExt + _T(".srt\" & pause");
		nLen = srtCmdSrt2Ttxt.GetLength();
		LPCSTR lpCmdSrt2Ttxt = T2A(srtCmdSrt2Ttxt.GetBuffer(nLen));
		if (system(lpCmdSrt2Ttxt) == -1)
		{
			// error
			return 0;
		}
	}

	// generate result file
	// MP4Box.exe -ipod -add "µçÓ°.mp4#1" -add "µçÓ°.mp4#2" -add "×ÖÄ».ttxt:lang=zho:font=Î¢ÈíÑÅºÚ:size=12" -new "ºÏ³É.mp4"
	CString srtCmdMp4AddSub = _T("cmd.exe /c MP4Box -ipod -add \"");
	srtCmdMp4AddSub = srtCmdMp4AddSub + szMp4PathName + _T("\" -add \"");
	srtCmdMp4AddSub = srtCmdMp4AddSub + szSRTPathNameWithOutExt + _T(".ttxt:lang=zho:font=");
	srtCmdMp4AddSub = srtCmdMp4AddSub + fontFacename + _T(":size=");
	srtCmdMp4AddSub = srtCmdMp4AddSub + srtfontSize + _T("\" -new \"") + CiPodMovSrtDlg::szMP4FolderPath + "\\" + CiPodMovSrtDlg::szMP4FileTitle + _T(".subbed.mp4\" & pause");
	nLen = srtCmdMp4AddSub.GetLength();
	LPCSTR lpCmdMp4AddSub = T2A (srtCmdMp4AddSub.GetBuffer(nLen));
	if (system(lpCmdMp4AddSub) == -1)
	{
		// error
		return 1;
	}	

	// delete ttxt file
	CFile ttxtFile;
	try
	{
		ttxtFile.Remove(szSRTPathNameWithOutExt + _T(".ttxt"));
	}
	catch (CFileException* pEx)
	{
		#ifdef _DEBUG
		afxDump << "File " << szSRTPathNameWithOutExt << " cannot be removed\n";
		#endif
		pEx->Delete();
	}
	return 33;
}

HBRUSH CiPodMovSrtDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDHtmlDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	static HBRUSH brush_red = ::CreateSolidBrush(RGB(233,233,0));
	if(pWnd->GetDlgCtrlID()==IDC_INFOSTATIC)
	{ 
		pDC->SetTextColor(RGB(0,0,0)); 
		pDC->SetBkMode(TRANSPARENT);
		CRect rect;
		GetDlgItem(IDC_INFOSTATIC) -> GetWindowRect (rect);
		pDC->SetBoundsRect(rect, DCB_DISABLE );
		return brush_red; 
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}
