#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../inc/app_test.h"

int main()
{
    char str[] = "app_test_print function!";

    printf("this is first c project!\r\n");

    app_test_print(str);

    system("pause");

    return 0;
}