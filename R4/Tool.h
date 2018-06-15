//Download by http://www.NewXing.com
// Tool.h: interface for the CTool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOL_H__50E92B15_31D3_483F_A2EF_9BF95362C723__INCLUDED_)
#define AFX_TOOL_H__50E92B15_31D3_483F_A2EF_9BF95362C723__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTool  
{
public:
	enum ToolState	//״̬
	{
		stInit = 0,	//��
		stFirst,	//����һ��
		stSecond,	//��������
		stThird,
		stFour
	};
	enum ToolType	//����
	{
		NoTool = 0,		//�޹���
		NoChange,		//���ı�
		Card,			//��ʾ��Ƭ
		Dice,			//��ɫ��
		Load,			//��ȡ
		MoveBigMap,		//�ƶ����ͼ����
		PerGlebeInfo,	//��ʾ����ķ�����Ϣ
		PerInfo,		//��ʾ������Ϣ
		PerMove,		//�ƶ���
		PerSell,		//��ʾ����������Ϣ
		PerStockInfo,	//��ʾ�����Ʊ��Ϣ
		Property,		//��ʾ����
		Save,			//����
		Sell,			//��ʾ������Ŀ
		ShowSmallMap,	//��ʾС��ͼ*
		Stock,			//��ʾ��Ʊ
		UsePropertyAndCard,//ʹ�õ��߿�Ƭ
		Bank,			//����ȡ���
		BankLend		//���д���
	};


	CTool();
	virtual ~CTool();

	virtual void Draw( CDC * pDC ) = 0;
	virtual bool IsOnMe( CPoint point ) = 0;
	virtual void OnLButtonDblClk( CDC * pDC, CPoint point ) = 0;
	virtual void OnLButtonDown( CDC * pDC, CPoint ptPos ) = 0;
	virtual void OnLButtonUp( CDC * pDC, CPoint ptPos ) = 0;
	virtual void OnMouseMove( CDC * pDC, CPoint ptPos ) = 0;
	virtual void OnTimer( CDC * pDC){}
	virtual int ToolName( CPoint point ) = 0;
	virtual void ChangeIsCard(){};

	static bool PointInRect( CPoint point, CRect rect );	//�жϵ��Ƿ���������*

protected:
	CBitmap m_MyBitmap;
	CDC m_MyDC;
	CBitmap m_MyShadowBitmap;
	CDC m_MyShadowDC;
	CRect m_MyRect;				//��������*
	ToolState m_ToolState;	//״̬
};

#endif // !defined(AFX_TOOL_H__50E92B15_31D3_483F_A2EF_9BF95362C723__INCLUDED_)
