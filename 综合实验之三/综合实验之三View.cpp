
// 综合实验之三View.cpp : C综合实验之三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验之三.h"
#endif

#include "综合实验之三Set.h"
#include "综合实验之三Doc.h"
#include "综合实验之三View.h"
#include"ADD_DLG.h"
#include"Change.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验之三View

IMPLEMENT_DYNCREATE(C综合实验之三View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验之三View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_ADD, &C综合实验之三View::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON3, &C综合实验之三View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &C综合实验之三View::OnBnClickedButton2)
END_MESSAGE_MAP()

// C综合实验之三View 构造/析构

C综合实验之三View::C综合实验之三View()
	: CRecordView(IDD_MY_FORM)
	, coun(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C综合实验之三View::~C综合实验之三View()
{
}

void C综合实验之三View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL C综合实验之三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验之三View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验之三Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验之三View 打印

BOOL C综合实验之三View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C综合实验之三View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C综合实验之三View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C综合实验之三View 诊断

#ifdef _DEBUG
void C综合实验之三View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验之三View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验之三Doc* C综合实验之三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验之三Doc)));
	return (C综合实验之三Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验之三View 数据库支持
CRecordset* C综合实验之三View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验之三View 消息处理程序


void C综合实验之三View::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->AddNew();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void C综合实验之三View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void C综合实验之三View::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Change c;
	int r = c.DoModal();
	if (r == IDOK)
	{
		int jk = c.j;
		m_pSet->Edit();
		m_pSet->m_1 = jk;
		m_pSet->Update();
		UpdateData(false);
	}

}
