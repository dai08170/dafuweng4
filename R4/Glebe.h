//Download by http://www.NewXing.com
// Glebe.h: interface for the CGlebe class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLEBE_H__98EB5134_8155_42DA_A1AD_3F9D45FE2193__INCLUDED_)
#define AFX_GLEBE_H__98EB5134_8155_42DA_A1AD_3F9D45FE2193__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Entity.h"

//������*
class CGlebe : public CEntity  //�̳�ʵ����
{
public://������
	CGlebe( CDC * pDC, int nTop, int nLeft, int nBottom, int nRight );//���캯��
	virtual ~CGlebe();//��������

	void Buy( int nName );//�������ط���
	void Degrade();//�������ӵķ���
	virtual void Draw( CDC * pDC );//��ʾ���صķ���
	void DrawOnSmallMap( CDC * pDC );//��С��ͼ����ʾ����
	void DrawOnSmallMapView( CDC * pDC );//�ڲ鿴С����ʱ��ʾ����
	int GetUpGradeValue();//����������������ķ���
	int GetValue();//���ص����
	int GetLevel();			//��÷��ӵȼ�
	virtual bool IsOnMe( CPoint point );//�ж��Ƿ���ڷ�����
	int Owner();//�������ص�������
	virtual void ReadFromStream( CDC * pDC, CArchive & ar );//��ȡ���ӵ���Ϣ
	virtual int ToolName( CPoint point );//���ص��ڷ���������Ĺ���
	virtual void WriteToStream( CArchive & ar );//���淿����Ϣ
	void UpGrade();//��������

private://˽�е�
	int m_nOwner;			//������
	int m_nGrade;			//���ӵȼ�
	int m_nMaxGrade;		//������ߵȼ�
	int m_nValue;			//�ؼ�
	CBitmap m_SmallBitmap;//����װ����ʾ��С��ͼ�ϵ�ͼƬ
	CDC m_SmallDC;//��ʾͼ���豸������
};

#endif // !defined(AFX_GLEBE_H__98EB5134_8155_42DA_A1AD_3F9D45FE2193__INCLUDED_)
