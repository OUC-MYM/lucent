#include "uselei.h"
#include <stdio.h>
#include "main.h"
#include <iostream>
#include <queue>
using namespace std;

giveplayer ss;

int initin(int ks[100000])
{
    ss.food.x=ks[0];
    ss.food.y=ks[1];
    ss.mpsize=ks[4];
    for(int i=0; i<40; i++)
    {
        for(int j=0; j<40; j++)
        {
            ss.smap[i][j]=ks[40+i*40+j];
        }
    }
    ss.p1.tail=ks[2000];
    ss.p1.head=ks[2002];
    ss.p1.bodylen=ks[2005];
    for(int i=0; i<76; i++)
    {
        ss.p1.body[i].x=ks[2006+2*i];
        ss.p1.body[i].y=ks[2006+2*i+1];
    }
    ss.p2.tail=ks[3000];
    ss.p2.head=ks[3002];
    ss.p2.bodylen=ks[3005];

    for(int i=0; i<76; i++)
    {
        ss.p2.body[i].x=ks[3006+2*i];
        ss.p2.body[i].y=ks[3006+2*i+1];
    }
    return 0;
}

int mapp[50][30][30];
bool snack2_exist=1;     //1为存在

bool find_snack2()
{
    for(int i=0; i<ss.p2.bodylen; i++)
        if(mapp[0][ss.p2.body[i].x][ss.p2.body[i].y]!=1)
            return false;
    return true;
}

int player_1(int ks[100000])
{
    initin(ks);   //就是在这里调用一下初始函数。
    //在这里写大家的程序，直接运用ss即可。
    //比如想获知食物坐标的时候，为：ss.food.x ,ss.food.y
    cout<<ss.mpsize << endl;
    //地图
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++)
            mapp[0][i][j]=ss.smap[i][j];

    snack2_exist = find_snack2();
    if(snack2_exist)
        for(int i=0; i<ss.p2.bodylen; i++)
            mapp[0][ss.p2.body[i].x][ss.p2.body[i].y]=3;


    for(int i=0; i<30; i++)
    {
        for(int j=0; j<30; j++)
            cout << mapp[0][i][j];
        cout << endl;
    }
    int dir;

    cin >> dir;
    cout << dir << endl;
    if(dir==6)
        return 1;
    if(dir==2)
        return 2;
    if(dir==4)
        return 3;
    if(dir==8)
        return 0;

}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // succesful
}
