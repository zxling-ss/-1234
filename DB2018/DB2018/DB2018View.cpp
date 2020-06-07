
// DB2018View.cpp : CDB2018View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CDB2018View ����/����

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

	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\Users\\����֮��\\Pictures\\");
}

CDB2018View::~CDB2018View()
{
}

void CDB2018View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}


void CDB2018View::OnInitialUpdate()
{

	m_pSet = &GetDocument()->m_DB2018Set;
	CRecordView::OnInitialUpdate();

}


// CDB2018View ���

#ifdef _DEBUG
void CDB2018View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDB2018View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDB2018Doc* CDB2018View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDB2018Doc)));
	return (CDB2018Doc*)m_pDocument;
}
#endif //_DEBUG


// CDB2018View ���ݿ�֧��
CRecordset* CDB2018View::OnGetRecordset()
{
	return m_pSet;

}



// CDB2018View ��Ϣ�������


void CDB2018View::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDB2018View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT9, s);
	filename = path + s;
	Invalidate();
	draw_pic(filename);
	OnPaint(filename);
	
	//CString sql = select���;//��select * from information��informationΪ������

		//	m_set->Open(CRecordset::dynaset, sql); // dynasetΪ��ѯ��ʽ������д���У�����ĵ�msdn�Ͽ���
	//	m_pSet->Open(CRecordset::dynaset, sql);

}


void CDB2018View::OnRecordPrev()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
					    /*TODO: �ڴ˴������Ϣ����������
					    ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()*/
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
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
