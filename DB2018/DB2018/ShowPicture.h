#pragma once


// ShowPicture �Ի���

class ShowPicture : public CDialogEx
{
	DECLARE_DYNAMIC(ShowPicture)

public:
	ShowPicture(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowPicture();
	

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	void OnPaint(CString filename);

	DECLARE_MESSAGE_MAP()

public:
	afx_msg
		void draw_pic(CString filename);
	CString str;
	void OnPaint();
};
