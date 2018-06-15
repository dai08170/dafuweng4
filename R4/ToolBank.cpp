//Download by http://www.NewXing.com
// ToolBank.cpp: implementation of the CToolBank class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "ToolBank.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolBank::CToolBank(CDC *pDC)
{
	this->m_ifund =0;
	this->m_ToolState =stInit;
	this->m_MyRect.bottom =480;
	this->m_MyRect.left =0;
	this->m_MyRect.top =0;
	this->m_MyRect.right =640;

	//����ʼͼ
	m_MyDC.CreateCompatibleDC( pDC );
	//������ͼ
	m_MyBitmap.m_hObject = (HBITMAP)::LoadImage( NULL,
								"img\\bank.bmp",
								IMAGE_BITMAP,
								300,
								300,
								LR_LOADFROMFILE );
	m_MyDC.SelectObject( m_MyBitmap);

	m_ToolState =stInit;
}

CToolBank::~CToolBank()
{
	m_MyDC.DeleteDC();
	m_MyBitmap.DeleteObject();
}


void CToolBank::Draw( CDC * pDC )
{

	theApp.m_TmpScreenDC.BitBlt(100, 150,
								300,
								300,
								& m_MyDC, 0, 0, SRCCOPY);

	CString str;
	str.Format("%d",m_ifund);
	theApp.m_TmpScreenDC.TextOut (100+150 , 150+100 , str, strlen(str));
}

void CToolBank::OnLButtonDown(CDC *pDC, CPoint ptPos)
{
	int itmp(0);
	if (m_ifund < 99999999)
	{
		if ((ptPos.x >= 100+1 && ptPos.x <= 400-200)
			&& (ptPos.y >= 150 +1 && ptPos.y <= 450 - 225))
		{//����
			this->m_ToolState =stSecond;
		}
		else if ((ptPos.x >= 100 + 101 && ptPos.x <= 400-100)
			&& (ptPos.y >= 150 +1 && ptPos.y <= 450 - 225))
		{
			//ȡ��
			this->m_ToolState =stFirst;
		}
		else if ((ptPos.x >= 100 + 1 && ptPos.x <= 400-226)
			&& (ptPos.y >= 150 +150 && ptPos.y <= 450 - 113))
		{
			itmp = 7;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 76 && ptPos.x <= 400-150)
			&& (ptPos.y >= 150 +150 && ptPos.y <= 450 - 113))
		{
			itmp = 8;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 151 && ptPos.x <= 400-75)
			&& (ptPos.y >= 150 +150 && ptPos.y <= 450 - 113))
		{
			itmp = 9;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 1 && ptPos.x <= 400-226)
			&& (ptPos.y >= 150 +188 && ptPos.y <= 450 - 75))
		{
			itmp = 4;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 76 && ptPos.x <= 400-150)
			&& (ptPos.y >= 150 +188 && ptPos.y <= 450 - 75) )
		{
			itmp = 5;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 151 && ptPos.x <= 400-75)
			&& (ptPos.y >= 150 +188 && ptPos.y <= 450 - 75))
		{
			itmp = 6;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 1 && ptPos.x <= 400-226)
			&& (ptPos.y >= 150 +226 && ptPos.y <= 450 - 38))
		{
			itmp = 1;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 76 && ptPos.x <= 400-151)
			&& (ptPos.y >= 150 +226 && ptPos.y <= 450 - 38) )
		{
			itmp = 2;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 151 && ptPos.x <= 400-75)
			&& (ptPos.y >= 150 +226 && ptPos.y <= 450 - 38))
		{
			itmp = 3;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 1 && ptPos.x <= 400-226)
			&& (ptPos.y >= 150 +263 && ptPos.y <= 450 - 1))
		{//c
			this->m_ifund = 0;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 76 && ptPos.x <= 400-150)
			&& (ptPos.y >= 150 +263 && ptPos.y <= 450 - 1 ))
		{
			itmp = 0;
			this->m_ifund= m_ifund *10 + itmp;
		}
		else if ((ptPos.x >= 100 + 151 && ptPos.x <= 400-75)
			&& (ptPos.y >= 150 +263 && ptPos.y <= 450 - 1) )
		{
			this->m_ifund = m_ifund / 10;
		}
		else if ((ptPos.x >= 100 + 226 && ptPos.x <= 400-1)
			&& (ptPos.y >= 150 +150 && ptPos.y <= 450 - 75 ))
		{
			//MAX����
			if (m_ToolState == stFirst)//ȡǮ
			{
				this->m_ifund = theApp.m_pPer->GetFund();
			}
			else if (m_ToolState ==stSecond)//��Ǯ
			{
				this->m_ifund = theApp.m_pPer->GetCash();
			}
		}
		else if ((ptPos.x >= 100 + 226 && ptPos.x <= 400-1)
			&& (ptPos.y >= 150 +226 && ptPos.y <= 450 - 1 ))
		{
			//ȷ��
			if (m_ToolState == stFirst)//ȡǮ
			{
				if (m_ifund - 1 < theApp.m_pPer->GetFund())
				{
					theApp.m_pPer->ReduceFund(m_ifund);
					theApp.m_pPer->AddCash(m_ifund);
				}
				else
				{
					AfxMessageBox( "�����������ֽ��!" );
				}
			}
			else if(m_ToolState ==stSecond)//��Ǯ
			{
				if (m_ifund <= theApp.m_pPer->GetCash())
				{
					theApp.m_pPer->ReduceCash(m_ifund);
					theApp.m_pPer->AddFund(m_ifund);
				}
				else
				{
					AfxMessageBox( "���������Ĵ���!" );
				}
			}
			AfxMessageBox( "�����ɹ�!" );
			m_ToolState =stInit;
			m_ifund=0;
		}
		theApp.Draw(pDC);
	}
	else
	{
		AfxMessageBox( "�ֽ������!" );
		theApp.m_ToolManager.SetActiveTool(pDC,CTool::Dice,NULL);
	}
}

bool CToolBank::IsOnMe( CPoint point )
{
	if( CTool::PointInRect(point,m_MyRect) )
	{
		return true;
	}
	return false;
}

int CToolBank::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		if( (point.x >= 300  && point.x <= 390)
		&& (point.y >= 150 && point.y <= 220))
		{
			return CTool::Dice;
		}
		return CTool::NoChange;
	}
	return CTool::NoTool;
}
//theApp.m_ToolManager.SetActiveTool(pDC,CTool::Dice,NULL);