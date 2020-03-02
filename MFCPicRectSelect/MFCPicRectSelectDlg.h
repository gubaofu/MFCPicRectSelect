
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
	//BOOL m_startRect;   //绘制矩形框标志
	bool m_bMove;		//移动调整矩形框
	const static int m_cBorderWidth = 15;
	//CRect m_rcTest;
	//int m_iLeft, m_iRight, m_iTop, m_iBottom;
	CPoint m_pStart;  //拖拽前位置
	int m_iLStart, m_iRStart, m_iTStart, m_iBStart;  //拖拽前位置
	CRect m_rcStart;  //拖拽前位置
	CRect m_rcOld, m_rcNew;
	CRect rcBorderL, rcBorderR, rcBorderT, rcBorderB;  //矩形框上下左右边界区域
	CRect rcBorderLT, rcBorderRT, rcBorderLB, rcBorderRB;  //矩形框拐角边界区域
	CRect rcCenter;  //矩形框中心区域
	bool bFlag;
	bool m_bMouseDown;  //鼠标按下

	//CPoint m_startPoint; //矩形框开始点
	//CPoint m_OldPoint;   //矩形框终点
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
