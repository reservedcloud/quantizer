#pragma once
#include <intrin.h>
#include "defs.h"

extern float g_PayloadBuffer[ 4096 ];
extern char g_Pallete[ 256 ];
extern unsigned char g_Font[ ];


extern char* g_BackBuffer;
extern char g_Unused2[ 763 ];
extern char g_DAC[ 765 ];
extern char g_Unused2[ 763 ];

extern int g_Seed;

extern unsigned __int8 SetupVga( );
extern char DisplayText( int a1, char *string, int a3, char xx );
extern unsigned int seed( );

extern float GenNoiseShader( float a1, float a2, float a3 );


extern void Payload1( );
extern void Payload2( );
extern void Payload3( );
extern void Payload4( );
extern void Payload5( );
extern void Payload6( );

