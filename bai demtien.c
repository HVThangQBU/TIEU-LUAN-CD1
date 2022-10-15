#include "stdio.h"
#include "conio.h"
 
int main()
{
    printf("Nhap so tien can rut: ");
    int x = 0;
    scanf("%d", &x);
 
    int soto_500 = 0;
    int soto_200 = 0;
    int soto_100 = 0;
    int soto_50 = 0;
 
    for (int i = 1; i > 0;)
    {
        if (x == 0)
        {
            break;
        }
 
        if (x >= 500000)
        {
            x -= 500000;
            soto_500++;
        }
        else if ((x < 500000) && (x >= 200000))
        {
            x -= 200000;
            soto_200++;
        }
        else if ((x < 200000) && (x >= 100000))
        {
            x -= 100000;
            soto_100++;
        }
        else if (x == 50000)
        {
            x -= 50000;
            soto_50++;
        }
    }
 
    printf("So to 500 rut duoc la: %d to\n", soto_500);
    printf("So to 200 rut duoc la: %d to\n", soto_200);
    printf("So to 100 rut duoc la: %d to\n", soto_100);
    printf("So to 50 rut duoc la: %d to\n", soto_50);
 
    getch();
    return 0;
}
