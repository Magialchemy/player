#include "precom.h"
#include "control.h"

//キー取得用配列
char key[256];

int g_count;

// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	SetGraphMode( winwidth , winheight , 32 ) ;
	SetWindowSizeExtendRate( 2.0 );
	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}


	CONTROL *control = new CONTROL;



	while(ScreenFlip()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && GetHitKeyStateAll(key)==0){
		
		control->All();
		
	}


	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;				// ソフトの終了 
}