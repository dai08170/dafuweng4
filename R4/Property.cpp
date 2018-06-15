//Download by http://www.NewXing.com
// Property.cpp: implementation of the CProperty class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Property.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
/*
	Torpedo = 1,      //����
	RoadBlock,    //·��       
	TimeBomb,	  //��ʱը��
    Missile,      //�ɵ�
	Nucleon,      //���ӷɵ�
    Car,          //����  
	Engine,       //����  
	RemoteDice,  //ң��ɫ��
	Mobile,       //���̳�  
	Robot,        //��������
	TimeMachine,  //ʱ���
    TransMachine, //���ͻ�
	RobotBaby     //��������
*/
CProperty::CProperty( CDC * pDC, int nID , CPoint point)
{
	//��ʼ����������������
	m_MyRect.top = point.y;
	m_MyRect.left = point.x;
	m_MyRect.right = point.x + 60;
	m_MyRect.bottom = point.y + 60;
	m_nDays = 0;
	Init_DC_BM( pDC );

	if( nID < 1 )
	{
		m_ID = rand()%3 + 1; 
	}
	else
	{
		m_ID = nID;
	}

	switch(m_ID)
	{
	case 1:
		m_BmpCount = "\\3";
	break;
	case 2:
		m_BmpCount = "\\5";
	break;	
	case 3:
		m_BmpCount = "\\2";
	break;	
	case 4:
		m_BmpCount = "\\3";
	break;	
	case 5:
		m_BmpCount = "\\4";
	break;	
	case 6:
		m_BmpCount = "\\5";
	break;	
	case 7:
		m_BmpCount = "\\6";
	break;	
	case 8:
		m_BmpCount = "\\7";
	break;	
	case 9:
		m_BmpCount = "\\8";
	break;	
	case 10:
		m_BmpCount = "\\9";
	break;	
	case 11:
		m_BmpCount = "\\10";
	break;	
	case 12:
		m_BmpCount = "\\11";
	break;	
	case 13:
		m_BmpCount = "\\13";
	break;	
	default:
		return;
	}
	
	CString head = "img\\";
	CString root = "pro.bmp";  
	m_Bmp = head + m_BmpCount + root;

	root = "proshd.bmp";
	m_BmpShadow = head + m_BmpCount + root;

	m_MyBitmap.DeleteObject();
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,  m_Bmp, IMAGE_BITMAP, 60,60, LR_LOADFROMFILE );
	m_MyDC.SelectObject(m_MyBitmap);

	m_MyShadowBitmap.DeleteObject();
	m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_BmpShadow, IMAGE_BITMAP, 60,60, LR_LOADFROMFILE );
	m_MyShadowDC.SelectObject(m_MyShadowBitmap);
}

CProperty::~CProperty()
{
	m_MyShadowDC.DeleteDC();
	m_MyDC.DeleteDC();
	m_MyShadowBitmap.DeleteObject();
	m_MyBitmap.DeleteObject();
}

//ը��סԺ����������1 ��Ҷ���ָ�룩  2סԺ����
//����  ��ʱը��   �ɵ�   ���ӷɵ�ʹ��
void CProperty::MakePeopleInHispital(CPer *, int)
{
}

//�ı�ɫ�Ӻ���������1 ɫ�Ӹ���  2ɫ�ӵ���
//����  ����  ң��ɫ��ʹ��
void CProperty::ChangeNumberOrCountOfDice()
{
}

//�ı䷿�ӵȼ���𷿡����� ���Ӷ���ָ�룩
//���̳�  ��������ʹ��
void CProperty::ChangeOrDestoryHouse()
{
}

//Load��һ�غϷ���  ʱ���ʹ��
void  CProperty::ReturnLast()
{
	//CSystem::ϵͳ���ĳһ��̬����
}
		

//�ƶ�����ָ���ص�  ���ͻ�ʹ��
void  CProperty::MoveObject( )
{
}

//��ֹ����ƶ�  ·��ʹ��
void  CProperty::StopPeople()
{
}

//������е��� ��������ʹ��
void CProperty::ClearRoad()
{
}

void CProperty::Draw( CDC * pDC )
{
	//��Ӱ��
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x, 
		                         m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
								 m_MyRect.right - m_MyRect.left,
								 m_MyRect.bottom - m_MyRect.top,
								 & m_MyShadowDC,
								 0,
								 0,
								 SRCAND );
	//����ɫ
	theApp.m_TmpScreenDC.BitBlt( m_MyRect.left - theApp.m_BigMap.m_ptBigMapCoordinate.x,
		                         m_MyRect.top - theApp.m_BigMap.m_ptBigMapCoordinate.y,
								 m_MyRect.right - m_MyRect.left,
								 m_MyRect.bottom - m_MyRect.top,
								 & m_MyDC,
								 0,
								 0,
								 SRCPAINT );
}

void CProperty::Draw( bool isBig, CPoint point ) 
{


	m_MyBitmap.DeleteObject();
	m_MyShadowBitmap.DeleteObject();
	
	if(isBig)
	{		
		m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_BmpShadow, IMAGE_BITMAP, 45,45, LR_LOADFROMFILE );
		m_MyShadowDC.SelectObject(m_MyShadowBitmap);
		m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_Bmp, IMAGE_BITMAP, 45,45, LR_LOADFROMFILE );
		m_MyDC.SelectObject(m_MyBitmap);
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 45, 45, &m_MyShadowDC, 0, 0, SRCAND );
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 45, 45, &m_MyDC, 0, 0, SRCPAINT );
	}
	else
	{
		m_MyShadowBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_BmpShadow, IMAGE_BITMAP, 30,30, LR_LOADFROMFILE );
		m_MyShadowDC.SelectObject(m_MyShadowBitmap);
		m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL, m_Bmp, IMAGE_BITMAP, 30,30, LR_LOADFROMFILE );
		m_MyDC.SelectObject(m_MyBitmap);
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 30, 30, &m_MyShadowDC, 0, 0, SRCAND );
		theApp.m_TmpScreenDC.BitBlt(  point.x, point.y, 30, 30, &m_MyDC, 0, 0, SRCPAINT );
	}	
}

int CProperty::GetID()
{
	return m_ID;
}

void CProperty::Init_DC_BM( CDC * pDC )
{
	m_MyDC.CreateCompatibleDC( pDC );
	m_MyShadowDC.CreateCompatibleDC( pDC);

}

bool CProperty::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point, m_MyRect) )
	{
		return true;
	}
	return false;
}

int CProperty::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return 0;
}


void CProperty::ChangeMyRect(CPoint point)
{
	m_MyRect.top = point.y +  theApp.m_BigMap.m_ptBigMapCoordinate.y - 30;
	m_MyRect.left = point.x +  theApp.m_BigMap.m_ptBigMapCoordinate.x - 30;
	m_MyRect.right = m_MyRect.left + 60;
	m_MyRect.bottom = m_MyRect.top + 60;
}

int CProperty::IsCard()
{
	//���ص��߱�־
	return 2;
}

void CProperty::WriteToStream( CArchive & ar )
{
	ar << m_ID; 
	ar << m_Money;
}

void CProperty::ReadFromStream( CDC * pDC, CArchive & ar)
{
	ar >> m_Money;
}

void CProperty::PropertyIsBeUsed( int nName )
{
	int nI(0);
	switch(m_ID)
	{
	case 1://����
		m_nDays = 3;
		for( nI = 0 ; nI < 2 ; nI++ )
		{
			if( theApp.m_pAllPer[nI]->GetName() == nName )
			{
				theApp.m_pAllPer[nI]->ChangeDays( ( m_ID+ 3),m_nDays );
			}
		}
		break;
	case 2://·��
		for( nI = 0 ; nI < 2 ; nI++ )
		{
			if( theApp.m_pAllPer[nI]->GetName() == nName )
			{
				theApp.m_pAllPer[nI]->ChangeDays( (m_ID + 3),m_nDays );
			}
		}
		break;
	case 3://��ʱը��
		m_nDays = 5;
		for( nI = 0 ; nI < 2 ; nI++ )
		{
			if( theApp.m_pAllPer[nI]->GetName() == nName )
			{
				theApp.m_pAllPer[nI]->ChangeDays( (m_ID + 1),m_nDays );
				theApp.m_pAllPer[nI]->m_ptCoordinate.x = 200;
				theApp.m_pAllPer[nI]->m_ptCoordinate.y = 1200;
			}
		}
		break;
	}
}