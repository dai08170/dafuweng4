//Download by http://www.NewXing.com
// Stock.cpp: implementation of the CStock class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "Stock.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStock::CStock( int nCompanyName )
{
	m_BusinessState =all;
	m_DisposePrice = 0;	
	m_iPrice =100;
	m_iPriceArray[0]=0;
	m_iStockID = nCompanyName;
	m_iSum = 10000;
	m_PriceState =up;
}

CStock::~CStock()
{
	
}

void CStock::PriceDispose( int nNum )//����۸�
{
	m_DisposePrice = rand() % 33;//�۸�������Χ
 	m_PriceState = rand()%2;
	//ȷ���¼۸�
	if (theApp.m_Date.GetDayOfWeek () == 7)
	{
		m_DisposePrice=0;
	}
	
	//if ()
	switch (m_PriceState)
	{
	case up://�Ǽ�
		if ( (m_iPrice + m_DisposePrice) >180 )
		{
			m_DisposePrice =0;
		}
 		m_iPrice += m_DisposePrice;	
		break;
 	case down://����
		if ( (m_iPrice - m_DisposePrice) < 60 )
		{
			m_DisposePrice =0;
		}
 		m_iPrice -= m_DisposePrice;
 		break;
	}
	m_iPriceArray[nNum] =m_iPrice;
}

bool CStock::IsOnMe( CPoint point )
{
	return false;
}

int CStock::ToolName( CPoint point )
{
	if( IsOnMe( point) )
	{
		return CTool::NoChange;
	}
	return 0;
}

//ȷ�½���״̬
int CStock::BuseinessType()
{
	//���ݼ۸�������Χͣ�����
 	if ( ( m_iPrice - m_iPriceArray[theApp.m_Date.GetDay() - 1] ) >= 10 )
 	{
		//����ֻ�����
 		m_BusinessState =out;
 	}
	else if ( (  m_iPrice - m_iPriceArray[theApp.m_Date.GetDay() - 1] ) <= -10)
	{
		m_BusinessState =into;
	}
	else
	{
		//������all
		m_BusinessState =all;
	}
	return m_BusinessState;
}

void CStock::ShowInfo(int nI)
{
	theApp.m_TmpScreenDC.SetTextColor(RGB(255,255,255));
	int itmpDispose (0);
	//����
	CString str;
	switch (m_iStockID)
	{
	case 0:
		//����
		theApp.m_TmpScreenDC.TextOut (30, 77 + nI * 33 ,"����ʵҵ",strlen("����ʵҵ"));
		break;	
	case 1:
		//����
		theApp.m_TmpScreenDC.TextOut (30,77 + nI * 33,"����ʵҵ",strlen("����ʵҵ"));
		break;
	}
	//�۸�
	str.Format("%d",m_iPrice);
	theApp.m_TmpScreenDC.TextOut ( 155,77 + nI * 33,str,strlen(str) );
	theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));

	//�ǵ�
	switch (m_PriceState)
	{
	case up:
		theApp.m_TmpScreenDC.SetTextColor(RGB(225,0,0));
		str.Format("%d",m_DisposePrice);
		theApp.m_TmpScreenDC.TextOut ( 255,77 + nI * 33,str,strlen(str) );
		theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));
		break;
	case down:	
		theApp.m_TmpScreenDC.SetTextColor(RGB(0,255,0));
		str.Format("%d",m_DisposePrice);
		theApp.m_TmpScreenDC.TextOut ( 255,77 + nI * 33,str,strlen(str) );
		theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));
		break;
	}
	
	theApp.m_TmpScreenDC.SetTextColor(RGB(255,255,255));
	//��������
	str.Format("%d",m_iSum);
	theApp.m_TmpScreenDC.TextOut( 340,77 + nI * 33,str,strlen(str) );

	//����PER����ʾ��Ʊ������
	str.Format("%d",theApp.m_pPer->GetStockAmount(m_iStockID + 1));
	theApp.m_TmpScreenDC.TextOut (440,77 + nI * 33,str,strlen(str));

	//����PER����ʾ��Ʊ�۸�
	if (theApp.m_pPer->GetStockAmount(m_iStockID + 1) > 0)
	{
		str.Format("%d",theApp.m_pPer->GetStockPrice(m_iStockID + 1));
		theApp.m_TmpScreenDC.TextOut (540,77 + nI * 33,str,strlen(str));
	}
	else
	{
		str.Format("%d",0);
		theApp.m_TmpScreenDC.TextOut (540,77 + nI * 33,str,strlen(str));
	}
	theApp.m_TmpScreenDC.SetTextColor(RGB(0,0,0));
}

void CStock::StockGraphShowInfo()
{
	CPen pen,* oldpen;
	int j(theApp.m_Date.GetDay());

	pen.CreatePen(PS_SOLID,2,RGB(255,255,255));
	oldpen=theApp.m_TmpScreenDC.SelectObject (&pen);
	theApp.m_TmpScreenDC.SelectObject (&pen);

	for (int i(theApp.m_Date.GetDay()); m_iPriceArray[i] < 0 && i < 32; i++){
		if (i > 32)
		{
			for (i = 1; m_iPriceArray[i] < 1 && i < 31; i++){}//400-m_iPriceArray[i]
		}
		theApp.m_TmpScreenDC.MoveTo((int)((j)* 10.0), 400 - m_iPriceArray[i]);
	}
	for (int i = theApp.m_Date.GetDay() + 1;i < 32;i++)
	{
		if (m_iPriceArray[i] > 0)
		{
			j++;
			theApp.m_TmpScreenDC.LineTo( (int)(j * 10.0), 400-m_iPriceArray[i] );	
		}
	}

	for (int i = 1 ;i < theApp.m_Date.GetDay() + 1;i++)
	{
		if (m_iPriceArray[i] > 0)
		{
			j++;
			theApp.m_TmpScreenDC.LineTo( (int)(j * 10.0), 400-m_iPriceArray[i] );	
		}
	}

	theApp.m_TmpScreenDC.SelectObject (oldpen);
	pen.DeleteObject ();
}


void CStock::AddStockAmount(int iAmount)
{
	m_iSum +=iAmount;	
}

void CStock::ReduceStockAmount(int iAmount)
{
	m_iSum -=iAmount;
}

int CStock::GetStockPrice()
{
	return m_iPrice;
}

int CStock::GetStockID()
{
	return m_iStockID;
}

int CStock::GetStochSum()
{
	return m_iSum;
}


void CStock::WriteToStream( CArchive & ar )
{
	ar<<m_iStockID;
	ar<<m_iSum;
	ar<<m_iPrice;
	ar<<m_DisposePrice;
	ar<<m_PriceState;
	ar<<m_BusinessState;

	for (int i = 1; i < 32 ;i++)
	{
		ar<<m_iPriceArray[i];
	}
}

void CStock::ReadFromStream(CDC * pDC, CArchive & ar )
{
	ar>>m_iStockID;
	ar>>m_iSum;
	ar>>m_iPrice;
	ar>>m_DisposePrice;
	ar>>m_PriceState;
	ar<<m_BusinessState;

	for (int i = 1; i < 32 ;i++)
	{
		ar<<m_iPriceArray[i];
	}
}
void CStock::Draw(CDC *pDC)
{
	
}
