#pragma once
#include <vector>
using std::vector;

class data
{
public:
	typedef struct _TANK 
	{
		unsigned int TankY;
		unsigned int TankX;
		unsigned int Orientation;	//��ǰ����
		unsigned int ChangeOrientation;//�ı䷽��
		unsigned int Bullet;           //�ӵ�
		unsigned int Shape   	 ; // ��ʾ����(256)
		unsigned int Bullft   	 ; // ����ֵ(64)
		unsigned int Direction	 ; // �˶�����(4)
		unsigned int Collide  	 ; // ��ײ���(4)
		unsigned int IsBullft	 ; // �Ƿ�Ϊ�ڵ�(2)
		unsigned int IsTank	     ; // �Ƿ�Ϊ̹��(2)
		unsigned int ID       	 ; // ����ID(256)
		unsigned int Type     	 ; // ��������(256)
		unsigned int isvalid     ; // �Ƿ���Ч
		unsigned int Bulletflag	 ;
	}TANK,*pTANK;
public:
	data(void);
	~data(void);

public:
	 TANK Tank;
	 TANK FTank;
	 vector<TANK>tanks;
	 TANK * g_TankBullet[160];
	static wchar_t szStr[15][40];
	static int g_PlayerTankStyle[4][3][3];
	static int g_nMapData[40][55];//g_nMapData[y][x] x��40����Ϊ�Ʒ�ϵͳ
	static int g_nMapDataTemp[40][40];

	static int m_g_nMapData[40][55];//�����ͼ
	static int m_g_nMapData1[40][55];//�����ͼ1
	char *filePath;
	char *filePath1;
	 DWORD dwRet;
	 HANDLE hout ;
	 COORD pos;
	 HANDLE hstdin;
 
public:								
	static int DoubleGame;			 //����˫����Ϸ��̬����
	static int TankQuantity;		 //�з�̹������
	static int EliteTankQuantity;	//��Ӣ̹������
	static int EliteTankValue;	//��Ӣ̹������ֵ
	static int flag;		//ˢ��һ��
	static int LifeValue;		 //̹��1����ֵ
	static int LifeValue1;				 //̹��2����ֵ
	static int LifeNumber;			 //̹��1������
	static int LifeNumber1;			 //̹��2������
	static int num;				//�Ʒ�
	static int n_TransferMatrix;//������
	static int MapFlag;//��ͼ���
	static int ClickCount;//��������
	static int SpaceStormflag;//�ռ�籩�������
	static int n_SkeletonKnight;//������ʿ
	static int TreatFlag;//�Է���־
	static int MapFlag1;
	static int AReward;
public:
	bool writeData(char * filePath);
	bool readData(char * filePath);

	
	

};
//�����
#define Random(x) (rand() % x)

//̹���ƶ�
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code)&0x8000)?0:1)
// ������ʾ���
#define REVERSE    COMMON_LVB_REVERSE_VIDEO // ��ɫ
#define UNDERSCORE COMMON_LVB_UNDERSCORE    // �»���

// ������ɫ
#define F_BLUE     FOREGROUND_BLUE      // ����
#define F_H_BLUE   0x0001|0x0008        // ����
#define F_GREEN    0x0002               // ����
#define F_H_GREEN  0x0002|0x0008        // ����
#define F_RED      0x0004               // ���
#define F_H_RED    0x0004|0x0008        // ����
#define F_YELLOW   0x0002|0x0004        // ���
#define F_H_YELLOW 0x0002|0x0004|0x0008 // ����
#define F_PURPLE   0x0001|0x0004        // ����
#define F_H_PURPLE 0x0001|0x0004|0x0008 // ����
#define F_CYAN     0x0002|0x0004        // ����
#define F_H_CYAN   0x0002|0x0004|0x0008 // ����
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008

// ������ɫ
#define B_BLUE     BACKGROUND_BLUE      // ����
#define B_H_BLUE   0x0010|0x0080        // ����
#define B_GREEN    0x0020               // ����
#define B_H_GREEN  0x0020|0x0080        // ����
#define B_RED      0x0040               // ���
#define B_H_RED    0x0040|0x0080        // ����
#define B_YELLOW   0x0020|0x0040        // ���
#define B_H_YELLOW 0x0020|0x0040|0x0080 // ����
#define B_PURPLE   0x0010|0x0040        // ����
#define B_H_PURPLE 0x0010|0x0040|0x0080 // ����
#define B_CYAN     0x0020|0x0040        // ����
#define B_H_CYAN   0x0020|0x0040|0x0080 // ����
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0010|0x0020|0x0040|0x0080

/*
*        1       23           4                56          78
*  0x    0       00           0                00          00
*     �������� ����ID ̹��/�ڵ�/��ײ��� �˶�����/Ѫֵ ��ʾ����
*/



#define TANK_BODY          0x1
#define TANK_STYLE_BODY    0x10090001 // �� ̹����ɲ���
#define TANK_STYLE_UP_L    0x10090002 // ��  �о�̹��-�� 
#define TANK_STYLE_UP_R    0x10090003 // ��  �о�̹��-��
#define TANK_STYLE_DOWN_L  0x10090004 // ��  �о�̹��-��
#define TANK_STYLE_DOWN_R  0x10090005 // ��  �о�̹��-��
#define TANK_STYLE_LEFT_L  0x10090006 // ��  �о�̹��-��
#define TANK_STYLE_LEFT_R  0x10090007 // ��  �о�̹��-��
#define TANK_STYLE_RIGHT_L 0x10090008 // ��  �о�̹��-��
#define TANK_STYLE_RIGHT_R 0x10090009 // ��  �о�̹��-��
#define TANK_HEART         0x2
#define TANK_LEVEL_1       0x20090011 // ��  Ѫ��1
#define TANK_LEVEL_2       0x20090012 // ��  Ѫ��2
#define TANK_LEVEL_3       0x20090013 // ��  Ѫ��3
#define TANK_LEVEL_4       0x20090014 // ��  Ѫ��4
#define TANK_LEVEL_5       0x20090015 // ��  Ѫ��5
#define TANK_LEVEL_6       0x20090016 // ��  Ѫ��6
#define TANK_LEVEL_7       0x20090017 // ��  Ѫ��7
#define TANK_LEVEL_8       0x20090018 // ��  Ѫ��8
#define TANK_LEVEL_9       0x20090019 // ��  Ѫ��9
#define TANK_LEVEL_10      0x2009001A // ��  Ѫ��10

#define WALL_A_Type        0x5
#define WALL_B_Type        0x6
#define WALL_A             0x50010030 // ��  ��ǽ�����ƻ���
#define WALL_B             0x60010031 // �� ��ǽ
#define WALL_C             0x70000032 // ��  ���������٣�  ̹�����ҿ��ƶ������� ���²����ƶ�
#define WALL_D             0x80000033 //     ��ռ�  �ض�����ſ��Խ�
#define WALL_F             0x80000034 // ��   ̹���ϰ�
#define GOODS_STYLE_A      0x90010040 // ��  ����-����
#define GOODS_STYLE_B      0xA0010041 // ��  ����-ʵ��
#define WALL_T			   0xA0010042 // \������
#define  WALL_G			   0xA0010043 // �� �ռ�籩

//�� �ж�����
#define BULLET             0xF
#define BULLET_A           0xF0050042 // ��  ��
#define BULLET_B           0xF0050043 // ��  �ڵ�
#define BULLET_C           0xF0050044 // �� ���׵�
#define BULLET_D           0xF0050045 // �� ƶ�ᵯ
#define BULLET_E           0xF0050046 // ��  ̹��ɱ����ĸ��

#define NULL_A             0x00000047 // ��  ��ͨ�հ�
#define NULL_COL           0x00010047 // ��  ����ײ����Ŀհ�


#define COLLIDE_1          0x00001000
#define COLLIDE_2          0x00002000


#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3




    
//���Ш������K�L��
//�����
//���ب�
//123
//456
//789

//�J��ШI
//| �� |
//�K���L

//�q�t���W�Z
//���w��    
//�t���s�]�`
//