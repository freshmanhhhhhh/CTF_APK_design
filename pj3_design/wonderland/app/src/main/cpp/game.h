//ysh push_box
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool check(char* c);
void InitializeMap(int map[255][255], int box[255][2], int WIDTH, int LENGTH, int BOX,int* p);
bool printMap(int map[255][255], int box[255][2], int dir, int WIDTH, int LENGTH, int BOX, int* player);

int validMove(int map[255][255], int* player, int dir, int WIDTH, int LENGTH, int DIR[5][2]);
int isThereabox(int map[255][255], int* player, int box[255][2], int dir, int DIR[5][2], int BOX);
int moveBox(int map[255][255], int* player, int box[255][2], int dir, int WIDTH, int LENGTH, int DIR[5][2], int BOX);


bool check(char* chars) {
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

    int WIDTH = 8, LENGTH = 8, BOX = 4;
    int box[255][2];
    int map[255][255];

    //judge flag format
    int len = strlen(chars);
    //printf("total len is %d \n", len);
    /*if (chars[0] != 'f' || chars[1] != 'l' || chars[2] != 'a' || chars[3] != 'g' || chars[4] != '{' || chars[len - 1] != '}')
        return false;*/
    /*if(chars[0] == 'f' && chars[1] == 'l' && chars[2] == 'a' && chars[3] == 'g' && chars[4] == '{' && chars[len - 1] == '}'){
        return true;
    }*/
    //no step number restriction!!!!!

    //Playing
    //初始化地图
    //1.map needs 10 steps
    InitializeMap(map, box, WIDTH, LENGTH, BOX, p);

    //judge
    int i = 5;
    int dir = 4;
    char c;
    bool flag = false;
    while (i < len - 1) {
        c = chars[i++];
        switch (c) {
            case 'w':
                dir = 0;
                break;
            case 's':
                dir = 1;
                break;
            case 'a':
                dir = 2;
                break;
            case 'd':
                dir = 3;
                break;
            default:
                dir = 4;//other input the player will stand still
        }
        if (moveBox(map, p, box, dir,WIDTH, LENGTH, DIR, BOX)) {}
        else if (validMove(map, p, dir, WIDTH, LENGTH, DIR)) {
            p[0] += DIR[dir][0];
            p[1] += DIR[dir][1];
        }

        flag = printMap(map, box, dir,WIDTH, LENGTH, BOX, p);//无需打印地图，可以优化
    }
    if (flag)
        return true;
    return false;
}

void InitializeMap(int map[255][255], int box[255][2], int WIDTH, int LENGTH, int BOX,int* p) {
    //FILE* fp = NULL;
    int buff[255][255] = {
            {0,0,0,1,1,1,0,0},
            {0,0,0,1,4,1,0,0},
            {1,1,1,1,3,1,0,0},
            {1,4,2,3,5,1,1,1},
            {1,1,1,3,2,3,4,1},
            {0,0,1,2,1,1,1,1},
            {0,0,1,4,1,0,0,0},
            {0,0,1,1,1,0,0,0},
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
            ch = map[i][j] = buff[i][j];// - '0';
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
    //fclose(fp);
}

bool printMap(int map[255][255], int box[255][2], int dir, int WIDTH, int LENGTH, int BOX, int* player) {
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

/*int isOutOfRange(Position p) {
    if (p[0] < 0 || p[1] < 0 || p[0] >= LENGTH || p[1] >= WIDTH) {
        return true;
    }
    return false;
}*/

int validMove(int map[255][255], int* player, int dir, int WIDTH, int LENGTH, int DIR[5][2]) {
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

int isThereabox(int map[255][255], int* player, int box[255][2], int dir,int DIR[5][2],int BOX) {
    int shadow[2] = { player[0],player[1] };
    shadow[0] += DIR[dir][0];
    shadow[1] += DIR[dir][1];
    for (int i = 0; i < BOX; i++) {
        if (shadow[0] == box[i][0] && shadow[1] == box[i][1])
            return i;
    }
    return -1;
}

int moveBox(int map[255][255], int* player, int box[255][2], int dir, int WIDTH, int LENGTH, int DIR[5][2], int BOX) {
    int i = isThereabox(map, player, box, dir, DIR, BOX);
    if (i != -1) {
        int activebox[2] = { box[i][0],box[i][1] };
        if (validMove(map, activebox, dir, WIDTH, LENGTH,DIR)) {
            if (isThereabox(map, activebox, box, dir, DIR, BOX) == -1) {
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
