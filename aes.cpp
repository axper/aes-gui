// aes.cpp

#include "aes.h"
#include "aes_lookup_tables.cpp"

/*
================
classAES::InputForEncrypt
Return values:
0 - normal exit
1 - text's size is null
2 - inputkey's size is more than 16
3 - inputkey's size is null
================
*/
int classAES::InputForEncrypt(string textReceived, string inputkey)
{
    int i;

    if (inputkey.size() > 17) {
        return 2;
    }
    else if (inputkey.size() == 0) {
        return 3;
    }
    else {
        for (i = inputkey.size(); i < 16; i++) {
            inputkey += '\0';
        }
    }

    if (textReceived.size() == 0) {
        return 1;
    }
    else {
        // add \0's to fill last 16-byte block
        for (i = textReceived.size() % 16; i < 16; i++) {
            textReceived += '\0';
        }
        text = textReceived;
    }

    memcpy(key, inputkey.c_str(), 16);

    /*
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    // uncomment this and comment everything above in this function
    // if you want to test the example in aes flash animation
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    unsigned char state2[ 16 ] = {
        0x32, 0x88, 0x31, 0xe0,
        0x43, 0x5a, 0x31, 0x37,
        0xf6, 0x30, 0x98, 0x07,
        0xa8, 0x8d, 0xa2, 0x34
    };

    unsigned char key2[ 16 ] = {
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    memcpy(state, state2, 16);
    memcpy(key, key2, 16);
    */

    return 0;
}

/*
================
classAES::InputForDecrypt
0 - normal exit
1 - text's size is NOT A MULTIPLY OF 32
2 - inputkey's size is more than 16
3 - inputkey's size is null
================
*/
int classAES::InputForDecrypt(string textReceived, string inputkey)
{
    int i;

    if (inputkey.size() > 16) {
        return 2;
    }
    else if (inputkey.size() == 0) {
        return 3;
    }
    else {
        for (i = inputkey.size(); i < 16; i++) {
            inputkey += '\0';
        }
    }

    if (textReceived.size()%32 != 0 || textReceived.size() == 0) {
        return 1;
    }
    else {
        text = textReceived;
    }

    memcpy(key, inputkey.c_str(), 16);

    /*
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    // uncomment this and comment everything above in this function
    // if you want to test the example in aes flash animation
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    unsigned char state2[ 16 ] = {
        0x39, 0x02, 0xdc, 0x19,
        0x25, 0xdc, 0x11, 0x6a,
        0x84, 0x09, 0x85, 0x0b,
        0x1d, 0xfb, 0x97, 0x32
    };

    unsigned char key2[ 16 ] = {
        0x2b, 0x28, 0xab, 0x09,
        0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f,
        0x16, 0xa6, 0x88, 0x3c
    };

    memcpy(state, state2, 16);
    memcpy(key, key2, 16);
    */

    return 0;
}

/*
================
classAES::Encrypt
Retruns encrypted text.
State should already be input
================
*/
std::string classAES::Encrypt()
{
    int i;
    int j;
    string result;

    for (j = 0; j < (int)text.size()/16; j++) {
        // copy 16 bytes into state
        memcpy(state, text.c_str() + 16*j, 16);

        // algorithm
        GenKeys();

        AddRoundKey( key[ 0 ] );

        for ( i = 0; i < 10; i++ ) {
            SubBytes();
            ShiftRows();
            if ( i != 9 ) {
                MixColumns();
            }
            AddRoundKey( key[ i + 1 ] );
        }

        // receive from state here!!!
        result += GetResult();
    }

    return result;
}

/*
================
classAES::Decrypt
Retruns decrypted text.
Encrypted text should already be input
================
*/
std::string classAES::Decrypt()
{
    unsigned int i;
    unsigned int j;
    string result;


    for (j = 0; j < text.size()/32; j++) {
        // copy to state
        for (i = 0; i < 16; i++) {
            // copy 16 bytes into state
            // --- left char ---
            // if letter
            if ( text.c_str()[ i*2 + j*16*2 + 1 ] <= 'F' && text.c_str()[ i*2 + j*16*2 + 1 ] >= 'A' ) {
                state[ i ] = text.c_str()[ i*2 + j*16*2 + 1 ] - 'A' + 10;
            }
            // if number
            else if ( text.c_str()[ i*2 + j*16*2 + 1 ] <= '9' && text.c_str()[ i*2 + j*16*2 + 1 ] >= '0' ) {
                state[ i ] = text.c_str()[ i*2 + j*16*2 + 1 ] - '0';
            }

            // --- right char ---
            // if letter
            if ( text.c_str()[ i*2 + j*16*2 ] <= 'F' && text.c_str()[ i*2 + j*16*2 ] >= 'A' ) {
                state[ i ] += 16 * (text.c_str()[ i*2 + j*16*2 ] - 'A' + 10);
            }
            // if number
            else if ( text.c_str()[ i*2 + j*16*2 ] <= '9' && text.c_str()[ i*2 + j*16*2 ] >= '0' ) {
                state[ i ] += 16 * (text.c_str()[ i*2 + j*16*2 ] - '0');
            }
        }

        // algorithm
        GenKeys();

        for (i = 10; i > 0; i--)
        {
            AddRoundKey( key[ i ] );
            if( i != 10 ) {
                MixColumnsInverse();
            }
            ShiftRowsInverse();
            SubBytesInverse();
        }

        AddRoundKey( key[ i ] );

        // receive from state here!!!
        result += GetResultText();
    }

    // find first 0x00
    for ( i = 0; i < result.size(); i++ ) {
        if ( result.c_str()[ i ] == '\0' ) {
            break;
        }
    }

    // delete 0x00's at the end
    result.erase(result.size() - (j*16 - i));

    return result;
}

//================================================================================
//                      PRIVATES MEMBERS BELOW
//================================================================================
/*
================
classAES::GetResult
Returns state[] as hex string
================
*/
string classAES::GetResult()
{
    char converted[100];
    int i;

    for( i = 0; i < 16; i++) {
        sprintf(&converted[ i * 2 ], "%02X", state[ i ]);
    }
    converted[ i * 2 ] = '\0';

    string result(converted);
    return result;
}

/*
================
classAES::GetResultText
Returns state[] as plaintext string
================
*/
string classAES::GetResultText()
{
    string result(state, state + 16);
    return result;
}

/*
================
classAES::SubBytes
1
================
*/
void classAES::SubBytes()
{
    unsigned char x, y;
    int i;
    for ( i = 0; i < 16; i++ ) {
        x = state[ i ] >> 4;
        y = state[ i ] & 0x0F;
        state[ i ] = sbox[ y + x * 16 ];
    }
}

/*
================
classAES::SubBytesInverse
~1
================
*/
void classAES::SubBytesInverse()
{
    unsigned char x, y;
    int i;
    for ( i = 0; i < 16; i++ ) {
        x = state[ i ] >> 4;
        y = state[ i ] & 0x0F;
        state[ i ] = sboxinverse[ y + x * 16 ];
    }
}

/*
================
classAES::ShiftRows
2
================
*/
void classAES::ShiftRows()
{
    unsigned char temp;

    // SHIFT RIGHT

    // 4 5 6 7
    // to
    // 5 6 7 4
    temp = state[ 4 ];
    state[ 4 ] = state[ 5 ];
    state[ 5 ] = state[ 6 ];
    state[ 6 ] = state[ 7 ];
    state[ 7 ] = temp;

    // 8  9  10 11
    // to
    // 10 11 8  9
    temp = state[ 8 ];
    state[ 8 ] = state[ 10 ];
    state[ 10 ] = temp;
    temp = state[ 9 ];
    state[ 9 ] = state[ 11 ];
    state[ 11 ] = temp;

    // 12 13 14 15
    // to
    // 15 12 13 14
    temp = state[ 12 ];
    state[ 12 ] = state[ 15 ];
    state[ 15 ] = state[ 14 ];
    state[ 14 ] = state[ 13 ];
    state[ 13 ] = temp;
}

/*
================
classAES::ShiftRowsInverse
~2
================
*/
void classAES::ShiftRowsInverse()
{
    unsigned char temp;

    // SHIFT LEFT

    // 4 5 6 7
    // to
    // 7 4 5 6
    temp = state[ 7 ];
    state[ 7 ] = state[ 6 ];
    state[ 6 ] = state[ 5 ];
    state[ 5 ] = state[ 4 ];
    state[ 4 ] = temp;

    // 8  9  10 11
    // to
    // 10 11 8  9
    temp = state[ 8 ];
    state[ 8 ] = state[ 10 ];
    state[ 10 ] = temp;
    temp = state[ 9 ];
    state[ 9 ] = state[ 11 ];
    state[ 11 ] = temp;

    // 12 13 14 15
    // to
    // 13 14 15 12
    temp = state[ 12 ];
    state[ 12 ] = state[ 13 ];
    state[ 13 ] = state[ 14 ];
    state[ 14 ] = state[ 15 ];
    state[ 15 ] = temp;
}

/*
================
classAES::MixColumns
3
Mulitplies state by this matrix
  2 3 1 1
  1 2 3 1
  1 1 2 3
  3 1 1 2
================
*/
void classAES::MixColumns()
{
    int j;
    unsigned char temp[ 16 ];
    for ( j = 0; j < 4; j++ ) { // j is COLUMN
        temp[0 + j] =
                table_2[state[0 + j]] ^
                table_3[state[4 + j]] ^
                state[8 + j] ^
                state[12 + j];
        temp[4 + j] =
                state[0 + j] ^
                table_2[state[4 + j]] ^
                table_3[state[8 + j]] ^
                state[12 + j];
        temp[8 + j] =
                state[0 + j] ^
                state[4 + j] ^
                table_2[state[8 + j]] ^
                table_3[state[12 + j]];
        temp[12 + j] =
                table_3[state[0 + j]] ^
                state[4 + j] ^
                state[8 + j] ^
                table_2[state[12 + j]];
    }
    memcpy(state, temp, 16);
}

/*
================
classAES::MixColumnsInverse
~3
Multiplies state by:
  14 11 13 9
  9  14 11 13
  13 9  14 11
  11 13 9  14
================
*/
void classAES::MixColumnsInverse()
{
    int j;
    unsigned char temp[ 16 ];
    for ( j = 0; j < 4; j++ ) { // j is COLUMN
        temp[0 + j] =
                table_14[state[0 + j]] ^
                table_11[state[4 + j]] ^
                table_13[state[8 + j]] ^
                table_9[state[12 + j]];
        temp[4 + j] =
                table_9[state[0 + j]] ^
                table_14[state[4 + j]] ^
                table_11[state[8 + j]] ^
                table_13[state[12 + j]];
        temp[8 + j] =
                table_13[state[0 + j]] ^
                table_9[state[4 + j]] ^
                table_14[state[8 + j]] ^
                table_11[state[12 + j]];
        temp[12 + j] =
                table_11[state[0 + j]] ^
                table_13[state[4 + j]] ^
                table_9[state[8 + j]] ^
                table_14[state[12 + j]];
    }
    memcpy(state, temp, 16);
}

/*
================
classAES::AddRoundKey
4
================
*/
void classAES::AddRoundKey( unsigned char * k )
{
    int i;
    for ( i = 0; i < 16; i++ ) {
        state[ i ] = state[ i ] ^ k[ i ];
    }
}

/*
================
classAES::GenKeys
Generates 10 keys from initial key for each round
================
*/
void classAES::GenKeys()
{
    // column0
    unsigned char t;
    unsigned char temp[ 4 ];
    unsigned char x, y;
    int i, j;

    for ( j = 0; j < 10; j++ ) {
        // copy
        temp[ 0 ] = key[ j ][ 3 ];
        temp[ 1 ] = key[ j ][ 7 ];
        temp[ 2 ] = key[ j ][ 11 ];
        temp[ 3 ] = key[ j ][ 15 ];

        // rotword
        t = temp[ 0 ];
        temp[ 0 ] = temp[ 1 ];
        temp[ 1 ] = temp[ 2 ];
        temp[ 2 ] = temp[ 3 ];
        temp[ 3 ] = t;

        // subbytes
        for ( i = 0; i < 4; i++ ) {
            x = temp[ i ] >> 4;
            y = temp[ i ] & 0x0F;
            temp[ i ] = sbox[ y + x * 16 ];
        }

        // xor with 2 others
        temp[ 0 ] = temp[ 0 ] ^ key[ j ][ 0 ] ^ rcon[ j + 0 ];
        temp[ 1 ] = temp[ 1 ] ^ key[ j ][ 4 ];
        temp[ 2 ] = temp[ 2 ] ^ key[ j ][ 8 ];
        temp[ 3 ] = temp[ 3 ] ^ key[ j ][ 12 ];

        // write temp to column
        key[ j + 1 ][ 0 ] = temp[ 0 ];
        key[ j + 1 ][ 4 ] = temp[ 1 ];
        key[ j + 1 ][ 8 ] = temp[ 2 ];
        key[ j + 1 ][ 12 ] = temp[ 3 ];

        /*
         *  0  1  2  3
         *  4  5  6  7
         *  8  9 10 11
         * 12 13 14 15
         */
        // columns 1 to 3
        for ( i = 0; i < 3; i++ ) {
            key[ j + 1 ][ i + 1 ]  = key[ j ][ i + 0 + 1 ] ^ key[ j + 1 ][ i + 0 ];
            key[ j + 1 ][ i + 5 ]  = key[ j ][ i + 4 + 1 ] ^ key[ j + 1 ][ i + 4 ];
            key[ j + 1 ][ i + 9 ]  = key[ j ][ i + 8 + 1 ] ^ key[ j + 1 ][ i + 8 ];
            key[ j + 1 ][ i + 13 ] = key[ j ][ i + 12+ 1 ] ^ key[ j + 1 ][ i + 12 ];
        }
    }
}
