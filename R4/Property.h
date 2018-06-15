//Download by http://www.NewXing.com
// Property.h: interface for the CProperty class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPERTY_H__3907DC42_5473_4FD6_9831_557BFDCA7700__INCLUDED_)
#define AFX_PROPERTY_H__3907DC42_5473_4FD6_9831_557BFDCA7700__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

class CProperty : public CEntity  
{
public:
	void ChangeMyRect(CPoint point);
	enum Type
	{
		Torpedo = 1,      //����
		RoadBlock,    //·��       
		TimeBomb,	  //��ʱը��
        Missile,      //�ɵ�
		Nucleon,      //���ӷɵ�
        Car,          //����  
		Engine,       //����  
		RemoteDice,  //ң��ɫ��
		Mobile,       //���̳�  
		Robot,        //��������
		TimeMachine,  //ʱ���
        TransMachine, //���ͻ�
		RobotBaby     //��������
	}; 
	CProperty(CDC * pDC, int nID =0 , CPoint point = CPoint(0, 0));
	virtual ~CProperty();
	virtual void Draw( CDC * pDC );      //������ĻDC��
	void Draw( bool isBig, CPoint point );   //���ڱ�����
	virtual void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual int IsCard();
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual void PropertyIsBeUsed( int nI );

	int GetID();
	void ClearRoad();
	//void SetProperty(int);         //���õ���
	char * GetNameOfProperty(int);         //���ݵ��߱�ŵõ���������

	//ը��סԺ����������1 ��Ҷ���ָ�룩  2סԺ����
	//����  ��ʱը��   �ɵ�   ���ӷɵ�ʹ��
	void MakePeopleInHispital(CPer *, int); 

	//�ı�ɫ�Ӻ���������1 ɫ�Ӹ���  2ɫ�ӵ���
	//����  ����  ң��ɫ��ʹ��
	void ChangeNumberOrCountOfDice();

    //�ı䷿�ӵȼ���𷿡����� ���Ӷ���ָ�룩
	//���̳�  ��������ʹ��
	void ChangeOrDestoryHouse();

	//Load��һ�غϷ���  ʱ���ʹ��
	void  ReturnLast();

	//�ƶ�����ָ���ص�  ���ͻ�ʹ��
	void  MoveObject( );

	//��ֹ����ƶ�  ·��ʹ��
	void  StopPeople();

	//������е��� ��������ʹ��
	
	enum canBuy               //�����ܷ���
	{
	    yes,
		no
	};

private:
    int m_Money;          //���ߵļ۸�
	int m_ID;             //���ߵı��
	int m_nDays;
	CString m_Bmp;        //ÿ������ͼƬ�ļ���
	CString m_BmpShadow;  //ÿ������Ӱ���ļ���
	CString m_BmpCount;   //ͼƬ��Ӱ�ӵĻ���
};

#endif // !defined(AFX_PROPERTY_H__3907DC42_5473_4FD6_9831_557BFDCA7700__INCLUDED_)
