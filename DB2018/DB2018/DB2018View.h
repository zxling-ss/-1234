
// DB2018View.h : CDB2018View 类的接口
//

#pragma once

class CDB2018Set;

class CDB2018View : public CRecordView
{
protected: // 仅从序列化创建
	CDB2018View();
	DECLARE_DYNCREATE(CDB2018View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB2018_FORM };
#endif
	CDB2018Set* m_pSet;

// 特性
public:
	CDB2018Doc * GetDocument() const;
	void draw_pic(CString file);

//	void OnPaint();
	void OnPaint(CString filename);
// 操作
public:
	CString  filename, path, s;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CDB2018View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnEnChangeEdit1();
	// 学生ID值
	long m_ID;
	// 姓名
	CString m_name;
	// 学号
	double m_number;
	// 专业
	CString m_zhuanye;
	// 性别
	CString m_sex;
	// 出生年月
	long m_birth;
	// 手机号码
	double m_phone;
	// 家庭住址
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

#ifndef _DEBUG  // DB2018View.cpp 中的调试版本
inline CDB2018Doc* CDB2018View::GetDocument() const
   { return reinterpret_cast<CDB2018Doc*>(m_pDocument); }
#endif

