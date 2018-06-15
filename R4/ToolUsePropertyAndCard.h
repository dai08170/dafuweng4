//Download by http://www.NewXing.com
// ToolUsePropertyAndCard.h: interface for the CToolUsePropertyAndCard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLUSEPROPERTYANDCARD_H__907614F4_777E_4C84_BDF9_4F304F186D21__INCLUDED_)
#define AFX_TOOLUSEPROPERTYANDCARD_H__907614F4_777E_4C84_BDF9_4F304F186D21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tool.h"
#include "Per.h"
#include "Property.h"
#include "Entity.h"

class CToolUsePropertyAndCard : public CTool  
{
public:
	CToolUsePropertyAndCard(CDC * pDC, CEntity * pEntity);
	virtual ~CToolUsePropertyAndCard();

	virtual void Draw( CDC * pDC);
	void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );

	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ){}
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos );
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ){}
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos );
	int ToolName( CPoint point );
	//virtual int ToolName( CPoint point );
private:
	int m_ID;
	CDC m_noUseDC;        //��*��ͼ��DC
	CDC m_noUseShadowDC;   //��*��ͼ��Ӱ��DC

	CDC m_useDC;          //����DC
	CDC m_useShadowDC;       //����Ӱ��DC
	
	CBitmap m_noUseBitMap;      //��*��ͼ��λͼ
	CBitmap m_noUseShadowBitMap;//��*��ͼ��Ӱ��λͼ

	CBitmap m_useBitMap;      //����ͼ��λͼ
	CBitmap m_useShadowBitMap;//����ͼ��Ӱ��λͼ

	bool m_canUseDraw;          //��ͼ״̬
	CPoint m_point;             //�ƶ�ʱ����
	CEntity * m_pEntity;        //���߻�Ƭָ��
	CCard * m_pTest;         //������
	int m_IsCard;				//��ʾ�Ƿ�Ƭ
};

#endif // !defined(AFX_TOOLUSEPROPERTYANDCARD_H__907614F4_777E_4C84_BDF9_4F304F186D21__INCLUDED_)
