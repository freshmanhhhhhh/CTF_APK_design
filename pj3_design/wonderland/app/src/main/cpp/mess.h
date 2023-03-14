//ysh push_box_obfuscated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool djiehiu(char* c);
void Jogoheuibwnr(int map[12][12], int box[255][2], int WIDTH, int LENGTH, int BOX,int* p);
bool jwhbiriwrnwjoqj(int map[12][12], int box[255][2], int dir, int WIDTH, int LENGTH, int BOX, int* player);

int jwehuibipjohio(int map[12][12], int* player, int dir, int WIDTH, int LENGTH, int DIR[5][2]);
int jwiubhiwbhwb(int map[12][12], int* player, int box[255][2], int dir, int DIR[5][2], int BOX);
int iojugyub(int map[12][12], int* player, int box[255][2], int dir, int WIDTH, int LENGTH, int DIR[5][2], int BOX);

//3.map
//flag{wdddsdwawdasaawwwdwdddddssswwawaaaaassssdddddsddwaaaasaawdsdw} obsoleted
//flag{!###_#!*!#*_**!!!#!#####___!!*!*****____#####_##!****_**!#_#!} obsoleted
bool djiehiu(char* chars) {//check
    /* 表示位置的数组 */
    //typedef int Position[2];
    int p[2];

    /* 位移向量 */
    int DIR[5][2] = {
            {-1,0},             /* UP */
            {1,0},              /* DOWN */
            {0,-1},             /* LEFT */
            {0,1},              /* RIGHT */
            {0,0}               /* SITU */
    };

    //constant unfold
    int WIDTH = 2, LENGTH = 9, BOX = 0;
    int a=WIDTH,b=LENGTH, c=BOX;
    int r = abs(random())%100;
    a = a+b+(r%11-((r%10-r/10)%11)+1)%11-1;//11
    c = a+r;c=c-b;c=c-r;//2
    b += (r%11-((r%10-r/10)%11))%11;//9
    WIDTH = a; LENGTH = b; BOX = c;

    int box[255][2];
    int map[12][12];

    //restrict the length
    int len = strlen(chars);

    Jogoheuibwnr(map, box, WIDTH, LENGTH, BOX, p);

    //judge
    int i = 5;
    int dir = 4;
    char ch;
    bool flag = false;
    while (i < len - 1) {
        ch = chars[i++];
        switch (ch) {
            case '!'://'w':
                dir = i*(i+1)*(i+2)*(i+3)%2;//0;
                break;
            case '_'://'s':
                int z ;
                z = i%100;
                dir = (z%11-((z%10-z/10)%11)+1)%11;//1
                break;
            case '*'://'a':
                dir = i*i*(i+1)*(i+1)%4+2;//2
                break;
            case '#'://'d':
                dir = i%2+(i+1)%2+(i+2)%2+(i+3)%2+(i+4)%2+(i+5)%2;//3
                break;
                //obfuscation
            case '@':
                dir = i*(i+1)%2+4;
                break;
            case '$':
                dir = i%2+(i+1)%2+(i+2)%2+(i+3)%2+(i+4)%2+(i+5)%2 + (i+6)%2+(i+7)%2;//4
                break;
            case '%':
                dir = (z%11-((z%10-z/10)%11)+4)%11;//4
                break;
            case '^':
                dir = i%2+(i+1)%2+(i+2)%2+(i+3)%2 +2;//4
                break;
            case '&':
                dir = (int)(((char)(i%255)|0xff)^0xfb);//4
                break;
            case '+' :
                dir = (((char)(i%255)&0x00)^0x34)-'0';//4
            default://other input the player will stand still
                int m = dir%4;
                dir = 4 - m + i; dir = dir + m; dir = dir + i ;//4
        }
        if (iojugyub(map, p, box, dir,WIDTH, LENGTH, DIR, BOX)) {}
        else if (jwehuibipjohio(map, p, dir, WIDTH, LENGTH, DIR)) {
            p[0] += DIR[dir][0];
            p[1] += DIR[dir][1];
        }

        flag = jwhbiriwrnwjoqj(map, box, dir,WIDTH, LENGTH, BOX, p);//无需打印地图，可以优化
    }
    if (flag)
        return true;
    return false;
}

void Jogoheuibwnr(int map[12][12], int box[255][2], int WIDTH, int LENGTH, int BOX,int* p) {
    //FILE* fp = NULL;
    int buff[12][12] = {//3.map
            {0,1,1,1,1,1,1,1,1,1,0},
            {0,1,2,2,1,1,1,2,2,1,0},
            {0,1,2,2,2,2,2,2,2,1,0},
            {0,1,2,1,1,1,1,1,3,1,0},
            {0,1,2,1,1,1,1,1,2,1,0},
            {1,1,2,1,4,1,4,1,2,1,1},
            {1,2,2,2,3,2,2,2,2,2,1},
            {1,2,2,2,5,1,2,2,2,2,1},
            {1,1,1,1,1,1,1,1,1,1,1},
    };
    //fp = fopen("1.map", "r");////注意修改
    //fscanf(fp, "%d %d %d", &WIDTH, &LENGTH, &BOX);
    //printf("%d %d %d\n", WIDTH, LENGTH, BOX);

    int i, j, k = 0, ch;
    /*for (i = 0; i < LENGTH; i++) {
        fscanf(fp, "%s", buff[i]);
        //printf("%s\n", buff[i]);
    }*/
    for (i = 0; i < LENGTH; i++) {
        for (j = 0; j < WIDTH; j++) {
            ch = map[i][j] = buff[i][j] ;
            if (ch == 3 || ch == 6) {
                box[k][0] = i; box[k][1] = j;
                k++;
                if (ch == 6)
                    map[i][j] = 4;
                else
                    map[i][j] = 2;
            }
            if (ch == 5 || ch == 7) {
                p[0] = i; p[1] = j;
                if (ch == 7)
                    map[i][j] = 4;
                else
                    map[i][j] = 2;
            }
        }
    }
}

bool jwhbiriwrnwjoqj(int map[12][12], int box[255][2], int dir, int WIDTH, int LENGTH, int BOX, int* player) {
    int i, j, count = 0;
    for (i = 0; i < LENGTH; i++) {
        for (j = 0; j < WIDTH; j++) {
            int ch = map[i][j];
            if (player[0] == i && player[1] == j) {
                if (ch == 4)
                    ch = 7;
                else
                    ch = 5;
            }
            for (int k = 0; k < BOX; k++) {
                if (box[k][0] == i && box[k][1] == j) {
                    if (ch == 4) {
                        ch = 6;
                        count++;
                    }
                    else
                        ch = 3;
                }
            }
            //printf("%s", symbols[ch]);
        }
        //printf("\n");
    }
    if (count == BOX)
        return true;
    else
        return false;
}

int jwehuibipjohio(int map[12][12], int* player, int dir, int WIDTH, int LENGTH, int DIR[5][2]) {
    int shadow[2] = { player[0],player[1] };
    shadow[0] += DIR[dir][0];
    shadow[1] += DIR[dir][1];
    if (shadow[0] < 0 || shadow[1] < 0 || shadow[0] >= LENGTH || shadow[1] >= WIDTH) {
        return false;
    }
    if (map[shadow[0]][shadow[1]] == 1 || map[shadow[0]][shadow[1]] == 6) {
        return false;
    }
    return true;
}

int jwiubhiwbhwb(int map[12][12], int* player, int box[255][2], int dir,int DIR[5][2],int BOX) {
    int shadow[2] = { player[0],player[1] };
    shadow[0] += DIR[dir][0];
    shadow[1] += DIR[dir][1];
    for (int i = 0; i < BOX; i++) {
        if (shadow[0] == box[i][0] && shadow[1] == box[i][1])
            return i;
    }
    return -1;
}

int iojugyub(int map[12][12], int* player, int box[255][2], int dir, int WIDTH, int LENGTH, int DIR[5][2], int BOX) {
    int i = jwiubhiwbhwb(map, player, box, dir, DIR, BOX);
    if (i != -1) {
        int activebox[2] = { box[i][0],box[i][1] };
        if (jwehuibipjohio(map, activebox, dir, WIDTH, LENGTH,DIR)) {
            if (jwiubhiwbhwb(map, activebox, box, dir, DIR, BOX) == -1) {
                player[0] += DIR[dir][0];
                player[1] += DIR[dir][1];
                box[i][0] += DIR[dir][0];
                box[i][1] += DIR[dir][1];
            }
        }
        return 1;
    }
    return 0;
}



