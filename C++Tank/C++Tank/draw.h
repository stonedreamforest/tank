#pragma once
#include "data.h"
class draw:public data
{
public:
	
	void ClrDrawStyle(TANK Tank);
	void DrawStyle(TANK Tank);
	void DrawMap();

	char GetKey();
	void SkeletonKnight();
	void GraphicsInterface();
	void ScoringSystem();
	void GameMenu();
	void DrawStyleID( TANK Tank);

	

	void ForestObstacle(TANK Tank);//ɭ���ϰ�
	void SpaceStorm();//�ռ�籩
	void PropRefresh();//�콵����
	void Interface();
	void CustomMap();
public:
	void MouseClicks(MOUSE_EVENT_RECORD mou);//�����
	void KeyEventProc(KEY_EVENT_RECORD key);   //��������
	void TankCursor(int x,int y,char *pszChar,WORD wArr);
	void Treat(MOUSE_EVENT_RECORD mou);//�Է�
	void PrintInterface();
public:
	
	//INPUT_RECORD  stcRecord;
	int index;
	draw(void);
	~draw(void);
};


