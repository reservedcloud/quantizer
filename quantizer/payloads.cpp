#include "inc.h"

volatile void WaitOnInterrupt( )
{
    for ( int i = 0; i < 0x10000; i++ )
        for ( int j = 0; j < 0x500; j++ )
            
        __asm nop;
}

void Payload1( )
{
    int i; // esi
    int v1; // eax
    char v2; // bl
    int v3; // kr00_4
    int v4; // ecx
    char v5; // al
    int j; // esi
    float v7; // xmm2_4
    unsigned int k; // edi
    unsigned int v9; // ebx
    float v10; // xmm0_4
    float v11; // xmm0_4
    char string[] = "noobes.sys"; // [esp+Ch] [ebp-1Ch]
    float v13; // [esp+1Ch] [ebp-Ch]
    unsigned int v14; // [esp+20h] [ebp-8h]
    float v15; // [esp+24h] [ebp-4h]
    for ( i = 0; i < 765; i += 3 )
    {
        v1 = i / 3;
        if ( ( unsigned __int8 )( i / 3 ) <= 0x7Fu )
        {
            LOBYTE( v4 ) = 0;
            v2 = ( unsigned __int8 )v1 >> 1;
            v5 = ( unsigned __int8 )v1 >> 2;
        } else
        {
            v2 = 63;
            v3 = ( unsigned __int8 )v1 - 127;
            LODWORD( v15 ) = v3 / 2;
            v4 = v3 / 2;
            v5 = v3 / 8 + 31;
        }
        g_DAC[ i ] = v5;
        g_DAC[ i ] = v4;
        g_DAC[ i ] = v2;
    }
    SetupVga( );
    for ( j = 0; ; ++j )
    {
        v7 = ( float )j;
        v13 = ( float )j;
        v15 = g_PayloadBuffer[ ( int )( float )( ( float )j * 4.0743666 ) & 0xFFF ];
        DisplayText( 0xD6, ( char* )&string, 0xB6, 0 );
        DisplayText( 0xD6, ( char* )&string, 0xB5, 48 );
        DisplayText( 0xD5, ( char* )&string, 0xB5, 112 );
        DisplayText( 0xD5, ( char* )&string, 0xB4, 176 );
        DisplayText( 0xD4, ( char* )&string, 0xB4, 255 );
        WaitOnInterrupt( );
        for ( k = 0; ( int )k < 64000; ++k )
        {
            v9 = k % 0x140;
            v14 = k / 0x140;
            v10 = COERCE_FLOAT( GenNoiseShader( ( float )( k % 0x140 ) + v7, ( float )( k / 0x140 ) + v7, 0.025 ) );
            v11 = v10 * v15;
            if ( v11 < 0.0 )
                v11 = v11 + 1.0;
            v7 = v13;
            g_BackBuffer[ 320 * v14 + v9 ] = ( int )( float )( v11 * 255.0 );
        }
    }
}
void Payload2( )
{
    int i; // esi
    float v1; // xmm2_4
    int j; // esi
    int k; // edi
    char string[ ] = "noobes.sys"; // [esp+0h] [ebp-10h]

    for ( i = 0; i < 765; i += 3 )
    {
        v1 = g_PayloadBuffer[ ( 1024 - ( unsigned __int16 )( int )( float )( ( float )( unsigned __int8 )( i / 3 ) * -16.062746 ) ) & 0xFFF ];
        g_DAC[ i ] = ( int )( float )( 31.5 - ( float )( v1 * 31.5 ) );
        g_Unused2[ i ] = ( int )( float )( 7.5 - ( float )( v1 * 7.5 ) );
    }
    SetupVga( );
    for ( j = 0; ; ++j )
    {
        DisplayText( 214, ( char* )&string, 182, 0 );
        DisplayText( 214, ( char* )&string, 181, 48 );
        DisplayText( 213, ( char* )&string, 181, 112 );
        DisplayText( 213, ( char* )&string, 180, 176 );
        DisplayText( 212, ( char* )&string, 180, 255 );
        WaitOnInterrupt( );
        for ( k = 0; k < 64000; ++k )
            g_BackBuffer[ k ] = ( ( int )( float )( ( float )( ( float )j * 0.5 ) + ( float )( k % 0x140u ) )
                                  - ( int )( float )( ( float )( ( float )( g_PayloadBuffer[ ( int )( float )( ( float )( ( float )( k % 0x140u )
                                  * 10.185916 )
                                  + ( float )( ( float )j * 32.594933 ) ) & 0xFFF ]
                                  + 1.0 )
                                  * -0.0015625 )
                                  * ( float )k ) )
            % 0xFFu;
    }
}
void Payload3( )
{
    int v0; // ebx
    float v1; // xmm2_4
    float v2; // xmm3_4
    float v3; // xmm4_4
    int v4; // esi
    int v5; // ebx
    int i; // ecx
    float v7; // xmm1_4
    int v8; // ebx
    unsigned int v9; // edi
    int v10; // esi
    float v11; // xmm0_4
    float v12; // xmm0_4
    float v13; // xmm0_4
    float v14; // xmm0_4
    char string[] = "noobes.sys"; // [esp+Ch] [ebp-2Ch]
    int v16; // [esp+1Ch] [ebp-1Ch]
    int v17; // [esp+20h] [ebp-18h]
    int v18; // [esp+24h] [ebp-14h]
    float v19; // [esp+28h] [ebp-10h]
    float v20; // [esp+2Ch] [ebp-Ch]
    float v21; // [esp+30h] [ebp-8h]
    int v22; // [esp+34h] [ebp-4h]

    v17 = seed( ) & 0x3FF;
    v0 = 0;
    v16 = seed( ) & 0x3FF;
    v1 = 1.0;
    v22 = 0;
    v2 = 0.0;
    v21 = 1.0;
    v3 = 0.0;
    v20 = 0.0;
    v19 = 0.0;
    v4 = 0;
    while ( 1 )
    {
        v18 = v4;
        DisplayText( 214, ( char* )&string, 182, 0 );
        DisplayText( 214, ( char* )&string, 181, 48 );
        DisplayText( 213, ( char* )&string, 181, 112 );
        DisplayText( 213, ( char* )&string, 180, 176 );
        DisplayText( 212, ( char* )&string, 180, 255 );
        WaitOnInterrupt( );
        if ( v0 )
        {
            switch ( v0 )
            {
                case 1:
                    v1 = v1 - 0.0099999998;
                    v21 = v1;
                    v14 = v1;
                    if ( v1 <= 0.0 )
                    {
                        v1 = 0.0;
                        v21 = 0.0;
                    }
                    v0 = v14 <= 0.0;
LABEL_11:
                    v5 = v0 + 1;
LABEL_12:
                    v22 = v5;
                    goto LABEL_13;
                case 2:
                    v3 = v3 + 0.0099999998;
                    v19 = v3;
                    v13 = v3;
                    if ( v3 >= 1.0 )
                    {
                        v3 = 1.0;
                        v19 = 1.0;
                    }
                    v5 = ( v13 >= 1.0 ) + 2;
                    goto LABEL_12;
                case 3:
                    v2 = v2 - 0.0099999998;
                    v20 = v2;
                    v12 = v2;
                    if ( v2 <= 0.0 )
                    {
                        v2 = 0.0;
                        v20 = 0.0;
                    }
                    v5 = ( v12 <= 0.0 ) + 3;
                    goto LABEL_12;
                case 4:
                    v1 = v1 + 0.0099999998;
                    v21 = v1;
                    v11 = v1;
                    if ( v1 >= 1.0 )
                    {
                        v1 = 1.0;
                        v21 = 1.0;
                    }
                    v5 = ( v11 >= 1.0 ) + 4;
                    goto LABEL_12;
                case 5:
                    v3 = v3 - 0.0099999998;
                    v19 = v3;
                    if ( v3 > 0.0 )
                        goto LABEL_13;
                    v3 = 0.0;
                    v5 = 0;
                    v19 = 0.0;
                    goto LABEL_12;
            }
            v0 = 0;
            v22 = 0;
        }
        v2 = v2 + 0.0099999998;
        v20 = v2;
        if ( v2 >= 1.0 )
        {
            v2 = 1.0;
            v20 = 1.0;
            goto LABEL_11;
        }
LABEL_13:
        for ( i = 0; i < 765; i += 3 )
        {
            v7 = ( float )( unsigned __int8 )( int )( float )( ( float )( unsigned __int8 )( i / 3 ) * 0.25 );
            g_DAC[ i ] = ( int )( float )( v7 * v1 );
        }
        SetupVga( );
        v8 = v18;
        v9 = 0;
        v10 = v4 / 2;
        do
        {
            g_BackBuffer[ v9 ] = ( int )( float )( COERCE_FLOAT(
                GenNoiseShader(
                ( float )( int )( ( v17 + v9 % 0x140 + 2 * v8 ) ^ ( v16 + v9 / 0x140 - v10 ) ),
                ( float )( int )( ( v17 + v9 % 0x140 + 2 * v8 ) & ( v16 + v9 / 0x140 - v10 ) ),
                0.050000001 ) )
                * 255.0 );
            ++v9;
        } while ( ( int )v9 < 64000 );
        v1 = v21;
        v4 = v18 + 1;
        v2 = v20;
        v3 = v19;
        v0 = v22;
    }
}
void Payload4( )
{
    int i; // esi
    float v1; // xmm2_4
    int j; // edi
    unsigned int k; // ebx
    float v4; // xmm2_4
    unsigned __int8 v5[ ] = "noobes.sys"; // [esp+0h] [ebp-10h]

    for ( i = 0; i < 765; i += 3 )
    {
        g_Unused2[ i ] = 0;
        v1 = g_PayloadBuffer[ ( 1024 - ( unsigned __int16 )( int )( float )( ( float )( unsigned __int8 )( i / 3 ) * -16.062746 ) ) & 0xFFF ];
        g_DAC[ i ] = ( int )( float )( 31.5 - ( float )( v1 * 31.5 ) );
    }
    SetupVga( );
    for ( j = 0; ; j += 8 )
    {
        DisplayText( 214, ( char * )v5, 182, 0 );
        DisplayText( 214, ( char * )v5, 181, 48 );
        DisplayText( 213, ( char * )v5, 181, 112 );
        DisplayText( 213, ( char * )v5, 180, 176 );
        DisplayText( 212, ( char * )v5, 180, 255 );
        WaitOnInterrupt( );

        for ( k = 0; ( int )k < 64000; ++k )
        {
            v4 = ( float )( seed( ) & 7 );
            g_BackBuffer[ k ] = ( int )( float )( ( float )( ( float )( ( float )( ( float )( k / 0x140 )
                                                  / ( float )( 200.0 - ( float )( ( float )( k / 0x140 ) * 0.79999995 ) ) )
                                                  * 320.0 )
                                                  + ( float )( v4 + v4 ) )
                                                  + ( float )( ( float )( ( float )j + ( float )( k % 0x140 ) ) + ( float )( k % 0x140 ) ) ) & 0xFE;
        }
    }
}
void Payload5( )
{
    int v0; // ecx
    float v1; // xmm0_4
    int v2; // esi
    int v3; // edi
    float v4; // xmm7_4
    float v5; // xmm6_4
    float v6; // xmm6_4
    unsigned int v7; // ebx
    float v8; // xmm5_4
    float v9; // xmm3_4
    float v10; // xmm0_4
    char string[] = "noobes.sys"; // [esp+Ch] [ebp-10h]

    v0 = 0;
    do
    {
        
        v1 = ( float )( unsigned __int8 )( v0 / 3 );
        v0 += 3;
        g_DAC[ v0 ] = ( int )( float )( v1 * 0.24705884 );

    } while ( v0 < 765 );
    SetupVga( );
    v2 = 0;
    v3 = 0;
    v4 = ( float )( seed( ) % 0x2711u );
    while ( 1 )
    {
        v5 = g_PayloadBuffer[ ( int )( float )( ( float )v2 * 13.037972 ) & 0xFFF ];
        DisplayText( 214, ( char* )&string, 182, 0 );
        DisplayText( 214, ( char* )&string, 181, 48 );
        DisplayText( 213, ( char* )&string, 181, 112 );
        DisplayText( 213, ( char* )&string, 180, 176 );
        DisplayText( 212, ( char* )&string, 180, 255 );
        WaitOnInterrupt( );
        v6 = v5 * 150.0;
        v7 = 0;
        v8 = ( float )v2 * 1.5;
        do
        {
            v9 = ( float )( ( float )( v7 % 0x140 ) + v8 ) + v6;
            v10 = ( float )( ( unsigned __int8 )( int )v9 ^ v2 & ( ( unsigned __int8 )( int )v9
                             + 2
                             * ( unsigned __int8 )( int )( float )( ( float )( ( float )( v7 / 0x140 ) + v8 ) - v4 ) ) );
            g_BackBuffer[ v7 ] = ( int )( float )( ( float )( ( float )( ( float )( ( float )( ( float )( ( int )( float )( ( float )( ( float )( v7 / 0x140 )
                                                   + v8 )
                                                   - v4 ) & ( int )v10 )
                                                   / v10 )
                                                   * 320.0 )
                                                   + ( float )v3 )
                                                   + v9 )
                                                   + ( float )( ( float )( g_PayloadBuffer[ ( int )( float )( ( float )( ( float )( ( float )( ( float )( v7 / 0x140 ) + v8 )
                                                   - v4 )
                                                   * 21.729956 )
                                                   + ( float )( ( float )v2 * 32.594933 ) ) & 0xFFF ]
                                                   * 256.0 )
                                                   + v9 ) ) & 0xFE;
            ++v7;
        } while ( ( int )v7 < 64000 );
        ++v2;
        v3 += 8;
    }
}
void Payload6( )
{
    int v0; // ecx
    int v1; // eax
    int v2; // esi
    int i; // edi
    float v4; // xmm4_4
    unsigned int v5; // ebx
    float v6; // xmm7_4
    float v7; // xmm4_4
    float v8; // xmm3_4
    char string[] = "noobes.sys"; // [esp+Ch] [ebp-18h]
    float v10; // [esp+1Ch] [ebp-8h]
    float v11; // [esp+20h] [ebp-4h]

    v0 = 0;
    do
    {
        
        v1 = ( int )( float )( ( float )( unsigned __int8 )( v0 / 3 ) * 0.24705884 );
        g_DAC[ v0 ] = v1;
        v0 += 3;
        
    } while ( v0 < 765 );

    SetupVga( );
    v2 = 0;
    for ( i = 0; ; i += 8 )
    {
        v4 = g_PayloadBuffer[ ( int )( float )( ( float )v2 * 13.037972 ) & 0xFFF ];
        DisplayText( 214, ( char* )&string, 182, 0 );
        DisplayText( 214, ( char* )&string, 181, 48 );
        DisplayText( 213, ( char* )&string, 181, 112 );
        DisplayText( 213, ( char* )&string, 180, 176 );
        DisplayText( 212, ( char* )&string, 180, 255 );
        WaitOnInterrupt( );
        v5 = 0;
        v6 = ( float )i;
        v7 = ( float )( v4 + 1.0 ) * 25.0;
        do
        {
            v8 = ( float )( ( float )( ( float )( g_PayloadBuffer[ ( int )( float )( ( float )( ( float )( v5 % 0x140 ) * 6.4000001 )
                            + ( float )( ( float )v2 * 21.729956 ) ) & 0xFFF ]
                            + 1.0 )
                            * 4.0 )
                            * ( float )( v5 % 0x140 ) )
                * ( float )( ( float )( v5 / 0x140 ) + v7 );
            LODWORD( v11 ) = 1597463007 - ( LODWORD( v8 ) >> 1 );
            LODWORD( v10 ) = ( int )( float )( ( float )( ( float )( COERCE_INT(
                ( float )( ( float )( ( float )( v5 / 0x140 ) + v7 ) * ( float )( v5 % 0x140 ) )
                + v6 )
                - 1064866805 )
                * 0.2 )
                + 1064866800.0 );
            g_BackBuffer[ v5++ ] = ( int )( float )( ( float )( ( float )( 1.0
                                                     / ( float )( ( float )( 1.5
                                                     - ( float )( ( float )( ( float )( v8 * 0.5 ) * v11 ) * v11 ) )
                                                     * v11 ) )
                                                     + v6 )
                                                     + ( float )( v10 * 10.0 ) ) & 0xFE;
        } while ( ( int )v5 < 64000 );
        ++v2;
    }
}