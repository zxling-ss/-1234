#pragma once


// ShowPicture 对话框

class ShowPicture : public CDialogEx
{
	DECLARE_DYNAMIC(ShowPicture)

public:
	ShowPicture(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowPicture();
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	void OnPaint(CString filename);

	DECLARE_MESSAGE_MAP()

public:
	afx_msg
		void draw_pic(CString filename);
	CString str;
	void OnPaint();
};
