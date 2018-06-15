//Download by http://www.NewXing.com
// SmallMap.cpp: implementation of the CSmallMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "SmallMap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSmallMap::CSmallMap()//����
{
	//����������
	m_MyRect.top = 280;
	m_MyRect.bottom = 480;
	m_MyRect.left = 440;
	m_MyRect.right = 640;
}

CSmallMap::~CSmallMap()//����
{
	//�ͷ��豸�����ĺ�λͼ
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
}

void CSmallMap::Draw( CDC * pDC )//��ʾС����ͼ�ķ���
{
	CBrush brush, * pOldBrush;//����һ��ˢ��
	CPen pen, * pOldPen;//����һֻ����

	//��С����ͼ
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left, m_MyRect.top,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC, 0, 0, SRCCOPY );
	//����ͼ�ϵ�����
	theApp.m_EntityRoadList.DrawOnSmallMap( pDC );

	//����ˢ�Ӻͻ���
	brush.CreateStockObject( NULL_BRUSH );//����һ����ˢ��
	pOldBrush = theApp.m_TmpScreenDC.SelectObject( & brush );
	pen.CreatePen( PS_SOLID,1,RGB( 255, 0, 0 ) );
	pOldPen = theApp.m_TmpScreenDC.SelectObject( & pen);

	//������
	theApp.m_TmpScreenDC.Rectangle( m_ptCoordinate.x - 17,
									m_ptCoordinate.y - 20,
									m_ptCoordinate.x + 17,
									m_ptCoordinate.y + 20 );

	brush.DeleteObject();
	pen.DeleteObject();

	theApp.m_TmpScreenDC.SelectObject( pOldPen );
	theApp.m_TmpScreenDC.SelectObject( pOldBrush );
}

void CSmallMap::Init_DC_BM( CDC * pDC )//��ʼ��
{
	//װ��ͼƬ
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\SmallMap.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap );

	//���þ��ε�λ��
	m_ptCoordinate.x = 
		(int)(theApp.m_pPer->m_ptCoordinate.x * 5.0 / 66.0) + 440;
	m_ptCoordinate.y = 
		(int)(theApp.m_pPer->m_ptCoordinate.y / 11.0) + 280;
}

bool CSmallMap::IsOnMe( CPoint point )//���Ƿ����ҵ���������
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

void CSmallMap::MoveRectangle( CPoint ptPos )//�ƶ�����
{
	m_ptCoordinate.x = ptPos.x;
	m_ptCoordinate.y = ptPos.y;

	//�жϱ߽�
	if( m_ptCoordinate.x < 457 )m_ptCoordinate.x = 457;
	if( m_ptCoordinate.y < 300 )m_ptCoordinate.y = 300;
	if( m_ptCoordinate.x > 627 )m_ptCoordinate.x = 627;
	if( m_ptCoordinate.y > 460 )m_ptCoordinate.y = 460;
}

void CSmallMap::ReadFromStream( CDC * pDC, CArchive & ar )//��ȡС����ͼ����Ϣ
{
	ar >> m_ptCoordinate.x;
	ar >> m_ptCoordinate.y;
}

int CSmallMap::ToolName( CPoint point )//С����ͼ���õĹ���
{
	if( IsOnMe( point) )
	{
		return CTool::MoveBigMap;
	}
	return CTool::NoTool;
}

void CSmallMap::WriteToStream( CArchive & ar )//����С��ͼ����Ϣ
{
	ar << m_ptCoordinate.x;
	ar << m_ptCoordinate.y;
}
