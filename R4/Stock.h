//Download by http://www.NewXing.com
// Stock.h: interface for the CStock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCK_H__ECEBB9CE_1509_4046_90A3_E3F7C290E29E__INCLUDED_)
#define AFX_STOCK_H__ECEBB9CE_1509_4046_90A3_E3F7C290E29E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"



class CStock : public CEntity  
{
public:
	CStock( int nCompanyName );
	virtual ~CStock();
	enum PriceState{up =0,
					down};//�۸�״̬

	enum BusinessState {
						all = 1,
						out,
						into
						};//����״̬
	
	enum StockIDName{
					QiBuFan = 0,
					LiWeiXin
					};//��Ʊ��ҵ����

	int BuseinessType();//ȷ������״̬
	int GetStockPrice();//���ص���۸�
	int GetStockID();//���ع�Ʊ����(ID)
	int GetStochSum();//���ع�Ʊ��ͨ��
	void StockGraphShowInfo();//�Թ�Ʊ����ͼ
	void PriceDispose( int nNum );//ȷ���¼۸�
	void ShowInfo(int nI);//��ʾ��Ʊ��Ϣ��
	void AddStockAmount(int iAmount);//���ؼ�����
	void ReduceStockAmount(int iAmount);//����������

	virtual void Draw(CDC * pDC);
	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC,CArchive & ar );//CDC * pDC,
	virtual int ToolName( CPoint point );
	virtual void WriteToStream( CArchive & ar );//CDC * pDC,
private:
	int m_iStockID;	//��Ʊ����
	int m_iSum;		//��������
	int m_iPrice;	//����۸�
	int m_DisposePrice;//�����۸�
	int m_PriceState;//�۸�״̬
	int m_iPriceArray[32];//����һ���µļ۸�
	int m_BusinessState;//����״̬
};

#endif // !defined(AFX_STOCK_H__ECEBB9CE_1509_4046_90A3_E3F7C290E29E__INCLUDED_)
