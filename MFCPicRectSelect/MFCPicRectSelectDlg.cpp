
// MFCPicRectSelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCPicRectSelect.h"
#include "MFCPicRectSelectDlg.h"
#include "afxdialogex.h"
#include "DialogImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCPicRectSelectDlg dialog



CMFCPicRectSelectDlg::CMFCPicRectSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCPicRectSelectDlg::IDD, pParent)
	, m_mx(0)
	, m_my(0)
	, m_rx(0)
	, m_ry(0)
	, m_rw(0)
	, m_rh(0)
	, m_sRectSelect(_T(""))
	, m_iValueX(1)
	, m_iValueY(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCPicRectSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC, m_pictureControl);
	DDX_Text(pDX, IDC_STATIC_MX, m_mx);
	DDX_Text(pDX, IDC_STATIC_MY, m_my);
	DDX_Text(pDX, IDC_STATIC_RX, m_rx);
	DDX_Text(pDX, IDC_STATIC_RY, m_ry);
	DDX_Text(pDX, IDC_STATIC_RW, m_rw);
	DDX_Text(pDX, IDC_STATIC_RH, m_rh);
	DDX_Text(pDX, IDC_STATIC_RECT, m_sRectSelect);
	DDX_Text(pDX, IDC_EDIT_X, m_iValueX);
	DDX_Text(pDX, IDC_EDIT_Y, m_iValueY);
}

BEGIN_MESSAGE_MAP(CMFCPicRectSelectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCPicRectSelectDlg::OnBnClickedOk)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_STN_DBLCLK(IDC_STATIC_PIC, &CMFCPicRectSelectDlg::OnStnDblclickStaticPic)
END_MESSAGE_MAP()


// CMFCPicRectSelectDlg message handlers

BOOL CMFCPicRectSelectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	// ����picture control����ߴ�
	CWnd* pWnd = GetDlgItem(IDC_STATIC_PIC);
	CRect rcPic;
	pWnd->GetClientRect(rcPic);

	rcPic.left = 0;
	rcPic.top = 0;
	rcPic.right = 360; // �ӿ�
	rcPic.bottom = 270; // �Ӹ�
	pWnd->MoveWindow(rcPic);  // �ı䴰�ڴ�С
	m_bMove = false;
	bFlag = false;
	m_bMouseDown = false;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCPicRectSelectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCPicRectSelectDlg::OnPaint()
{
	if (IsIconic())
	{
		//HDC hdc = ::GetDC(m_hWnd);
		//CDC dc;
		//dc.Attach(hdc);

		CPaintDC dc(&m_pictureControl); // device context for painting

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCPicRectSelectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCPicRectSelectDlg::OnBnClickedOk()
{
	UpdateData();

	show_picture();
	// ����IDΪ1�Ķ�ʱ��
	SetTimer(1, 50, NULL);

	DialogImage dg;
	dg.DoModal();
}

BOOL CMFCPicRectSelectDlg::show_picture()
{
	int height, width;
	CRect rect;//���������
	CRect rect1;
	CImage image; //����ͼƬ��
	CString imgPath;//ͼƬ·��

	TCHAR DirectoryBuffer[1024] = {'\0'};
	GetCurrentDirectory(1024, DirectoryBuffer);
	imgPath.Format(_T("%s\\Test.bmp"),DirectoryBuffer);

	image.Load(imgPath);
	height = image.GetHeight();
	width = image.GetWidth();

	m_pictureControl.GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������

	CDC *pDc = m_pictureControl.GetDC();//���pictrue�ؼ���Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	if (width <= rect.Width() && height <= rect.Width()) //СͼƬ��������
	{
		rect1 = CRect(rect.TopLeft(), CSize(width, height));
		image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
		return TRUE;
	}
	else
	{
		float xScale = (float)rect.Width() / (float)width / m_iValueX;
		float yScale = (float)rect.Height() / (float)height / m_iValueY;
		float ScaleIndex = (xScale <= yScale ? xScale : yScale);
		width = (int)width*ScaleIndex;
		height= (int)height*ScaleIndex;

		for	(int x = 0; x < m_iValueX; x++)
		{
			for(int y = 0; y <m_iValueY; y++)
			{
				rect1 = CRect(rect.TopLeft(), CSize((int)width*ScaleIndex, (int)height*ScaleIndex));
				rect1 = CRect(CPoint(x * width, y * height), CSize((int)width, (int)height));
				image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
			}
		}
	}
	ReleaseDC(pDc);//�ͷ�picture�ؼ���Dc
	return TRUE;
}


void CMFCPicRectSelectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CRect rect;
	m_pictureControl.GetClientRect(&rect);

	if (rect.PtInRect(point))
	{
		rcBorderL.left = m_rcOld.left - m_cBorderWidth;
		rcBorderL.right = m_rcOld.left +m_cBorderWidth;
		rcBorderL.top = m_rcOld.top + m_cBorderWidth;
		rcBorderL.bottom = m_rcOld.bottom - m_cBorderWidth >rcBorderL.top ? m_rcOld.bottom - m_cBorderWidth: rcBorderL.top + 1;
	
		rcBorderR = rcBorderL;
		rcBorderR.left = m_rcOld.right - m_cBorderWidth;
		rcBorderR.right = m_rcOld.right +m_cBorderWidth;
	
		rcBorderT.left = m_rcOld.left + m_cBorderWidth;
		rcBorderT.right = m_rcOld.right - m_cBorderWidth >rcBorderT.left ? m_rcOld.right - m_cBorderWidth: rcBorderT.left + 1;
		rcBorderT.top = m_rcOld.top - m_cBorderWidth;
		rcBorderT.bottom = m_rcOld.top + m_cBorderWidth;
	
		rcBorderB = rcBorderT;
		rcBorderB.top = m_rcOld.bottom - m_cBorderWidth;
		rcBorderB.bottom = m_rcOld.bottom +m_cBorderWidth;

		rcBorderLT = rcBorderL;
		rcBorderLT.top = rcBorderT.top;
		rcBorderLT.bottom = rcBorderT.bottom;

		rcBorderRT = rcBorderR;
		rcBorderRT.top = rcBorderT.top;
		rcBorderRT.bottom = rcBorderT.bottom;

		rcBorderLB = rcBorderL;
		rcBorderLB.top = rcBorderB.top;
		rcBorderLB.bottom = rcBorderB.bottom;

		rcBorderRB = rcBorderR;
		rcBorderRB.top = rcBorderB.top;
		rcBorderRB.bottom = rcBorderB.bottom;

		rcCenter = rcBorderL;
		rcCenter.left = rcBorderT.left;
		rcCenter.right = rcBorderT.right;

		//���任
		if(rcBorderL.PtInRect(point) )
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEWE)));
		}
		else if(rcBorderR.PtInRect(point))
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEWE)));
		}
		else if(rcBorderT.PtInRect(point) || rcBorderB.PtInRect(point))
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENS)));
		}
		else if(rcBorderLT.PtInRect(point) || rcBorderRB.PtInRect(point))
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENWSE)));
		}
		else if(rcBorderRT.PtInRect(point) || rcBorderLB.PtInRect(point))
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZENESW)));
		}
		else if(rcCenter.PtInRect(point))
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_SIZEALL)));
		}
		else
		{
			::SetCursor(::LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW)));
		}

		if(m_bMouseDown)
		{	
			if(m_bMove)
			{
				//ѡ�о����ƶ���ק���ı��С
				if(rcBorderL.PtInRect(point) )
				{
					m_rcNew.left = m_iLStart + point.x - m_pStart.x;
					DrawRect();
				}
				else if(rcBorderR.PtInRect(point))
				{
					m_rcNew.right = m_iRStart + point.x - m_pStart.x;
					DrawRect();
				}
				else if(rcBorderT.PtInRect(point))
				{
					m_rcNew.top = m_iTStart + point.y - m_pStart.y;
					DrawRect();
				}
				else if(rcBorderB.PtInRect(point))
				{
					m_rcNew.bottom = m_iBStart + point.y - m_pStart.y;
					DrawRect();
				}
				else if(rcBorderLT.PtInRect(point) )
				{
					m_rcNew.left = m_iLStart + point.x - m_pStart.x;
					m_rcNew.top = m_iTStart + point.y - m_pStart.y;
					DrawRect();
				}
				else if( rcBorderRB.PtInRect(point))
				{
					m_rcNew.right = m_iRStart + point.x - m_pStart.x;
					m_rcNew.bottom = m_iBStart + point.y - m_pStart.y;
					DrawRect();
				}
				else if(rcBorderRT.PtInRect(point) )
				{
					m_rcNew.right = m_iRStart + point.x - m_pStart.x;
					m_rcNew.top = m_iTStart + point.y - m_pStart.y;
					DrawRect();
				}
				else if( rcBorderLB.PtInRect(point))
				{
					m_rcNew.left = m_iLStart + point.x - m_pStart.x;
					m_rcNew.bottom = m_iBStart + point.y - m_pStart.y;
					DrawRect();
				}
				else if(rcCenter.PtInRect(point))
				{
					m_rcNew.left = m_rcStart.left + point.x - m_pStart.x;
					m_rcNew.right =  m_rcStart.right  + point.x - m_pStart.x;
					m_rcNew.top =  m_rcStart.top + point.y - m_pStart.y;
					m_rcNew.bottom =  m_rcStart.bottom + point.y - m_pStart.y;
					DrawRect();
				}
			}
			else
			{
				m_rcNew = CRect(m_pStart, point);
				DrawRect();
			}
			
			m_sRectSelect.Format(_T("Rect : %ld, %ld, %ld, %ld"),
									m_rcOld.left,
									m_rcOld.top,
									m_rcOld.Width(),
									m_rcOld.Height());
			UpdateData(FALSE);	
		}
	}

	CDialogEx::OnMouseMove(nFlags, point);
}

void CMFCPicRectSelectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRect rect;
	m_pictureControl.GetClientRect(&rect);

	if (rect.PtInRect(point))
	{		
		CRect rcTemp;
		
		m_bMouseDown = true;
		m_pStart = point;

		rcTemp.left = m_rcOld.left - m_cBorderWidth;
		rcTemp.top = m_rcOld.top - m_cBorderWidth;
		rcTemp.right = m_rcOld.right+ m_cBorderWidth;
		rcTemp.bottom = m_rcOld.bottom + m_cBorderWidth;

		if(rcTemp.PtInRect(point))
		{
			m_bMove = true;
			//m_pStart = point;

			if(rcBorderL.PtInRect(point))
			{
				m_iLStart = point.x;
			}
			else if(rcBorderR.PtInRect(point))
			{
				m_iRStart = point.x;
			}
			else if(rcBorderT.PtInRect(point))
			{
				m_iTStart = point.y;
			}
			else if(rcBorderB.PtInRect(point))
			{
				m_iBStart = point.y;
			}
			else if(rcBorderLT.PtInRect(point) )
			{
				m_iLStart = point.x;
				m_iTStart = point.y;
			}
			else if( rcBorderLB.PtInRect(point))
			{
				m_iLStart = point.x;
				m_iBStart = point.y;
			}
			else if(rcBorderRT.PtInRect(point) )
			{
				m_iRStart = point.x;
				m_iTStart = point.y;
			}
			else if(rcBorderRB.PtInRect(point))
			{
				m_iRStart = point.x;
				m_iBStart = point.y;
			}
			else if(rcCenter.PtInRect(point))
			{
				m_rcStart = m_rcOld;
			}
		}
		else
		{
			m_bMove = false;
			m_rcNew = CRect(point, point);
			DrawRect();
		}
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CMFCPicRectSelectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bMouseDown = false;

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCPicRectSelectDlg::OnTimer(UINT_PTR nIDEvent)
{
	CRect rect;
	CPoint cursorPos;

	m_pictureControl.GetClientRect(&rect);
	GetCursorPos(&cursorPos);

	m_mx = cursorPos.x;
	m_my = cursorPos.y;
	m_rx = rect.left;
	m_ry = rect.top;
	//m_rw = rect.Width();
	//m_rh = rect.Height();
	m_rw = rect.right;
	m_rh = rect.bottom;

	UpdateData(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}

void CMFCPicRectSelectDlg::DrawRect()
{
	int iTemp;
	CClientDC dc(&m_pictureControl);   //��ȡ�豸���
	CBrush newBrush;         // �������»�ˢ
	CBrush RedBrush(RGB(255, 0, 0));
    CBrush *pOldBrush;       // �ɻ�ˢ��ָ��
	// ��ѡ�����ɫ�����»�ˢ   
    //newBrush.CreateSolidBrush(color);   


	dc.SetROP2(R2_NOTXORPEN);   //��Ϊ�ؼ�!!! R2_NOT   Pixel is the inverse of the screen color.(MSDN)�����ú�������������Ƶ���ɫ�����ò�������ɫ����Ϊԭ��Ļ��ɫ�ķ�ɫ
	//dc.SelectStockObject(HS_FDIAGONAL); //��ʹ�û�ˢ
	newBrush.CreateHatchBrush(HS_FDIAGONAL, RGB(0, 0, 0));

	pOldBrush = dc.SelectObject(&newBrush);
	dc.Rectangle(m_rcOld);  //�ػ�����

	if(m_rcNew.left > m_rcNew.right)
	{
		iTemp = m_rcNew.left;
		m_rcNew.left = m_rcNew.right;
		m_rcNew.right = iTemp;
	}
	if(m_rcNew.top > m_rcNew.bottom)
	{
		iTemp = m_rcNew.top;
		m_rcNew.top = m_rcNew.bottom;
		m_rcNew.bottom = iTemp;
	}

	dc.Rectangle(m_rcNew);

	dc.SelectObject(pOldBrush); 
	newBrush.DeleteObject();

	m_rcOld = m_rcNew;
}

void CMFCPicRectSelectDlg::OnStnDblclickStaticPic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DrawRect();
}
