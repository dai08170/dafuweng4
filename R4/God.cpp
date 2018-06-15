//Download by http://www.NewXing.com
// God.cpp: implementation of the CGod class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "God.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGod::CGod( CDC *pDC , CPoint point ,int nName )
{
	int immortal(0);
	m_MyRect.top = point.y; 
	m_MyRect.left = point.x;
	m_MyRect.bottom = m_MyRect.top + 50 , m_MyRect.right = m_MyRect.left + 50;
	if( nName == 0)
	{
		immortal = rand() % 8 + 1;
	}
	else
	{
		immortal = nName;
	}
	switch (immortal)//�ж���������
	{	
		case Wealth://����
			m_WalkNum=7;//������������
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Wealth1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Wealth2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );
			////////////////�����뿪����/////////////////////////////
			m_FlyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_FlyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_FlyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\flyW2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_FlyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\flyW1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_FlyShadowDC.SelectObject( m_FlyShadowBitmap );
			//��ͼ
			m_FlyDC.SelectObject( m_FlyBitmap );
			break;
		case PoorMan://����
			m_WalkNum=7;//������������
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\PoorMan1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\PoorMan2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );

			////////////////�����뿪����/////////////////////////////
			m_FlyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_FlyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_FlyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\PoorManfly2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_FlyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\PoorManfly1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_FlyShadowDC.SelectObject( m_FlyShadowBitmap );
			//��ͼ
			m_FlyDC.SelectObject( m_FlyBitmap );
			break;
		case Billiken://����
			m_WalkNum=7;//������������
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Billiken1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Billiken2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );
			////////////////�����뿪����/////////////////////////////
			m_FlyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_FlyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_FlyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Billikenfly2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_FlyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Billikenfly1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_FlyShadowDC.SelectObject( m_FlyShadowBitmap );
			//��ͼ
			m_FlyDC.SelectObject( m_FlyBitmap );
			break;
		case GriefMan://����
			m_WalkNum=7;//������������
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\GriefMan1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\GriefMan2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );
			////////////////�����뿪����/////////////////////////////
			m_FlyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_FlyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_FlyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\GriefManManfly2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_FlyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\GriefManfly1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_FlyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_FlyDC.SelectObject( m_MyBitmap );
			break;	
		case Angell://��ʹ
			m_WalkNum=4;//��������������뿪
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Angell1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\Angell2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case present://����
			m_WalkNum = 0;
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\present1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\present2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case dog://��
			m_WalkNum = 0;
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\dog1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\dog2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case box://����
			m_WalkNum=0;
			//��Ӱ��
			m_MyShadowDC.CreateCompatibleDC( pDC );
			//��ͼ
			m_MyDC.CreateCompatibleDC( pDC );
			//��Ӱ��
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\box1.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��ͼ
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
											"img\\box2.bmp", IMAGE_BITMAP,
											m_MyRect.right - m_MyRect.left,
											m_MyRect.bottom - m_MyRect.top,
											LR_LOADFROMFILE );
			//��Ӱ��
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );
			//��ͼ
			m_MyDC.SelectObject( m_MyBitmap );
			break;
	}
	m_immortal = immortal;
	m_WalkNum = 0;
}



CGod::~CGod()
{
	//���Bitmap
	m_MyBitmap.DeleteObject();
	m_MyShadowBitmap.DeleteObject();

	//���DC
	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();

	m_FlyShadowBitmap.DeleteObject();
	m_FlyShadowDC.DeleteDC();

	m_FlyBitmap.DeleteObject();
	m_FlyDC.DeleteDC();
}

void CGod::Draw( CDC * pDC )
{
	//��Ӱ��
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
								m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyShadowDC, 0, 0, SRCAND);
	//��ͼ
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
								m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								& m_MyDC, 0, 0, SRCPAINT);
}


//���ɸ���
void CGod::GetGod()
{
	int iRandomNum( rand()+1 );
	int iHundred(iRandomNum / 100);
	int iTen(iRandomNum / 1000);
	int iEntries(iRandomNum / 10000);

	switch (m_immortal)//�ж���������
	{	
		case Wealth://����
			m_WalkNum =5;
			theApp.m_pPer->AddCash(iHundred + iTen + iEntries);
			break;
		case PoorMan://����
			theApp.m_pPer->ReduceCard (iHundred + iTen + iEntries);
			m_WalkNum =5;
			break;
		case Billiken://����
			m_WalkNum =5;
			//�����һ�ſ�
			break;
		case GriefMan://����
			m_WalkNum =5;
			//�����һ�ſ�
			break;	
		case Angell://��ʹ
			theApp.m_pPer->BiuldHouse();
			m_WalkNum =5;
			break;
		case present://����
			m_WalkNum =5;
			//��һ������;
			break;
		case dog://��
			m_WalkNum =5;
			theApp.m_pPer->ChangeDays(0,3);
			break;
		case box://����
			m_WalkNum =0;
			theApp.m_pPer->AddPoint(500);
			AfxMessageBox( "��õ�500��!" );
			theApp.m_pPer->ChangeDays(0,1);
			break;
	}
}

void CGod::DrawOnPerInfo()
{
	//��Ӱ��
	theApp.m_TmpScreenDC.BitBlt( 35 ,
								170 ,
								60,
								60,
								& m_MyShadowDC, 0, 0, SRCAND);
	//��ͼ
	theApp.m_TmpScreenDC.BitBlt( 35 ,
								170 ,
								60,
								60,
								& m_MyDC, 0, 0, SRCPAINT);
}

//�����뿪
void CGod::LeaveGod()
{
	//��Ӱ��
	theApp.m_TmpScreenDC.BitBlt(m_MyRect.left, m_MyRect.top-30 ,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top - 30,
								& m_FlyShadowDC, 0, 0, SRCAND);
	//��ͼ
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left , m_MyRect.top -30,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top -30,
								& m_FlyDC, 0, 0, SRCPAINT);			
}

bool CGod::IsOnMe( CPoint point )
{
	return false;
}
void CGod::ReadFromStream( CDC * pDC, CArchive & ar )
{
	ar >> m_WalkNum;
	ar >> m_MyRect.top;
	ar >> m_MyRect.bottom;
	ar >> m_MyRect.left;
	ar >> m_MyRect.right;
}
int CGod::ToolName( CPoint point )
{return 0;}
void CGod::WriteToStream( CArchive & ar )
{
	ar << m_immortal;
	ar << m_WalkNum;
	ar << m_MyRect.top;
	ar << m_MyRect.bottom;
	ar << m_MyRect.left;
	ar << m_MyRect.right;
}

int CGod::ReduceWalkNum()
{
	m_WalkNum--;
	return m_WalkNum;
}

bool CGod::IsWalkNum()
{
	if(m_WalkNum > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
