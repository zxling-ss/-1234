#pragma once


// Change �Ի���

class Change : public CDialogEx
{
	DECLARE_DYNAMIC(Change)

public:
	Change(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Change();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int j;
};
