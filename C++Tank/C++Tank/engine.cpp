#include "stdafx.h"
#include "engine.h"


engine::engine(void)
{

}


engine::~engine(void)
{
}






//����̹��
bool engine::HitTank(TANK * bullet,int x,int y)
{
//�ӵ��໥��������
		/*if(g_nMapDataTemp[y][x]>=1000)
		{
		bullet->isvalid = false;
		return false;
		}*/
		//���еı��̹��
		if (g_nMapDataTemp[y][x]<1000)
		{
			//��������̹�ˣ��ҵ����е�̹�˵�����˭,������Ч����Ϊfalse /
			//�о��ӵ�ID����1100
			if((g_nMapDataTemp[y][x]==Tank.ID||g_nMapDataTemp[y][x]==FTank.ID)&&bullet->ID<1100)
			{			
				//���򵽵�̹��
				int tankID = g_nMapDataTemp[y][x];
				//̹��1����ֵ ��ʼֵΪ10
				if (tankID==100)
				{
					TankCursor(43+(LifeValue-=1),19,"  ",F_YELLOW);
				}					
				//�ж�̹��1����ֵ�Ƿ�Ϊ��
				if (LifeValue==0&&tankID==100)
				{
					Tank.isvalid = false;
					ClrDrawStyle(Tank);
					ClrDrawStyleID(Tank);
					TankCursor(45+(LifeNumber-=1),21,"  ",F_YELLOW);
				//	LifeNumber-=1;//��������һ
				}
				//̹��1������
				if (LifeNumber>0&&LifeValue==0)
				{
					Tank.TankY=37;
					Tank.TankX=14;
					Tank.ID = 100;
					Tank.Orientation=UP;
					Tank.isvalid = true;
					TankCursor(42,22,"�����������",F_YELLOW);
					LifeValue=10;
					DrawStyle(Tank);
				}
				//̹��2����ֵ ��ʼֵΪ10
				if (tankID==101&&DoubleGame==2)
				{
					TankCursor(43+(LifeValue1-=1),25,"  ",F_YELLOW);
				}
				//�ж�̹��2����ֵ�Ƿ�Ϊ��
				if (LifeValue1==0&&DoubleGame==2)
				{
					FTank.isvalid = false;
					ClrDrawStyle(FTank);
					ClrDrawStyleID(FTank);
					TankCursor(45+(LifeNumber1-=1),27,"  ",F_YELLOW);
					//LifeNumber1-=1;//��������һ
				}		
				//̹��2������
				if (LifeNumber1>0&&LifeValue1==0)
				{
					FTank.TankY=37;
					FTank.TankX=24;
					FTank.ID = 101;
					FTank.Orientation=UP;
					FTank.isvalid = true;
					DrawStyle(FTank);
					TankCursor(42,25,"�����������",F_YELLOW);
					LifeValue1=10;
				}
				// ˫����Ϸ ̹��1 ̹��2 ��û����������Ϸ����
				if ((LifeNumber==0&&LifeNumber1==0)&&DoubleGame==2)
				{
					system("cls");
					pos.X=55;
					WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
					Sleep(2000);
					exit(0);
					return false;
				}
				else   //������Ϸ  ̹��1û����������Ϸ����
				{
					if (LifeNumber==0)
					{
						system("cls");
						pos.X=55;
						WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
						Sleep(2000);
						exit(0);
						return false;
					}
				}
			}						
		}
		//�����ӵ����ез�̹��
		for(unsigned int i=0;i<tanks.size();i++)
		{
			
			if(g_nMapDataTemp[y][x]==tanks[i].ID&&bullet->ID>=1100){			
				if (num<5)
				{
					tanks[i].isvalid = false;
					ClrDrawStyle(tanks[i]);
					ClrDrawStyleID(tanks[i]);
					TankCursor(45+(TankQuantity-=1),7,"��",F_YELLOW);
					TankCursor(49,15," ",F_YELLOW);
					printf("00%d",++num);
				}				
				//���к�����ʿ ʱ  ���� ��Ӣ��(��λһ��)
				else if(n_SkeletonKnight==100)
				{
					EliteTankValue-=1;
			
				}
				//���к�����ʿ ���� ��ͨ��ȫ��ʱ  ��ˢ�� ��Ӣ�� flag��ʾֻˢ��һ��
				if (num>=5&&n_SkeletonKnight==100&&flag==0)
				{
					flag=1;
					//�м�̹��ˢ��
					TANK Tank4;
					Tank4.TankY=2;
					Tank4.TankX=20;
					Tank4.Orientation=DOWN;
					Tank4.ChangeOrientation=DOWN;
					Tank4.isvalid = true;
					Tank4.ID = 4;
					tanks.push_back(Tank4);

					//���̹��ˢ��
					TANK Tank2;
					Tank2.TankY=20;
					Tank2.TankX=2;
					Tank2.Orientation=RIGHT;
					Tank2.ChangeOrientation=RIGHT;
					Tank2.isvalid = true;
					Tank2.ID = 2;
					tanks.push_back(Tank2);

					//�ұ�̹��ˢ��
					TANK Tank5;
					Tank5.TankY=20;
					Tank5.TankX=37;
					Tank5.Orientation=LEFT;
					Tank5.ChangeOrientation=LEFT;
					Tank5.isvalid = true;
					Tank5.ID = 5;
					tanks.push_back(Tank5);
					DrawStyle(Tank4);
					DrawStyleID(Tank4);

				
				}
				if (num>=5&&EliteTankValue==0)
				{
					//��Ϸ����
					system("cls");
					pos.X=55;
					WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
					Sleep(2000);
					exit(0);
					return false;
				}
				 if(num>=5&&n_SkeletonKnight==0)
				{
					//��Ϸ����
					system("cls");
					pos.X=55;
					WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
					Sleep(2000);
					exit(0);
					return false;
				}
			}
		}
		return true;
}

//�ж�ɭ���ϰ�
bool engine::JudgeForestObstacle(TANK Tank)
{
	switch (Tank.ChangeOrientation)
	{
	case UP:
		if(
			g_nMapData[Tank.TankY-2][Tank.TankX]==WALL_D||
			g_nMapData[Tank.TankY-2][Tank.TankX+1]==WALL_D||
			g_nMapData[Tank.TankY-2][Tank.TankX-1]==WALL_D
			)
		{
			return true;
		}
		break;
	case DOWN:
		if(
			g_nMapData[Tank.TankY+2][Tank.TankX]==(WALL_D)||
			g_nMapData[Tank.TankY+2][Tank.TankX+1]==(WALL_D)||
			g_nMapData[Tank.TankY+2][Tank.TankX-1]==(WALL_D)
			)
		{
			return false;
		}
		break;
	case LEFT:
		if(
			g_nMapData[Tank.TankY][Tank.TankX-2]==(WALL_D)||
			g_nMapData[Tank.TankY+1][Tank.TankX-2]==(WALL_D)||
			g_nMapData[Tank.TankY-1][Tank.TankX-2]==(WALL_D)
			)
		{
			return false;
		}		
		break;
	case RIGHT:
		if(
			g_nMapData[Tank.TankY][Tank.TankX+2]==(WALL_D)||
			g_nMapData[Tank.TankY+1][Tank.TankX+2]==(WALL_D)||
			g_nMapData[Tank.TankY-1][Tank.TankX+2]==(WALL_D)
			)
			//��ײʵ��
		{
			return false;
		}
		break;
	}
	return false;
}

//������
void engine::TransferMatrix(TANK &Tank)
{
	int x=rand() %35+2;
	int y=rand() %35+2;
	//�ж�ǰ���ǲ��Ǵ�����
	if (WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX-1]||	//����
		WALL_T==g_nMapData[Tank.TankY+1][Tank.TankX]||	//����
		WALL_T==g_nMapData[Tank.TankY+1][Tank.TankX+1]||	//����
		WALL_T==g_nMapData[Tank.TankY][Tank.TankX+1]||	//����
		WALL_T==g_nMapData[Tank.TankY][Tank.TankX-1]||	//����
		WALL_T==g_nMapData[Tank.TankY][Tank.TankX]||	//���ĵ�
		WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX]||	//����
		WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX+1]||	//����
		WALL_T==g_nMapData[Tank.TankY-1][Tank.TankX-1]	//����	
	)
	{
		CTransferMatrix();
		
		//�����ǰx��y�� û�κ�����Ŵ��� x��ʾ�� y��ʾ��
		if (CanTransferMatrix(x,y))
		{
			Tank.isvalid = false;
			ClrDrawStyle(Tank);
			ClrDrawStyleID(Tank);
			Tank.TankY=y;
			Tank.TankX=x;
			Tank.ID = 100;
			Tank.Bulletflag=1;
			Tank.Orientation=UP;
			Tank.isvalid = true;
			n_TransferMatrix--;
			TankCursor(43,28,"��ǰ���ͳɹ�",F_YELLOW);
		}
		else
		{
			n_TransferMatrix--;
			TankCursor(43,28,"��ǰ����ʧ��",F_YELLOW);
		}
		
//		DrawStyle(Tank);
//	DrawStyleID(Tank);
	}
}
//���������
void engine::CTransferMatrix()//��δ�������
{
	if (g_nMapData[Tank.TankY+1][Tank.TankX+1]==WALL_G)	//����
	{
		g_nMapData[Tank.TankY+1][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX-1]=0;
	}
	if (g_nMapData[Tank.TankY+1][Tank.TankX]==WALL_G)//����
	{
		g_nMapData[Tank.TankY+1][Tank.TankX]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY+1][Tank.TankX]=0;
	}
	if (g_nMapData[Tank.TankY+1][Tank.TankX+1]==WALL_G)//����
	{
		g_nMapData[Tank.TankY+1][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY+1][Tank.TankX+1]=0;
	}
	if (g_nMapData[Tank.TankY][Tank.TankX+1]==WALL_G)//����
	{
		g_nMapData[Tank.TankY][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY][Tank.TankX+1]=0;
	}
	if (g_nMapData[Tank.TankY][Tank.TankX-1]==WALL_G)//����
	{
		g_nMapData[Tank.TankY][Tank.TankX-1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY][Tank.TankX-1]=0;
	}
		g_nMapData[Tank.TankY][Tank.TankX]	=0;  //���ĵ�
	if (g_nMapData[Tank.TankY-1][Tank.TankX]==WALL_G)//����
	{
		g_nMapData[Tank.TankY-1][Tank.TankX]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX]=0;
	}
	if (g_nMapData[Tank.TankY-1][Tank.TankX+1]==WALL_G)//����
	{
		g_nMapData[Tank.TankY-1][Tank.TankX+1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX+1]=0;
	}
	if (g_nMapData[Tank.TankY-1][Tank.TankX-1]==WALL_G)//����
	{
		g_nMapData[Tank.TankY-1][Tank.TankX-1]=WALL_G;
	}
	else
	{
		g_nMapData[Tank.TankY-1][Tank.TankX-1]=0;
	}
}
//�Ƿ���Դ���
bool engine::CanTransferMatrix(int x,int y)
{
	if (0==g_nMapData[y-1][x-1]&&	//����
		0==g_nMapData[y+1][x]&&	//����
		0==g_nMapData[y+1][x+1]&&	//����
		0==g_nMapData[y][x+1]&&	//����
		0==g_nMapData[y][x-1]&&	//����
		0==g_nMapData[y][x]&&	//���ĵ�
		0==g_nMapData[y-1][x]&&	//����
		0==g_nMapData[y-1][x+1]&&	//����
		0==g_nMapData[y-1][x-1]	//����
		)
	{
		return true;
	}
		return false;
}

//�ж��ӵ��Ƿ��ܹ��ƶ�
//true  ���ƶ�
//false �����ƶ�
bool engine::isAllowMove( TANK * bullet,int x,int y)
{
	//�Ƚϵ�ͼԪ��
	if(g_nMapData[y][x]==WALL_A)
	{
		g_nMapData[y][x] = 0;
		TankCursor(x,y,"  ",F_YELLOW);
		bullet->isvalid = false;

		return false;
	}
	if(g_nMapData[y][x]==WALL_B)
	{
		bullet->isvalid = false;
		return false;
	}
	if (g_nMapData[0])
	{
	}
	if(g_nMapData[y][x]==WALL_T) //���ڵ��ڲ����ҷ��ӵ�
	{
		if (bullet->ID>=1100)
		{
			n_TransferMatrix--;
			g_nMapData[y][x]=0;//(������һ�δ���)
			TankCursor(x,y,"  ",F_YELLOW);
			ClrDrawStyle(Tank);
			ClrDrawStyleID(Tank);
			Tank.TankY=37;
			Tank.TankX=37;
			Tank.ID = 100;
			Tank.Bulletflag=1;
			Tank.Orientation=UP;
			Tank.isvalid = true;
			bullet->isvalid = false;
			return false;
		}
		else
		{
			g_nMapData[y][x]=0;//(������һ�δ���)
			TankCursor(x,y,"  ",F_YELLOW);
			bullet->isvalid = false;
			return false;
		}
	}
	if(g_nMapData[y][x]==WALL_F)
	{
		system("cls");
		pos.X=55;
		WriteConsoleOutputCharacter(hout,szStr[8],35,pos,&dwRet);
		Sleep(2000);
		exit(0);
		return false;
	}
	//�ӵ��໥��������
	if(g_nMapDataTemp[y][x]>=1000)
	{
		bullet->isvalid = false;
		return false;
	}
	//����̹��
	if(g_nMapDataTemp[y][x]>0)
	{ 
		HitTank(bullet,x,y);
		//�����ӵ�
		bullet->isvalid = false;
		return false;
	}
	return true;
}

//�ƶ�һ���ӵ�
void engine::BulletMove( TANK * bullet){
	//����ӵ�

	TankCursor(bullet->TankX,bullet->TankY,"  ",F_YELLOW);
	ClrDrawBulletID(*bullet);
	//��ײ�ж�
	switch(bullet->Orientation){
	case UP: 
		if(isAllowMove(bullet,bullet->TankX-1,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX  ,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY-1)){
				bullet->TankY--;
		}else{
			return;
		}
		break;
	case DOWN: 
		if(isAllowMove(bullet,bullet->TankX-1,bullet->TankY+1)&
			isAllowMove(bullet,bullet->TankX  ,bullet->TankY+1)&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY+1)){
				bullet->TankY++;
		}else{
			return;
		}
		break;
	case LEFT: 
		if(isAllowMove(bullet,bullet->TankX-1,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX-1,bullet->TankY  )&
			isAllowMove(bullet,bullet->TankX-1,bullet->TankY+1)){
				bullet->TankX--;
		}else{
			return;
		}
		break;
	case RIGHT: 
		if(isAllowMove(bullet,bullet->TankX+1,bullet->TankY-1)&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY  )&
			isAllowMove(bullet,bullet->TankX+1,bullet->TankY+1)){
				bullet->TankX++;
		}else{
			return;
		}
		break;
	}
	//�����ӵ�
	if (n_SkeletonKnight==100&&bullet->Bulletflag==1)
	{
		TankCursor(bullet->TankX,bullet->TankY,"�e",F_YELLOW);
	}
	else if(n_SkeletonKnight==100&&flag==1)
	{
		TankCursor(bullet->TankX,bullet->TankY,"��",F_YELLOW);
	}
	else
	{
		TankCursor(bullet->TankX,bullet->TankY,"��",F_YELLOW);
	}
	DrawBulletID(*bullet);

}
//̹�ˣ��ӵ����ƶ���ײ������
void engine::BulletsMove()
{	
	int i;
	for ( i = 0; i < 160; i++)
	{
		if ( g_TankBullet[i] != 0)
		{
			if(g_TankBullet[i]->isvalid == false)
			{
				free(g_TankBullet[i]);
				g_TankBullet[i] = 0;
				continue;
			}
			BulletMove( g_TankBullet[i]);
		}
	}
}

//CollisionDetection(��ײ���)
bool engine::Collisionetection(TANK Tank)
{
	switch (Tank.ChangeOrientation)
	{
	case UP:
		if(g_nMapData[Tank.TankY-2][Tank.TankX]==(WALL_B)||//̹��1�ƶ�  �ɿ�BUG 
			g_nMapData[Tank.TankY-2][Tank.TankX]==WALL_A||
			g_nMapData[Tank.TankY-2][Tank.TankX+1]==WALL_A||
			g_nMapData[Tank.TankY-2][Tank.TankX-1]==WALL_A||
			g_nMapData[Tank.TankY-2][Tank.TankX]==WALL_F||
			g_nMapData[Tank.TankY-2][Tank.TankX+1]==WALL_F||
			g_nMapData[Tank.TankY-2][Tank.TankX-1]==WALL_F||
			g_nMapDataTemp[Tank.TankY-2][Tank.TankX]>0||
			g_nMapDataTemp[Tank.TankY-2][Tank.TankX+1]>0||
			g_nMapDataTemp[Tank.TankY-2][Tank.TankX-1]>0)
		{
			return false;
		}
		break;
	case DOWN:
		if((g_nMapData[Tank.TankY+2][Tank.TankX]==WALL_B)||
			g_nMapData[Tank.TankY+2][Tank.TankX]==(WALL_A)||
			g_nMapData[Tank.TankY+2][Tank.TankX+1]==(WALL_A)||
			g_nMapData[Tank.TankY+2][Tank.TankX-1]==(WALL_A)||
			g_nMapData[Tank.TankY+2][Tank.TankX]==(WALL_F)||
			g_nMapData[Tank.TankY+2][Tank.TankX+1]==(WALL_F)||
			g_nMapData[Tank.TankY+2][Tank.TankX-1]==(WALL_F)||
			g_nMapDataTemp[Tank.TankY+2][Tank.TankX]>0||
			g_nMapDataTemp[Tank.TankY+2][Tank.TankX+1]>0||
			g_nMapDataTemp[Tank.TankY+2][Tank.TankX-1]>0)
		{
			return false;
		}
		break;
	case LEFT:
		if((g_nMapData[Tank.TankY][Tank.TankX-2]==WALL_B)||
			g_nMapData[Tank.TankY][Tank.TankX-2]==(WALL_A)||
			g_nMapData[Tank.TankY+1][Tank.TankX-2]==(WALL_A)||
			g_nMapData[Tank.TankY-1][Tank.TankX-2]==(WALL_A)||
			g_nMapData[Tank.TankY][Tank.TankX-2]==(WALL_F)||
			g_nMapData[Tank.TankY+1][Tank.TankX-2]==(WALL_F)||
			g_nMapData[Tank.TankY-1][Tank.TankX-2]==(WALL_F)||
			g_nMapDataTemp[Tank.TankY][Tank.TankX-2]>0||
			g_nMapDataTemp[Tank.TankY+1][Tank.TankX-2]>0||
			g_nMapDataTemp[Tank.TankY-1][Tank.TankX-2]>0)
		{
			return false;
		}		
		break;
	case RIGHT:
		if((g_nMapData[Tank.TankY][Tank.TankX+2]==WALL_B)||
			g_nMapData[Tank.TankY][Tank.TankX+2]==(WALL_A)||
			g_nMapData[Tank.TankY+1][Tank.TankX+2]==(WALL_A)||
			g_nMapData[Tank.TankY-1][Tank.TankX+2]==(WALL_A)||
			g_nMapData[Tank.TankY][Tank.TankX+2]==(WALL_F)||
			g_nMapData[Tank.TankY+1][Tank.TankX+2]==(WALL_F)||
			g_nMapData[Tank.TankY-1][Tank.TankX+2]==(WALL_F)||
			g_nMapDataTemp[Tank.TankY][Tank.TankX+2]>0||
			g_nMapDataTemp[Tank.TankY+1][Tank.TankX+2]>0||
			g_nMapDataTemp[Tank.TankY-1][Tank.TankX+2]>0)
			//��ײʵ��
		{
			return false;
		}
		break;
	}
	return true;
}


//���̹��ID 
void engine::ClrDrawStyleID(TANK Tank)
{
	for(unsigned int i=0,y=Tank.TankY-1;y<=Tank.TankY+1;i++,y++)
	{
		for(unsigned int j=0,x=Tank.TankX-1;x<=Tank.TankX+1;j++,x++)
		{
			g_nMapDataTemp[y][x]=0;
		}

	}
}
//���ӵ�id
void engine::DrawBulletID(TANK  bullet)
{
	g_nMapDataTemp[bullet.TankY][bullet.TankX]=bullet.ID;
}
//����ӵ�ID
void engine::ClrDrawBulletID(TANK bullet)
{
	g_nMapDataTemp[bullet.TankY][bullet.TankX]=0;

}
//Tank1�ƶ�����ײ���
void engine::Tank1Collisionetection(TANK & Tank1,int caozuo)
{
	//caozuo = 20;
	if(Tank1.isvalid == false){
		ClrDrawStyle(Tank1);
		return;
	}
	if(caozuo<4){
		Tank1.ChangeOrientation=caozuo;
		ClrDrawStyle(Tank1);
		ClrDrawStyleID(Tank1);
		if(Tank1.Orientation==Tank1.ChangeOrientation)
		{
			Tank1.Orientation=Tank1.ChangeOrientation;
			switch(Tank1.ChangeOrientation)
			{
			case UP:		
				if ( Collisionetection(Tank1))
				{

					Tank1.TankY--;	
				}
				else
				{
					break ;
				}
			case DOWN:
				if ( Collisionetection(Tank1))
				{
					Tank1.TankY++;	
				}
				else
				{
					break ;
				}
			case LEFT:
				if ( Collisionetection(Tank1))
				{
					Tank1.TankX--;	
				}
				else
				{
					break ;
				}		
			case RIGHT:
				if ( Collisionetection(Tank1))
				{
					Tank1.TankX++;	
				}
				else
				{
					break ;
				}	
			}
		}
		Tank1.Orientation=Tank1.ChangeOrientation;
	}
	DrawStyle(Tank1);
	DrawStyleID(Tank1);
	if(caozuo>3&&caozuo<7)
	{
		FireBullet(Tank1);
	}
}
//Tank�ƶ�����ײ���
void engine::TankCollisionetection(TANK & Tank )
{
	int Forestflag=0,Forestflag1=0;
	if(Tank.isvalid == false){
		ClrDrawStyle(Tank);
		return;
	}
	ClrDrawStyle(Tank);
	ClrDrawStyleID(Tank);
	if(Tank.Orientation==Tank.ChangeOrientation)
	{
		Tank.Orientation=Tank.ChangeOrientation;
		switch(Tank.ChangeOrientation)
		{
		case UP:		
			if ( Collisionetection(Tank))
			{
				if(JudgeForestObstacle(Tank))
				{
					ForestObstacle(Tank);
					Tank.TankY--;
					Forestflag=1;
					break;
				}
				Tank.TankY--;
			}
			break;
		case DOWN:
			if ( Collisionetection(Tank))
			{

				Tank.TankY++;	
			}
			break ;
		case LEFT:
			if ( Collisionetection(Tank))
			{
				Tank.TankX--;	
			}
			break ;			
		case RIGHT:
			if ( Collisionetection(Tank))
			{
				Tank.TankX++;	
			}
			break ;		
		}
	}
	//
	TransferMatrix(Tank);
	Tank.Orientation=Tank.ChangeOrientation;
	if (Forestflag!=1)
	{
		DrawStyle(Tank);
	}	
	DrawStyleID(Tank);
}
//���忪��
void engine::FireBullet(TANK Tank)
{
	TANK *bullet = (TANK *)malloc(sizeof(TANK));
	bullet->TankX = Tank.TankX;
	bullet->TankY = Tank.TankY;
	bullet->ID    = Tank.ID+1000;
	bullet->Orientation = Tank.Orientation;
	bullet->Bulletflag = Tank.Bulletflag;

	switch(bullet->Orientation){
	case UP:	bullet->TankY--;	break;
	case DOWN:	bullet->TankY++;	break;
	case LEFT:	bullet->TankX--;	break;
	case RIGHT:	bullet->TankX++;	break;
	}

	for (int i = 0; i < 160; i++)
	{
		if ( g_TankBullet[i] == 0)
		{
			g_TankBullet[i] = bullet;
			BulletMove( g_TankBullet[i]);
			DrawStyle(Tank);
			break;
		}
	}
}

//������ʿ
void engine::SpeedTANK(clock_t start2,clock_t finish2,clock_t start3,clock_t start4)
{
	clock_t finish3 ;
	clock_t finish4 ;
	if( (finish2 -start2 )>2)
	{
		start2 = finish2 ;	
		if (KEYDOWN('w')||KEYDOWN('W'))
		{
			Tank.ChangeOrientation=0;
			TankCollisionetection(Tank);
		}
		if (KEYDOWN('s')||KEYDOWN('S'))
		{
			Tank.ChangeOrientation=1;
			TankCollisionetection(Tank);
		}
		if (KEYDOWN('a')||KEYDOWN('A'))
		{
			Tank.ChangeOrientation=2;
			TankCollisionetection(Tank);
		}
		if (KEYDOWN('d')||KEYDOWN('D'))
		{
			Tank.ChangeOrientation=3;
			TankCollisionetection(Tank);
		}
		finish3=clock();
		if ((finish3-start3)>500)
		{
			start3=finish3;
			if(KEYDOWN('j')||KEYDOWN('J'))
			{
				FireBullet(Tank);
			}
		}
		if (KEYDOWN('k')||KEYDOWN('K'))
		{
			//memcpy(g_nMapData,m_g_nMapData,40*55*sizeof(int));
			memcpy(m_g_nMapData1,g_nMapData,40*55*sizeof(int));

			writeData("222.mapsb");
			exit(0);
		}
		finish3=clock();
		//̹��2�����ƶ�
		if (DoubleGame==2)
		{
			if (KEYDOWN(VK_UP))
			{
				FTank.ChangeOrientation=0;
				TankCollisionetection(FTank);
			}
			if (KEYDOWN(VK_DOWN))
			{
				FTank.ChangeOrientation=1;
				TankCollisionetection(FTank);
			}
			if (KEYDOWN(VK_LEFT))
			{
				FTank.ChangeOrientation=2;
				TankCollisionetection(FTank);
			}
			if (KEYDOWN(VK_RIGHT))
			{
				FTank.ChangeOrientation=3;
				TankCollisionetection(FTank);
			}

			finish4= clock();
			if ((finish4-start4)>500)
			{
				start4=finish4;
				if (KEYDOWN(VK_DECIMAL))
				{
					FireBullet(FTank);
				}
			}
			finish4=clock();
		}
	}
	
}

//����(ָ��)��Ϸ
void engine::index()
{

	char ch=GetKey();
	GraphicsInterface();//ͼ�ν���
	//�з�̹��ʱ��
	clock_t start = clock();
	clock_t finish ;
	clock_t start1= clock();
	clock_t finish1 ;
	//����̹��ʱ��
	clock_t start2 = clock();
	clock_t finish2 ;
	//����̹��1�ӵ�ʱ��
	clock_t start3= clock();
	clock_t finish3 ;
	//����̹��2�ӵ�ʱ��
	clock_t start4= clock();
	clock_t finish4;
	//�콵����
	clock_t start5= clock();
	clock_t finish5;
	clock_t start6= clock();
	clock_t finish6;
	srand((unsigned)time(NULL));//���ֵ
	while(1)
	{
		finish1=clock();
		if( (finish1 -start1 )>500)//���Ƶз�̹�˷����ƶ�
		{
			start1  = finish1 ;	
			vector<TANK>::iterator  it = tanks.begin();
			for (;it!=tanks.end();)
			{				
				if (it->isvalid==false)
				{
					it = tanks.erase(it);
				}else{
					Tank1Collisionetection(*it,rand()%15);
					it++;
				}
			}		
		}	
		finish = clock();
		if( (finish -start )>50)//�����ӵ�Ƶ��
		{
			start  = finish ;
			BulletsMove();
		}		
		//̹��1�����ƶ�
		finish2 =clock();
		if (n_SkeletonKnight==100)
		{
			SpeedTANK( start2 , finish2,start3, start4);
		}		
		else
		{
			if( (finish2 -start2 )>30)
			{
				start2 = finish2 ;	
				if (KEYDOWN('w')||KEYDOWN('W'))
				{
					Tank.ChangeOrientation=0;
					TankCollisionetection(Tank);
				}
				if (KEYDOWN('s')||KEYDOWN('S'))
				{
					Tank.ChangeOrientation=1;
					TankCollisionetection(Tank);
				}
				if (KEYDOWN('a')||KEYDOWN('A'))
				{
					Tank.ChangeOrientation=2;
					TankCollisionetection(Tank);
				}
				if (KEYDOWN('d')||KEYDOWN('D'))
				{
					Tank.ChangeOrientation=3;
					TankCollisionetection(Tank);
				}
				finish3=clock();
				if ((finish3-start3)>70)
				{
					start3=finish3;
					if(KEYDOWN('j')||KEYDOWN('J'))
					{
						FireBullet(Tank);
					}
				}
				if (KEYDOWN('k')||KEYDOWN('K'))
				{
					//memcpy(g_nMapData,m_g_nMapData,40*55*sizeof(int));
					memcpy(m_g_nMapData1,g_nMapData,40*55*sizeof(int));

					writeData("222.mapsb");
					exit(0);
				}
				finish3=clock();
				//̹��2�����ƶ�
				if (DoubleGame==2)
				{
					if (KEYDOWN(VK_UP))
					{
						FTank.ChangeOrientation=0;
						TankCollisionetection(FTank);
					}
					if (KEYDOWN(VK_DOWN))
					{
						FTank.ChangeOrientation=1;
						TankCollisionetection(FTank);
					}
					if (KEYDOWN(VK_LEFT))
					{
						FTank.ChangeOrientation=2;
						TankCollisionetection(FTank);
					}
					if (KEYDOWN(VK_RIGHT))
					{
						FTank.ChangeOrientation=3;
						TankCollisionetection(FTank);
					}

					finish4= clock();
					if ((finish4-start4)>70)
					{
						start4=finish4;
						if (KEYDOWN(VK_DECIMAL))
						{
							FireBullet(FTank);
						}
					}
					finish4=clock();
				}
			}
			finish5=clock();
			if ((finish5-start5)>1000*10)
			{
				start5=finish5;
				PropRefresh();
			}
			finish5=clock();
		}	
		finish2=clock();

		finish6 = clock();
		if (finish6-start6>1 )
		{
			start6 = finish6;
			if (MapFlag!=1||SpaceStormflag==1)
			{
				SpaceStorm();
			}
		}
		if (GetKey()=='p'||GetKey()=='P')
		{
			while (1)
			{
				if (GetKey()=='o'||GetKey()=='O')
				{
					break;
				}
			}
		}

	}
	
}

