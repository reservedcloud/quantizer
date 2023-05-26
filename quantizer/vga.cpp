#include "inc.h"

char* g_BackBuffer = ( char* )0xA0000;
char g_DAC[ 765 ] = {};
char g_Unused2[ 763 ] = {};

char DisplayText( int a1, char *string, int a3, char xx )
{
    char *stringText; // edi
    int v5; // ecx
    char result; // al
    int v7; // ebx
    int v8; // esi
    int v9; // eax
    int v10; // eax
    char *v11; // esi
    char v12; // ch
    int v13; // ebx
    char v14; // cl
    char *v15; // [esp+4h] [ebp-18h]
    int v16; // [esp+8h] [ebp-14h]
    int v17; // [esp+Ch] [ebp-10h]
    int v18; // [esp+10h] [ebp-Ch]
    int v19; // [esp+14h] [ebp-8h]
    char v20; // [esp+1Bh] [ebp-1h]

    stringText = string;
    v15 = string;
    v5 = a1;
    v16 = a1;
    result = *stringText;

    // if there is any characters to print
    if ( *stringText )
    {
        v7 = 320 * a3;
        v17 = 320 * a3;
        while ( 1 )
        {
            v8 = result;
            v9 = result - 9;
            if ( !v9 )
                break;
            v10 = v9 - 1;
            if ( v10 )
            {
                if ( v10 != 3 )
                {
                    v19 = v7;
                    // 16 width font
                    v11 = ( char * )&g_Font + 16 * v8;
                    v18 = 16;
                    do
                    {
                        v12 = *v11;
                        v13 = 0;
                        v14 = 7;
                        v20 = *v11;
                        do
                        {
                            if ( ( v12 >> v14 ) & 1 )
                            {
                                g_BackBuffer[ v19 + v13 + a1 ] = xx;
                                v12 = v20;
                            }
                            --v14;
                            ++v13;
                        } while ( v14 >= -1 );
                        v19 += 320;
                        ++v11;
                        --v18;
                    } while ( v18 );
                    stringText = v15;
                    a1 += 8;
                    v7 = v17;
                    goto LABEL_16;
                }
            } else
            {
                v7 += 5120;
                v17 = v7;
            }
            a1 = v5;
increment:

            // increment stringText to display next character
            v15 = ++stringText;
            result = *stringText;
            if ( !*stringText )
                return result;
        }
        // 28 height font
        a1 += 28 - a1 % 4;
LABEL_16:
        v5 = v16;
        goto increment;
    }
    return result;
}

unsigned __int8 SetupVga( )
{
    unsigned __int8 *v0; // ecx
    int v1; // esi
    unsigned __int8 v2; // al
    unsigned __int8 result; // al

    v0 = ( unsigned __int8 * )g_DAC;
    v1 = 256;
    __outbyte( 0x3C8u, 0 );
    do
    {
        v2 = *v0;
        v0 += 3;
        __outbyte( 0x3C9u, v2 );
        __outbyte( 0x3C9u, *( v0 - 2 ) );
        result = *( v0 - 1 );
        __outbyte( 0x3C9u, result );
        --v1;
    } while ( v1 );
    return result;
}

int lol = 0;
char CompileShader( int a1, int a2 )
{
    return g_Pallete[ ( a1 + ( unsigned __int8 )g_Pallete[ ( a2 ) % 256 ] ) % 256 ];
}

float GenNoiseShader( float a1, float a2, float a3 )
{
    float v3; // xmm4_4
    float v4; // xmm3_4
    float v5; // xmm7_4
    float v6; // xmm6
    int v7; // ebx
    float v8; // xmm1_4
    float v9; // xmm5_4
    float v10; // xmm1_4
    float v11; // xmm3_4
    int v12; // edx
    int v13; // edx
    float v14; // xmm4_4
    float v15; // xmm0_4
    int v16; // edx
    float v17; // xmm2_4
    float v18; // xmm2_4
    float v20; // [esp+0h] [ebp-Ch]
    float v21; // [esp+4h] [ebp-8h]
    float v22; // [esp+8h] [ebp-4h]

    v3 = 1.0;
    v4 = a2 * a3;
    v5 = a1 * a3;
    v6 = 0i64;
    v7 = 5;
    v22 = 1.0;
    v8 = 0.0;
    v21 = v4;
    while ( 1 )
    {
        v20 = ( float )( v3 * 256.0 ) + v8;
        v9 = v4 - ( float )( int )v4;
        v10 = ( float )( unsigned __int8 )CompileShader( ( int )v5, ( int )v4 );
        v11 = ( float )( 3.0 - ( float )( ( float )( v5 - ( float )( int )v5 ) + ( float )( v5 - ( float )( int )v5 ) ) )
            * ( float )( ( float )( v5 - ( float )( int )v5 ) * ( float )( v5 - ( float )( int )v5 ) );
        v14 = ( float )( ( float )( ( float )( unsigned __int8 )CompileShader( ( int )v5 + 1, v12 ) - v10 ) * v11 ) + v10;
        v15 = ( float )( unsigned __int8 )CompileShader( ( int )v5, v13 + 1 );
        v17 = ( float )( ( float )( unsigned __int8 )CompileShader( ( int )v5 + 1, v16 ) - v15 ) * v11;
        v4 = v21 + v21;
        v21 = v21 + v21;
        v5 = v5 + v5;
        v18 = ( float )( ( float )( ( float )( ( float )( v17 + v15 ) - v14 ) * ( float )( 3.0 - ( float )( v9 + v9 ) ) ) * ( float )( v9 * v9 ) ) + v14;
        v3 = v22 * 0.5;
        *( float * )&v6 = *( float * )&v6 + ( float )( v18 * v22 );
        v22 = v22 * 0.5;

        // hits 0?
        if ( !--v7 )
            break;
        v8 = v20;
    }
    *( float * )&v6 = *( float * )&v6 / v20;
    return v6;
}