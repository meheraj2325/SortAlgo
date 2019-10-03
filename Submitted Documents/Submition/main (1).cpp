#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<iostream>
#include<ctime>
#include<algorithm>

using namespace std;

struct coordinate
{
    int x1;
    int y1;
    int x2;
    int y2;
};
FILE *f;
struct coordinate bubble[20];

int n,a[20],flag=1;
char c[6];
int maxx,maxy,maxx1,maxy1;

void bubble_sort();
void selection_sort();
void insertion_sort();
void bubble_manual_1();
void bubble_manual_2();
void selection_manual_1();
void selection_manual_2();
void insertion_manual_1();
void insertion_manual_2();
void bubble_pseudocode();
void selection_pseudocode();
void insertion_pseudocode();

int main()
{
    initwindow(800,600,"SortAlgo",50,50);
    readimagefile("First.jpg",0,0,800,600);
    do
    {
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);
    }
    while(maxx<=611 && maxx>=781 && maxy<=489 && maxy>=575);
    if(maxx>=611 && maxx<=781 && maxy>=489 && maxy<=575)
    {
        delay(50);
        cleardevice();
again:
        readimagefile("Main menu.jpg",0,0,800,600);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);
        if(maxx>=171 && maxx<=608 && maxy>=166 && maxy<=234)
        {
            delay(50);
            cleardevice();
            readimagefile("Bubble1.jpg",0,0,800,600);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);
            if(maxx>=141 && maxx<=650 && maxy>=184 && maxy<=247)
            {
                bubble_sort();
                delay(1000);
                goto again;
            }
            else if(maxx>=141 && maxx<=650 && maxy>=290 && maxy<=355)
            {
                bubble_manual_1();
                if(flag!=0)
                {
                    delay(1000);
                    bubble_manual_2();
                }
                delay(1000);
                cleardevice();
                goto again;
            }
            else if(maxx>=571 && maxx<=772 && maxy>=520 && maxy<=574)
            {
                delay(50);
                cleardevice();
                goto again;
            }
        }
        else if(maxx>=174 && maxx<=610 && maxy>=276 && maxy<=348)
        {
            delay(50);
            cleardevice();
            readimagefile("Selection1.jpg",0,0,800,600);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);
            if(maxx>=135 && maxx<=649 && maxy>=182 && maxy<=247)
            {
                selection_sort();
                delay(1000);
                goto again;
            }
            else if(maxx>=141 && maxx<=649 && maxy>=290 && maxy<=358)
            {
                selection_manual_1();
                if(flag!=0)
                {
                    delay(1000);
                    selection_manual_2();
                }
                delay(1000);
                cleardevice();
                goto again;
            }
            else if(maxx>=565 && maxx<=763 && maxy>=515 && maxy<=575)
            {
                delay(50);
                cleardevice();
                goto again;
            }
        }
        else if(maxx>=171 && maxx<=608 && maxy>=383 && maxy<=458)
        {
            delay(50);
            cleardevice();
            readimagefile("Insertion1.jpg",0,0,800,600);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);
            if(maxx>=141 && maxx<=649 && maxy>=177 && maxy<=247)
            {
                insertion_sort();
                delay(1000);
                goto again;
            }
            else if(maxx>=141 && maxx<=649 && maxy>=287 && maxy<=355)
            {
                insertion_manual_1();
                if(flag!=0)
                {
                    delay(1000);
                    insertion_manual_2();
                }
                delay(1000);
                cleardevice();
                goto again;
            }
            else if(maxx>=565 && maxx<=763 && maxy>=519 && maxy<=575)
            {
                delay(50);
                cleardevice();
                goto again;
            }
        }
        else if(maxx>=627 && maxx<=763 && maxy>=533 && maxy<=573)
        {
            closegraph();
        }
    }
}

void bubble_sort()
{
    f=fopen("inputx.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=75;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=480-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=500;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        settextstyle(BOLD_FONT,0,5);
        outtextxy(36,27,"Bubble Sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,515,c);
    }
    bubble_pseudocode();
    delay(50);

    for(int k=0; k<n-1; k++)
    {
        for(int i=0; i<n-k-1; i++)
        {
            if(a[i]>a[i+1])
            {

                for(int j=1; j<=45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    bubble_pseudocode();
                    settextstyle(BOLD_FONT,0,5);
                    outtextxy(36,27,"Bubble sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[i].x1+j,bubble[i].y1,bubble[i].x2+j,bubble[i].y2);
                    setfillstyle(1,LIGHTRED);
                    floodfill(bubble[i].x1+5+j,bubble[i].y1+5,WHITE);
                    rectangle(bubble[i+1].x1-j,bubble[i+1].y1,bubble[i+1].x2-j,bubble[i+1].y2);
                    setfillstyle(1,LIGHTRED);
                    floodfill(bubble[i+1].x1+5-j,bubble[i+1].y1+5,WHITE);
                    setfillstyle(1,BLUE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=i && l!=i+1)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,515,c);
                        }
                    }
                    sprintf(c,"%d",a[i]);
                    outtextxy(bubble[i].x1+15+j,515,c);
                    sprintf(c,"%d",a[i+1]);
                    outtextxy(bubble[i+1].x1+15-j,515,c);
                }
                swap(bubble[i].y1,bubble[i+1].y1);
                swap(bubble[i].y2,bubble[i+1].y2);
                swap(a[i],a[i+1]);
            }
            delay(500);
        }
    }
    settextstyle(BOLD_FONT,0,3);
    outtextxy(65,550,"Rectangles are sorted according to numbers.");
    settextstyle(0,0,0);
}

void selection_sort()
{
    int i, j, min_indx;
    f=fopen("inputx.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=70;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=480-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=500;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    for(i=0; i<n; i++)
    {
        settextstyle(BOLD_FONT,0,5);
        outtextxy(26,27,"Selection Sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,515,c);
    }
    selection_pseudocode();
    delay(50);
    for (i = 0; i < n-1; i++)
    {
        min_indx = i;
        for (j = i+1; j < n; j++)
        {
            if (a[j] < a[min_indx])
            {
                min_indx = j;
            }
        }
        for( j=1; j<=((min_indx-i)*45); j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            selection_pseudocode();
            rectangle(bubble[i].x1+j,bubble[i].y1,bubble[i].x2+j,bubble[i].y2);
            setfillstyle(1,LIGHTRED);
            floodfill(bubble[i].x1+5+j,bubble[i].y1+5,WHITE);
            rectangle(bubble[min_indx].x1-j,bubble[min_indx].y1,bubble[min_indx].x2-j,bubble[min_indx].y2);
            setfillstyle(1,LIGHTRED);
            floodfill(bubble[min_indx].x1+5-j,bubble[min_indx].y1+5,WHITE);
            setfillstyle(1,BLUE);
            settextstyle(BOLD_FONT,0,5);
            outtextxy(36,27,"Selection sort");
            settextstyle(0,0,0);
            for(int l=0; l<n; l++)
            {
                if(l!=i && l!=min_indx)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,515,c);
                }
            }
            sprintf(c,"%d",a[i]);
            outtextxy(bubble[i].x1+15+j,515,c);
            sprintf(c,"%d",a[min_indx]);
            outtextxy(bubble[min_indx].x1+15-j,515,c);
        }
        swap(bubble[i].y1,bubble[min_indx].y1);
        swap(bubble[i].y2,bubble[min_indx].y2);
        swap(a[min_indx], a[i]);
        delay(500);
    }
    settextstyle(BOLD_FONT,0,3);
    outtextxy(65,550,"Rectangles are sorted according to numbers.");
    settextstyle(0,0,0);
}

void insertion_sort()
{
    int i, key,k,j,l;
    f=fopen("inputx.txt","r");
    fscanf(f,"%d",&n);

    setbkcolor(LIGHTBLUE);

    for(int i=0; i<n; i++)
        fscanf(f,"%d",&a[i]);

    int t=70;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=480-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=500;
        t+=45;
    }
    delay(100);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        settextstyle(BOLD_FONT,0,5);
        outtextxy(36,27,"Insertion Sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,515,c);
    }
    insertion_pseudocode();
    delay(100);

    for(int k=0; k<n; k++)
    {
        int i = k;
        while(i)
        {
            if(a[i]<a[i-1])
            {
                for(int j=1; j<=45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    insertion_pseudocode();
                    settextstyle(BOLD_FONT,0,5);
                    outtextxy(36,27,"Insertion Sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[i].x1-j,bubble[i].y1,bubble[i].x2-j,bubble[i].y2);
                    setfillstyle(1,LIGHTRED);
                    floodfill(bubble[i].x1+5-j,bubble[i].y1+5,WHITE);
                    rectangle(bubble[i-1].x1+j,bubble[i-1].y1,bubble[i-1].x2+j,bubble[i-1].y2);
                    setfillstyle(1,LIGHTRED);
                    floodfill(bubble[i-1].x1+5+j,bubble[i-1].y1+5,WHITE);
                    setfillstyle(1,BLUE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=i && l!=i-1)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,515,c);
                        }
                    }
                    sprintf(c,"%d",a[i]);
                    outtextxy(bubble[i].x1+15-j,515,c);
                    sprintf(c,"%d",a[i-1]);
                    outtextxy(bubble[i-1].x1+15+j,515,c);
                }
                swap(bubble[i].y1,bubble[i-1].y1);
                swap(bubble[i].y2,bubble[i-1].y2);
                swap(a[i],a[i-1]);
                sprintf(c,"%d",a[i]);
                outtextxy(bubble[i].x1+15,515,c);
                sprintf(c,"%d",a[i-1]);
                outtextxy(bubble[i-1].x1+15,515,c);
                delay(500);
            }
            else break;
            i--;
        }
        if(k==n-1)
            delay(1000);

    }
        settextstyle(BOLD_FONT,0,3);
    outtextxy(65,550,"Rectangles are sorted according to numbers.");
    settextstyle(0,0,0);
}

void bubble_manual_1()
{
    f=fopen("level 1.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=280-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=300;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,0,5);
    outtextxy((getmaxx()/2)-100,getmaxy()/2,"LEVEL 1");
    settextstyle(0,0,0);
    delay(1000);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Bubble sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }
    settextstyle(1,0,2);
    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
    settextstyle(0,0,0);
    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


    if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Bubble sort");
            settextstyle(0,0,0);
            rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
            floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
            rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
            floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=1 && l!=2)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15+j,315,c);
            sprintf(c,"%d",a[2]);
            outtextxy(bubble[2].x1+15-j,315,c);
        }
        swap(bubble[1].y1,bubble[2].y1);
        swap(bubble[2].y2,bubble[2].y2);
        swap(a[1],a[2]);
    }
    else if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Bubble sort");
            settextstyle(0,0,0);
            rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
            floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
            rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
            floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=1 && l!=2)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15+j,315,c);
            sprintf(c,"%d",a[2]);
            outtextxy(bubble[2].x1+15-j,315,c);
        }
        swap(bubble[1].y1,bubble[2].y1);
        swap(bubble[1].y2,bubble[2].y2);
        swap(a[1],a[2]);

    }
    else
    {
        settextstyle(1,0,5);
        flag=0;
        outtextxy(102,400,"Wrong move.");
        settextstyle(0,0,0);
    }
    if(flag==1)
    {
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on two desired rectangle you want to swap.");
        settextstyle(0,0,0);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

        if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
        {
            for(int j=1; j<=45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Bubble sort");
                settextstyle(0,0,0);
                rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=3 && l!=2)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[2]);
                outtextxy(bubble[2].x1+15+j,315,c);
                sprintf(c,"%d",a[3]);
                outtextxy(bubble[3].x1+15-j,315,c);
            }
            swap(bubble[3].y1,bubble[2].y1);
            swap(bubble[3].y2,bubble[2].y2);
            swap(a[3],a[2]);

        }
        else if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
        {
            for(int j=1; j<=45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Bubble sort");
                settextstyle(0,0,0);
                rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=3 && l!=2)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[2]);
                outtextxy(bubble[2].x1+15+j,315,c);
                sprintf(c,"%d",a[3]);
                outtextxy(bubble[3].x1+15-j,315,c);
            }
            swap(bubble[3].y1,bubble[2].y1);
            swap(bubble[3].y2,bubble[2].y2);
            swap(a[3],a[2]);
        }
        else
        {
            settextstyle(1,0,5);
            flag=0;
            outtextxy(102,400,"Wrong move.");
            settextstyle(0,0,0);
        }

        if(flag==1)
        {
            settextstyle(1,0,2);
            outtextxy(102,150,"Click on two  desired rectangle you want to swap.");
            settextstyle(0,0,0);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

            if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
            {
                for(int j=1; j<=45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Bubble sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                    floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                    rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                    floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=3 && l!=4)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[3]);
                    outtextxy(bubble[3].x1+15+j,315,c);
                    sprintf(c,"%d",a[4]);
                    outtextxy(bubble[4].x1+15-j,315,c);
                }
                swap(bubble[3].y1,bubble[4].y1);
                swap(bubble[3].y2,bubble[4].y2);
                swap(a[3],a[4]);
            }
            else if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
            {
                for(int j=1; j<=45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Bubble sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                    floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                    rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                    floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=3 && l!=4)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[3]);
                    outtextxy(bubble[3].x1+15+j,315,c);
                    sprintf(c,"%d",a[4]);
                    outtextxy(bubble[4].x1+15-j,315,c);
                }
                swap(bubble[3].y1,bubble[4].y1);
                swap(bubble[3].y2,bubble[4].y2);
                swap(a[3],a[4]);
            }
            else
            {
                settextstyle(1,0,5);
                flag=0;
                outtextxy(102,400,"Wrong move.");
                settextstyle(0,0,0);
            }

            if(flag==1)
            {
                settextstyle(1,0,2);
                outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                settextstyle(0,0,0);

                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Bubble sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                        floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                        rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
                        floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=1 && l!=2)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[1]);
                        outtextxy(bubble[1].x1+15+j,315,c);
                        sprintf(c,"%d",a[2]);
                        outtextxy(bubble[2].x1+15-j,315,c);
                    }
                    swap(bubble[1].y1,bubble[2].y1);
                    swap(bubble[1].y2,bubble[2].y2);
                    swap(a[1],a[2]);

                }
                else if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Bubble sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                        floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                        rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
                        floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=1 && l!=2)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[1]);
                        outtextxy(bubble[1].x1+15+j,315,c);
                        sprintf(c,"%d",a[2]);
                        outtextxy(bubble[2].x1+15-j,315,c);
                    }
                    swap(bubble[1].y1,bubble[2].y1);
                    swap(bubble[1].y2,bubble[2].y2);
                    swap(a[1],a[2]);
                }
                else
                {
                    settextstyle(1,0,5);
                    flag=0;
                    outtextxy(102,400,"Wrong move.");
                    settextstyle(0,0,0);
                }

                if(flag==1)
                {
                    settextstyle(1,0,2);
                    outtextxy(102,150,"Click on two  desired rectangle you want to swap.");
                    settextstyle(0,0,0);
                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                    if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
                    {
                        for(int j=1; j<=45; j++)
                        {
                           delay(20);
                            cleardevice();
                            setbkcolor(LIGHTBLUE);
                            settextstyle(BOLD_FONT,0,4);
                            outtextxy(100,65,"Bubble sort");
                            settextstyle(0,0,0);
                            rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                            floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                            rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                            floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                            for(int l=0; l<n; l++)
                            {
                                if(l!=3 && l!=2)
                                {
                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                    sprintf(c,"%d",a[l]);
                                    outtextxy(bubble[l].x1+15,315,c);
                                }
                            }
                            sprintf(c,"%d",a[2]);
                            outtextxy(bubble[2].x1+15+j,315,c);
                            sprintf(c,"%d",a[3]);
                            outtextxy(bubble[3].x1+15-j,315,c);
                        }
                        swap(bubble[3].y1,bubble[2].y1);
                        swap(bubble[3].y2,bubble[2].y2);
                        swap(a[3],a[2]);
                    }
                    else if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
                    {
                        for(int j=1; j<=45; j++)
                        {
                           delay(20);
                            cleardevice();
                            setbkcolor(LIGHTBLUE);
                            settextstyle(BOLD_FONT,0,4);
                            outtextxy(100,65,"Bubble sort");
                            settextstyle(0,0,0);
                            rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                            floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                            rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                            floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                            for(int l=0; l<n; l++)
                            {
                                if(l!=3 && l!=2)
                                {
                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                    sprintf(c,"%d",a[l]);
                                    outtextxy(bubble[l].x1+15,315,c);
                                }
                            }
                            sprintf(c,"%d",a[2]);
                            outtextxy(bubble[2].x1+15+j,315,c);
                            sprintf(c,"%d",a[3]);
                            outtextxy(bubble[3].x1+15-j,315,c);
                        }
                        swap(bubble[3].y1,bubble[2].y1);
                        swap(bubble[3].y2,bubble[2].y2);
                        swap(a[3],a[2]);
                    }
                    else
                    {
                        settextstyle(1,0,5);
                        flag=0;
                        outtextxy(102,400,"Wrong move.");
                        settextstyle(0,0,0);
                    }

                    if(flag==1)
                    {
                        settextstyle(1,0,2);
                        outtextxy(102,150,"Click on two  desired rectangle you want to swap.");
                        settextstyle(0,0,0);
                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                        if(maxx>=bubble[0].x1 && maxx<=bubble[0].x2 && maxy>=bubble[0].y1 && maxy<=bubble[0].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
                        {
                            for(int j=1; j<=45; j++)
                            {
                               delay(20);
                                cleardevice();
                                setbkcolor(LIGHTBLUE);
                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Bubble sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
                                floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
                                rectangle(bubble[1].x1-j,bubble[1].y1,bubble[1].x2-j,bubble[1].y2);
                                floodfill(bubble[1].x1+5-j,bubble[1].y1+5,WHITE);
                                for(int l=0; l<n; l++)
                                {
                                    if(l!=0 && l!=1)
                                    {
                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                        sprintf(c,"%d",a[l]);
                                        outtextxy(bubble[l].x1+15,315,c);
                                    }
                                }
                                sprintf(c,"%d",a[0]);
                                outtextxy(bubble[0].x1+15+j,315,c);
                                sprintf(c,"%d",a[1]);
                                outtextxy(bubble[1].x1+15-j,315,c);
                            }
                            swap(bubble[0].y1,bubble[1].y1);
                            swap(bubble[0].y2,bubble[1].y2);
                            swap(a[1],a[0]);
                        }
                        else if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[0].x1 && maxx1<=bubble[0].x2 && maxy1>=bubble[0].y1 && maxy1<=bubble[0].y2)
                        {
                            for(int j=1; j<=45; j++)
                            {
                               delay(20);
                                cleardevice();
                                setbkcolor(LIGHTBLUE);
                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Bubble sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
                                floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
                                rectangle(bubble[1].x1-j,bubble[1].y1,bubble[1].x2-j,bubble[1].y2);
                                floodfill(bubble[1].x1+5-j,bubble[1].y1+5,WHITE);
                                for(int l=0; l<n; l++)
                                {
                                    if(l!=0 && l!=1)
                                    {
                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                        sprintf(c,"%d",a[l]);
                                        outtextxy(bubble[l].x1+15,315,c);
                                    }
                                }
                                sprintf(c,"%d",a[0]);
                                outtextxy(bubble[0].x1+15+j,315,c);
                                sprintf(c,"%d",a[1]);
                                outtextxy(bubble[1].x1+15-j,315,c);
                            }
                            swap(bubble[0].y1,bubble[1].y1);
                            swap(bubble[0].y2,bubble[1].y2);
                            swap(a[1],a[0]);
                        }
                        else
                        {
                            settextstyle(1,0,5);
                            flag=0;
                            outtextxy(102,400,"Wrong move.");
                            settextstyle(0,0,0);
                        }
                        if(flag==1)
                        {
                            delay(1000);
                            cleardevice();
                            settextstyle(BOLD_FONT,0,5);
                            outtextxy((getmaxx()/2)-150,(getmaxy()/2)-50,"Congratulation");
                            outtextxy(100,(getmaxy()/2),"You have passed level 1");
                            settextstyle(0,0,0);
                        }
                    }
                }
            }
        }
    }
}

void bubble_manual_2()
{
    f=fopen("level 2.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=280-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=300;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,0,5);
    outtextxy((getmaxx()/2)-100,getmaxy()/2,"LEVEL 2");
    settextstyle(0,0,0);
    delay(2000);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Bubble sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }
    settextstyle(1,0,2);
    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
    settextstyle(0,0,0);
    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

    if(maxx>=bubble[0].x1 && maxx<=bubble[0].x2 && maxy>=bubble[0].y1 && maxy<=bubble[0].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Bubble sort");
            settextstyle(0,0,0);
            rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
            floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
            rectangle(bubble[1].x1-j,bubble[1].y1,bubble[1].x2-j,bubble[1].y2);
            floodfill(bubble[1].x1+5-j,bubble[1].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=0 && l!=1)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[0]);
            outtextxy(bubble[0].x1+15+j,315,c);
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15-j,315,c);
        }
        swap(bubble[0].y1,bubble[1].y1);
        swap(bubble[0].y2,bubble[1].y2);
        swap(a[1],a[0]);
    }
    else if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[0].x1 && maxx1<=bubble[0].x2 && maxy1>=bubble[0].y1 && maxy1<=bubble[0].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Bubble sort");
            settextstyle(0,0,0);
            rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
            floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
            rectangle(bubble[1].x1-j,bubble[1].y1,bubble[1].x2-j,bubble[1].y2);
            floodfill(bubble[1].x1+5-j,bubble[1].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=0 && l!=1)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[0]);
            outtextxy(bubble[0].x1+15+j,315,c);
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15-j,315,c);
        }
        swap(bubble[0].y1,bubble[1].y1);
        swap(bubble[0].y2,bubble[1].y2);
        swap(a[1],a[0]);
    }
    else
    {
        settextstyle(1,0,5);
        flag=0;
        outtextxy(102,400,"Wrong move.");
        settextstyle(0,0,0);
    }
    if(flag==1)
    {
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on two desired rectangle you want to swap.");
        settextstyle(0,0,0);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

        if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
        {
            for(int j=1; j<=45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Bubble sort");
                settextstyle(0,0,0);
                rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
                floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=2 && l!=1)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[1]);
                outtextxy(bubble[1].x1+15+j,315,c);
                sprintf(c,"%d",a[2]);
                outtextxy(bubble[2].x1+15-j,315,c);
            }
            swap(bubble[2].y1,bubble[1].y1);
            swap(bubble[2].y2,bubble[1].y2);
            swap(a[1],a[2]);
        }
        else if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
        {
            for(int j=1; j<=45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Bubble sort");
                settextstyle(0,0,0);
                rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
                floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=2 && l!=1)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[1]);
                outtextxy(bubble[1].x1+15+j,315,c);
                sprintf(c,"%d",a[2]);
                outtextxy(bubble[2].x1+15-j,315,c);
            }
            swap(bubble[2].y1,bubble[1].y1);
            swap(bubble[2].y2,bubble[1].y2);
            swap(a[1],a[2]);
        }
        else
        {
            settextstyle(1,0,5);
            flag=0;
            outtextxy(102,400,"Wrong move.");
            settextstyle(0,0,0);
        }
        if(flag==1)
        {
            settextstyle(1,0,2);
            outtextxy(102,150,"Click on two desired rectangle you want to swap.");
            settextstyle(0,0,0);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

            if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
            {
                for(int j=1; j<=45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Bubble sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                    floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                    rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                    floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=3 && l!=2)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[2]);
                    outtextxy(bubble[2].x1+15+j,315,c);
                    sprintf(c,"%d",a[3]);
                    outtextxy(bubble[3].x1+15-j,315,c);
                }
                swap(bubble[2].y1,bubble[3].y1);
                swap(bubble[2].y2,bubble[3].y2);
                swap(a[3],a[2]);
            }
            else if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
            {
                for(int j=1; j<=45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Bubble sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                    floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                    rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                    floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=3 && l!=2)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[2]);
                    outtextxy(bubble[2].x1+15+j,315,c);
                    sprintf(c,"%d",a[3]);
                    outtextxy(bubble[3].x1+15-j,315,c);
                }
                swap(bubble[2].y1,bubble[3].y1);
                swap(bubble[2].y2,bubble[3].y2);
                swap(a[3],a[2]);
            }
            else
            {
                settextstyle(1,0,5);
                flag=0;
                outtextxy(102,400,"Wrong move.");
                settextstyle(0,0,0);
            }
            if(flag==1)
            {
                settextstyle(1,0,2);
                outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                settextstyle(0,0,0);
                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Bubble sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                        floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                        rectangle(bubble[5].x1-j,bubble[5].y1,bubble[5].x2-j,bubble[5].y2);
                        floodfill(bubble[5].x1+5-j,bubble[5].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=4 && l!=5)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[4]);
                        outtextxy(bubble[4].x1+15+j,315,c);
                        sprintf(c,"%d",a[5]);
                        outtextxy(bubble[5].x1+15-j,315,c);
                    }
                    swap(bubble[5].y1,bubble[4].y1);
                    swap(bubble[5].y2,bubble[4].y2);
                    swap(a[4],a[5]);
                }
                else if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Bubble sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                        floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                        rectangle(bubble[5].x1-j,bubble[5].y1,bubble[5].x2-j,bubble[5].y2);
                        floodfill(bubble[5].x1+5-j,bubble[5].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=4 && l!=5)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[4]);
                        outtextxy(bubble[4].x1+15+j,315,c);
                        sprintf(c,"%d",a[5]);
                        outtextxy(bubble[5].x1+15-j,315,c);
                    }
                    swap(bubble[5].y1,bubble[4].y1);
                    swap(bubble[5].y2,bubble[4].y2);
                    swap(a[4],a[5]);
                }
                else
                {
                    settextstyle(1,0,5);
                    flag=0;
                    outtextxy(102,400,"Wrong move.");
                    settextstyle(0,0,0);
                }
                if(flag==1)
                {
                    settextstyle(1,0,2);
                    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                    settextstyle(0,0,0);
                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                    if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[6].x1 && maxx1<=bubble[6].x2 && maxy1>=bubble[6].y1 && maxy1<=bubble[6].y2)
                    {
                        for(int j=1; j<=45; j++)
                        {
                           delay(20);
                            cleardevice();
                            setbkcolor(LIGHTBLUE);
                            settextstyle(BOLD_FONT,0,4);
                            outtextxy(100,65,"Bubble sort");
                            settextstyle(0,0,0);
                            rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                            floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                            rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                            floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                            for(int l=0; l<n; l++)
                            {
                                if(l!=5 && l!=6)
                                {
                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                    sprintf(c,"%d",a[l]);
                                    outtextxy(bubble[l].x1+15,315,c);
                                }
                            }
                            sprintf(c,"%d",a[5]);
                            outtextxy(bubble[5].x1+15+j,315,c);
                            sprintf(c,"%d",a[6]);
                            outtextxy(bubble[6].x1+15-j,315,c);
                        }
                        swap(bubble[5].y1,bubble[6].y1);
                        swap(bubble[5].y2,bubble[6].y2);
                        swap(a[5],a[6]);
                    }
                    else if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                    {
                        for(int j=1; j<=45; j++)
                        {
                           delay(20);
                            cleardevice();
                            setbkcolor(LIGHTBLUE);
                            settextstyle(BOLD_FONT,0,4);
                            outtextxy(100,65,"Bubble sort");
                            settextstyle(0,0,0);
                            rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                            floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                            rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                            floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                            for(int l=0; l<n; l++)
                            {
                                if(l!=5 && l!=6)
                                {
                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                    sprintf(c,"%d",a[l]);
                                    outtextxy(bubble[l].x1+15,315,c);
                                }
                            }
                            sprintf(c,"%d",a[5]);
                            outtextxy(bubble[5].x1+15+j,315,c);
                            sprintf(c,"%d",a[6]);
                            outtextxy(bubble[6].x1+15-j,315,c);
                        }
                        swap(bubble[5].y1,bubble[6].y1);
                        swap(bubble[5].y2,bubble[6].y2);
                        swap(a[5],a[6]);
                    }
                    else
                    {
                        settextstyle(1,0,5);
                        flag=0;
                        outtextxy(102,400,"Wrong move.");
                        settextstyle(0,0,0);
                    }
                    if(flag==1)
                    {
                        settextstyle(1,0,2);
                        outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                        settextstyle(0,0,0);
                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                        if(maxx>=bubble[7].x1 && maxx<=bubble[7].x2 && maxy>=bubble[7].y1 && maxy<=bubble[7].y2 && maxx1>=bubble[8].x1 && maxx1<=bubble[8].x2 && maxy1>=bubble[8].y1 && maxy1<=bubble[8].y2)
                        {
                            for(int j=1; j<=45; j++)
                            {
                               delay(20);
                                cleardevice();
                                setbkcolor(LIGHTBLUE);
                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Bubble sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[7].x1+j,bubble[7].y1,bubble[7].x2+j,bubble[7].y2);
                                floodfill(bubble[7].x1+5+j,bubble[7].y1+5,WHITE);
                                rectangle(bubble[8].x1-j,bubble[8].y1,bubble[8].x2-j,bubble[8].y2);
                                floodfill(bubble[8].x1+5-j,bubble[8].y1+5,WHITE);
                                for(int l=0; l<n; l++)
                                {
                                    if(l!=7 && l!=8)
                                    {
                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                        sprintf(c,"%d",a[l]);
                                        outtextxy(bubble[l].x1+15,315,c);
                                    }
                                }
                                sprintf(c,"%d",a[7]);
                                outtextxy(bubble[7].x1+15+j,315,c);
                                sprintf(c,"%d",a[8]);
                                outtextxy(bubble[8].x1+15-j,315,c);
                            }
                            swap(bubble[8].y1,bubble[7].y1);
                            swap(bubble[8].y2,bubble[7].y2);
                            swap(a[7],a[8]);
                        }
                        else if(maxx>=bubble[8].x1 && maxx<=bubble[8].x2 && maxy>=bubble[8].y1 && maxy<=bubble[8].y2 && maxx1>=bubble[7].x1 && maxx1<=bubble[7].x2 && maxy1>=bubble[7].y1 && maxy1<=bubble[7].y2)
                        {
                            for(int j=1; j<=45; j++)
                            {
                               delay(20);
                                cleardevice();
                                setbkcolor(LIGHTBLUE);
                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Bubble sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[7].x1+j,bubble[7].y1,bubble[7].x2+j,bubble[7].y2);
                                floodfill(bubble[7].x1+5+j,bubble[7].y1+5,WHITE);
                                rectangle(bubble[8].x1-j,bubble[8].y1,bubble[8].x2-j,bubble[8].y2);
                                floodfill(bubble[8].x1+5-j,bubble[8].y1+5,WHITE);
                                for(int l=0; l<n; l++)
                                {
                                    if(l!=7 && l!=8)
                                    {
                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                        sprintf(c,"%d",a[l]);
                                        outtextxy(bubble[l].x1+15,315,c);
                                    }
                                }
                                sprintf(c,"%d",a[7]);
                                outtextxy(bubble[7].x1+15+j,315,c);
                                sprintf(c,"%d",a[8]);
                                outtextxy(bubble[8].x1+15-j,315,c);
                            }
                            swap(bubble[8].y1,bubble[7].y1);
                            swap(bubble[8].y2,bubble[7].y2);
                            swap(a[7],a[8]);
                        }
                        else
                        {
                            settextstyle(1,0,5);
                            flag=0;
                            outtextxy(102,400,"Wrong move.");
                            settextstyle(0,0,0);
                        }
                        if(flag==1)
                        {
                            settextstyle(1,0,2);
                            outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                            settextstyle(0,0,0);
                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                            if(maxx>=bubble[8].x1 && maxx<=bubble[8].x2 && maxy>=bubble[8].y1 && maxy<=bubble[8].y2 && maxx1>=bubble[9].x1 && maxx1<=bubble[9].x2 && maxy1>=bubble[9].y1 && maxy1<=bubble[9].y2)
                            {
                                for(int j=1; j<=45; j++)
                                {
                                   delay(20);
                                    cleardevice();
                                    setbkcolor(LIGHTBLUE);
                                    settextstyle(BOLD_FONT,0,4);
                                    outtextxy(100,65,"Bubble sort");
                                    settextstyle(0,0,0);
                                    rectangle(bubble[8].x1+j,bubble[8].y1,bubble[8].x2+j,bubble[8].y2);
                                    floodfill(bubble[8].x1+5+j,bubble[8].y1+5,WHITE);
                                    rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                                    floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                                    for(int l=0; l<n; l++)
                                    {
                                        if(l!=9 && l!=8)
                                        {
                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                            sprintf(c,"%d",a[l]);
                                            outtextxy(bubble[l].x1+15,315,c);
                                        }
                                    }
                                    sprintf(c,"%d",a[8]);
                                    outtextxy(bubble[8].x1+15+j,315,c);
                                    sprintf(c,"%d",a[9]);
                                    outtextxy(bubble[9].x1+15-j,315,c);
                                }
                                swap(bubble[9].y1,bubble[8].y1);
                                swap(bubble[9].y2,bubble[8].y2);
                                swap(a[8],a[9]);
                            }
                            else if(maxx>=bubble[9].x1 && maxx<=bubble[9].x2 && maxy>=bubble[9].y1 && maxy<=bubble[9].y2 && maxx1>=bubble[8].x1 && maxx1<=bubble[8].x2 && maxy1>=bubble[8].y1 && maxy1<=bubble[8].y2)
                            {
                                for(int j=1; j<=45; j++)
                                {
                                   delay(20);
                                    cleardevice();
                                    setbkcolor(LIGHTBLUE);
                                    settextstyle(BOLD_FONT,0,4);
                                    outtextxy(100,65,"Bubble sort");
                                    settextstyle(0,0,0);
                                    rectangle(bubble[8].x1+j,bubble[8].y1,bubble[8].x2+j,bubble[8].y2);
                                    floodfill(bubble[8].x1+5+j,bubble[8].y1+5,WHITE);
                                    rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                                    floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                                    for(int l=0; l<n; l++)
                                    {
                                        if(l!=9 && l!=8)
                                        {
                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                            sprintf(c,"%d",a[l]);
                                            outtextxy(bubble[l].x1+15,315,c);
                                        }
                                    }
                                    sprintf(c,"%d",a[8]);
                                    outtextxy(bubble[8].x1+15+j,315,c);
                                    sprintf(c,"%d",a[9]);
                                    outtextxy(bubble[9].x1+15-j,315,c);
                                }
                                swap(bubble[9].y1,bubble[8].y1);
                                swap(bubble[9].y2,bubble[8].y2);
                                swap(a[8],a[9]);
                            }
                            else
                            {
                                settextstyle(1,0,5);
                                flag=0;
                                outtextxy(102,400,"Wrong move.");
                                settextstyle(0,0,0);
                            }
                            if(flag==1)
                            {
                                settextstyle(1,0,2);
                                outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                settextstyle(0,0,0);
                                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
                                {
                                    for(int j=1; j<=45; j++)
                                    {
                                       delay(20);
                                        cleardevice();
                                        setbkcolor(LIGHTBLUE);
                                        settextstyle(BOLD_FONT,0,4);
                                        outtextxy(100,65,"Bubble sort");
                                        settextstyle(0,0,0);
                                        rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                                        floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                                        rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
                                        floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
                                        for(int l=0; l<n; l++)
                                        {
                                            if(l!=2 && l!=1)
                                            {
                                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                sprintf(c,"%d",a[l]);
                                                outtextxy(bubble[l].x1+15,315,c);
                                            }
                                        }
                                        sprintf(c,"%d",a[1]);
                                        outtextxy(bubble[1].x1+15+j,315,c);
                                        sprintf(c,"%d",a[2]);
                                        outtextxy(bubble[2].x1+15-j,315,c);
                                    }
                                    swap(bubble[2].y1,bubble[1].y1);
                                    swap(bubble[2].y2,bubble[1].y2);
                                    swap(a[1],a[2]);
                                }
                                else if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
                                {
                                    for(int j=1; j<=45; j++)
                                    {
                                       delay(20);
                                        cleardevice();
                                        setbkcolor(LIGHTBLUE);
                                        settextstyle(BOLD_FONT,0,4);
                                        outtextxy(100,65,"Bubble sort");
                                        settextstyle(0,0,0);
                                        rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                                        floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                                        rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
                                        floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
                                        for(int l=0; l<n; l++)
                                        {
                                            if(l!=2 && l!=1)
                                            {
                                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                sprintf(c,"%d",a[l]);
                                                outtextxy(bubble[l].x1+15,315,c);
                                            }
                                        }
                                        sprintf(c,"%d",a[1]);
                                        outtextxy(bubble[1].x1+15+j,315,c);
                                        sprintf(c,"%d",a[2]);
                                        outtextxy(bubble[2].x1+15-j,315,c);
                                    }
                                    swap(bubble[2].y1,bubble[1].y1);
                                    swap(bubble[2].y2,bubble[1].y2);
                                    swap(a[1],a[2]);
                                }
                                else
                                {
                                    settextstyle(1,0,5);
                                    flag=0;
                                    outtextxy(102,400,"Wrong move.");
                                    settextstyle(0,0,0);
                                }
                                if(flag==1)
                                {
                                    settextstyle(1,0,2);
                                    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                    settextstyle(0,0,0);
                                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                    if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                                    {
                                        for(int j=1; j<=45; j++)
                                        {
                                           delay(20);
                                            cleardevice();
                                            setbkcolor(LIGHTBLUE);
                                            settextstyle(BOLD_FONT,0,4);
                                            outtextxy(100,65,"Bubble sort");
                                            settextstyle(0,0,0);
                                            rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                                            floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                                            rectangle(bubble[5].x1-j,bubble[5].y1,bubble[5].x2-j,bubble[5].y2);
                                            floodfill(bubble[5].x1+5-j,bubble[5].y1+5,WHITE);
                                            for(int l=0; l<n; l++)
                                            {
                                                if(l!=4 && l!=5)
                                                {
                                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                    sprintf(c,"%d",a[l]);
                                                    outtextxy(bubble[l].x1+15,315,c);
                                                }
                                            }
                                            sprintf(c,"%d",a[4]);
                                            outtextxy(bubble[4].x1+15+j,315,c);
                                            sprintf(c,"%d",a[5]);
                                            outtextxy(bubble[5].x1+15-j,315,c);
                                        }
                                        swap(bubble[5].y1,bubble[4].y1);
                                        swap(bubble[5].y2,bubble[4].y2);
                                        swap(a[4],a[5]);
                                    }
                                    else if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                                    {
                                        for(int j=1; j<=45; j++)
                                        {
                                           delay(20);
                                            cleardevice();
                                            setbkcolor(LIGHTBLUE);
                                            settextstyle(BOLD_FONT,0,4);
                                            outtextxy(100,65,"Bubble sort");
                                            settextstyle(0,0,0);
                                            rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                                            floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                                            rectangle(bubble[5].x1-j,bubble[5].y1,bubble[5].x2-j,bubble[5].y2);
                                            floodfill(bubble[5].x1+5-j,bubble[5].y1+5,WHITE);
                                            for(int l=0; l<n; l++)
                                            {
                                                if(l!=4 && l!=5)
                                                {
                                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                    sprintf(c,"%d",a[l]);
                                                    outtextxy(bubble[l].x1+15,315,c);
                                                }
                                            }
                                            sprintf(c,"%d",a[4]);
                                            outtextxy(bubble[4].x1+15+j,315,c);
                                            sprintf(c,"%d",a[5]);
                                            outtextxy(bubble[5].x1+15-j,315,c);
                                        }
                                        swap(bubble[5].y1,bubble[4].y1);
                                        swap(bubble[5].y2,bubble[4].y2);
                                        swap(a[4],a[5]);
                                    }
                                    else
                                    {
                                        settextstyle(1,0,5);
                                        flag=0;
                                        outtextxy(102,400,"Wrong move.");
                                        settextstyle(0,0,0);
                                    }
                                    if(flag==1)
                                    {
                                        settextstyle(1,0,2);
                                        outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                        settextstyle(0,0,0);
                                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                        if(maxx>=bubble[7].x1 && maxx<=bubble[7].x2 && maxy>=bubble[7].y1 && maxy<=bubble[7].y2 && maxx1>=bubble[6].x1 && maxx1<=bubble[6].x2 && maxy1>=bubble[6].y1 && maxy1<=bubble[6].y2)
                                        {
                                            for(int j=1; j<=45; j++)
                                            {
                                               delay(20);
                                                cleardevice();
                                                setbkcolor(LIGHTBLUE);
                                                settextstyle(BOLD_FONT,0,4);
                                                outtextxy(100,65,"Bubble sort");
                                                settextstyle(0,0,0);
                                                rectangle(bubble[6].x1+j,bubble[6].y1,bubble[6].x2+j,bubble[6].y2);
                                                floodfill(bubble[6].x1+5+j,bubble[6].y1+5,WHITE);
                                                rectangle(bubble[7].x1-j,bubble[7].y1,bubble[7].x2-j,bubble[7].y2);
                                                floodfill(bubble[7].x1+5-j,bubble[7].y1+5,WHITE);
                                                for(int l=0; l<n; l++)
                                                {
                                                    if(l!=7 && l!=6)
                                                    {
                                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                        sprintf(c,"%d",a[l]);
                                                        outtextxy(bubble[l].x1+15,315,c);
                                                    }
                                                }
                                                sprintf(c,"%d",a[6]);
                                                outtextxy(bubble[6].x1+15+j,315,c);
                                                sprintf(c,"%d",a[7]);
                                                outtextxy(bubble[7].x1+15-j,315,c);
                                            }
                                            swap(bubble[6].y1,bubble[7].y1);
                                            swap(bubble[6].y2,bubble[7].y2);
                                            swap(a[7],a[6]);
                                        }
                                        else if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[7].x1 && maxx1<=bubble[7].x2 && maxy1>=bubble[7].y1 && maxy1<=bubble[7].y2)
                                        {
                                            for(int j=1; j<=45; j++)
                                            {
                                               delay(20);
                                                cleardevice();
                                                setbkcolor(LIGHTBLUE);
                                                settextstyle(BOLD_FONT,0,4);
                                                outtextxy(100,65,"Bubble sort");
                                                settextstyle(0,0,0);
                                                rectangle(bubble[6].x1+j,bubble[6].y1,bubble[6].x2+j,bubble[6].y2);
                                                floodfill(bubble[6].x1+5+j,bubble[6].y1+5,WHITE);
                                                rectangle(bubble[7].x1-j,bubble[7].y1,bubble[7].x2-j,bubble[7].y2);
                                                floodfill(bubble[7].x1+5-j,bubble[7].y1+5,WHITE);
                                                for(int l=0; l<n; l++)
                                                {
                                                    if(l!=7 && l!=6)
                                                    {
                                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                        sprintf(c,"%d",a[l]);
                                                        outtextxy(bubble[l].x1+15,315,c);
                                                    }
                                                }
                                                sprintf(c,"%d",a[6]);
                                                outtextxy(bubble[6].x1+15+j,315,c);
                                                sprintf(c,"%d",a[7]);
                                                outtextxy(bubble[7].x1+15-j,315,c);
                                            }
                                            swap(bubble[6].y1,bubble[7].y1);
                                            swap(bubble[6].y2,bubble[7].y2);
                                            swap(a[7],a[6]);
                                        }
                                        else
                                        {
                                            settextstyle(1,0,5);
                                            flag=0;
                                            outtextxy(102,400,"Wrong move.");
                                            settextstyle(0,0,0);
                                        }
                                        if(flag==1)
                                        {
                                            settextstyle(1,0,2);
                                            outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                            settextstyle(0,0,0);
                                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                            if(maxx>=bubble[7].x1 && maxx<=bubble[7].x2 && maxy>=bubble[7].y1 && maxy<=bubble[7].y2 && maxx1>=bubble[8].x1 && maxx1<=bubble[8].x2 && maxy1>=bubble[8].y1 && maxy1<=bubble[8].y2)
                                            {
                                                for(int j=1; j<=45; j++)
                                                {
                                                   delay(20);
                                                    cleardevice();
                                                    setbkcolor(LIGHTBLUE);
                                                    settextstyle(BOLD_FONT,0,4);
                                                    outtextxy(100,65,"Bubble sort");
                                                    settextstyle(0,0,0);
                                                    rectangle(bubble[7].x1+j,bubble[7].y1,bubble[7].x2+j,bubble[7].y2);
                                                    floodfill(bubble[7].x1+5+j,bubble[7].y1+5,WHITE);
                                                    rectangle(bubble[8].x1-j,bubble[8].y1,bubble[8].x2-j,bubble[8].y2);
                                                    floodfill(bubble[8].x1+5-j,bubble[8].y1+5,WHITE);
                                                    for(int l=0; l<n; l++)
                                                    {
                                                        if(l!=7 && l!=8)
                                                        {
                                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                            sprintf(c,"%d",a[l]);
                                                            outtextxy(bubble[l].x1+15,315,c);
                                                        }
                                                    }
                                                    sprintf(c,"%d",a[7]);
                                                    outtextxy(bubble[7].x1+15+j,315,c);
                                                    sprintf(c,"%d",a[8]);
                                                    outtextxy(bubble[8].x1+15-j,315,c);
                                                }
                                                swap(bubble[8].y1,bubble[7].y1);
                                                swap(bubble[8].y2,bubble[7].y2);
                                                swap(a[7],a[8]);
                                            }
                                            else if(maxx>=bubble[8].x1 && maxx<=bubble[8].x2 && maxy>=bubble[8].y1 && maxy<=bubble[8].y2 && maxx1>=bubble[7].x1 && maxx1<=bubble[7].x2 && maxy1>=bubble[7].y1 && maxy1<=bubble[7].y2)
                                            {
                                                for(int j=1; j<=45; j++)
                                                {
                                                   delay(20);
                                                    cleardevice();
                                                    setbkcolor(LIGHTBLUE);
                                                    settextstyle(BOLD_FONT,0,4);
                                                    outtextxy(100,65,"Bubble sort");
                                                    settextstyle(0,0,0);
                                                    rectangle(bubble[7].x1+j,bubble[7].y1,bubble[7].x2+j,bubble[7].y2);
                                                    floodfill(bubble[7].x1+5+j,bubble[7].y1+5,WHITE);
                                                    rectangle(bubble[8].x1-j,bubble[8].y1,bubble[8].x2-j,bubble[8].y2);
                                                    floodfill(bubble[8].x1+5-j,bubble[8].y1+5,WHITE);
                                                    for(int l=0; l<n; l++)
                                                    {
                                                        if(l!=7 && l!=8)
                                                        {
                                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                            sprintf(c,"%d",a[l]);
                                                            outtextxy(bubble[l].x1+15,315,c);
                                                        }
                                                    }
                                                    sprintf(c,"%d",a[7]);
                                                    outtextxy(bubble[7].x1+15+j,315,c);
                                                    sprintf(c,"%d",a[8]);
                                                    outtextxy(bubble[8].x1+15-j,315,c);
                                                }
                                                swap(bubble[8].y1,bubble[7].y1);
                                                swap(bubble[8].y2,bubble[7].y2);
                                                swap(a[7],a[8]);
                                            }
                                            else
                                            {
                                                settextstyle(1,0,5);
                                                flag=0;
                                                outtextxy(102,400,"Wrong move.");
                                                settextstyle(0,0,0);
                                            }
                                            if(flag==1)
                                            {
                                                settextstyle(1,0,2);
                                                outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                                settextstyle(0,0,0);
                                                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                                if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                                                {
                                                    for(int j=1; j<=45; j++)
                                                    {
                                                       delay(20);
                                                        cleardevice();
                                                        setbkcolor(LIGHTBLUE);
                                                        settextstyle(BOLD_FONT,0,4);
                                                        outtextxy(100,65,"Bubble sort");
                                                        settextstyle(0,0,0);
                                                        rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                                                        floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                                                        rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                                                        floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                                                        for(int l=0; l<n; l++)
                                                        {
                                                            if(l!=3 && l!=4)
                                                            {
                                                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                sprintf(c,"%d",a[l]);
                                                                outtextxy(bubble[l].x1+15,315,c);
                                                            }
                                                        }
                                                        sprintf(c,"%d",a[3]);
                                                        outtextxy(bubble[3].x1+15+j,315,c);
                                                        sprintf(c,"%d",a[4]);
                                                        outtextxy(bubble[4].x1+15-j,315,c);
                                                    }
                                                    swap(bubble[4].y1,bubble[3].y1);
                                                    swap(bubble[4].y2,bubble[3].y2);
                                                    swap(a[3],a[4]);
                                                }
                                                else if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
                                                {
                                                    for(int j=1; j<=45; j++)
                                                    {
                                                       delay(20);
                                                        cleardevice();
                                                        setbkcolor(LIGHTBLUE);
                                                        settextstyle(BOLD_FONT,0,4);
                                                        outtextxy(100,65,"Bubble sort");
                                                        settextstyle(0,0,0);
                                                        rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                                                        floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                                                        rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                                                        floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                                                        for(int l=0; l<n; l++)
                                                        {
                                                            if(l!=3 && l!=4)
                                                            {
                                                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                sprintf(c,"%d",a[l]);
                                                                outtextxy(bubble[l].x1+15,315,c);
                                                            }
                                                        }
                                                        sprintf(c,"%d",a[3]);
                                                        outtextxy(bubble[3].x1+15+j,315,c);
                                                        sprintf(c,"%d",a[4]);
                                                        outtextxy(bubble[4].x1+15-j,315,c);
                                                    }
                                                    swap(bubble[4].y1,bubble[3].y1);
                                                    swap(bubble[4].y2,bubble[3].y2);
                                                    swap(a[3],a[4]);
                                                }
                                                else
                                                {
                                                    settextstyle(1,0,5);
                                                    flag=0;
                                                    outtextxy(102,400,"Wrong move.");
                                                    settextstyle(0,0,0);
                                                }
                                                if(flag==1)
                                                {
                                                    settextstyle(1,0,2);
                                                    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                                    settextstyle(0,0,0);
                                                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                                    if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[6].x1 && maxx1<=bubble[6].x2 && maxy1>=bubble[6].y1 && maxy1<=bubble[6].y2)
                                                    {
                                                        for(int j=1; j<=45; j++)
                                                        {
                                                           delay(20);
                                                            cleardevice();
                                                            setbkcolor(LIGHTBLUE);
                                                            settextstyle(BOLD_FONT,0,4);
                                                            outtextxy(100,65,"Bubble sort");
                                                            settextstyle(0,0,0);
                                                            rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                                                            floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                                                            rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                                                            floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                                                            for(int l=0; l<n; l++)
                                                            {
                                                                if(l!=5 && l!=6)
                                                                {
                                                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                    sprintf(c,"%d",a[l]);
                                                                    outtextxy(bubble[l].x1+15,315,c);
                                                                }
                                                            }
                                                            sprintf(c,"%d",a[5]);
                                                            outtextxy(bubble[5].x1+15+j,315,c);
                                                            sprintf(c,"%d",a[6]);
                                                            outtextxy(bubble[6].x1+15-j,315,c);
                                                        }
                                                        swap(bubble[5].y1,bubble[6].y1);
                                                        swap(bubble[5].y2,bubble[6].y2);
                                                        swap(a[5],a[6]);
                                                    }
                                                    else if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                                                    {
                                                        for(int j=1; j<=45; j++)
                                                        {
                                                           delay(20);
                                                            cleardevice();
                                                            setbkcolor(LIGHTBLUE);
                                                            settextstyle(BOLD_FONT,0,4);
                                                            outtextxy(100,65,"Bubble sort");
                                                            settextstyle(0,0,0);
                                                            rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                                                            floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                                                            rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                                                            floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                                                            for(int l=0; l<n; l++)
                                                            {
                                                                if(l!=5 && l!=6)
                                                                {
                                                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                    sprintf(c,"%d",a[l]);
                                                                    outtextxy(bubble[l].x1+15,315,c);
                                                                }
                                                            }
                                                            sprintf(c,"%d",a[5]);
                                                            outtextxy(bubble[5].x1+15+j,315,c);
                                                            sprintf(c,"%d",a[6]);
                                                            outtextxy(bubble[6].x1+15-j,315,c);
                                                        }
                                                        swap(bubble[5].y1,bubble[6].y1);
                                                        swap(bubble[5].y2,bubble[6].y2);
                                                        swap(a[5],a[6]);
                                                    }
                                                    else
                                                    {
                                                        settextstyle(1,0,5);
                                                        flag=0;
                                                        outtextxy(102,400,"Wrong move.");
                                                        settextstyle(0,0,0);
                                                    }
                                                    if(flag==1)
                                                    {
                                                        settextstyle(1,0,2);
                                                        outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                                        settextstyle(0,0,0);
                                                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                                        if(maxx>=bubble[7].x1 && maxx<=bubble[7].x2 && maxy>=bubble[7].y1 && maxy<=bubble[7].y2 && maxx1>=bubble[6].x1 && maxx1<=bubble[6].x2 && maxy1>=bubble[6].y1 && maxy1<=bubble[6].y2)
                                                        {
                                                            for(int j=1; j<=45; j++)
                                                            {
                                                               delay(20);
                                                                cleardevice();
                                                                setbkcolor(LIGHTBLUE);
                                                                settextstyle(BOLD_FONT,0,4);
                                                                outtextxy(100,65,"Bubble sort");
                                                                settextstyle(0,0,0);
                                                                rectangle(bubble[6].x1+j,bubble[6].y1,bubble[6].x2+j,bubble[6].y2);
                                                                floodfill(bubble[6].x1+5+j,bubble[6].y1+5,WHITE);
                                                                rectangle(bubble[7].x1-j,bubble[7].y1,bubble[7].x2-j,bubble[7].y2);
                                                                floodfill(bubble[7].x1+5-j,bubble[7].y1+5,WHITE);
                                                                for(int l=0; l<n; l++)
                                                                {
                                                                    if(l!=7 && l!=6)
                                                                    {
                                                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                        sprintf(c,"%d",a[l]);
                                                                        outtextxy(bubble[l].x1+15,315,c);
                                                                    }
                                                                }
                                                                sprintf(c,"%d",a[6]);
                                                                outtextxy(bubble[6].x1+15+j,315,c);
                                                                sprintf(c,"%d",a[7]);
                                                                outtextxy(bubble[7].x1+15-j,315,c);
                                                            }
                                                            swap(bubble[6].y1,bubble[7].y1);
                                                            swap(bubble[6].y2,bubble[7].y2);
                                                            swap(a[7],a[6]);
                                                        }
                                                        else if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[7].x1 && maxx1<=bubble[7].x2 && maxy1>=bubble[7].y1 && maxy1<=bubble[7].y2)
                                                        {
                                                            for(int j=1; j<=45; j++)
                                                            {
                                                               delay(20);
                                                                cleardevice();
                                                                setbkcolor(LIGHTBLUE);
                                                                settextstyle(BOLD_FONT,0,4);
                                                                outtextxy(100,65,"Bubble sort");
                                                                settextstyle(0,0,0);
                                                                rectangle(bubble[6].x1+j,bubble[6].y1,bubble[6].x2+j,bubble[6].y2);
                                                                floodfill(bubble[6].x1+5+j,bubble[6].y1+5,WHITE);
                                                                rectangle(bubble[7].x1-j,bubble[7].y1,bubble[7].x2-j,bubble[7].y2);
                                                                floodfill(bubble[7].x1+5-j,bubble[7].y1+5,WHITE);
                                                                for(int l=0; l<n; l++)
                                                                {
                                                                    if(l!=7 && l!=6)
                                                                    {
                                                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                        sprintf(c,"%d",a[l]);
                                                                        outtextxy(bubble[l].x1+15,315,c);
                                                                    }
                                                                }
                                                                sprintf(c,"%d",a[6]);
                                                                outtextxy(bubble[6].x1+15+j,315,c);
                                                                sprintf(c,"%d",a[7]);
                                                                outtextxy(bubble[7].x1+15-j,315,c);
                                                            }
                                                            swap(bubble[6].y1,bubble[7].y1);
                                                            swap(bubble[6].y2,bubble[7].y2);
                                                            swap(a[7],a[6]);
                                                        }
                                                        else
                                                        {
                                                            settextstyle(1,0,5);
                                                            flag=0;
                                                            outtextxy(102,400,"Wrong move.");
                                                            settextstyle(0,0,0);
                                                        }
                                                        if(flag==1)
                                                        {
                                                            settextstyle(1,0,2);
                                                            outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                                            settextstyle(0,0,0);
                                                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                                            if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[6].x1 && maxx1<=bubble[6].x2 && maxy1>=bubble[6].y1 && maxy1<=bubble[6].y2)
                                                            {
                                                                for(int j=1; j<=45; j++)
                                                                {
                                                                   delay(20);
                                                                    cleardevice();
                                                                    setbkcolor(LIGHTBLUE);
                                                                    settextstyle(BOLD_FONT,0,4);
                                                                    outtextxy(100,65,"Bubble sort");
                                                                    settextstyle(0,0,0);
                                                                    rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                                                                    floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                                                                    rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                                                                    floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                                                                    for(int l=0; l<n; l++)
                                                                    {
                                                                        if(l!=5 && l!=6)
                                                                        {
                                                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                            sprintf(c,"%d",a[l]);
                                                                            outtextxy(bubble[l].x1+15,315,c);
                                                                        }
                                                                    }
                                                                    sprintf(c,"%d",a[5]);
                                                                    outtextxy(bubble[5].x1+15+j,315,c);
                                                                    sprintf(c,"%d",a[6]);
                                                                    outtextxy(bubble[6].x1+15-j,315,c);
                                                                }
                                                                swap(bubble[5].y1,bubble[6].y1);
                                                                swap(bubble[5].y2,bubble[6].y2);
                                                                swap(a[5],a[6]);
                                                            }
                                                            else if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                                                            {
                                                                for(int j=1; j<=45; j++)
                                                                {
                                                                   delay(20);
                                                                    cleardevice();
                                                                    setbkcolor(LIGHTBLUE);
                                                                    settextstyle(BOLD_FONT,0,4);
                                                                    outtextxy(100,65,"Bubble sort");
                                                                    settextstyle(0,0,0);
                                                                    rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                                                                    floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                                                                    rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                                                                    floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                                                                    for(int l=0; l<n; l++)
                                                                    {
                                                                        if(l!=5 && l!=6)
                                                                        {
                                                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                            sprintf(c,"%d",a[l]);
                                                                            outtextxy(bubble[l].x1+15,315,c);
                                                                        }
                                                                    }
                                                                    sprintf(c,"%d",a[5]);
                                                                    outtextxy(bubble[5].x1+15+j,315,c);
                                                                    sprintf(c,"%d",a[6]);
                                                                    outtextxy(bubble[6].x1+15-j,315,c);
                                                                }
                                                                swap(bubble[5].y1,bubble[6].y1);
                                                                swap(bubble[5].y2,bubble[6].y2);
                                                                swap(a[5],a[6]);
                                                            }
                                                            else
                                                            {
                                                                settextstyle(1,0,5);
                                                                flag=0;
                                                                outtextxy(102,400,"Wrong move.");
                                                                settextstyle(0,0,0);
                                                            }
                                                            if(flag==1)
                                                            {
                                                                settextstyle(1,0,2);
                                                                outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                                                settextstyle(0,0,0);
                                                                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                                                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                                                if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                                                                {
                                                                    for(int j=1; j<=45; j++)
                                                                    {
                                                                       delay(20);
                                                                        cleardevice();
                                                                        setbkcolor(LIGHTBLUE);
                                                                        settextstyle(BOLD_FONT,0,4);
                                                                        outtextxy(100,65,"Bubble sort");
                                                                        settextstyle(0,0,0);
                                                                        rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                                                                        floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                                                                        rectangle(bubble[5].x1-j,bubble[5].y1,bubble[5].x2-j,bubble[5].y2);
                                                                        floodfill(bubble[5].x1+5-j,bubble[5].y1+5,WHITE);
                                                                        for(int l=0; l<n; l++)
                                                                        {
                                                                            if(l!=4 && l!=5)
                                                                            {
                                                                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                                sprintf(c,"%d",a[l]);
                                                                                outtextxy(bubble[l].x1+15,315,c);
                                                                            }
                                                                        }
                                                                        sprintf(c,"%d",a[4]);
                                                                        outtextxy(bubble[4].x1+15+j,315,c);
                                                                        sprintf(c,"%d",a[5]);
                                                                        outtextxy(bubble[5].x1+15-j,315,c);
                                                                    }
                                                                    swap(bubble[5].y1,bubble[4].y1);
                                                                    swap(bubble[5].y2,bubble[4].y2);
                                                                    swap(a[4],a[5]);
                                                                }
                                                                else if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                                                                {
                                                                    for(int j=1; j<=45; j++)
                                                                    {
                                                                       delay(20);
                                                                        cleardevice();
                                                                        setbkcolor(LIGHTBLUE);
                                                                        settextstyle(BOLD_FONT,0,4);
                                                                        outtextxy(100,65,"Bubble sort");
                                                                        settextstyle(0,0,0);
                                                                        rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                                                                        floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                                                                        rectangle(bubble[5].x1-j,bubble[5].y1,bubble[5].x2-j,bubble[5].y2);
                                                                        floodfill(bubble[5].x1+5-j,bubble[5].y1+5,WHITE);
                                                                        for(int l=0; l<n; l++)
                                                                        {
                                                                            if(l!=4 && l!=5)
                                                                            {
                                                                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                                sprintf(c,"%d",a[l]);
                                                                                outtextxy(bubble[l].x1+15,315,c);
                                                                            }
                                                                        }
                                                                        sprintf(c,"%d",a[4]);
                                                                        outtextxy(bubble[4].x1+15+j,315,c);
                                                                        sprintf(c,"%d",a[5]);
                                                                        outtextxy(bubble[5].x1+15-j,315,c);
                                                                    }
                                                                    swap(bubble[5].y1,bubble[4].y1);
                                                                    swap(bubble[5].y2,bubble[4].y2);
                                                                    swap(a[4],a[5]);
                                                                }
                                                                else
                                                                {
                                                                    settextstyle(1,0,5);
                                                                    flag=0;
                                                                    outtextxy(102,400,"Wrong move.");
                                                                    settextstyle(0,0,0);
                                                                }
                                                                if(flag==1)
                                                                {
                                                                    settextstyle(1,0,2);
                                                                    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                                                                    settextstyle(0,0,0);
                                                                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                                    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                                                                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                                                                    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                                                                    if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                                                                    {
                                                                        for(int j=1; j<=45; j++)
                                                                        {
                                                                           delay(20);
                                                                            cleardevice();
                                                                            setbkcolor(LIGHTBLUE);
                                                                            settextstyle(BOLD_FONT,0,4);
                                                                            outtextxy(100,65,"Bubble sort");
                                                                            settextstyle(0,0,0);
                                                                            rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                                                                            floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                                                                            rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                                                                            floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                                                                            for(int l=0; l<n; l++)
                                                                            {
                                                                                if(l!=3 && l!=4)
                                                                                {
                                                                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                                    sprintf(c,"%d",a[l]);
                                                                                    outtextxy(bubble[l].x1+15,315,c);
                                                                                }
                                                                            }
                                                                            sprintf(c,"%d",a[3]);
                                                                            outtextxy(bubble[3].x1+15+j,315,c);
                                                                            sprintf(c,"%d",a[4]);
                                                                            outtextxy(bubble[4].x1+15-j,315,c);
                                                                        }
                                                                        swap(bubble[4].y1,bubble[3].y1);
                                                                        swap(bubble[4].y2,bubble[3].y2);
                                                                        swap(a[3],a[4]);
                                                                    }
                                                                    else if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
                                                                    {
                                                                        for(int j=1; j<=45; j++)
                                                                        {
                                                                           delay(20);
                                                                            cleardevice();
                                                                            setbkcolor(LIGHTBLUE);
                                                                            settextstyle(BOLD_FONT,0,4);
                                                                            outtextxy(100,65,"Bubble sort");
                                                                            settextstyle(0,0,0);
                                                                            rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                                                                            floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                                                                            rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                                                                            floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                                                                            for(int l=0; l<n; l++)
                                                                            {
                                                                                if(l!=3 && l!=4)
                                                                                {
                                                                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                                                    sprintf(c,"%d",a[l]);
                                                                                    outtextxy(bubble[l].x1+15,315,c);
                                                                                }
                                                                            }
                                                                            sprintf(c,"%d",a[3]);
                                                                            outtextxy(bubble[3].x1+15+j,315,c);
                                                                            sprintf(c,"%d",a[4]);
                                                                            outtextxy(bubble[4].x1+15-j,315,c);
                                                                        }
                                                                        swap(bubble[4].y1,bubble[3].y1);
                                                                        swap(bubble[4].y2,bubble[3].y2);
                                                                        swap(a[3],a[4]);
                                                                    }
                                                                    else
                                                                    {
                                                                        settextstyle(1,0,5);
                                                                        flag=0;
                                                                        outtextxy(102,400,"Wrong move.");
                                                                        settextstyle(0,0,0);
                                                                    }
                                                                    if(flag==1)
                                                                    {
                                                                        delay(1000);
                                                                        cleardevice();
                                                                        settextstyle(BOLD_FONT,0,5);
                                                                        outtextxy((getmaxx()/2)-100,(getmaxy()/2)-50,"Congratulation");
                                                                        outtextxy(100,(getmaxy()/2),"You have passed level 2");
                                                                        outtextxy((getmaxx()/2)-100,(getmaxy()/2)+50,"Thank you");
                                                                        settextstyle(0,0,0);
                                                                        delay(1000);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void selection_manual_1()
{
    f=fopen("level 1.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=280-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=300;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,0,5);
    outtextxy((getmaxx()/2)-100,getmaxy()/2,"LEVEL 1");
    settextstyle(0,0,0);
    delay(1000);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Selection sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }
    settextstyle(1,0,2);
    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
    settextstyle(0,0,0);
    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

    if(maxx>=bubble[0].x1 && maxx<=bubble[0].x2 && maxy>=bubble[0].y1 && maxy<=bubble[0].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
    {
        for(int j=1; j<=3*45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Selection sort");
            settextstyle(0,0,0);
            rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
            floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
            rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
            floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=0 && l!=3)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[0]);
            outtextxy(bubble[0].x1+15+j,315,c);
            sprintf(c,"%d",a[3]);
            outtextxy(bubble[3].x1+15-j,315,c);
        }
        swap(bubble[0].y1,bubble[3].y1);
        swap(bubble[0].y2,bubble[3].y2);
        swap(a[3],a[0]);
    }
    else if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[0].x1 && maxx1<=bubble[0].x2 && maxy1>=bubble[0].y1 && maxy1<=bubble[0].y2)
    {
        for(int j=1; j<=3*45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Selection sort");
            settextstyle(0,0,0);
            rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
            floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
            rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
            floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=0 && l!=3)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[0]);
            outtextxy(bubble[0].x1+15+j,315,c);
            sprintf(c,"%d",a[3]);
            outtextxy(bubble[3].x1+15-j,315,c);
        }
        swap(bubble[0].y1,bubble[3].y1);
        swap(bubble[0].y2,bubble[3].y2);
        swap(a[3],a[0]);
    }
    else
    {
        settextstyle(1,0,5);
        flag=0;
        outtextxy(102,400,"Wrong move.");
        settextstyle(0,0,0);
    }
    if(flag==1)
    {
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on two desired rectangle you want to swap.");
        settextstyle(0,0,0);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

        if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
        {
            for(int j=1; j<=2*45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Selection sort");
                settextstyle(0,0,0);
                rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=3 && l!=1)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[1]);
                outtextxy(bubble[1].x1+15+j,315,c);
                sprintf(c,"%d",a[3]);
                outtextxy(bubble[3].x1+15-j,315,c);
            }
            swap(bubble[3].y1,bubble[1].y1);
            swap(bubble[3].y2,bubble[1].y2);
            swap(a[1],a[3]);
        }
        else if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
        {
            for(int j=1; j<=2*45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Selection sort");
                settextstyle(0,0,0);
                rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=3 && l!=1)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[1]);
                outtextxy(bubble[1].x1+15+j,315,c);
                sprintf(c,"%d",a[3]);
                outtextxy(bubble[3].x1+15-j,315,c);
            }
            swap(bubble[3].y1,bubble[1].y1);
            swap(bubble[3].y2,bubble[1].y2);
            swap(a[1],a[3]);
        }
        else
        {
            settextstyle(1,0,5);
            flag=0;
            outtextxy(102,400,"Wrong move.");
            settextstyle(0,0,0);
        }
        if(flag==1)
        {
            settextstyle(1,0,2);
            outtextxy(102,150,"Click on two desired rectangle you want to swap.");
            settextstyle(0,0,0);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

            if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
            {
                for(int j=1; j<=2*45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Selection sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                    floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                    rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                    floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=2 && l!=4)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[2]);
                    outtextxy(bubble[2].x1+15+j,315,c);
                    sprintf(c,"%d",a[4]);
                    outtextxy(bubble[4].x1+15-j,315,c);
                }
                swap(bubble[4].y1,bubble[2].y1);
                swap(bubble[4].y2,bubble[2].y2);
                swap(a[2],a[4]);
            }
            else if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
            {
                for(int j=1; j<=2*45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Selection sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[2].x1+j,bubble[2].y1,bubble[2].x2+j,bubble[2].y2);
                    floodfill(bubble[2].x1+5+j,bubble[2].y1+5,WHITE);
                    rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                    floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=2 && l!=4)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[2]);
                    outtextxy(bubble[2].x1+15+j,315,c);
                    sprintf(c,"%d",a[4]);
                    outtextxy(bubble[4].x1+15-j,315,c);
                }
                swap(bubble[4].y1,bubble[2].y1);
                swap(bubble[4].y2,bubble[2].y2);
                swap(a[2],a[4]);
            }
            else
            {
                settextstyle(1,0,5);
                flag=0;
                outtextxy(102,400,"Wrong move.");
                settextstyle(0,0,0);
            }
            if(flag==1)
            {
                settextstyle(1,0,2);
                outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                settextstyle(0,0,0);
                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Selection sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                        floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                        rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                        floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=3 && l!=4)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[3]);
                        outtextxy(bubble[3].x1+15+j,315,c);
                        sprintf(c,"%d",a[4]);
                        outtextxy(bubble[4].x1+15-j,315,c);
                    }
                    swap(bubble[4].y1,bubble[3].y1);
                    swap(bubble[4].y2,bubble[3].y2);
                    swap(a[3],a[4]);
                }
                else if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Selection sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                        floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                        rectangle(bubble[4].x1-j,bubble[4].y1,bubble[4].x2-j,bubble[4].y2);
                        floodfill(bubble[4].x1+5-j,bubble[4].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=3 && l!=4)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[3]);
                        outtextxy(bubble[3].x1+15+j,315,c);
                        sprintf(c,"%d",a[4]);
                        outtextxy(bubble[4].x1+15-j,315,c);
                    }
                    swap(bubble[4].y1,bubble[3].y1);
                    swap(bubble[4].y2,bubble[3].y2);
                    swap(a[3],a[4]);
                }
                else
                {
                    settextstyle(1,0,5);
                    flag=0;
                    outtextxy(102,400,"Wrong move.");
                    settextstyle(0,0,0);
                }
                if(flag==1)
                {
                    delay(1000);
                    cleardevice();
                    settextstyle(BOLD_FONT,0,5);
                    outtextxy((getmaxx()/2)-150,(getmaxy()/2)-50,"Congratulation");
                    outtextxy(100,(getmaxy()/2),"You have passed level 1");
                    settextstyle(0,0,0);
                }
            }
        }
    }
}

void selection_manual_2()
{
    f=fopen("level 2.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=280-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=300;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,0,5);
    outtextxy((getmaxx()/2)-100,getmaxy()/2,"LEVEL 2");
    settextstyle(0,0,0);
    delay(2000);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Selection sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }
    settextstyle(1,0,2);
    outtextxy(102,150,"Click on two desired rectangle you want to swap.");
    settextstyle(0,0,0);
    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

    if(maxx>=bubble[0].x1 && maxx<=bubble[0].x2 && maxy>=bubble[0].y1 && maxy<=bubble[0].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Selection sort");
            settextstyle(0,0,0);
            rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
            floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
            rectangle(bubble[1].x1-j,bubble[1].y1,bubble[1].x2-j,bubble[1].y2);
            floodfill(bubble[1].x1+5-j,bubble[1].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=0 && l!=1)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[0]);
            outtextxy(bubble[0].x1+15+j,315,c);
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15-j,315,c);
        }
        swap(bubble[0].y1,bubble[1].y1);
        swap(bubble[0].y2,bubble[1].y2);
        swap(a[1],a[0]);
    }
    else if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[0].x1 && maxx1<=bubble[0].x2 && maxy1>=bubble[0].y1 && maxy1<=bubble[0].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Selection sort");
            settextstyle(0,0,0);
            rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
            floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
            rectangle(bubble[1].x1-j,bubble[1].y1,bubble[1].x2-j,bubble[1].y2);
            floodfill(bubble[1].x1+5-j,bubble[1].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=0 && l!=1)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[0]);
            outtextxy(bubble[0].x1+15+j,315,c);
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15-j,315,c);
        }
        swap(bubble[0].y1,bubble[1].y1);
        swap(bubble[0].y2,bubble[1].y2);
        swap(a[1],a[0]);
    }
    else
    {
        settextstyle(1,0,5);
        flag=0;
        outtextxy(102,400,"Wrong move.");
        settextstyle(0,0,0);
    }
    if(flag==1)
    {
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on two desired rectangle you want to swap.");
        settextstyle(0,0,0);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

        if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
        {
            for(int j=1; j<=2*45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Selection sort");
                settextstyle(0,0,0);
                rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=3 && l!=1)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[1]);
                outtextxy(bubble[1].x1+15+j,315,c);
                sprintf(c,"%d",a[3]);
                outtextxy(bubble[3].x1+15-j,315,c);
            }
            swap(bubble[3].y1,bubble[1].y1);
            swap(bubble[3].y2,bubble[1].y2);
            swap(a[1],a[3]);
        }
        else if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
        {
            for(int j=1; j<=2*45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Selection sort");
                settextstyle(0,0,0);
                rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                rectangle(bubble[3].x1-j,bubble[3].y1,bubble[3].x2-j,bubble[3].y2);
                floodfill(bubble[3].x1+5-j,bubble[3].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=3 && l!=1)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[1]);
                outtextxy(bubble[1].x1+15+j,315,c);
                sprintf(c,"%d",a[3]);
                outtextxy(bubble[3].x1+15-j,315,c);
            }
            swap(bubble[3].y1,bubble[1].y1);
            swap(bubble[3].y2,bubble[1].y2);
            swap(a[1],a[3]);
        }
        else
        {
            settextstyle(1,0,5);
            flag=0;
            outtextxy(102,400,"Wrong move.");
            settextstyle(0,0,0);
        }
        if(flag==1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

            if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[9].x1 && maxx1<=bubble[9].x2 && maxy1>=bubble[9].y1 && maxy1<=bubble[9].y2)
            {
                for(int j=1; j<=6*45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Selection sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                    floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                    rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                    floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=3 && l!=9)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[3]);
                    outtextxy(bubble[3].x1+15+j,315,c);
                    sprintf(c,"%d",a[9]);
                    outtextxy(bubble[9].x1+15-j,315,c);
                }
                swap(bubble[9].y1,bubble[3].y1);
                swap(bubble[9].y2,bubble[3].y2);
                swap(a[3],a[9]);
            }
            else if(maxx>=bubble[9].x1 && maxx<=bubble[9].x2 && maxy>=bubble[9].y1 && maxy<=bubble[9].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
            {
                for(int j=1; j<=6*45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Selection sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[3].x1+j,bubble[3].y1,bubble[3].x2+j,bubble[3].y2);
                    floodfill(bubble[3].x1+5+j,bubble[3].y1+5,WHITE);
                    rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                    floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=3 && l!=9)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[3]);
                    outtextxy(bubble[3].x1+15+j,315,c);
                    sprintf(c,"%d",a[9]);
                    outtextxy(bubble[9].x1+15-j,315,c);
                }
                swap(bubble[9].y1,bubble[3].y1);
                swap(bubble[9].y2,bubble[3].y2);
                swap(a[3],a[9]);
            }
            else
            {
                settextstyle(1,0,5);
                flag=0;
                outtextxy(102,400,"Wrong move.");
                settextstyle(0,0,0);
            }
            if(flag==1)
            {
                settextstyle(1,0,2);
                outtextxy(102,150,"Click on two desired rectangle you want to swap.");
                settextstyle(0,0,0);
                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[6].x1 && maxx1<=bubble[6].x2 && maxy1>=bubble[6].y1 && maxy1<=bubble[6].y2)
                {
                    for(int j=1; j<=2*45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Selection sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                        floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                        rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                        floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=4 && l!=6)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[4]);
                        outtextxy(bubble[4].x1+15+j,315,c);
                        sprintf(c,"%d",a[6]);
                        outtextxy(bubble[6].x1+15-j,315,c);
                    }
                    swap(bubble[6].y1,bubble[4].y1);
                    swap(bubble[6].y2,bubble[4].y2);
                    swap(a[4],a[6]);
                }
                else if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                {
                    for(int j=1; j<=2*45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Selection sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                        floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                        rectangle(bubble[6].x1-j,bubble[6].y1,bubble[6].x2-j,bubble[6].y2);
                        floodfill(bubble[6].x1+5-j,bubble[6].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=4 && l!=6)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[4]);
                        outtextxy(bubble[4].x1+15+j,315,c);
                        sprintf(c,"%d",a[6]);
                        outtextxy(bubble[6].x1+15-j,315,c);
                    }
                    swap(bubble[6].y1,bubble[4].y1);
                    swap(bubble[6].y2,bubble[4].y2);
                    swap(a[4],a[6]);
                }
                else
                {
                    settextstyle(1,0,5);
                    flag=0;
                    outtextxy(102,400,"Wrong move.");
                    settextstyle(0,0,0);
                }
                if(flag==1)
                {
                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                    if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[9].x1 && maxx1<=bubble[9].x2 && maxy1>=bubble[9].y1 && maxy1<=bubble[9].y2)
                    {
                        for(int j=1; j<=4*45; j++)
                        {
                           delay(20);
                            cleardevice();
                            setbkcolor(LIGHTBLUE);
                            settextstyle(BOLD_FONT,0,4);
                            outtextxy(100,65,"Selection sort");
                            settextstyle(0,0,0);
                            rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                            floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                            rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                            floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                            for(int l=0; l<n; l++)
                            {
                                if(l!=5 && l!=9)
                                {
                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                    sprintf(c,"%d",a[l]);
                                    outtextxy(bubble[l].x1+15,315,c);
                                }
                            }
                            sprintf(c,"%d",a[5]);
                            outtextxy(bubble[5].x1+15+j,315,c);
                            sprintf(c,"%d",a[9]);
                            outtextxy(bubble[9].x1+15-j,315,c);
                        }
                        swap(bubble[9].y1,bubble[5].y1);
                        swap(bubble[9].y2,bubble[5].y2);
                        swap(a[5],a[9]);
                    }
                    else if(maxx>=bubble[9].x1 && maxx<=bubble[9].x2 && maxy>=bubble[9].y1 && maxy<=bubble[9].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                    {
                        for(int j=1; j<=4*45; j++)
                        {
                           delay(20);
                            cleardevice();
                            setbkcolor(LIGHTBLUE);
                            settextstyle(BOLD_FONT,0,4);
                            outtextxy(100,65,"Selection sort");
                            settextstyle(0,0,0);
                            rectangle(bubble[5].x1+j,bubble[5].y1,bubble[5].x2+j,bubble[5].y2);
                            floodfill(bubble[5].x1+5+j,bubble[5].y1+5,WHITE);
                            rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                            floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                            for(int l=0; l<n; l++)
                            {
                                if(l!=5 && l!=9)
                                {
                                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                    sprintf(c,"%d",a[l]);
                                    outtextxy(bubble[l].x1+15,315,c);
                                }
                            }
                            sprintf(c,"%d",a[5]);
                            outtextxy(bubble[5].x1+15+j,315,c);
                            sprintf(c,"%d",a[9]);
                            outtextxy(bubble[9].x1+15-j,315,c);
                        }
                        swap(bubble[9].y1,bubble[5].y1);
                        swap(bubble[9].y2,bubble[5].y2);
                        swap(a[5],a[9]);
                    }
                    else
                    {
                        settextstyle(1,0,5);
                        flag=0;
                        outtextxy(102,400,"Wrong move.");
                        settextstyle(0,0,0);
                    }

                    if(flag==1)
                    {
                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                        if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[8].x1 && maxx1<=bubble[8].x2 && maxy1>=bubble[8].y1 && maxy1<=bubble[8].y2)
                        {
                            for(int j=1; j<=2*45; j++)
                            {
                               delay(20);
                                cleardevice();
                                setbkcolor(LIGHTBLUE);
                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Selection sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[6].x1+j,bubble[6].y1,bubble[6].x2+j,bubble[6].y2);
                                floodfill(bubble[6].x1+5+j,bubble[6].y1+5,WHITE);
                                rectangle(bubble[8].x1-j,bubble[8].y1,bubble[8].x2-j,bubble[8].y2);
                                floodfill(bubble[8].x1+5-j,bubble[8].y1+5,WHITE);
                                for(int l=0; l<n; l++)
                                {
                                    if(l!=6 && l!=8)
                                    {
                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                        sprintf(c,"%d",a[l]);
                                        outtextxy(bubble[l].x1+15,315,c);
                                    }
                                }
                                sprintf(c,"%d",a[6]);
                                outtextxy(bubble[6].x1+15+j,315,c);
                                sprintf(c,"%d",a[8]);
                                outtextxy(bubble[8].x1+15-j,315,c);
                            }
                            swap(bubble[8].y1,bubble[6].y1);
                            swap(bubble[8].y2,bubble[6].y2);
                            swap(a[6],a[8]);
                        }
                        else if(maxx>=bubble[8].x1 && maxx<=bubble[8].x2 && maxy>=bubble[8].y1 && maxy<=bubble[8].y2 && maxx1>=bubble[6].x1 && maxx1<=bubble[6].x2 && maxy1>=bubble[6].y1 && maxy1<=bubble[6].y2)
                        {
                            for(int j=1; j<=2*45; j++)
                            {
                               delay(20);
                                cleardevice();
                                setbkcolor(LIGHTBLUE);
                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Selection sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[6].x1+j,bubble[6].y1,bubble[6].x2+j,bubble[6].y2);
                                floodfill(bubble[6].x1+5+j,bubble[6].y1+5,WHITE);
                                rectangle(bubble[8].x1-j,bubble[8].y1,bubble[8].x2-j,bubble[8].y2);
                                floodfill(bubble[8].x1+5-j,bubble[8].y1+5,WHITE);
                                for(int l=0; l<n; l++)
                                {
                                    if(l!=6 && l!=8)
                                    {
                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                        sprintf(c,"%d",a[l]);
                                        outtextxy(bubble[l].x1+15,315,c);
                                    }
                                }
                                sprintf(c,"%d",a[6]);
                                outtextxy(bubble[6].x1+15+j,315,c);
                                sprintf(c,"%d",a[8]);
                                outtextxy(bubble[8].x1+15-j,315,c);
                            }
                            swap(bubble[8].y1,bubble[6].y1);
                            swap(bubble[8].y2,bubble[6].y2);
                            swap(a[6],a[8]);
                        }
                        else
                        {
                            settextstyle(1,0,5);
                            flag=0;
                            outtextxy(102,400,"Wrong move.");
                            settextstyle(0,0,0);
                        }

                        if(flag==1)
                        {
                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);

                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);

                            if(maxx>=bubble[7].x1 && maxx<=bubble[7].x2 && maxy>=bubble[7].y1 && maxy<=bubble[7].y2 && maxx1>=bubble[9].x1 && maxx1<=bubble[9].x2 && maxy1>=bubble[9].y1 && maxy1<=bubble[9].y2)
                            {
                                for(int j=1; j<=2*45; j++)
                                {
                                   delay(20);
                                    cleardevice();
                                    setbkcolor(LIGHTBLUE);
                                    settextstyle(BOLD_FONT,0,4);
                                    outtextxy(100,65,"Selection sort");
                                    settextstyle(0,0,0);
                                    rectangle(bubble[7].x1+j,bubble[7].y1,bubble[7].x2+j,bubble[7].y2);
                                    floodfill(bubble[7].x1+5+j,bubble[7].y1+5,WHITE);
                                    rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                                    floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                                    for(int l=0; l<n; l++)
                                    {
                                        if(l!=7 && l!=9)
                                        {
                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                            sprintf(c,"%d",a[l]);
                                            outtextxy(bubble[l].x1+15,315,c);
                                        }
                                    }
                                    sprintf(c,"%d",a[7]);
                                    outtextxy(bubble[7].x1+15+j,315,c);
                                    sprintf(c,"%d",a[9]);
                                    outtextxy(bubble[9].x1+15-j,315,c);
                                }
                                swap(bubble[9].y1,bubble[7].y1);
                                swap(bubble[9].y2,bubble[7].y2);
                                swap(a[7],a[9]);
                            }
                            else if(maxx>=bubble[9].x1 && maxx<=bubble[9].x2 && maxy>=bubble[9].y1 && maxy<=bubble[9].y2 && maxx1>=bubble[7].x1 && maxx1<=bubble[7].x2 && maxy1>=bubble[7].y1 && maxy1<=bubble[7].y2)
                            {
                                for(int j=1; j<=2*45; j++)
                                {
                                   delay(20);
                                    cleardevice();
                                    setbkcolor(LIGHTBLUE);
                                    settextstyle(BOLD_FONT,0,4);
                                    outtextxy(100,65,"Selection sort");
                                    settextstyle(0,0,0);
                                    rectangle(bubble[7].x1+j,bubble[7].y1,bubble[7].x2+j,bubble[7].y2);
                                    floodfill(bubble[7].x1+5+j,bubble[7].y1+5,WHITE);
                                    rectangle(bubble[9].x1-j,bubble[9].y1,bubble[9].x2-j,bubble[9].y2);
                                    floodfill(bubble[9].x1+5-j,bubble[9].y1+5,WHITE);
                                    for(int l=0; l<n; l++)
                                    {
                                        if(l!=7 && l!=9)
                                        {
                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                            sprintf(c,"%d",a[l]);
                                            outtextxy(bubble[l].x1+15,315,c);
                                        }
                                    }
                                    sprintf(c,"%d",a[7]);
                                    outtextxy(bubble[7].x1+15+j,315,c);
                                    sprintf(c,"%d",a[9]);
                                    outtextxy(bubble[9].x1+15-j,315,c);
                                }
                                swap(bubble[9].y1,bubble[7].y1);
                                swap(bubble[9].y2,bubble[7].y2);
                                swap(a[7],a[9]);
                            }
                            else
                            {
                                settextstyle(1,0,5);
                                flag=0;
                                outtextxy(102,400,"Wrong move.");
                                settextstyle(0,0,0);
                            }
                            if(flag==1)
                            {
                                delay(1000);
                                cleardevice();
                                settextstyle(BOLD_FONT,0,5);
                                outtextxy((getmaxx()/2)-100,(getmaxy()/2)-50,"Congratulation");
                                outtextxy(100,(getmaxy()/2),"You have passed level 2");
                                outtextxy((getmaxx()/2)-100,(getmaxy()/2)+50,"Thank you");
                                settextstyle(0,0,0);
                                delay(1000);
                            }
                        }
                    }
                }
            }
        }
    }
}

void insertion_manual_1()
{
    f=fopen("level 1.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=280-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=300;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,0,5);
    outtextxy((getmaxx()/2)-100,getmaxy()/2,"LEVEL 1");
    settextstyle(0,0,0);
    delay(1000);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Insertion sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }
    settextstyle(1,0,2);
    outtextxy(102,150,"Click on a rectangle that you want to move.");
    settextstyle(0,0,0);
    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


    delay(50);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Insertion sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }
    settextstyle(1,0,2);
    outtextxy(102,150,"Click on a rectangle where you want to");
    outtextxy(102,175,"insert the chosen rectangle");
    settextstyle(0,0,0);

    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


    if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Insertion sort");
            settextstyle(0,0,0);
            rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
            floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
            rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
            floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=1 && l!=2)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15+j,315,c);
            sprintf(c,"%d",a[2]);
            outtextxy(bubble[2].x1+15-j,315,c);
        }
        swap(bubble[1].y1,bubble[2].y1);
        swap(bubble[2].y2,bubble[2].y2);
        swap(a[1],a[2]);
    }
    else
    {
        settextstyle(1,0,5);
        flag=0;
        outtextxy(102,400,"Wrong move.");
        settextstyle(0,0,0);
    }
    if(flag==1)
    {
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on a rectangle that you want to move.");
        settextstyle(0,0,0);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


        delay(50);
        cleardevice();
        for(int i=0; i<n; i++)
        {

            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Insertion sort");
            settextstyle(0,0,0);
            rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
            setfillstyle(1,BLUE);
            floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
            sprintf(c,"%d",a[i]);
            outtextxy(bubble[i].x1+15,315,c);
        }
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on a rectangle where you want to");
        outtextxy(102,175,"insert the chosen rectangle");
        settextstyle(0,0,0);

        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


        if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[0].x1 && maxx1<=bubble[0].x2 && maxy1>=bubble[0].y1 && maxy1<=bubble[0].y2)
        {
            t=3;
            while(t)
            {
                for(int j=1; j<=45; j++)
                {
                   delay(20);
                    cleardevice();
                    setbkcolor(LIGHTBLUE);
                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Insertion sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[t-1].x1+j,bubble[t-1].y1,bubble[t-1].x2+j,bubble[t-1].y2);
                    floodfill(bubble[t-1].x1+5+j,bubble[t-1].y1+5,WHITE);
                    rectangle(bubble[t].x1-j,bubble[t].y1,bubble[t].x2-j,bubble[t].y2);
                    floodfill(bubble[t].x1+5-j,bubble[t].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=t && l!=t-1)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,315,c);
                        }
                    }
                    sprintf(c,"%d",a[t-1]);
                    outtextxy(bubble[t-1].x1+15+j,315,c);
                    sprintf(c,"%d",a[t]);
                    outtextxy(bubble[t].x1+15-j,315,c);
                }
                swap(bubble[t-1].y1,bubble[t].y1);
                swap(bubble[t-1].y2,bubble[t].y2);
                swap(a[t-1],a[t]);
                t--;
            }
        }
        else
        {
            settextstyle(1,0,5);
            flag=0;
            outtextxy(102,400,"Wrong move.");
            settextstyle(0,0,0);
        }
        if(flag==1)
        {
            settextstyle(1,0,2);
            outtextxy(102,150,"Click on a rectangle that you want to move.");
            settextstyle(0,0,0);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


            delay(50);
            cleardevice();
            for(int i=0; i<n; i++)
            {

                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Insertion sort");
                settextstyle(0,0,0);
                rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
                setfillstyle(1,BLUE);
                floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
                sprintf(c,"%d",a[i]);
                outtextxy(bubble[i].x1+15,315,c);
            }
            settextstyle(1,0,2);
            outtextxy(102,150,"Click on a rectangle where you want to");
            outtextxy(102,175,"insert the chosen rectangle");
            settextstyle(0,0,0);

            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


            if(maxx>=bubble[4].x1 && maxx<=bubble[4].x2 && maxy>=bubble[4].y1 && maxy<=bubble[4].y2 && maxx1>=bubble[2].x1 && maxx1<=bubble[2].x2 && maxy1>=bubble[2].y1 && maxy1<=bubble[2].y2)
            {
                t=4;
                while(t>=3)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Insertion sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[t-1].x1+j,bubble[t-1].y1,bubble[t-1].x2+j,bubble[t-1].y2);
                        floodfill(bubble[t-1].x1+5+j,bubble[t-1].y1+5,WHITE);
                        rectangle(bubble[t].x1-j,bubble[t].y1,bubble[t].x2-j,bubble[t].y2);
                        floodfill(bubble[t].x1+5-j,bubble[t].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=t && l!=t-1)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[t-1]);
                        outtextxy(bubble[t-1].x1+15+j,315,c);
                        sprintf(c,"%d",a[t]);
                        outtextxy(bubble[t].x1+15-j,315,c);
                    }
                    swap(bubble[t-1].y1,bubble[t].y1);
                    swap(bubble[t-1].y2,bubble[t].y2);
                    swap(a[t-1],a[t]);
                    t--;
                }
            }
            else
            {
                settextstyle(1,0,5);
                flag=0;
                outtextxy(102,400,"Wrong move.");
                settextstyle(0,0,0);
            }
            if(flag==1)
            {
                delay(1000);
                cleardevice();
                settextstyle(BOLD_FONT,0,5);
                outtextxy((getmaxx()/2)-150,(getmaxy()/2)-50,"Congratulation");
                outtextxy(100,(getmaxy()/2),"You have passed level 1");
                settextstyle(0,0,0);
            }
        }
    }
}

void insertion_manual_2()
{
    f=fopen("level 2.txt","r");
    fscanf(f,"%d",&n);
    setbkcolor(LIGHTBLUE);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=280-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=300;
        t+=45;
    }
    delay(50);
    cleardevice();
    setbkcolor(LIGHTBLUE);
    settextstyle(BOLD_FONT,0,5);
    outtextxy((getmaxx()/2)-100,getmaxy()/2,"LEVEL 2");
    settextstyle(0,0,0);
    delay(2000);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Insertion sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }

    settextstyle(1,0,2);
    outtextxy(102,150,"Click on a rectangle that you want to move.");
    settextstyle(0,0,0);
    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


    delay(50);
    cleardevice();
    for(int i=0; i<n; i++)
    {

        settextstyle(BOLD_FONT,0,4);
        outtextxy(100,65,"Insertion sort");
        settextstyle(0,0,0);
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,315,c);
    }
    settextstyle(1,0,2);
    outtextxy(102,150,"Click on a rectangle where you want to");
    outtextxy(102,175,"insert the chosen rectangle");
    settextstyle(0,0,0);

    while(!ismouseclick(WM_LBUTTONDOWN)) {}
    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


    if(maxx>=bubble[1].x1 && maxx<=bubble[1].x2 && maxy>=bubble[1].y1 && maxy<=bubble[1].y2 && maxx1>=bubble[0].x1 && maxx1<=bubble[0].x2 && maxy1>=bubble[0].y1 && maxy1<=bubble[0].y2)
    {
        for(int j=1; j<=45; j++)
        {
           delay(20);
            cleardevice();
            setbkcolor(LIGHTBLUE);
            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Insertion sort");
            settextstyle(0,0,0);
            rectangle(bubble[0].x1+j,bubble[0].y1,bubble[0].x2+j,bubble[0].y2);
            floodfill(bubble[0].x1+5+j,bubble[0].y1+5,WHITE);
            rectangle(bubble[1].x1-j,bubble[1].y1,bubble[1].x2-j,bubble[1].y2);
            floodfill(bubble[1].x1+5-j,bubble[1].y1+5,WHITE);
            for(int l=0; l<n; l++)
            {
                if(l!=0 && l!=1)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,315,c);
                }
            }
            sprintf(c,"%d",a[0]);
            outtextxy(bubble[0].x1+15+j,315,c);
            sprintf(c,"%d",a[1]);
            outtextxy(bubble[1].x1+15-j,315,c);
        }
        swap(bubble[0].y1,bubble[1].y1);
        swap(bubble[0].y2,bubble[1].y2);
        swap(a[1],a[0]);
    }
    else
    {
        settextstyle(1,0,5);
        flag=0;
        outtextxy(102,400,"Wrong move.");
        settextstyle(0,0,0);
    }
    if(flag==1)
    {
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on a rectangle that you want to move.");
        settextstyle(0,0,0);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


        delay(50);
        cleardevice();
        for(int i=0; i<n; i++)
        {

            settextstyle(BOLD_FONT,0,4);
            outtextxy(100,65,"Insertion sort");
            settextstyle(0,0,0);
            rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
            setfillstyle(1,BLUE);
            floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
            sprintf(c,"%d",a[i]);
            outtextxy(bubble[i].x1+15,315,c);
        }
        settextstyle(1,0,2);
        outtextxy(102,150,"Click on a rectangle where you want to");
        outtextxy(102,175,"insert the chosen rectangle");
        settextstyle(0,0,0);

        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


        if(maxx>=bubble[2].x1 && maxx<=bubble[2].x2 && maxy>=bubble[2].y1 && maxy<=bubble[2].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
        {
            for(int j=1; j<=45; j++)
            {
               delay(20);
                cleardevice();
                setbkcolor(LIGHTBLUE);
                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Insertion sort");
                settextstyle(0,0,0);
                rectangle(bubble[1].x1+j,bubble[1].y1,bubble[1].x2+j,bubble[1].y2);
                floodfill(bubble[1].x1+5+j,bubble[1].y1+5,WHITE);
                rectangle(bubble[2].x1-j,bubble[2].y1,bubble[2].x2-j,bubble[2].y2);
                floodfill(bubble[2].x1+5-j,bubble[2].y1+5,WHITE);
                for(int l=0; l<n; l++)
                {
                    if(l!=1 && l!=2)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                        sprintf(c,"%d",a[l]);
                        outtextxy(bubble[l].x1+15,315,c);
                    }
                }
                sprintf(c,"%d",a[1]);
                outtextxy(bubble[1].x1+15+j,315,c);
                sprintf(c,"%d",a[2]);
                outtextxy(bubble[2].x1+15-j,315,c);
            }
            swap(bubble[1].y1,bubble[2].y1);
            swap(bubble[2].y2,bubble[2].y2);
            swap(a[1],a[2]);
        }
        else
        {
            settextstyle(1,0,5);
            flag=0;
            outtextxy(102,400,"Wrong move.");
            settextstyle(0,0,0);
        }
        if(flag==1)
        {

            settextstyle(1,0,2);
            outtextxy(102,150,"Click on a rectangle that you want to move.");
            settextstyle(0,0,0);
            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


            delay(50);
            cleardevice();
            for(int i=0; i<n; i++)
            {

                settextstyle(BOLD_FONT,0,4);
                outtextxy(100,65,"Insertion sort");
                settextstyle(0,0,0);
                rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
                setfillstyle(1,BLUE);
                floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
                sprintf(c,"%d",a[i]);
                outtextxy(bubble[i].x1+15,315,c);
            }
            settextstyle(1,0,2);
            outtextxy(102,150,"Click on a rectangle where you want to");
            outtextxy(102,175,"insert the chosen rectangle");
            settextstyle(0,0,0);

            while(!ismouseclick(WM_LBUTTONDOWN)) {}
            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


            if(maxx>=bubble[3].x1 && maxx<=bubble[3].x2 && maxy>=bubble[3].y1 && maxy<=bubble[3].y2 && maxx1>=bubble[1].x1 && maxx1<=bubble[1].x2 && maxy1>=bubble[1].y1 && maxy1<=bubble[1].y2)
            {
                t=3;
                while(t>=2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Insertion sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[t-1].x1+j,bubble[t-1].y1,bubble[t-1].x2+j,bubble[t-1].y2);
                        floodfill(bubble[t-1].x1+5+j,bubble[t-1].y1+5,WHITE);
                        rectangle(bubble[t].x1-j,bubble[t].y1,bubble[t].x2-j,bubble[t].y2);
                        floodfill(bubble[t].x1+5-j,bubble[t].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=t && l!=t-1)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[t-1]);
                        outtextxy(bubble[t-1].x1+15+j,315,c);
                        sprintf(c,"%d",a[t]);
                        outtextxy(bubble[t].x1+15-j,315,c);
                    }
                    swap(bubble[t-1].y1,bubble[t].y1);
                    swap(bubble[t-1].y2,bubble[t].y2);
                    swap(a[t-1],a[t]);
                    t--;
                }
            }
            else
            {
                settextstyle(1,0,5);
                flag=0;
                outtextxy(102,400,"Wrong move.");
                settextstyle(0,0,0);
            }

            if(flag==1)
            {
                settextstyle(1,0,2);
                outtextxy(102,150,"Click on a rectangle that you want to move.");
                settextstyle(0,0,0);
                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


                delay(50);
                cleardevice();
                for(int i=0; i<n; i++)
                {

                    settextstyle(BOLD_FONT,0,4);
                    outtextxy(100,65,"Insertion sort");
                    settextstyle(0,0,0);
                    rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
                    setfillstyle(1,BLUE);
                    floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
                    sprintf(c,"%d",a[i]);
                    outtextxy(bubble[i].x1+15,315,c);
                }
                settextstyle(1,0,2);
                outtextxy(102,150,"Click on a rectangle where you want to");
                outtextxy(102,175,"insert the chosen rectangle");
                settextstyle(0,0,0);

                while(!ismouseclick(WM_LBUTTONDOWN)) {}
                getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


                if(maxx>=bubble[5].x1 && maxx<=bubble[5].x2 && maxy>=bubble[5].y1 && maxy<=bubble[5].y2 && maxx1>=bubble[4].x1 && maxx1<=bubble[4].x2 && maxy1>=bubble[4].y1 && maxy1<=bubble[4].y2)
                {
                    for(int j=1; j<=45; j++)
                    {
                       delay(20);
                        cleardevice();
                        setbkcolor(LIGHTBLUE);
                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Insertion sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[4].x1+j,bubble[4].y1,bubble[4].x2+j,bubble[4].y2);
                        floodfill(bubble[4].x1+5+j,bubble[4].y1+5,WHITE);
                        rectangle(bubble[5].x1-j,bubble[5].y1,bubble[5].x2-j,bubble[5].y2);
                        floodfill(bubble[5].x1+5-j,bubble[5].y1+5,WHITE);
                        for(int l=0; l<n; l++)
                        {
                            if(l!=4 && l!=5)
                            {
                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                sprintf(c,"%d",a[l]);
                                outtextxy(bubble[l].x1+15,315,c);
                            }
                        }
                        sprintf(c,"%d",a[4]);
                        outtextxy(bubble[4].x1+15+j,315,c);
                        sprintf(c,"%d",a[5]);
                        outtextxy(bubble[5].x1+15-j,315,c);
                    }
                    swap(bubble[5].y1,bubble[4].y1);
                    swap(bubble[5].y2,bubble[4].y2);
                    swap(a[4],a[5]);
                }
                else
                {
                    settextstyle(1,0,5);
                    flag=0;
                    outtextxy(102,400,"Wrong move.");
                    settextstyle(0,0,0);
                }

                if(flag==1)
                {
                    settextstyle(1,0,2);
                    outtextxy(102,150,"Click on a rectangle that you want to move.");
                    settextstyle(0,0,0);
                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


                    delay(50);
                    cleardevice();
                    for(int i=0; i<n; i++)
                    {

                        settextstyle(BOLD_FONT,0,4);
                        outtextxy(100,65,"Insertion sort");
                        settextstyle(0,0,0);
                        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
                        setfillstyle(1,BLUE);
                        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
                        sprintf(c,"%d",a[i]);
                        outtextxy(bubble[i].x1+15,315,c);
                    }
                    settextstyle(1,0,2);
                    outtextxy(102,150,"Click on a rectangle where you want to");
                    outtextxy(102,175,"insert the chosen rectangle");
                    settextstyle(0,0,0);

                    while(!ismouseclick(WM_LBUTTONDOWN)) {}
                    getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


                    if(maxx>=bubble[6].x1 && maxx<=bubble[6].x2 && maxy>=bubble[6].y1 && maxy<=bubble[6].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
                    {
                        t=6;
                        while(t>=4)
                        {
                            for(int j=1; j<=45; j++)
                            {
                               delay(20);
                                cleardevice();
                                setbkcolor(LIGHTBLUE);
                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Insertion sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[t-1].x1+j,bubble[t-1].y1,bubble[t-1].x2+j,bubble[t-1].y2);
                                floodfill(bubble[t-1].x1+5+j,bubble[t-1].y1+5,WHITE);
                                rectangle(bubble[t].x1-j,bubble[t].y1,bubble[t].x2-j,bubble[t].y2);
                                floodfill(bubble[t].x1+5-j,bubble[t].y1+5,WHITE);
                                for(int l=0; l<n; l++)
                                {
                                    if(l!=t && l!=t-1)
                                    {
                                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                        floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                        sprintf(c,"%d",a[l]);
                                        outtextxy(bubble[l].x1+15,315,c);
                                    }
                                }
                                sprintf(c,"%d",a[t-1]);
                                outtextxy(bubble[t-1].x1+15+j,315,c);
                                sprintf(c,"%d",a[t]);
                                outtextxy(bubble[t].x1+15-j,315,c);
                            }
                            swap(bubble[t-1].y1,bubble[t].y1);
                            swap(bubble[t-1].y2,bubble[t].y2);
                            swap(a[t-1],a[t]);
                            t--;
                        }
                    }
                    else
                    {
                        settextstyle(1,0,5);
                        flag=0;
                        outtextxy(102,400,"Wrong move.");
                        settextstyle(0,0,0);
                    }

                    if(flag==1)
                    {
                        settextstyle(1,0,2);
                        outtextxy(102,150,"Click on a rectangle that you want to move.");
                        settextstyle(0,0,0);
                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


                        delay(50);
                        cleardevice();
                        for(int i=0; i<n; i++)
                        {

                            settextstyle(BOLD_FONT,0,4);
                            outtextxy(100,65,"Insertion sort");
                            settextstyle(0,0,0);
                            rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
                            setfillstyle(1,BLUE);
                            floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
                            sprintf(c,"%d",a[i]);
                            outtextxy(bubble[i].x1+15,315,c);
                        }
                        settextstyle(1,0,2);
                        outtextxy(102,150,"Click on a rectangle where you want to");
                        outtextxy(102,175,"insert the chosen rectangle");
                        settextstyle(0,0,0);

                        while(!ismouseclick(WM_LBUTTONDOWN)) {}
                        getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


                        if(maxx>=bubble[8].x1 && maxx<=bubble[8].x2 && maxy>=bubble[8].y1 && maxy<=bubble[8].y2 && maxx1>=bubble[5].x1 && maxx1<=bubble[5].x2 && maxy1>=bubble[5].y1 && maxy1<=bubble[5].y2)
                        {
                            t=8;
                            while(t>=6)
                            {
                                for(int j=1; j<=45; j++)
                                {
                                   delay(20);
                                    cleardevice();
                                    setbkcolor(LIGHTBLUE);
                                    settextstyle(BOLD_FONT,0,4);
                                    outtextxy(100,65,"Insertion sort");
                                    settextstyle(0,0,0);
                                    rectangle(bubble[t-1].x1+j,bubble[t-1].y1,bubble[t-1].x2+j,bubble[t-1].y2);
                                    floodfill(bubble[t-1].x1+5+j,bubble[t-1].y1+5,WHITE);
                                    rectangle(bubble[t].x1-j,bubble[t].y1,bubble[t].x2-j,bubble[t].y2);
                                    floodfill(bubble[t].x1+5-j,bubble[t].y1+5,WHITE);
                                    for(int l=0; l<n; l++)
                                    {
                                        if(l!=t && l!=t-1)
                                        {
                                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                            sprintf(c,"%d",a[l]);
                                            outtextxy(bubble[l].x1+15,315,c);
                                        }
                                    }
                                    sprintf(c,"%d",a[t-1]);
                                    outtextxy(bubble[t-1].x1+15+j,315,c);
                                    sprintf(c,"%d",a[t]);
                                    outtextxy(bubble[t].x1+15-j,315,c);
                                }
                                swap(bubble[t-1].y1,bubble[t].y1);
                                swap(bubble[t-1].y2,bubble[t].y2);
                                swap(a[t-1],a[t]);
                                t--;
                            }
                        }
                        else
                        {
                            settextstyle(1,0,5);
                            flag=0;
                            outtextxy(102,400,"Wrong move.");
                            settextstyle(0,0,0);
                        }

                        if(flag==1)
                        {
                            settextstyle(1,0,2);
                            outtextxy(102,150,"Click on a rectangle that you want to move.");
                            settextstyle(0,0,0);
                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                            getmouseclick(WM_LBUTTONDOWN,maxx,maxy);


                            delay(50);
                            cleardevice();
                            for(int i=0; i<n; i++)
                            {

                                settextstyle(BOLD_FONT,0,4);
                                outtextxy(100,65,"Insertion sort");
                                settextstyle(0,0,0);
                                rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
                                setfillstyle(1,BLUE);
                                floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
                                sprintf(c,"%d",a[i]);
                                outtextxy(bubble[i].x1+15,315,c);
                            }
                            settextstyle(1,0,2);
                            outtextxy(102,150,"Click on a rectangle where you want to");
                            outtextxy(102,175,"insert the chosen rectangle");
                            settextstyle(0,0,0);

                            while(!ismouseclick(WM_LBUTTONDOWN)) {}
                            getmouseclick(WM_LBUTTONDOWN,maxx1,maxy1);


                            if(maxx>=bubble[9].x1 && maxx<=bubble[9].x2 && maxy>=bubble[9].y1 && maxy<=bubble[9].y2 && maxx1>=bubble[3].x1 && maxx1<=bubble[3].x2 && maxy1>=bubble[3].y1 && maxy1<=bubble[3].y2)
                            {
                                t=9;
                                while(t>=4)
                                {
                                    for(int j=1; j<=45; j++)
                                    {
                                       delay(20);
                                        cleardevice();
                                        setbkcolor(LIGHTBLUE);
                                        settextstyle(BOLD_FONT,0,4);
                                        outtextxy(100,65,"Insertion sort");
                                        settextstyle(0,0,0);
                                        rectangle(bubble[t-1].x1+j,bubble[t-1].y1,bubble[t-1].x2+j,bubble[t-1].y2);
                                        floodfill(bubble[t-1].x1+5+j,bubble[t-1].y1+5,WHITE);
                                        rectangle(bubble[t].x1-j,bubble[t].y1,bubble[t].x2-j,bubble[t].y2);
                                        floodfill(bubble[t].x1+5-j,bubble[t].y1+5,WHITE);
                                        for(int l=0; l<n; l++)
                                        {
                                            if(l!=t && l!=t-1)
                                            {
                                                rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                                                floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                                                sprintf(c,"%d",a[l]);
                                                outtextxy(bubble[l].x1+15,315,c);
                                            }
                                        }
                                        sprintf(c,"%d",a[t-1]);
                                        outtextxy(bubble[t-1].x1+15+j,315,c);
                                        sprintf(c,"%d",a[t]);
                                        outtextxy(bubble[t].x1+15-j,315,c);
                                    }
                                    swap(bubble[t-1].y1,bubble[t].y1);
                                    swap(bubble[t-1].y2,bubble[t].y2);
                                    swap(a[t-1],a[t]);
                                    t--;
                                }
                            }
                            else
                            {
                                settextstyle(1,0,5);
                                flag=0;
                                outtextxy(102,400,"Wrong move.");
                                settextstyle(0,0,0);
                            }
                            if(flag==1)
                            {
                                delay(1000);
                                cleardevice();
                                settextstyle(BOLD_FONT,0,5);
                                outtextxy((getmaxx()/2)-100,(getmaxy()/2)-50,"Congratulation");
                                outtextxy(100,(getmaxy()/2),"You have passed level 2");
                                outtextxy((getmaxx()/2)-100,(getmaxy()/2)+50,"Thank you");
                                settextstyle(0,0,0);
                                delay(1000);
                            }
                        }
                    }
                }
            }
        }
    }
}


void bubble_pseudocode()
{
    settextstyle(BOLD_FONT,0,4);
    outtextxy(495,102+3,"Pseudo-code");
    settextstyle(0,0,0);
    rectangle(422,146,789,289+3+20+25);
    setfillstyle(1,LIGHTBLUE);
    floodfill(450,200,WHITE);
    setfillstyle(1,BLUE);
    outtextxy(425+2,150     ,"function bubblesort ( array )");
    outtextxy(425+2,152+20  ,"    for i from 0 to N-1");
    outtextxy(425+2,169+3+20,"        for j from 0 to N - i - 1");
    outtextxy(425+2,189+3+20,"            if a[j] > a[j + 1]");
    outtextxy(425+2,209+3+20,"                swap(a[j], a[j + 1])");
    outtextxy(425+2,229+3+20,"            end if");
    outtextxy(425+2,249+3+20,"        end for");
    outtextxy(425+2,269+3+20,"    end for");
    outtextxy(425+2,289+3+20,"end function");

}
void selection_pseudocode()
{
    settextstyle(BOLD_FONT,0,4);
    outtextxy(495,102+3+10,"Pseudo-code");
    settextstyle(0,0,0);
    rectangle(422,146+10,789,263+50+25+10);
    setfillstyle(1,LIGHTBLUE);
    floodfill(450,200,WHITE);
    setfillstyle(1,BLUE);
    outtextxy(425+2,150+10   ,"function SelectionSort ( array )");
    outtextxy(425+2,170+10   ,"    for i from 0 to N-1");
    outtextxy(425+2,190+10   ,"        for j from i+1 to N - 1");
    outtextxy(425+2,210+10   ,"            if a[i] > a[j]");
    outtextxy(425+2,230+10   ,"                swap( a[i], a[j] )");
    outtextxy(425+2,203+50+10,"            end if");
    outtextxy(425+2,223+50+10,"        end for");
    outtextxy(425+2,243+50+10,"    end for");
    outtextxy(425+2,263+50+10,"end function");
}
void insertion_pseudocode()
{
    rectangle(402,100,770,363);
    setfillstyle(1,LIGHTBLUE);
    floodfill(450,200,WHITE);
    setfillstyle(1,BLUE);
    outtextxy(405,103,"function InsertionSort ( array )");
    outtextxy(405,123,"  for i from 1 to N-1");
    outtextxy(405,143,"    	 j = i");
    outtextxy(405,163,"     while j > 0");
    outtextxy(405,183,"		        if a[j]<a[j-1]");
    outtextxy(405,203,"			           swap ( a[j] , a[j-1] )");
    outtextxy(405,223,"			           j = j – 1");
    outtextxy(405,243,"		        else");
    outtextxy(405,263,"			           break;  ");
    outtextxy(405,283,"     end while");
    outtextxy(405,303,"  end for");
    outtextxy(405,343,"end function");
}
