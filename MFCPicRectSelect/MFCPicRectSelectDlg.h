
// MFCPicRectSelectDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFCPicRectSelectDlg dialog
class CMFCPicRectSelectDlg : public CDialogEx
{
// Construction
public:
	CMFCPicRectSelectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCPICRECTSELECT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pictureControl;
	afx_msg void OnBnClickedOk();

private:
	//BOOL m_startRect;   //���ƾ��ο��־
	bool m_bMove;		//�ƶ��������ο�
	const static int m_cBorderWidth = 15;
	//CRect m_rcTest;
	//int m_iLeft, m_iRight, m_iTop, m_iBottom;
	CPoint m_pStart;  //��קǰλ��
	int m_iLStart, m_iRStart, m_iTStart, m_iBStart;  //��קǰλ��
	CRect m_rcStart;  //��קǰλ��
	CRect m_rcOld, m_rcNew;
	CRect rcBorderL, rcBorderR, rcBorderT, rcBorderB;  //���ο��������ұ߽�����
	CRect rcBorderLT, rcBorderRT, rcBorderLB, rcBorderRB;  //���ο�սǱ߽�����
	CRect rcCenter;  //���ο���������
	bool bFlag;
	bool m_bMouseDown;  //��갴��

	//CPoint m_startPoint; //���ο�ʼ��
	//CPoint m_OldPoint;   //���ο��յ�
	BOOL show_picture();
	void DrawRect();

public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_mx;
	int m_my;
	int m_rx;
	int m_ry;
	int m_rw;
	int m_rh;
	CString m_sRectSelect;
	int m_iValueX;
	int m_iValueY;
	afx_msg void OnStnDblclickStaticPic();
};
