#include "stdafx.h"
#include "data.h"
data::data(void)
{
	 hstdin=GetStdHandle(STD_INPUT_HANDLE);
	 hout=GetStdHandle(STD_OUTPUT_HANDLE);
	 pos.X=30;
	 pos.Y=10;
	 memset(g_TankBullet,0,sizeof(TANK*)*160);
	 filePath="111.mapsb"; 
	 filePath1="222.mapsb"; 
	  
}
data::~data(void){}

int data::DoubleGame=0;//����˫����Ϸ��̬����
int data::TankQuantity=0;//�з�̹������
int data::EliteTankQuantity=0;//��Ӣ̹������
int data::EliteTankValue=0;	////��Ӣ̹������ֵ
int data::flag=0;		//ˢ��һ��
int data::LifeValue=0;//̹��1����ֵ
int data::LifeValue1=0;//̹��2����ֵ
int data::LifeNumber=0;//̹��1������
int data::LifeNumber1=0;//̹��2������
int data::num=0;//�Ʒ�
int data::n_TransferMatrix=0;//������


int data::MapFlag=0;

int data::ClickCount=0;

int data::SpaceStormflag=0;

int data::n_SkeletonKnight=0;//������ʿ

int data::TreatFlag=0;//�Ƿ�Է�

int data::MapFlag1=0;//�Ƿ�浵

int data::AReward=0;//�Ƿ����

bool data::writeData(char * filePath)
{
	int result = 0;
	FILE *pFile;
	//DoubleGame
	if (0 == fopen_s(&pFile,filePath , "wb")){
		result = fwrite(&m_g_nMapData,	sizeof(int) * 40 * 55, 1, pFile);
		result = fwrite(&n_SkeletonKnight,	sizeof(int) , 1, pFile);
		result = fwrite(&DoubleGame,	sizeof(int) , 1, pFile);
		result = fwrite(&EliteTankQuantity,	sizeof(int) , 1, pFile);
		result = fwrite(&EliteTankValue,	sizeof(int) , 1, pFile);
		result = fwrite(&m_g_nMapData1,	sizeof(int)*40*55 , 1, pFile);
		//result = fwrite(&MapFlag,	sizeof(int) , 1, pFile);
		/*
		result = fwrite(&m_playTanks,		sizeof(m_playTanks) * 40 * 40, 1, pFile);
		result = fwrite(&m_playMissiles,	sizeof(m_playMissiles) * 40 * 40, 1, pFile);
		result = fwrite(&m_NPCTanks,		sizeof(m_NPCTanks) * 40 * 40, 1, pFile);
		result = fwrite(&m_NPCMissiles,		sizeof(m_NPCMissiles) * 40 * 40, 1, pFile);
		*/
		fclose(pFile);
		pFile = NULL;
	}

	return true;
}

bool data::readData(char * filePath)
{
	
	int result = 0;
	FILE *pFile;

	if (0 == fopen_s(&pFile, filePath, "rb")){		
		result = fread(&m_g_nMapData,	sizeof(int)*40*55, 1, pFile);	
		result = fread(&n_SkeletonKnight,	sizeof(int) , 1, pFile);
		result = fread(&DoubleGame,	sizeof(int) , 1, pFile);
		result = fread(&EliteTankQuantity,	sizeof(int) , 1, pFile);
		result = fread(&EliteTankValue,	sizeof(int) , 1, pFile);
		result = fread(&m_g_nMapData1,	sizeof(int)*40*55 , 1, pFile);
		//result = fread(&MapFlag,	sizeof(int) , 1, pFile);
		/*����һ��vector�ܲ���ֱ�������洢
		result = fread(&m_playTanks,		sizeof(m_playTanks) * 40 * 40, 1, pFile); 
		result = fread(&m_playMissiles,		sizeof(m_playMissiles) * 40 * 40, 1, pFile);
		result = fread(&m_NPCTanks,			sizeof(m_NPCTanks) * 40 * 40, 1, pFile);
		result = fread(&m_NPCMissiles,		sizeof(m_NPCMissiles) * 40 * 40, 1, pFile);
		*/
		fclose(pFile);
		pFile = NULL;
	}
	return true;
}



wchar_t data::szStr[15][40]={ L"��  ӭ  ��  ��  ̹  ��  ��  ս��",
	L"|1.������Ϸ",L"|2.˫����Ϸ",L"|4.��ȡ�Զ�����Ϸ",L"��1��ʼ������Ϸ ��2��ʼ˫����Ϸ ��3������Ϸ���� ESC�˳��������",
	L"����Ա��Ŭ���Ӱ���...",L"һ���ʼ��Ϸ...",L"������������",
	L"��Ϸ����",L"W���ϣ�A����S���£�D���ң��ƶ�  J:�����ӵ�",
	L"�����ϣ������󣩡����£������ң��ƶ� .(С����):�����ӵ�",
	L"��ĸ����p/P��ͣ��Ϸ ��ĸ����o/O������Ϸ",
	L"�Ƿ��ٻ���Ԩ��ħ(Y)[Ĩ��������������]  (N)[��Ҫ��ƽս��]",
	L"|3.�༭��ͼ",L"|5.��ȡ�浵"
};
int data::g_PlayerTankStyle[4][3][3] = 
{
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	},
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},

		},
		{
			{1,2,3},
			{4,5,6},
			{7,8,9},
		},
		{
			{1,2,3},
			{4,5,6},
			{7,8,9},
			}
};
int data::m_g_nMapData[40][55]={0};

int data::m_g_nMapData1[40][55]={0};

int data::g_nMapData[40][55]={
	WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,WALL_A,WALL_A,WALL_A,WALL_A,WALL_A,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,	   0,     0,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,WALL_G,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,WALL_D,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,     0,     0,     0,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,     0,WALL_F,     0,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,WALL_F,WALL_F,WALL_F,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,     0,WALL_F,     0,WALL_F,     0,WALL_B,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, \
	WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,WALL_B,      0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};
int data::g_nMapDataTemp[40][40]={0};