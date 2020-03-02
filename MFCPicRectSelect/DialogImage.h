#pragma once
#include "resource.h"
#include "afxwin.h"

// DialogImage 对话框

class DialogImage : public CDialogEx
{
	DECLARE_DYNAMIC(DialogImage)

public:
	DialogImage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DialogImage();

// 对话框数据
	enum { IDD = IDD_DIALOG_IMAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
