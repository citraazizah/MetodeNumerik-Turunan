#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maks 100
float a,b,n;

float fungsi (float x)
{
    return (x*x*x)+(5*x);
}

float nilai_h()
{
    return (b-a)/n;
}

float eksak(float x)
{
    return (3*(x*x)) + 5;
}

void maju()
{
    int i;
    float h;
    float x[maks], fx[maks],tmajufx[maks];
    float hx[maks],erx[maks];
    h = nilai_h();
    printf("\n\n\t\t\t\tTABEL METODE MAJU\n\n");
    printf("\n=========================================================================================================\n");
    printf("|\ti\t|\tx\t|\tf(x)\t|\tf'(x)maju\t|\teksak\t|\terror\t|\n");
    printf("=========================================================================================================\n");
    for(i=0;i<=n;i++)
    {
        x[i] = a +(i*h);
        fx[i]= fungsi(x[i]);
        hx[i] = eksak(x[i]);
        fx[i+1] = fungsi(x[i]+h);
        tmajufx[i] = (fx[i+1] - fx[i])/h;
        erx[i] = abs(hx[i]-tmajufx[i]);
        printf("|\t%d\t|\t%.4f\t|\t%.4f\t|\t%.4f\t\t|\t%.4f\t|\t%.4f\t|\n",i,x[i],fx[i],tmajufx[i],hx[i],erx[i]);
    }
    printf("=========================================================================================================\n");


}

void mundur()
{
    int i;
    float h,x0;
    float x[maks], fx[maks],tmundurfx[maks];
    float hx[maks],erx[maks];
    h = nilai_h();
    printf("\nInput nilai X awal\t: ");
    scanf("%f",&x0);
    x[0] = x0;
    fx[0] = fungsi(x0);

    printf("\n\n\t\t\t\tTABEL METODE MUNDUR\n\n");
    printf("\n=========================================================================================================\n");
    printf("|\ti\t|\tx\t|\tf(x)\t|\tf'(x)mundur\t|\teksak\t|\terror\t|\n");
    printf("=========================================================================================================\n");
    printf("|\t\t\t%.4f\t|\t\%.4f\t|\n",x[0],fx[0]);

    for(i=0;i<=n;i++)
    {
        x[i+1] = a +(i*h);
        fx[i+1]= fungsi(x[i+1]);
        hx[i+1] = eksak(x[i+1]);
        tmundurfx[i+1] = (fx[i+1] - fx[i])/h;
        erx[i+1] = abs(hx[i+1]-tmundurfx[i+1]);
        printf("|\t%d\t|\t%.4f\t|\t%.5f\t|\t%.5f\t\t|\t%.4f\t|\t%.4f\t|\n",i,x[i+1],fx[i+1],tmundurfx[i+1],hx[i+1],erx[i+1]);
    }
       printf("=========================================================================================================\n");
}

void tengah ()
{
    int i;
    float h,x0;
    float x[maks], fx[maks],ttengahfx[maks];
    float hx[maks],erx[maks];
    h = nilai_h();
    printf("\nInput nilai X awal\t: ");
    scanf("%f",&x0);
    x[0] = x0;
    fx[0] = fungsi(x0);

    printf("\n\n\t\t\t\tTABEL METODE TENGAH\n\n");
    printf("\n=========================================================================================================\n");
    printf("|\ti\t|\tx\t|\tf(x)\t|\tf'(x)tengah\t|\teksak\t|\terror\t|\n");
    printf("=========================================================================================================\n");
    printf("|\t\t\t%.4f\t|\t\%.4f\t|\n",x[0],fx[0]);

    for(i=0;i<=n;i++)
    {
        x[i+1] = a +(i*h);
        fx[i+1]= fungsi(x[i+1]);
        hx[i+1] = eksak(x[i+1]);
        fx[i+2]=fungsi(x[i+2]);
        ttengahfx[i+1] = ((fx[i+2] - fx[i])/h);
        erx[i+1] = abs(hx[i+1]-ttengahfx[i+1]);
        printf("|\t%d\t|\t%.4f\t|\t%.5f\t|\t%.5f\t\t|\t%.4f\t|\t%.4f\t|\n",i,x[i+1],fx[i+1],ttengahfx[i+1],hx[i+1],erx[i+1]);
    }
       printf("=========================================================================================================\n");
}

void all()
{
    int i;
    float h,x0;
    float x[maks], fx[maks];
    float ttengahfx[maks],tmundurfx[maks],tmajufx[maks];
    float hx[maks],erx1[maks],erx2[maks],erx3[maks];
    h = nilai_h();
    printf("\nInput nilai X awal\t: ");
    scanf("%f",&x0);
    x[0] = x0;
    fx[0] = fungsi(x0);

//er1=error maju
//er2=error mundur
//er3=error tengah

    printf("\n\n\t\t\t\t\tALL METODE\n\n");
    printf("\n===============================================================================================================================================================================================\n");
    printf("|  i\t|\tx\t|\tf(x)\t|\tf'(x)maju\t|\tf'(x)mundur\t|\tf'(x)tengah\t|\teksak\t|\terr1\t|\terr2\t|\terr3\t|\n");
    printf("================================================================================================================================================================================================\n");
    printf("|\t\t%.4f\t|\t\%.4f\t|\n",x[0],fx[0]);

     for(i=0;i<=n;i++)
    {
        x[i+1] = a +(i*h);
        fx[i+1]= fungsi(x[i+1]);
        hx[i+1] = eksak(x[i+1]);
        fx[i+2]=fungsi(x[i+2]);
        tmajufx[i+1] = (fx[i+2]-fx[i+1])/h;
        erx1[i+1] = abs(hx[i+1]-tmajufx[i+1]);
        tmundurfx[i+1] = (fx[i+1] - fx[i])/h;
        erx2[i+1] = abs(hx[i+1]-tmundurfx[i+1]);
        ttengahfx[i+1] = ((fx[i+2] - fx[i])/h);
        erx3[i+1] = abs(hx[i+1]-ttengahfx[i+1]);
        printf("|  %d\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\t%.4f\t|\n",i,x[i+1],fx[i+1],tmajufx[i+1],tmundurfx[i+1],ttengahfx[i+1],hx[i+1],erx1[i+1],erx2[i+1],erx3[i+1]);
    }
       printf("===================================================================================================================================================================================================\n");
}


int main()
{
    int pilih;
    char jwb;
    printf("\n\t===============================================\n");
    printf("\t\t\tMencari Nilai TURUNAN\n");
    printf("\t===============================================\n\n");
    printf("Input nilai a\t: ");
    scanf("%f",&a);
    printf("Input nilai b\t: ");
    scanf("%f",&b);
    printf("Jumlah iterasi\t: ");
    scanf("%f",&n);

    do
        {
            printf("\nPilihan Menu\t: ");
            printf("1.Metode maju\n\t\t  2.Metode mundur\n\t\t  3.Metode tengah\n\t\t  4.All Metode\n");
            printf("\nInput Pilihanmu\t: ");
            scanf("%d",&pilih);
            if(pilih==1)
                maju();
            else if(pilih==2)
                mundur();
            else if (pilih==3)
                tengah();
            else if(pilih==4)
                all();
            else
                printf("Menu yang anda pilih salah!!\n");

                fflush(stdin);

    printf("\n\nMau coba lagi(y/t)? ");
    scanf("%c",&jwb);
        }
        while(jwb=='y'||jwb=='Y');


            return 0;
}
