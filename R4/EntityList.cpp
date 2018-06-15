//Download by http://www.NewXing.com
// EntityList.cpp: implementation of the CEntityList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "R4.h"
#include "EntityList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEntityList::CEntityList()
{
	m_pENHead = NULL;
}

CEntityList::~CEntityList()
{
	FreeAll();
}

void CEntityList::AddGodOrProperty( CEntity * pEntity , CPoint point )
{
	CEntityNode * pEntityNode = m_pENHead;
	if( NULL != m_pENHead )
	{
		if(pEntityNode->AddGodOrProperty(pEntity , point)) return ;
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			pEntityNode->AddGodOrProperty(pEntity , point);
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
}

void CEntityList::AddEntityNode( CPoint ptCoordinate,
								int nWayName, CGod * pGod,
								CGlebe * pGlebe, CPer * pPer )
{
	//��ӽڵ�

	CEntityNode * pEntityNode = new CEntityNode( ptCoordinate,
										nWayName, pGod,
										pGlebe,	pPer);

	if( NULL == m_pENHead )
	{
		m_pENHead = pEntityNode;
		pEntityNode->m_pENPrevious = m_pENHead;
		pEntityNode->m_pENNext = m_pENHead;
	}
	else
	{
		pEntityNode->m_pENPrevious = m_pENHead->m_pENPrevious;
		pEntityNode->m_pENNext = m_pENHead;
		m_pENHead->m_pENPrevious->m_pENNext = pEntityNode;
		m_pENHead->m_pENPrevious = pEntityNode;
	}
}

void CEntityList::Draw( CDC * pDC )
{
	//��ʾ���нڵ�*

	CEntityNode * pEntityNode = m_pENHead;
	if( NULL != m_pENHead )
	{
		pEntityNode->Draw( pDC );
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			pEntityNode->Draw( pDC );
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
}

void CEntityList::DrawOnSmallMap( CDC * pDC )
{
	CEntityNode * pEntityNode = m_pENHead;
	if( NULL != m_pENHead )
	{
		pEntityNode->DrawOnSmallMap( pDC );
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			pEntityNode->DrawOnSmallMap( pDC );
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
}

void CEntityList::DrawOnSmallMapView( CDC * pDC )
{
	CEntityNode * pEntityNode = m_pENHead;
	if( NULL != m_pENHead )
	{
		pEntityNode->DrawOnSmallMapView( pDC );
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			pEntityNode->DrawOnSmallMapView( pDC );
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
}

void CEntityList::FreeAll()
{
	//�ͷ�����
	CEntityNode * pEntityNode;
	while( NULL != m_pENHead )
	{
		if( m_pENHead != m_pENHead->m_pENNext )
		{
			if( m_pENHead->m_pGlebe ==
								m_pENHead->m_pENNext->m_pGlebe )
			{//˫�ڵ����ص�ɾ��*
				m_pENHead->m_pENNext->m_pGlebe = NULL;
			}

			pEntityNode = m_pENHead->m_pENNext;
			m_pENHead->m_pENPrevious->m_pENNext =
											m_pENHead->m_pENNext;
			m_pENHead->m_pENNext->m_pENPrevious =
											m_pENHead->m_pENPrevious;
			delete m_pENHead;
			m_pENHead = pEntityNode;
		}
		else
		{
			delete m_pENHead;
			m_pENHead = NULL;
		}
	}
}

int CEntityList::GetCount()
{
	//���ؽڵ����

	int nCount(0);
	CEntityNode * pEntityNode = m_pENHead;

	if( NULL != m_pENHead )
	{
		nCount++;
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			nCount++;
			pEntityNode = pEntityNode->m_pENNext;
		}
	}

	return nCount;
}

bool CEntityList::IsOnGlebe( CPoint point )
{
	CEntityNode * pEntityNode = m_pENHead;
	if( NULL != m_pENHead )
	{
		if( pEntityNode->IsOnGlebe( point ) )return true;
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			if( pEntityNode->IsOnGlebe( point ) )return true;
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
	return false;
}

bool CEntityList::IsOnNode( CPoint point )
{
	CEntityNode * pEntityNode = m_pENHead;
	if( NULL != m_pENHead )
	{
		if( pEntityNode->IsOnMe( point ) )return true;
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			if( pEntityNode->IsOnMe( point ) )return true;
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
	return false;
}

bool CEntityList::IsOnPer( CPoint point )
{
	CEntityNode * pEntityNode = m_pENHead;
	if( NULL != m_pENHead )
	{
		if( pEntityNode->IsOnPer( point ) )return true;
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			if( pEntityNode->IsOnPer( point ) )return true;
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
	return false;
}

void CEntityList::ReadFromFile( CDC * pDC, CArchive & ar )
{
	CEntityNode * pEntityNode = m_pENHead;

	if( NULL != m_pENHead )
	{
		pEntityNode->ReadFromStream( pDC, ar );
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			pEntityNode->ReadFromStream( pDC, ar );
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
}

void CEntityList::SaveToFile( CArchive & ar )
{
	CEntityNode * pEntityNode = m_pENHead;

	if( NULL != m_pENHead )
	{
		pEntityNode->WriteToStream( ar );
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			pEntityNode->WriteToStream( ar );
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
}

void CEntityList::SetPerGlebe( CPer::Gelbe * m_Gelbe , int nName )
{
	CEntityNode * pEntityNode = m_pENHead;
	int nI(0);
	if( NULL != m_pENHead )
	{
		if(pEntityNode->m_pGlebe != NULL)
		{
			if( nName == pEntityNode->m_pGlebe->Owner()) 
			{
				m_Gelbe[nI].Sport = pEntityNode->m_WayName;
				m_Gelbe[nI].Develop = pEntityNode->m_pGlebe->GetLevel();
				m_Gelbe[nI].Value = pEntityNode->m_pGlebe->GetValue();
				nI++;
			}
		}
		pEntityNode = pEntityNode->m_pENNext;
		while( m_pENHead != pEntityNode )
		{
			if(pEntityNode->m_pGlebe != NULL)
			{
				if(pEntityNode->m_pGlebe->Owner() == nName) 
				{
					m_Gelbe[nI].Sport = pEntityNode->m_WayName;
					m_Gelbe[nI].Develop = pEntityNode->m_pGlebe->GetLevel();
					m_Gelbe[nI].Value = pEntityNode->m_pGlebe->GetValue();
					nI++;
				}
			}
			pEntityNode = pEntityNode->m_pENNext;
		}
	}
}