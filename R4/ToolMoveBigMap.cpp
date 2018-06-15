//Download by http://www.NewXing.com
// MoveBigMap.cpp: implementation of the CMoveBigMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolMoveBigMap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolMoveBigMap::CToolMoveBigMap()
{

}

CToolMoveBigMap::~CToolMoveBigMap()
{
}

void CToolMoveBigMap::OnLButtonDown( CDC * pDC, CPoint ptPos )//�������
{
	if( ptPos.x > 440 && ptPos.x <640 && ptPos.y >280 && ptPos.y < 480 )
	{
		theApp.m_SmallMap.MoveRectangle( ptPos );
		theApp.m_BigMap.MoveBigMap( pDC, theApp.m_BigMap.Point_SmallMapToBigMap(ptPos) );

		theApp.Draw( pDC );

		m_ToolState = stFirst;//�ı乤��״̬��ʾ�������
	}
}

void CToolMoveBigMap::OnLButtonUp( CDC * pDC, CPoint ptPos )//���̧��
{
	if( stFirst == m_ToolState )
	{
		theApp.m_ToolManager.SetActiveTool( pDC, CTool::Dice ,NULL);
		m_ToolState = stInit;
	}
}

void CToolMoveBigMap::OnMouseMove( CDC * pDC, CPoint ptPos )//�ƶ����
{
	if( stFirst == m_ToolState && ptPos.x > 440 && ptPos.x <640 && ptPos.y >280 && ptPos.y < 480 )
	{
		theApp.m_SmallMap.MoveRectangle( ptPos );
		theApp.m_BigMap.MoveBigMap( pDC, theApp.m_BigMap.Point_SmallMapToBigMap(ptPos) );

		theApp.Draw( pDC );
	}
}
