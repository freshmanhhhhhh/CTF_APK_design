//ysh xor fakeflag
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool djiehiuyeah(char* c,int len){
    if(len!=14)
        return false;
    char chars[]={0x66,0x60,0x69,0x66,0x62,0x69,0x67,0x60};//"f`ifbig`";
    for(int i=5;i<len-1;i++){
        c[i]^=i;
    }
    if(strcmp(c,chars))
        return true;
    return false;
}
