//Download by http://www.NewXing.com
// ToolDice.h: interface for the CToolDice class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLDICE_H__298F5993_80A4_4B94_86BE_ABBD6B8F3816__INCLUDED_)
#define AFX_TOOLDICE_H__298F5993_80A4_4B94_86BE_ABBD6B8F3816__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolDice : public CTool  
{
public:
	enum GoType
	{
		None = 0,	//���״̬
		Go,			//�ƶ�����
		Move		//�ƶ�ͼƬ
	};

	CToolDice( CDC *pDC );
	virtual ~CToolDice();

	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos );
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos );
	virtual void OnTimer( CDC * pDC );
	virtual int ToolName( CPoint point );

private:
	CDC m_DiceShadowDC;
	CBitmap m_DiceShadowBitmap;

	CDC m_DiceDC;
	CBitmap m_DiceBitmap;

	CDC m_LightDC;
	CBitmap m_LightBitmap;

	bool m_bBitmapType;//��ͼ�ж�
	int m_nCount;	//��˸����*
	int m_Type;		//�ж������������¼�
	CPoint m_pt;	//������λ��
	CRect m_DiceRect;	//ɫ������*
	int m_DiceNum;		//ɸ�ӵ���*
	int m_DiceStep;		//ɫ����ͼ*
	int m_nDiceCount;	//��˸����*

	static CRect m_MoveRect; //���������������ƶ�
};

#endif // !defined(AFX_TOOLDICE_H__298F5993_80A4_4B94_86BE_ABBD6B8F3816__INCLUDED_)
