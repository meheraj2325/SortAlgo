#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

struct coordinate
{
    int x1;
    int y1;
    int x2;
    int y2;
};
FILE *f;
struct coordinate bubble[10];

//int j,i,k,l;

int n,a[20];
char c[6];

void bubble_sort()
{
    f=fopen("inputx.txt","r");
    fscanf(f,"%d",&n);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100,page=0;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=580-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=600;
        t+=45;
    }
    delay(10);
    cleardevice(); ///Screen clear hobe
    for(int i=0; i<n; i++)
    {

        outtextxy(50,50,"Bubble sort");  ///Corner theke (50,50) co ordinate a
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2); ///rectngle aklam
        setfillstyle(1,BLUE); ///ki colour choose korbo
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE); ///fill kore dao
        sprintf(c,"%d",a[i]); ///int to string
        outtextxy(bubble[i].x1+15,615,c); ///print kore dilam
    }
    for(int k=0; k<n-1; k++)
    {
        for(int i=0; i<n-k-1; i++)
        {
            if(a[i]>a[i+1])
            {

                for(int j=1; j<=45; j++)
                {
                    setactivepage(page);
                    setvisualpage(1-page);
                    cleardevice();
                    outtextxy(50,50,"Bubble sort");
                    rectangle(bubble[i].x1+j,bubble[i].y1,bubble[i].x2+j,bubble[i].y2);
                    floodfill(bubble[i].x1+5+j,bubble[i].y1+5,WHITE);
                    rectangle(bubble[i+1].x1-j,bubble[i+1].y1,bubble[i+1].x2-j,bubble[i+1].y2);
                    floodfill(bubble[i+1].x1+5-j,bubble[i+1].y1+5,WHITE);
                    for(int l=0; l<n; l++)
                    {
                        if(l!=i && l!=i+1)
                        {
                            rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                            floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                            sprintf(c,"%d",a[l]);
                            outtextxy(bubble[l].x1+15,615,c);
                        }
                    }
                    page=1-page;
                    delay(5);
                }
                swap(bubble[i].y1,bubble[i+1].y1);
                swap(bubble[i].y2,bubble[i+1].y2);
                swap(a[i],a[i+1]);
                sprintf(c,"%d",a[i]);
                outtextxy(bubble[i].x1+15,615,c);
                sprintf(c,"%d",a[i+1]);
                outtextxy(bubble[i+1].x1+15,615,c);
            }
            delay(500);
        }
    }
}

void selectionSort()
{
    int i, j, min_indx,page=0;
    f=fopen("inputx.txt","r");
    fscanf(f,"%d",&n);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=580-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=600;
        t+=45;
    }
    delay(10);
    cleardevice();
    for(i=0; i<n; i++)
    {
        outtextxy(50,50,"Selection sort");
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,615,c);
    }

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
            rectangle(bubble[i].x1+j,bubble[i].y1,bubble[i].x2+j,bubble[i].y2);
            floodfill(bubble[i].x1+5+j,bubble[i].y1+5,WHITE);
            rectangle(bubble[min_indx].x1-j,bubble[min_indx].y1,bubble[min_indx].x2-j,bubble[min_indx].y2);
            floodfill(bubble[min_indx].x1+5-j,bubble[min_indx].y1+5,WHITE);
            outtextxy(50,50,"Selection sort");
            for(int l=0; l<n; l++)
            {
                if(l!=i && l!=min_indx)
                {
                    rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                    floodfill(bubble[l].x1+5,bubble[l].y1+5,WHITE);
                    sprintf(c,"%d",a[l]);
                    outtextxy(bubble[l].x1+15,615,c);
                }
            }
        }
        swap(bubble[i].y1,bubble[min_indx].y1);
        swap(bubble[i].y2,bubble[min_indx].y2);
        swap(a[min_indx], a[i]);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,615,c);
        sprintf(c,"%d",a[min_indx]);
        outtextxy(bubble[min_indx].x1+15,615,c);
    }
}

void insertion_sort()
{
    int i, key,k,j,l;
    f=fopen("inputx.txt","r");
    fscanf(f,"%d",&n);
    for(int i=0; i<n; i++)
    {
        fscanf(f,"%d",&a[i]);
    }
    int t=100;
    for(int i=0; i<n; i++)
    {
        bubble[i].x1=t;
        bubble[i].y1=580-a[i];
        bubble[i].x2=t+40;
        bubble[i].y2=600;
        t+=45;
    }
    delay(10);
    cleardevice();

    for(int i=0; i<n; i++)
    {

        outtextxy(50,50,"Insertion sort");
        rectangle(bubble[i].x1,bubble[i].y1,bubble[i].x2,bubble[i].y2);
        setfillstyle(1,BLUE);
        floodfill(bubble[i].x1+5,bubble[i].y1+5,WHITE);
        sprintf(c,"%d",a[i]);
        outtextxy(bubble[i].x1+15,615,c);
    }
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i-1;
        while (j >= 0 && a[j] > key)
        {
            for(k=1; k<=45; k++)
            {
                delay(1000);
                cleardevice();
                rectangle(bubble[j].x1+k,bubble[j].y1,bubble[j].x2+k,bubble[j].y2);
                floodfill(bubble[j].x1+5+k,bubble[j].y1+5,WHITE);
                for(l=0; l<n; l++)
                {
                    if(l>i)
                    {
                        rectangle(bubble[l].x1,bubble[l].y1,bubble[l].x2,bubble[l].y2);
                        floodfill(bubble[l].x1+5+k,bubble[l].y1+5,WHITE);
                    }
                }
            }
            swap(bubble[j].y1,bubble[i].y1);
            swap(bubble[j].y2,bubble[i].y2);
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
        rectangle(bubble[j+1].x1,bubble[j+1].y1,bubble[j+1].x2,bubble[j+1].y2);
        floodfill(bubble[j+1].x1+5,bubble[j+1].y1+5,WHITE);
    }
}

int main()
{
    DWORD screenwidth= GetSystemMetrics(SM_CXSCREEN);
    DWORD screenheight= GetSystemMetrics(SM_CYSCREEN);

    initwindow(1000,700,"Project",50,50);
    readimagefile("Capture.jpg", 0, 0, 1000,700);
    //settextstyle(5,0,4);
    //outtextxy(50,50,"Welcome to visualization of sorting algorithms.");
    //outtextxy(50,100,"Here algorithms are visualized through animation.");
    //outtextxy(50,150,"Here you can use your own input for any algorithm instead of the sample inputs.");
    settextstyle(0,0,0);
    //rectangle(100,100,400,50);
    getch();
    bubble_sort();
    //selectionSort();
    //insertion_sort();
    getch();
    cleardevice();

    getch();
    closegraph();
    return 0;
}
