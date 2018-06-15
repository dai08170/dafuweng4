//Download by http://www.NewXing.com
// EntityNode.h: interface for the CEntityNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENTITYNODE_H__E04BBCE9_B606_4E93_AB00_2B7E1A65FDE3__INCLUDED_)
#define AFX_ENTITYNODE_H__E04BBCE9_B606_4E93_AB00_2B7E1A65FDE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"
#include "Glebe.h"
#include "Per.h"

//·�ڵ�*
class CEntityNode  
{
public:
	enum WayName
	{
		NotOnWay = 0,
		NanJinWay,
		BeiJinway
	};

	CEntityNode( CPoint ptCoordinate, int nWayName,
				CGod * pGod, CGlebe * pGlebe, CPer * pPer);
	virtual ~CEntityNode();
	bool AddGodOrProperty( CEntity * pEntity , CPoint point );
	void Draw( CDC * pDC );
	void DrawOnSmallMap( CDC * pDC );
	void DrawOnSmallMapView( CDC * pDC );
	bool IsOnGlebe( CPoint point );
	bool IsOnMe( CPoint point );
	bool IsOnPer( CPoint point );
	void ReadFromStream( CDC * pDC, CArchive & ar );
	void WriteToStream( CArchive & ar );

public:
	CPoint m_ptCoordinate;			//����
	int m_WayName;					//�������ڵ�·��
	CGlebe * m_pGlebe;				//ָ������
	CPer * m_pPer;					//ָ����
	CPer * m_pSecondPer;			//ָ��ڶ�����
	CEntity * m_pGod;				//ָ�����ɻ����
	CEntityNode * m_pENPrevious;	//ָ��ǰһ���ڵ�
	CEntityNode * m_pENNext;
};

#endif // !defined(AFX_ENTITYNODE_H__E04BBCE9_B606_4E93_AB00_2B7E1A65FDE3__INCLUDED_)
