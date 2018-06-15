//Download by http://www.NewXing.com
// Entity.h: interface for the CEntity class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENTITY_H__C462478F_B828_4816_877C_4709250387DA__INCLUDED_)
#define AFX_ENTITY_H__C462478F_B828_4816_877C_4709250387DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//ʵ���ุ��*
class CEntity  
{
public:
    enum Type
	{
		Nothing = 0,
		Glebe,
		Per,
		God
	};

	CEntity();
	virtual ~CEntity();

	virtual void Draw( CDC * pDC ) = 0;		//��ͼ����ʱ�ڴ�*
	virtual void DrawOnPerInfo(){}			//��������Ϣ����ʾ�й�����
	virtual bool IsWalkNum(){return false;}
	virtual bool IsOnMe( CPoint point ) = 0;	//���Ƿ����ҵ�������*
	virtual void ReadFromStream( CDC * pDC, CArchive & ar ) = 0;	//��ȡ*
	virtual int ToolName( CPoint point ) = 0;	//����Ҫ�Ĺ���*
	virtual void WriteToStream( CArchive & ar ) = 0;	//����*
	void ChangeMyRect(CPoint point);  //Ϊ�˵��ߺͿ�Ƭ���ڴ��ͼ��
	virtual int GetID(){return 0;}
	virtual void GetGod(){}				//��������
	virtual void LeaveGod(){}			//�����뿪
	virtual int ReduceWalkNum(){return 0;}	
	virtual int IsCard(){return 0;}//�ж��ǿ�Ƭ���ǵ���
	virtual void CardISBeUsed( int nI ){}//�˱���Ƭ����
	virtual void PropertyIsBeUsed( int nI ){};//�˱���������

protected:
	CBitmap m_MyShadowBitmap;	//��ͼ��*
	CDC m_MyShadowDC;
	CBitmap m_MyBitmap;
	CDC m_MyDC;
	CRect m_MyRect;				//��������*
};

#endif // !defined(AFX_ENTITY_H__C462478F_B828_4816_877C_4709250387DA__INCLUDED_)
