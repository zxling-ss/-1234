// MyDlg3.cpp : 实现文件
//

#include "stdafx.h"
#include "DB2018.h"
#include "MyDlg3.h"
#include "afxdialogex.h"


// MyDlg3 对话框

IMPLEMENT_DYNAMIC(MyDlg3, CDialogEx)

MyDlg3::MyDlg3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, str3(_T(""))
{

}

MyDlg3::~MyDlg3()
{
}

void MyDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_LBString(pDX, IDC_LIST1, str3);
}


BEGIN_MESSAGE_MAP(MyDlg3, CDialogEx)
END_MESSAGE_MAP()


// MyDlg3 消息处理程序
