//Download by http://www.NewXing.com
// SmallMap.h: interface for the CSmallMap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMALLMAP_H__594E1251_F9C4_4C40_A8B8_B83D076A0413__INCLUDED_)
#define AFX_SMALLMAP_H__594E1251_F9C4_4C40_A8B8_B83D076A0413__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

class CSmallMap : public CEntity  
{
public:
	CSmallMap();//���캯��
	virtual ~CSmallMap();//��������

	virtual void Draw( CDC * pDC );//��ʾС��ͼ
	virtual void Init_DC_BM( CDC * pDC );//��ʼ���豸������
	virtual bool IsOnMe( CPoint point );//�Ƿ�����ҵ���������
	void MoveRectangle( CPoint ptPos );//��Сͼ�ƶ�����
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );//��ȡС��ͼ��Ϣ
	virtual int ToolName( CPoint point );//��Сͼʱ����Ĺ���
	virtual void WriteToStream( CArchive & ar );//����С��ͼ��Ϣ

public:
	CPoint m_ptCoordinate;	//���ͼ��ʾ��������������С��ͼ�е�λ��*
};

#endif // !defined(AFX_SMALLMAP_H__594E1251_F9C4_4C40_A8B8_B83D076A0413__INCLUDED_)
