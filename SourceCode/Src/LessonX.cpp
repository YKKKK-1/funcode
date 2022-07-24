/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState		=	0;		// 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中

char        sPosition[256];
char        szTimeBuffer[1024];
long        musicLength;                    // 音乐长度
long        currentLength;                  // 当前播放长度
bool        bgMusicState = false;           // 音乐播放状态
float       dSpeedLeft, dSpeedRight;        // 精灵速度
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();

void GameMusicStatus(){     // 暂停/播放音乐
    bgMusicState = !bgMusicState;
    if (bgMusicState) {
        mciSendString("play music", NULL, NULL, NULL);
    } else {
        mciSendString("pause music", 0, 0, 0);
    }
}

//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。


//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态.
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void GameMainLoop( float	fDeltaTime )
{
	switch( g_iGameState )
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
		{
			GameInit();
            g_iGameState = 2;
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else
			{
				// 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
				g_iGameState	=	0;
				GameEnd();
			}
		}
		break;

		// 游戏结束/等待按空格键开始
	case 0:
	default:
		break;
	};
}

//==============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void GameInit()
{

    dSpeedLeft = 0;
    dSpeedRight = 0;
//    加载背景音乐
    mciSendString("open game/data/audio/music.wav Alias music",NULL,NULL,NULL);
//    获取音乐总长度
    mciSendString("status music length", sPosition, 256, 0);
    musicLength = strtol(sPosition, NULL, 10);
//    开始播放
    GameMusicStatus();
}
//==============================================================================
//
// 每局游戏进行中
void GameRun( float fDeltaTime )
{
//      背景音乐循环
    mciSendString("status music position", szTimeBuffer, 1024, 0);
    currentLength = strtol(szTimeBuffer, NULL, 10); // 当前播放长度
//    printf("%ld\n", currentLength);
//      当前音乐播放长度等于总长度时，刷新音乐
    if (currentLength == musicLength){
        mciSendString("close music", 0, 0, 0);
        mciSendString("open game/data/audio/music.wav Alias music",NULL,NULL,NULL);
        mciSendString("play music", 0, 0, 0);
    }

    dSetSpriteLinearVelocity("banai", dSpeedRight - dSpeedLeft, 0);

//    switch (mapID) {
//        case 0:
//            dLoadMap("mainMap.t2d");
//            break;
//        case 1:
//            dLoadMap("jcsyl.t2d");
//            break;
//        case 2:
//            printf("第三地图");
//            break;
//        case 3:
//            printf("2");
//            break;
//        default:
//            break;
//    }
}
//==============================================================================
//
// 本局游戏结束
void GameEnd()
{
    printf("End");
}
//==========================================================================
//
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseMove( const float fMouseX, const float fMouseY )
{
     //鼠标跟随移动
    dSpriteMoveTo("mouse", fMouseX, fMouseY, 30, 1);
    //鼠标悬浮放大
    if(dIsPointInSprite("startBtn",fMouseX,fMouseY))
    {
        dSetSpriteWidth("startBtn",30);
        dSetSpriteHeight("startBtn",30);
    }
    if(dIsPointInSprite("startBtn",fMouseX,fMouseY)==0)
    {
        dSetSpriteWidth("startBtn",20);
        dSetSpriteHeight("startBtn",20);
    }
}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
//    点击开始按钮初始化游戏
    if(iMouseType == 0 && dIsPointInSprite("startBtn",fMouseX,fMouseY)){
        g_iGameState = 1;
        dLoadMap("mainMap.t2d");
    }
//    点击开关背景音乐
    if(iMouseType == 0 && dIsPointInSprite("musicPower",fMouseX,fMouseY)){
        GameMusicStatus();
    }

    // 基础实验楼
    if(iMouseType == 0 && dIsPointInSprite("m_btn_jcsyl",fMouseX,fMouseY)){
        dLoadMap("jcsyl.t2d");
    }
}
//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{

    switch (iKey) {
        case KEY_A:
            dSpeedLeft = 15;
            dAnimateSpritePlayAnimation("banai", "leftAnimation", 1);
            break;
        case KEY_D:
            dSpeedRight = 15;
            dAnimateSpritePlayAnimation("banai", "rightAnimation", 1);
            break;
        case KEY_M:
            GameMusicStatus();
            break;
        default:
            break;
    }

}
//==========================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
void OnKeyUp( const int iKey )
{
    switch (iKey) {
        case KEY_A:
            dSpeedLeft = 0;
            dAnimateSpritePlayAnimation("banai", "banaiAnimation", 1);
            break;
        case KEY_D:
            dSpeedRight = 0;
            dAnimateSpritePlayAnimation("banai", "banaiAnimation", 1);
            break;
        default:
            break;
    }
}
//===========================================================================
//
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{

}
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
