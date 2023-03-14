//
// Created by Ham on 2022/6/6.
//

#ifndef ONE_AES_SIMPLIFIED_H
#define ONE_AES_SIMPLIFIED_H
#include<iostream>
#include<bitset>
#include<string>
typedef std::bitset<8> byte;
typedef std::bitset<32> word;

//种子密钥长度以及扩展轮数
const int Nr = 10;
const int Nk = 4;

//种子密钥
byte Key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
//密码明文flag{reverse_it}
byte code[16] = { 0xd1,0x71,0xf6,0x0,0x3c,0x30,0x64,0xc3,0xb7,0xef,0x73,0x70,0xee,0xf1,0x67,0x6d };
//AES-128轮常量
word rcon[10] = { 0x01000000UL, 0x02000000UL, 0x04000000UL, 0x08000000UL, 0x10000000UL,0x20000000UL, 0x40000000UL, 0x80000000UL, 0x1B000000UL, 0x36000000UL };

word Wdksjeigord(byte b0, byte b1, byte b2, byte b3) {
    word wordres = 0x00000000;
    word temp;
    temp = b0.to_ulong();//b0
    temp <<= 24;
    wordres |= temp;
    temp = b1.to_ulong();//b1
    temp <<= 16;
    wordres |= temp;
    temp = b2.to_ulong();//b2
    temp <<= 8;
    wordres |= temp;
    temp = b3.to_ulong();//b0
    wordres |= temp;
    return wordres;
}


void KksodeyExpadefGnsksIion(byte key[4 * Nk], word w[4 * (Nr + 1)]) {
    word temp;
    int i = 0;
    while (i < Nk) {
        w[i] = Wdksjeigord(key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3]);
        i++;
    }
    i = Nk;
    while (i < 4 * (Nr + 1)) {
        temp = w[i - 1];
        if (i % Nk == 0)
            w[i] = w[i - Nk] ^ rcon[i / Nk - 1];
        else
            w[i] = w[i - Nk] ^ temp;
        i++;
    }
}

void RbdgKeesdgyAkddod(byte sta_matr[4 * 4], word w[4]) {
    for (int i = 0; i < 4; i++) {
        word k0 = w[i] >> 24;
        word k1 = (w[i] << 8) >> 24;
        word k2 = (w[i] << 16) >> 24;
        word k3 = (w[i] << 24) >> 24;

        sta_matr[i] = sta_matr[i] ^ byte(k0.to_ulong());
        sta_matr[i + 4] = sta_matr[i + 4] ^ byte(k1.to_ulong());
        sta_matr[i + 8] = sta_matr[i + 8] ^ byte(k2.to_ulong());
        sta_matr[i + 12] = sta_matr[i + 12] ^ byte(k3.to_ulong());
    }
}

void ShIkdowhftRkdiwOjoiwhbw(byte sta_matr[4 * 4]) {
    for (int i = 0; i < 4; i++) {
        byte temp[4];
        for (int j = 0; j < i; j++)
            temp[j] = sta_matr[i * 4 + j];
        for (int j = 0; j < 4 - i; j++)
            sta_matr[i * 4 + j] = sta_matr[i * 4 + j + i];
        for (int m = 4 - i; m < 4; m++)
            sta_matr[i * 4 + m] = temp[m + i - 4];
    }
}

void jaorBkcxDfg(byte sta_matr[4 * 4], word w[4 * (Nr + 1)]) {
    word key[4];
    for (int i = 0; i < 4; i++)
        key[i] = w[i];
    RbdgKeesdgyAkddod(sta_matr, key);
    for (int r = 1; r <= Nr; r++) {
        ShIkdowhftRkdiwOjoiwhbw(sta_matr);
        for (int i = 0; i < 4; i++)
            key[i] = w[4 * r + i];
        RbdgKeesdgyAkddod(sta_matr, key);
    }
}


bool checkstr(std::string input) {
    if (input.length() != 16)
        return false;

    word w[4 * (Nr + 1)];
    KksodeyExpadefGnsksIion(Key, w);

    byte strin[16];
    for (int i = 0; i != 16; i++)
        strin[i] = input[i];
    jaorBkcxDfg(strin, w);
    for (int i = 0; i != 16; i++)
        if (strin[i] != code[i])
            return false;
    return true;
}


#endif //ONE_AES_SIMPLIFIED_H
