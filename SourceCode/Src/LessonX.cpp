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
int			g_iGameState		=	0;		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������

char        sPosition[256];
char        szTimeBuffer[1024];
long        musicLength;                    // ���ֳ���
long        currentLength;                  // ��ǰ���ų���
bool        bgMusicState = false;            // ���ֲ���״̬
float       dSpeedLeft;
float       dSpeedRight;
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();

void GameMusicStatus(){     // ��ͣ/��������
    bgMusicState = !bgMusicState;
    if (bgMusicState) {
        mciSendString("play music", NULL, NULL, NULL);
    } else {
        mciSendString("pause music", 0, 0, 0);
    }
}

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�


//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void GameMainLoop( float	fDeltaTime )
{
	switch( g_iGameState )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
            g_iGameState = 2;
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else
			{
				// ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
				g_iGameState	=	0;
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}

//==============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void GameInit()
{

    dSpeedLeft = 0;
    dSpeedRight = 0;
//    ���ر�������
    mciSendString("open game/data/audio/music.wav Alias music",NULL,NULL,NULL);
//    ��ȡ�����ܳ���
    mciSendString("status music length", sPosition, 256, 0);
    musicLength = strtol(sPosition, NULL, 10);
//    ��ʼ����
    GameMusicStatus();
}
//==============================================================================
//
// ÿ����Ϸ������
void GameRun( float fDeltaTime )
{
//      ��������ѭ��
    mciSendString("status music position", szTimeBuffer, 1024, 0);
    currentLength = strtol(szTimeBuffer, NULL, 10); // ��ǰ���ų���
//    printf("%ld\n", currentLength);
//      ��ǰ���ֲ��ų��ȵ����ܳ���ʱ��ˢ������
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
//            printf("������ͼ");
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
// ������Ϸ����
void GameEnd()
{
    printf("End");
}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseMove( const float fMouseX, const float fMouseY )
{
     //�������ƶ�
    dSpriteMoveTo("mouse", fMouseX, fMouseY, 30, 1);
    //��������Ŵ�
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
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
//    �����ʼ��ť��ʼ����Ϸ
    if(iMouseType == 0 && dIsPointInSprite("startBtn",fMouseX,fMouseY)){
        g_iGameState = 1;
        dLoadMap("mainMap.t2d");
    }
//    ������ر�������
    if(iMouseType == 0 && dIsPointInSprite("musicPower",fMouseX,fMouseY)){
        GameMusicStatus();
    }

    // ����ʵ��¥
    if(iMouseType == 0 && dIsPointInSprite("m_btn_jcsyl",fMouseX,fMouseY)){
        dLoadMap("jcsyl.t2d");
    }
}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{

    switch (iKey) {
        case KEY_A:
            dSpeedLeft = 10;
            break;
        case KEY_D:
            dSpeedRight = 10;
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
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void OnKeyUp( const int iKey )
{
    switch (iKey) {
        case KEY_A:
            dSpeedLeft = 0;
            break;
        case KEY_D:
            dSpeedRight = 0;
            break;
        default:
            break;
    }
}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{

}
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
