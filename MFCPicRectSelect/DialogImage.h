#pragma once
#include "resource.h"
#include "afxwin.h"

// DialogImage �Ի���

class DialogImage : public CDialogEx
{
	DECLARE_DYNAMIC(DialogImage)

public:
	DialogImage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialogImage();

// �Ի�������
	enum { IDD = IDD_DIALOG_IMAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
