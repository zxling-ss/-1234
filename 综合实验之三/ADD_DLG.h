#pragma once


// ADD_DLG �Ի���

class ADD_DLG : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_DLG)

public:
	ADD_DLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADD_DLG();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
