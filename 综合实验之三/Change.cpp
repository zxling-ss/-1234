// Change.cpp : 实现文件
//

#include "stdafx.h"
#include "综合实验之三.h"
#include "Change.h"
#include "afxdialogex.h"


// Change 对话框

IMPLEMENT_DYNAMIC(Change, CDialogEx)

Change::Change(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, j(0)
{

}

Change::~Change()
{
}

void Change::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, j);
}


BEGIN_MESSAGE_MAP(Change, CDialogEx)
END_MESSAGE_MAP()


// Change 消息处理程序
