
// DB2018View.cpp : CDB2018View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DB2018.h"
#endif

#include "DB2018Set.h"
#include "DB2018Doc.h"
#include "DB2018View.h"
#include"ShowPicture.h"
#include"MyDlg2.h"
#include"MyDlg3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB2018View

IMPLEMENT_DYNCREATE(CDB2018View, CRecordView)

BEGIN_MESSAGE_MAP(CDB2018View, CRecordView)
	ON_EN_CHANGE(IDC_EDIT1, &CDB2018View::OnEnChangeEdit1)
	ON_COMMAND(ID_RECORD_FIRST, &CDB2018View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CDB2018View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CDB2018View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CDB2018View::OnRecordLast)
	//ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CDB2018View::OnBnClickedButton1)
	ON_COMMAND(ID_Write, &CDB2018View::OnWrite)
	ON_COMMAND(ID_Sort, &CDB2018View::OnSort)
	ON_COMMAND(ID_Search, &CDB2018View::OnSearch)
END_MESSAGE_MAP()

// CDB2018View 构造/析构

CDB2018View::CDB2018View()
	: CRecordView(IDD_DB2018_FORM)
	, m_ID(0)
	, m_name(_T(""))
	, m_number(0)
	, m_zhuanye(_T(""))
	, m_sex(_T(""))
	, m_birth(0)
	, m_phone(0)
	, m_add(_T(""))
{
	m_pSet = NULL;

	// TODO: 在此处添加构造代码
	path = _T("C:\\Users\\破晓之灵\\Pictures\\");
}

CDB2018View::~CDB2018View()
{
}

void CDB2018View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1,m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2,m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT9, m_pSet->column8);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
}

BOOL CDB2018View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}


void CDB2018View::OnInitialUpdate()
{

	m_pSet = &GetDocument()->m_DB2018Set;
	CRecordView::OnInitialUpdate();

}


// CDB2018View 诊断

#ifdef _DEBUG
void CDB2018View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB2018View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB2018Doc* CDB2018View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB2018Doc)));
	return (CDB2018Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB2018View 数据库支持
CRecordset* CDB2018View::OnGetRecordset()
{
	return m_pSet;

}



// CDB2018View 消息处理程序


void CDB2018View::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDB2018View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT9, s);
	filename = path + s;
	Invalidate();
	draw_pic(filename);
	OnPaint(filename);
	
	//CString sql = select语句;//如select * from information。information为表名。

		//	m_set->Open(CRecordset::dynaset, sql); // dynaset为查询方式，你照写就行，具体的到msdn上看看
	//	m_pSet->Open(CRecordset::dynaset, sql);

}


void CDB2018View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT9, s);
	filename = path + s;
	OnPaint(filename);
//	Invalidate();
}


void CDB2018View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT9, s);
	filename = path + s;
	OnPaint(filename);
	// Invalidate();
}


void CDB2018View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT9, s);
	filename = path + s;
	OnPaint(filename);
//	Invalidate();
}
void CDB2018View::draw_pic(CString file) {
	CImage img;
	img.Load(file); 
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

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

void CDB2018View::OnPaint(CString filename)
{
	CPaintDC dc(this); // device context for painting
					    /*TODO: 在此处添加消息处理程序代码
					    不为绘图消息调用 CRecordView::OnPaint()*/
//	CString filename;
	CImage img;
	img.Load(filename);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
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
////	CString filename;
//	GetDlgItemText(IDC_EDIT9, s);
//	filename = path + s;
//	draw_pic(filename);
//
}


void CDB2018View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowPicture cfd;
	GetDlgItemText(IDC_EDIT9, s);
	filename = path + s;
	UpdateData(true);
	cfd.str = filename;
	UpdateData(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
			
	}

}


void CDB2018View::OnWrite()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg3 dlg3;
	CString str; int i;
	m_pSet->MoveFirst();
	while (!(m_pSet->IsEOF())) {
		for (i = 1; i < m_pSet->GetODBCFieldCount(); i++) {
			m_pSet->GetFieldValue((short)i, str);
			dlg3.str3 = dlg3.str3 + ' ' + ' ';
			dlg3.str3 = dlg3.str3 + str;
		}
		m_pSet->MoveNext();
	}
	int r = dlg3.DoModal();

}


void CDB2018View::OnSort()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strSort = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}
}


void CDB2018View::OnSearch()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg2 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		this->UpdateData(false);
		m_pSet->m_strFilter = dlg.a;
		m_pSet->Requery();
		Invalidate();
	}

}
