// Glebe.cpp: implementation of the CGlebe class.
// Download by http://www.NewXing.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Glebe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGlebe::CGlebe( CDC * pDC, int nLeft, int nTop, int nRight, int nBottom )
{
	//���ҵ���������ֵ
	m_MyRect.top = nTop;//�ϱ߽�
	m_MyRect.bottom =nBottom;//�±߽�
	m_MyRect.left = nLeft;//��߽�
	m_MyRect.right = nRight;//�ұ߽�

	//�����豸������
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyShadowDC.CreateCompatibleDC( pDC );
	m_SmallDC.CreateCompatibleDC( pDC );

	m_nGrade = 0;//���صȼ���ʼ��Ϊ0
	m_nMaxGrade = 5;//�������ȼ�Ϊ5
	m_nOwner = CPer::NoOne;//���ӵ�������Ϊû����
	m_nValue = 100;//���صļ�ֵ��ʼ��Ϊ100
}

CGlebe::~CGlebe()
{
	//�ͷ�λͼ���豸������
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
	m_MyShadowDC.DeleteDC();
	m_MyShadowBitmap.DeleteObject();
	m_SmallDC.DeleteDC();
	m_SmallBitmap.DeleteObject();
}

void CGlebe::Buy( int nName )//�������صķ���
{
	m_nOwner = nName;//����������

	//����������װ��ͼƬ 
	switch( m_nOwner )
	{
	case CPer::NoOne:
		//װ������ɫ��ͼƬ
		break;
	case CPer::KongFanYin:

		//װ����ʾ��С��ͼ�ϵ�ͼƬ
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowKongSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		//���ݷ��ӵȼ�װ��ͼ
		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		}
		break;
	case CPer::ZhangJun:
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowZhangSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		default:
			AfxMessageBox( "CGlebe::Draw��Ϣ����" );
		}
		break;
	}
}

void CGlebe::Degrade()//���ӽ����ķ���
{
	if( m_nGrade> 0)
	{
		m_nGrade--;

		switch( m_nOwner )
		{
		case CPer::NoOne:
			//װ������ɫ��ͼƬ*
			break;
		case CPer::KongFanYin:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			}
			break;
		case CPer::ZhangJun:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			default:
				AfxMessageBox( "CGlebe::Draw��Ϣ����" );
			}
			break;
		}
	}
}

void CGlebe::Draw( CDC * pDC )//��ʾ���ӵķ���
{
	//����ʱ�ڴ��ͼ
	theApp.m_TmpScreenDC.BitBlt(
		m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
		m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
		m_MyRect.right - m_MyRect.left,
		m_MyRect.bottom - m_MyRect.top,
		& m_MyShadowDC, 0, 0, SRCAND);

	theApp.m_TmpScreenDC.BitBlt(
		m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
		m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
		m_MyRect.right - m_MyRect.left,
		m_MyRect.bottom - m_MyRect.top,
		& m_MyDC, 0, 0, SRCPAINT);
}

void CGlebe::DrawOnSmallMap( CDC * pDC )//��С��ͼ����ʾ����
{
	theApp.m_TmpScreenDC.BitBlt( 
				(int)(m_MyRect.left * 5.0 / 66.0 + 440),
				(int)(m_MyRect.top / 11.0 + 280),
				5, 5, & m_SmallDC, 0, 0, SRCCOPY );
}

void CGlebe::DrawOnSmallMapView( CDC * pDC )//�鿴С��ͼʱ��ʾ����
{
	theApp.m_TmpScreenDC.BitBlt( 
				(int)(m_MyRect.left * 5.0 / 33.0 + 20),
				(int)(m_MyRect.top * 2.0 / 11.0 + 60),
				10, 10, & m_SmallDC, 0, 0, SRCCOPY );
}

int CGlebe::GetUpGradeValue()//������������ķ���
{
	if(  m_nGrade< m_nMaxGrade )
	{
		return (int)(m_nValue * 2.0);
	}
	return 0;
}

int CGlebe::GetValue()//���ӵļ�ֵ
{
	return m_nValue;
}

bool CGlebe::IsOnMe( CPoint point )//���Ƿ����ҵ���������
{
	CRect rect;
	rect.left =
		m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x;
	rect.right =
		m_MyRect.right - theApp.m_BigMap.m_ptBigMapCoordinate.x;
	rect.top =
		m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y;
	rect.bottom =
		m_MyRect.bottom - theApp.m_BigMap.m_ptBigMapCoordinate.y;

	if( CTool::PointInRect(point, rect) )//���ù������һ����̬����
	{
		return true;
	}
	return false;
}

int CGlebe::Owner()//����������
{
	return m_nOwner;
}

void CGlebe::ReadFromStream( CDC * pDC, CArchive & ar )//��ȡ������Ϣ
{
	ar >> m_nOwner;			//������
	ar >> m_nGrade;			//���ӵȼ�
	ar >> m_nMaxGrade;		//������ߵȼ�
	ar >> m_nValue;			//�ؼ�

	//��ԭ�豸������
	m_SmallDC.DeleteDC();
	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyShadowDC.CreateCompatibleDC( pDC );
	m_SmallDC.CreateCompatibleDC( pDC );

	switch( m_nOwner )
	{
	case CPer::NoOne:
		//װ������ɫ��ͼƬ*
		break;
	case CPer::KongFanYin:
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowKongSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeKong5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		}
		break;
	case CPer::ZhangJun:
		m_SmallBitmap.DeleteObject();
		m_SmallBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
							"img\\GlebeShadowZhangSmall.bmp",
							IMAGE_BITMAP, 10, 10,
							LR_LOADFROMFILE );
		m_SmallDC.SelectObject( m_SmallBitmap );

		switch( m_nGrade )
		{
		case 0:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadowZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 1:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang1.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 2:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang2.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 3:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang3.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 4:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang4.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		case 5:
			m_MyShadowBitmap.DeleteObject();
			m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeShadow5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyShadowDC.SelectObject( m_MyShadowBitmap );

			m_MyBitmap.DeleteObject();
			m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\GlebeZhang5.bmp",
								IMAGE_BITMAP,
								m_MyRect.right - m_MyRect.left,
								m_MyRect.bottom - m_MyRect.top,
								LR_LOADFROMFILE );
			m_MyDC.SelectObject( m_MyBitmap );
			break;
		default:
			AfxMessageBox( "CGlebe::Draw��Ϣ����" );
		}
		break;
	}
}

int CGlebe::ToolName( CPoint point )//�������������Ҫ�Ĺ���
{
	if( IsOnMe(point) )
	{
		return CTool::NoChange;
	}
	return CTool::NoTool;
}

void CGlebe::WriteToStream( CArchive & ar )//���淿����Ϣ
{
	ar << m_nOwner;			//������
	ar << m_nGrade;			//���ӵȼ�
	ar << m_nMaxGrade;		//������ߵȼ�
	ar << m_nValue;			//�ؼ�
}

void CGlebe::UpGrade()//��������
{
	if( m_nGrade< m_nMaxGrade)
	{
		m_nGrade++;
		m_nValue = (int)(m_nValue * 2.0);

		switch( m_nOwner )
		{
		case CPer::NoOne:
			//װ������ɫ��ͼƬ*
			break;
		case CPer::KongFanYin:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeKong5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			}
			break;
		case CPer::ZhangJun:
			switch( m_nGrade )
			{
			case 0:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadowZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 1:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang1.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 2:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang2.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 3:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang3.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 4:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang4.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			case 5:
				m_MyShadowBitmap.DeleteObject();
				m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeShadow5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyShadowDC.SelectObject( m_MyShadowBitmap );

				m_MyBitmap.DeleteObject();
				m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
									"img\\GlebeZhang5.bmp",
									IMAGE_BITMAP,
									m_MyRect.right - m_MyRect.left,
									m_MyRect.bottom - m_MyRect.top,
									LR_LOADFROMFILE );
				m_MyDC.SelectObject( m_MyBitmap );
				break;
			default:
				AfxMessageBox( "CGlebe::Draw��Ϣ����" );
			}
			break;
		}
	}
	else
	{
		AfxMessageBox( "��������������" );
	}
}

int CGlebe::GetLevel()//���ط��ӵȼ�
{
	return m_nGrade;
}
