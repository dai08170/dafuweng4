//Download by http://www.NewXing.com
// ToolLendFund.h: interface for the CToolLendFund class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLLENDFUND_H__FA96168B_CB59_473F_AF02_4E372DE1B07D__INCLUDED_)
#define AFX_TOOLLENDFUND_H__FA96168B_CB59_473F_AF02_4E372DE1B07D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"

class CToolLendFund : public CTool  
{
public:
	CToolLendFund(CDC * pDC);
	virtual ~CToolLendFund();

	virtual void Draw(CDC * pDC);
	virtual bool IsOnMe( CPoint point );
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ){}
	virtual void OnTimer( CDC * pDC){}
	virtual int ToolName( CPoint point);

private:
	int m_iLend;//����
	CRect m_CounterRect;//����������
	CDC m_CounterDC;//������������
	CBitmap m_CounterBitmap;//������λͼ
};

#endif // !defined(AFX_TOOLLENDFUND_H__FA96168B_CB59_473F_AF02_4E372DE1B07D__INCLUDED_)
