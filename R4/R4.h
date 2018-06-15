//Download by http://www.NewXing.com
// R4.h : main header file for the R4 application
//

#if !defined(AFX_R4_H__4080D773_53FA_4CA6_87FC_AEF67EF168AF__INCLUDED_)
#define AFX_R4_H__4080D773_53FA_4CA6_87FC_AEF67EF168AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "EntityList.h"
#include "ToolManager.h"
#include "SmallMap.h"
#include "Bankroll.h"
#include "ButtonToolbar.h"
#include "Stock.h"

/////////////////////////////////////////////////////////////////////////////
// CR4App:
// See R4.cpp for the implementation of this class
//

class CR4App : public CWinApp
{
public:
	CR4App();

	void Draw( CDC * pDC );
	void InitAll_DC_BM( CDC * pDC );
	int ToolName( CPoint point );

public:
	CBankroll m_Bankroll;			//�ʽ���*
	CBigMap m_BigMap;				//���ͼ*
	CButtonToolbar m_ButtonToolbar;	//������*
	CEntityList m_EntityRoadList;	//·�ڵ�����*
	CPer * m_pPer;					//��ǰ��Ϸ��*
	CPer * m_pAllPer[2];			//������Ϸ��*
	CDate m_Date;					//����*
	CSmallMap m_SmallMap;			//С��ͼ*
	CStock * m_Stock[2];					//��Ʊ*
	CBitmap m_TmpScreenBitmap;		//��ʱ����*
	CDC m_TmpScreenDC;
	CToolManager m_ToolManager;		//���߹�����*

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CR4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CR4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_R4_H__4080D773_53FA_4CA6_87FC_AEF67EF168AF__INCLUDED_)
