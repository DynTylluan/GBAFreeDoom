// PsionDoomDoc.cpp
//
// Copyright 17/02/2019 
//

#include "i_system_win.h"

#include <stdarg.h>
#include <stdio.h>

#include "i_system_e32.h"

#include "lprintf.h"


//**************************************************************************************

unsigned int vid_width = 0;
unsigned int vid_height = 0;

unsigned int screen_width = 0;
unsigned int screen_height = 0;

unsigned int y_pitch = 0;

DoomWindow* window = NULL;

QApplication * app = NULL;

unsigned char* pb = NULL;
unsigned char* pl = NULL;

//**************************************************************************************

void I_InitScreen_e32()
{
	//Gives 480px on a 5(mx) and 320px on a Revo.
    vid_width = 240;

    vid_height = screen_height = 160;
}

//**************************************************************************************

void I_BlitScreenBmp_e32()
{

}

//**************************************************************************************

void I_StartWServEvents_e32()
{        

}

//**************************************************************************************

void I_PollWServEvents_e32()
{

}

//**************************************************************************************

void I_ClearWindow_e32()
{

}


//**************************************************************************************

void I_CreateWindow_e32()
{
    int z = 0;

    app = new QApplication (z, nullptr);

    window = new DoomWindow();

    window->setAttribute(Qt::WA_PaintOnScreen);



    window->resize(vid_width * 4, vid_height * 4);

    window->show();
}

//**************************************************************************************

void I_CreateBackBuffer_e32()
{	
	I_CreateWindow_e32();
}

//**************************************************************************************

void I_FinishUpdate_e32(const byte* srcBuffer, const byte* pallete, const unsigned int width, const unsigned int height)
{
    pb = (unsigned char*)srcBuffer;
    pl = (unsigned char*)pallete;

    window->repaint();

    app->processEvents();
}

//**************************************************************************************

int I_GetVideoWidth_e32()
{
    return vid_width;
}

//**************************************************************************************

int I_GetVideoHeight_e32()
{
	return vid_height;
}

//**************************************************************************************

void I_ProcessKeyEvents()
{
	I_PollWServEvents_e32();
}

//**************************************************************************************

#define MAX_MESSAGE_SIZE 2048

void I_Error (const char *error, ...)
{
	char msg[MAX_MESSAGE_SIZE];
 
	va_list v;
	va_start(v, error);
	
	vsprintf(msg, error, v);
	
	va_end(v);

	printf("%s", msg);


    fflush( stderr );
	fflush( stdout );

    gets(msg);

	I_Quit_e32();
}

//**************************************************************************************

void I_Quit_e32()
{

}

//**************************************************************************************
