#pragma once
#include "draw.h"
class engine: public draw
{
public:
	engine(void);
	~engine(void);
public:
	void index();
	
	void GameMenu();
	bool isAllowMove( TANK * bullet,int x,int y);
	void BulletMove( TANK * bullet);
	void BulletsMove();
	bool Collisionetection(TANK Tank);
	
	void ClrDrawStyleID(TANK Tank);
	void Tank1Collisionetection(TANK & Tank1,int caozuo);
	void TankCollisionetection(TANK &Tank );
	void FireBullet(TANK Tank);
	void DrawBulletID(TANK  bullet);
	void ClrDrawBulletID(TANK bullet);
	void SpeedTANK(clock_t start2,clock_t finish2,clock_t start3,clock_t start4);
	void OrdinarySpeed();
	bool HitTank(TANK * bullet,int x,int y);

	bool JudgeForestObstacle(TANK Tank);//�ж�ɭ���ϰ�
	void TransferMatrix(TANK &Tank);
	void CTransferMatrix();//���������
	bool CanTransferMatrix(int x,int y);//�Ƿ���Դ���

	
};
