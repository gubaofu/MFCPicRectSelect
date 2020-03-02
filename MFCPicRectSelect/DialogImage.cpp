// DialogImage.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCPicRectSelect.h"
#include "DialogImage.h"
#include "afxdialogex.h"


// DialogImage 对话框

IMPLEMENT_DYNAMIC(DialogImage, CDialogEx)

DialogImage::DialogImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(DialogImage::IDD, pParent)
{

}

DialogImage::~DialogImage()
{
}

void DialogImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC2, m_pic);
}


BEGIN_MESSAGE_MAP(DialogImage, CDialogEx)
	ON_BN_CLICKED(IDOK, &DialogImage::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DialogImage 消息处理程序


void DialogImage::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	int height, width;
	CRect rect;//定义矩形类
	CRect rect1;
	CImage image; //创建图片类
	CString imgPath;//图片路径
	int m_iValueX = 1, m_iValueY = 1;

	TCHAR DirectoryBuffer[1024] = {'\0'};
	GetCurrentDirectory(1024, DirectoryBuffer);
	imgPath.Format(_T("%s\\Test.bmp"),DirectoryBuffer);

	image.Load(imgPath);
	height = image.GetHeight();
	width = image.GetWidth();

	m_pic.GetClientRect(&rect); //获得pictrue控件所在的矩形区域

	CDC *pDc = m_pic.GetDC();//获得pictrue控件的Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	if (width <= rect.Width() && height <= rect.Width()) //小图片，不缩放
	{
		rect1 = CRect(rect.TopLeft(), CSize(width, height));
		image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //将图片画到Picture控件表示的矩形区域
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
				image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //将图片画到Picture控件表示的矩形区域
			}
		}
	}
	ReleaseDC(pDc);//释放picture控件的Dc
}


BOOL DialogImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	int height, width;
	CRect rect;//定义矩形类
	CRect rect1;
	CImage image; //创建图片类
	CString imgPath;//图片路径
	int m_iValueX = 1, m_iValueY = 1;

	TCHAR DirectoryBuffer[1024] = {'\0'};
	GetCurrentDirectory(1024, DirectoryBuffer);
	imgPath.Format(_T("%s\\Test.bmp"),DirectoryBuffer);

	image.Load(imgPath);
	height = image.GetHeight();
	width = image.GetWidth();

	m_pic.GetClientRect(&rect); //获得pictrue控件所在的矩形区域

	CDC *pDc = m_pic.GetDC();//获得pictrue控件的Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	if (width <= rect.Width() && height <= rect.Width()) //小图片，不缩放
	{
		rect1 = CRect(rect.TopLeft(), CSize(width, height));
		image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //将图片画到Picture控件表示的矩形区域
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
				image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //将图片画到Picture控件表示的矩形区域
			}
		}
	}
	ReleaseDC(pDc);//释放picture控件的Dc

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void DialogImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	int height, width;
	CRect rect;//定义矩形类
	CRect rect1;
	CImage image; //创建图片类
	CString imgPath;//图片路径
	int m_iValueX = 1, m_iValueY = 1;

	TCHAR DirectoryBuffer[1024] = {'\0'};
	GetCurrentDirectory(1024, DirectoryBuffer);
	imgPath.Format(_T("%s\\Test.bmp"),DirectoryBuffer);

	image.Load(imgPath);
	height = image.GetHeight();
	width = image.GetWidth();

	m_pic.GetClientRect(&rect); //获得pictrue控件所在的矩形区域

	CDC *pDc = m_pic.GetDC();//获得pictrue控件的Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	if (width <= rect.Width() && height <= rect.Width()) //小图片，不缩放
	{
		rect1 = CRect(rect.TopLeft(), CSize(width, height));
		image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //将图片画到Picture控件表示的矩形区域
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
				image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //将图片画到Picture控件表示的矩形区域
			}
		}
	}
	ReleaseDC(pDc);//释放picture控件的Dc
	// 不为绘图消息调用 CDialogEx::OnPaint()
}
