// DialogImage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCPicRectSelect.h"
#include "DialogImage.h"
#include "afxdialogex.h"


// DialogImage �Ի���

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


// DialogImage ��Ϣ�������


void DialogImage::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int height, width;
	CRect rect;//���������
	CRect rect1;
	CImage image; //����ͼƬ��
	CString imgPath;//ͼƬ·��
	int m_iValueX = 1, m_iValueY = 1;

	TCHAR DirectoryBuffer[1024] = {'\0'};
	GetCurrentDirectory(1024, DirectoryBuffer);
	imgPath.Format(_T("%s\\Test.bmp"),DirectoryBuffer);

	image.Load(imgPath);
	height = image.GetHeight();
	width = image.GetWidth();

	m_pic.GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������

	CDC *pDc = m_pic.GetDC();//���pictrue�ؼ���Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	if (width <= rect.Width() && height <= rect.Width()) //СͼƬ��������
	{
		rect1 = CRect(rect.TopLeft(), CSize(width, height));
		image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
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
}


BOOL DialogImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int height, width;
	CRect rect;//���������
	CRect rect1;
	CImage image; //����ͼƬ��
	CString imgPath;//ͼƬ·��
	int m_iValueX = 1, m_iValueY = 1;

	TCHAR DirectoryBuffer[1024] = {'\0'};
	GetCurrentDirectory(1024, DirectoryBuffer);
	imgPath.Format(_T("%s\\Test.bmp"),DirectoryBuffer);

	image.Load(imgPath);
	height = image.GetHeight();
	width = image.GetWidth();

	m_pic.GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������

	CDC *pDc = m_pic.GetDC();//���pictrue�ؼ���Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	if (width <= rect.Width() && height <= rect.Width()) //СͼƬ��������
	{
		rect1 = CRect(rect.TopLeft(), CSize(width, height));
		image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
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

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void DialogImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	int height, width;
	CRect rect;//���������
	CRect rect1;
	CImage image; //����ͼƬ��
	CString imgPath;//ͼƬ·��
	int m_iValueX = 1, m_iValueY = 1;

	TCHAR DirectoryBuffer[1024] = {'\0'};
	GetCurrentDirectory(1024, DirectoryBuffer);
	imgPath.Format(_T("%s\\Test.bmp"),DirectoryBuffer);

	image.Load(imgPath);
	height = image.GetHeight();
	width = image.GetWidth();

	m_pic.GetClientRect(&rect); //���pictrue�ؼ����ڵľ�������

	CDC *pDc = m_pic.GetDC();//���pictrue�ؼ���Dc
	SetStretchBltMode(pDc->m_hDC, STRETCH_HALFTONE);

	if (width <= rect.Width() && height <= rect.Width()) //СͼƬ��������
	{
		rect1 = CRect(rect.TopLeft(), CSize(width, height));
		image.StretchBlt(pDc->m_hDC, rect1, SRCCOPY); //��ͼƬ����Picture�ؼ���ʾ�ľ�������
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
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
