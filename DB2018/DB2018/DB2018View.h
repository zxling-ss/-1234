
// DB2018View.h : CDB2018View ��Ľӿ�
//

#pragma once

class CDB2018Set;

class CDB2018View : public CRecordView
{
protected: // �������л�����
	CDB2018View();
	DECLARE_DYNCREATE(CDB2018View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB2018_FORM };
#endif
	CDB2018Set* m_pSet;

// ����
public:
	CDB2018Doc * GetDocument() const;
	void draw_pic(CString file);

//	void OnPaint();
	void OnPaint(CString filename);
// ����
public:
	CString  filename, path, s;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDB2018View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnEnChangeEdit1();
	// ѧ��IDֵ
	long m_ID;
	// ����
	CString m_name;
	// ѧ��
	double m_number;
	// רҵ
	CString m_zhuanye;
	// �Ա�
	CString m_sex;
	// ��������
	long m_birth;
	// �ֻ�����
	double m_phone;
	// ��ͥסַ
	CString m_add;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnWrite();
	void OnSort();
	void OnSearch();
};

#ifndef _DEBUG  // DB2018View.cpp �еĵ��԰汾
inline CDB2018Doc* CDB2018View::GetDocument() const
   { return reinterpret_cast<CDB2018Doc*>(m_pDocument); }
#endif

