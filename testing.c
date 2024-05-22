#include<stdio.h>

#define SIZE3 9
#define SIZE5 25
#define SIZE7 49
#define ENTER_KEY 13
#define ARROW_DOWN 80
#define ARROW_UP 72
#define MAX_MENU_ITEMS 3
#define MIN_MENU_ITEMS 1
#define MAX_MENU_BACK 4

void pointer(int realPosition, int arrowPosition, const char *text)
{
    if (realPosition == arrowPosition)
    {
        printf("\033[0;32m"); // Set color to green

        printf("%s", text);
        printf("\033[0m"); // Reset color
    }
    else
    {
        printf("");
    }
}

int main(){
    pointer(1, 1, "Hello");
    pointer(2, 1, "World");
}