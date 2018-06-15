//Download by http://www.NewXing.com
// God.h: interface for the CGod class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GOD_H__1DE64F01_DABC_44C6_9B3C_1987E13060CA__INCLUDED_)
#define AFX_GOD_H__1DE64F01_DABC_44C6_9B3C_1987E13060CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"
//#include "Per.h"
class CPer;

class CGod : public CEntity  
{
public:
	enum Immortal{None = 0,
				Wealth/*����*/,
				GriefMan/*����*/,
				Billiken/*����*/,
				PoorMan/*����*/,
				Angell/*��ʹ*/,
				present/*����*/,
				dog/*��*/,
				box/*����*/};//��������

	CGod( CDC *pDC , CPoint point, int nName  = 0 );
	virtual ~CGod();
	virtual void Draw( CDC * pDC );
	virtual bool IsWalkNum();
	virtual void GetGod();//��������
	virtual void LeaveGod();//�����뿪
	virtual void DrawOnPerInfo();
	virtual int ReduceWalkNum();//��������������

	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );
private:
	int m_WalkNum;//����
	int m_immortal;//��������

	CBitmap m_FlyShadowBitmap;
	CDC m_FlyShadowDC;

	CBitmap m_FlyBitmap;
	CDC m_FlyDC;
};

#endif // !defined(AFX_GOD_H__1DE64F01_DABC_44C6_9B3C_1987E13060CA__INCLUDED_)
