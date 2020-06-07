#pragma once


// Change 对话框

class Change : public CDialogEx
{
	DECLARE_DYNAMIC(Change)

public:
	Change(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Change();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int j;
};
