// ShowPicture.cpp : 实现文件
//

#include "stdafx.h"
#include "DB2018.h"
#include "ShowPicture.h"
#include "afxdialogex.h"

// ShowPicture 对话框

IMPLEMENT_DYNAMIC(ShowPicture, CDialogEx)

ShowPicture::ShowPicture(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, str(_T(""))
{

}

ShowPicture::~ShowPicture()
{
}

void ShowPicture::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}




BEGIN_MESSAGE_MAP(ShowPicture, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ShowPicture 消息处理程序
void ShowPicture::draw_pic(CString filename)
{
	
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC2)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC2)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}

void ShowPicture::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
//	CString  str = _T("C:\\Users\\破晓之灵\\Pictures\\1.jpg");
	draw_pic(str);

	/*CImage img;
	img.Load(str);
	CDC* pDC = GetDlgItem(IDC_STATIC2)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC2)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);*/
}
