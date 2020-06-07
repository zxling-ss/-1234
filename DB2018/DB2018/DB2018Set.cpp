
// DB2018Set.cpp : CDB2018Set ���ʵ��
//

#include "stdafx.h"
#include "DB2018.h"
#include "DB2018Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB2018Set ʵ��

// ���������� 2020��5��12��, 20:02

IMPLEMENT_DYNAMIC(CDB2018Set, CRecordset)

CDB2018Set::CDB2018Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = 0.0;
	column3 = L"";
	column4 = L"";
	column5 = 0;
	column6 = 0.0;
	column7 = L"";
	column8 = L"";
	column9 = L"";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB2018Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f;DBQ=C:\\Users\\\x7834\x6653\x4e4b\x7075\\Documents\\\x5b66\x751f\x4fe1\x606f.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDB2018Set::GetDefaultSQL()
{

	
	return _T("[ѧ����Ϣ]");
}

void CDB2018Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[רҵ]"), column3);
	RFX_Text(pFX, _T("[�Ա�]"), column4);
	RFX_Long(pFX, _T("[��������]"), column5);
	RFX_Double(pFX, _T("[�ֻ�����]"), column6);
	RFX_Text(pFX, _T("[��ͥסַ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ�ļ���]"), column8);
	RFX_Text(pFX, _T("[��Ƭ�ļ���]"), column9);

}
/////////////////////////////////////////////////////////////////////////////
// CDB2018Set ���

#ifdef _DEBUG
void CDB2018Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB2018Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

