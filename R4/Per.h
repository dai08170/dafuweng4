//Download by http://www.NewXing.com
// Per.h: interface for the CPer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PER_H__F5BE94F0_EA14_4EC5_BFBA_D76E1D1E40C5__INCLUDED_)
#define AFX_PER_H__F5BE94F0_EA14_4EC5_BFBA_D76E1D1E40C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"
#include "Card.h"
#include "God.h"

class CEntityNode;
class CProperty;

class CPer : public CEntity  
{
public:
	enum Name
	{
		NoOne = 0,
		ZhangJun,
		KongFanYin
	};
	enum Way
	{
		Next = 0,
		Up,
		Hospital,
		Goal,
		Hotel
	};
	enum State
	{
		Stop = 0,
		Ready,
		Going,
		HitGoing,	//��ײ
		HitInvest,	//��ײ��Ľ��ס��¼�
		Invest		//Ͷ��
		
	};
	struct STOCK//��Ʊ�ṹ��
	{
		int StockName;//��Ʊ����
		int StockNum;//��������
		double StockMoney;//����۸�
	};
	//�������
	struct Property
	{
		int nTpye;
		CProperty *pItem[9];
	};

	//�������
	struct Gelbe
	{
		//�ص�
		int Sport;
		//��չ״��
		int Develop;
		//�۸�
		int Value;
	};

	void PerGlebeInfo( CRect & rect );
	void PerStockInfo( CRect &rect );
	void PerShowInfo( CRect &rect );
	void Move( CDC * pDC );
	void MoveOnHit( CDC * pDC );
	void MoveOnHitNode( CDC * pDC );
	void MoveOnNode( CDC * pDC );
	//���½�С��ͼ�ϻ���
	void DrawOnSmallMap( CDC * pDC );
	//������ֵ�С��ͼ����
	void DrawOnSmallMapView( CDC * pDC );
	//���ͼ�ϻ���
	virtual void Draw( CDC * pDC );
	virtual bool IsOnMe( CPoint point );
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );
	virtual int ToolName( CPoint point ){return 0;}
	virtual void WriteToStream( CArchive & ar );
	CPer( CDC *pDC, int nName , CPoint point );
	virtual ~CPer();

	//����
	void DestroyHouse();
	//�Ƿ���
	void BiuldHouse();
	//��������
	//�����ֽ�
	void AddCash(int nMoney);
	//�����ֽ�
	void ReduceCash(int nMoney);
	//���Ӵ��
	void AddFund(int nMoney);
	//���ٴ��
	void ReduceFund(int nMoney);
	//�����ܲ�ֵ
	void AddValue(int nMoney);
	//�����ܲ�ֵ
	void ReduceValue(int nMoney);
	//���Ӵ���
	void AddLoan(int nMoney);
	//���ٴ���
	void ReduceLoan(int nMoney);
	//���ӵ���
	void AddPoint(int nPoint);
	//���ٵ���
	void ReducePoint(int nPoint);
	//�ı䲽��
	void SplashDice( CDC * pDC, int nWalkNum );
	//��·
	//����������Ŀ
	void AddLandNum( CEntityNode * pNode );
	//����������Ŀ
	void ReduceLandNum();
	//���ӷ�����Ŀ
	void AddHouseNum();
	//���ٷ�����Ŀ
	void ReduceHouseNum();
	//����Ƭ
	void AddCard( CCard &card );
	//ʹ�ÿ�Ƭ
	CCard *  ReduceCard(int nI);
	//�������
	void AddItem(CProperty &item);
	//ʹ�õ���
	CProperty* ReduceItem( int nType );
	//��������
	void SetGod( CEntity & god );
	//�����������
	int GetName();
	//��ô��
	int GetFund();
	//��ȡ�ֽ�
	int GetCash();
	//��ø��˹�Ʊ������
	int GetStockAmount(int nid);
	//��ù�Ʊ�ɽ���
	int GetStockPrice(int nid);
	//�����뿪
	void LeaveGod();
	//�����Ʊ
	void AddStock(int nMoney,int nName,int nNum);
	//������Ʊ
	void ReduceStock(int nName,int nNum);
	//�ı�סԺ,����,�ù�����
	void ChangeDays(int nID ,int nDay);
	//�ı����﷽��
	void ChangeWay();
	//סԺ
	void InHospital();
	//��Ժ
	void OutHospital();
	//����
	void InGaol();
	//����
	void OutGaol();
	//ס�ù�
	void InHotel();
	//���ù�
	void OutHotel();
	//�õ����
	void GetEntityNode(CEntityNode & EntityNode);
	//���Ϸ�ҳ
	void PageDown();
	//���·�ҳ
	void PageUp();
	//��ʾ�ұ߿���Ϣ
	void ShowOtherInfo();
	void ShowStockInfo();
	void ShowGelebInfo();
	void ShowFundInfo();

	void ShowPropertyInfo( CPoint point , bool nType );
	void ShowCardInfo( CPoint point , bool nType );

	int GetWay();
	int GetLoan();
	void ChangeOrientation();

	int m_nState;
	CPoint m_ptCoordinate;	//��������
private:
	int m_iType;
	int m_Build;//��ʩ��Ŀ
	//��Ƭ����
	CCard *m_Card[15];//��Ƭ����
	//�ֽ�
	int m_Cash;
	int m_CompanyNum;//ӵ�й�˾��
	//סԺ,��������
	int m_Days;
	//���
	int m_Fund;
	Gelbe m_Gelbe[100];//�������
	//�������������
	CEntity * m_God;//��������
	//��������
	int m_HouseNum;//������Ŀ
	Property m_Item[15];//��������,����
	//����ռ����
	int m_LandNum;//������Ŀ
	//����
	int m_Loan;
	int m_Name;	//��������
	int m_nOrientation;	//��ͼ�ķ���
	int m_nStep;	//��ͼ�Ĳ���
	//��ҳ��
	int m_PageCount;
	//��ǰҳ��
	int m_PageNum;
	//���ָ��
	CEntityNode * m_pEntityNode;//�������ڵ�
	CBitmap m_Perbmp[4];
	CDC m_PerDC[4];
	CBitmap m_Pershadowbmp[4];
	CDC m_PershadowDC[4];
	//����
	int m_Point;
	int m_SafetyDate;//Ͷ������
	CBitmap m_SmallBitmap;
	CDC m_SmallDC;
	//��Ʊ�������
	STOCK m_Stock[12];//��Ʊ����
	//�ܲ�ֵ
	int m_Value;
	//����
	int m_WalkNum;
	//���﷽��
	int m_Way;
};

#endif // !defined(AFX_PER_H__F5BE94F0_EA14_4EC5_BFBA_D76E1D1E40C5__INCLUDED_)
