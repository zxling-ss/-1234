
// 综合实验之三View.h : C综合实验之三View 类的接口
//

#pragma once

class C综合实验之三Set;

class C综合实验之三View : public CRecordView
{
protected: // 仅从序列化创建
	C综合实验之三View();
	DECLARE_DYNCREATE(C综合实验之三View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C综合实验之三Set* m_pSet;

// 特性
public:
	C综合实验之三Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C综合实验之三View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedButton3();
	int coun;
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // 综合实验之三View.cpp 中的调试版本
inline C综合实验之三Doc* C综合实验之三View::GetDocument() const
   { return reinterpret_cast<C综合实验之三Doc*>(m_pDocument); }
#endif

