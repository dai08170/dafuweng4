//Download by http://www.NewXing.com
// Date.h: interface for the CDate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATE_H__FE19F358_D6BE_490F_AE37_4E884B58728D__INCLUDED_)
#define AFX_DATE_H__FE19F358_D6BE_490F_AE37_4E884B58728D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDate : public CEntity
{
public:
	void ShowDate();
	void DayPass( CDC *pDC );
	int GetINP();
	int GetDay();
	int GetDayOfWeek();
	CDate();
	virtual ~CDate();
	
	virtual void Draw( CDC * pDC ){}		//��ͼ����ʱ�ڴ�*
	virtual bool IsOnMe( CPoint point ){return false;}	//���Ƿ����ҵ�������*
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );	//��ȡ*
	virtual int ToolName( CPoint point ){return 0;}	//����Ҫ�Ĺ���*
	virtual void WriteToStream( CArchive & ar );	//����*

private:
	int m_Date;		//��
	int m_Month;	//��
	int m_Year;		//��
	int m_DayOfWeek;//���ڼ�
	int m_AllDay;	//��¼����
	int m_INP;		//���ָ��
};

#endif // !defined(AFX_DATE_H__FE19F358_D6BE_490F_AE37_4E884B58728D__INCLUDED_)
