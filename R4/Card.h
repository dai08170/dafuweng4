//Download by http://www.NewXing.com
// Card.h: interface for the CCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARD_H__3BBA202D_DE48_4956_AB9F_289382023C26__INCLUDED_)
#define AFX_CARD_H__3BBA202D_DE48_4956_AB9F_289382023C26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

class CCard : public CEntity  
{
public:
	int Poor();
	//ö�ٿ�Ƭ����
    enum Type
	{
		AngelCard = 1,	//��ʹ��
		SleepCard,		//���߿�
		LeagueCard,		//ͬ�˿�
		FreeCard,		//��ѿ�
		RemissionCard,	//���￨
		ChangeWayCard	//ת��
	};

	CCard(CDC * pDC,int nID = 0);
	virtual ~CCard();
	virtual void CardISBeUsed( int nI );
	//һ���ַ��ݼӸ�һ��
	virtual void AddBiuldHouse();
	//��Ʊ��ͣ����
	void Harden();
	//gupiao zhangting santian

	//��ѿ���ѵ���һ��
	//virtual void Free();
	//���￨
	void Remission();

	virtual void Draw( CDC * pDC );      //������ĻDC��
	void Draw( CPoint point );   //���ڱ�����
	virtual void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual int IsCard();
	virtual int ToolName( CPoint point );
	int GetID();
	virtual void WriteToStream( CArchive & ar );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );

private:
	int m_Point;	//��Ƭ����
	int m_nDays;
	int m_ID;       //��Ƭ�ı��
	CString m_Bmp;  //ÿ����ƬͼƬ���ļ���
	CString m_str;    //����ID�õ���Ƭ�ַ���
};

#endif // !defined(AFX_CARD_H__3BBA202D_DE48_4956_AB9F_289382023C26__INCLUDED_)
