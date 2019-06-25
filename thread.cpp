
#include <stdio.h>

int x = 0;
int y = 1;
void T1(){
     while (1)
     {
         /* code */
         x = y+1;
         printf("%d", x);
     }
}
void T2(){
    y =2;
    y = y*2;
}

int main(){
    HANDLE h1, h2;
    DWORD ThreadId;
    return 0;
}