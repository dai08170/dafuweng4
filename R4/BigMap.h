//Download by http://www.NewXing.com
// BigMap.h: interface for the CBigMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BIGMAP_H__0AC78C93_9A49_422D_8FC6_592B418F0DC4__INCLUDED_)
#define AFX_BIGMAP_H__0AC78C93_9A49_422D_8FC6_592B418F0DC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

//���ͼ*
class CBigMap : public CEntity  
{
public:
	CBigMap();
	virtual ~CBigMap();

	virtual void Draw( CDC * pDC );
	virtual void Init_DC_BM( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	void MoveBigMap( CDC * pDC, CPoint ptPos );		//�ƶ����ͼ*
	CPoint Point_SmallMapToBigMap( CPoint ptPos );	//С��ͼ�����ͼ��ӳ��*
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );

public:
	CPoint m_ptBigMapCoordinate;	//��ʾ�����ڴ��ͼ������*
private:
	CPoint m_ptBigMapSize;			//���ͼ�Ĵ�С*
};

#endif // !defined(AFX_BIGMAP_H__0AC78C93_9A49_422D_8FC6_592B418F0DC4__INCLUDED_)
