
// iPodMovStrDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CiPodMovStrDlg dialog
class CiPodMovSrtDlg : public CDHtmlDialog
{
// Construction
public:
	CiPodMovSrtDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_IPODMOVSTR_DIALOG, IDH = IDR_HTML_IPODMOVSTR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnBnClickedButtonSelectmp4file();

private:
	// // Infobar
	CStatic infoStatic;
	CString szMP4PathName;
	CString szMP4FolderPath;
	CString szMP4FileName;
	CString szMP4FileTitle;
	CString szMP4FileExt;

	CString szSRTPathName;
	CString szSRTFolderPath;
	CString szSRTFileName;
	CString szSRTFileTitle;
	CString szSRTFileExt;
	CString szSRTPathNameWithOutExt;

	int Mp4BoxParse(CString szMp4PathName, CString szSRTPathNameWithOutExt, CString fontFacename, int fontSize, BOOL bIsSrtFile);
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
