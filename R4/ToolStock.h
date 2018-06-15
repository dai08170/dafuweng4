//Download by http://www.NewXing.com
// ToolStock.h: interface for the CToolStock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLSTOCK_H__3FE57EE0_A672_4C3D_BA75_1E42B8D8D191__INCLUDED_)
#define AFX_TOOLSTOCK_H__3FE57EE0_A672_4C3D_BA75_1E42B8D8D191__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"


class CToolStock : public CTool  
{
public:
	enum CounterState{None,Move};//���״̬,�ƶ�״̬
	bool IsOnCounterMove(CPoint pt);
	bool IsOnCounterNum( CPoint pt_Num);

	CToolStock(CDC * pDC);
	virtual ~CToolStock();
	virtual void Draw( CDC * pDC);
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ) ;
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ) ;
	virtual void OnLButtonDblClk( CDC * pDC, CPoint ptPos );
	virtual void OnRButtonDown( CDC * pDC, CPoint point );
	virtual int ToolName( CPoint point );
private:
	CDC m_CounterDC;//������������
	CBitmap m_CounterBitmap;//������λͼ
	CDC m_BusinessStateDC;//����״̬������
	CBitmap m_BusinessStateBitmap;//����״̬λͼ
	CDC m_GraphDC;//����״̬������
	CBitmap m_GraphBitmap;//����״̬λͼ

	CRect m_CounterRect;//����������
	CRect m_CounterMoveRect;//���������ƶ�����(����������)

	CPoint m_ptCounter;	//ȷ��������λ��
	CounterState m_CounterState;//ȷ��������״̬
	int m_iCounterNum;//��¼�������
	int m_ID;
};

#endif // !defined(AFX_TOOLSTOCK_H__3FE57EE0_A672_4C3D_BA75_1E42B8D8D191__INCLUDED_)
