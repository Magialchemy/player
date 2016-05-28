#include "precom.h"
#include "enemy.h"

ENEMY::ENEMY()
{
	LoadDivGraph("image/kedamar.png",4,4,1,32,32,gh);

	wid=32;
	hei=32;

	x=winwidth+50;
	y=80;

	intime=100;
	stoptime=300;
	outtime=320;

	count=0;

	endflag=false;
}

void ENEMY::Move()
{
		//出てから止まる時間までの間なら下に移動
	if(intime<g_count && g_count<stoptime){
	x-=1;
	//時間が過ぎたら戻る
	}else if(g_count>outtime){
	x+=1;
	if(x>winwidth+wid/2)
	endflag=true;
	}

}

void ENEMY::Draw()
{
	int temp;

	if(!endflag){
	
	temp=count%40/10;
	if(temp==3)
		temp=1;
	
	DrawGraph(x,y,gh[temp],TRUE);
	}
}

bool ENEMY::All()
{
Move();
Draw();
++count;
return endflag;
}