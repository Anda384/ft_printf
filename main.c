#include <stdio.h>
#include "ft_printf.h"
int main(void) {
    int num = 123456;
    unsigned int unum = 987654321;
    void *ptr = &num;
    char c = 'A';
    char str[] = "Hello, World!";

    printf("Using built-in printf:\n");
    printf("c: %c\n", c);
    printf("s: %s\n", str);
    printf("p: %p\n", ptr);
    printf("d: %d\n", num);
    printf("i: %i\n", num);
    printf("u: %u\n", unum);
    printf("x: %x\n", unum);
    printf("X: %X\n", unum);
    printf("%%: %%\n");

    printf("\nUsing libftprintf:\n");
    ft_printf("c: %c\n", c);
    ft_printf("s: %s\n", str);
    ft_printf("p: %p\n", ptr);
    ft_printf("d: %d\n", num);
    ft_printf("i: %i\n", num);
    ft_printf("u: %u\n", unum);
    ft_printf("x: %x\n", unum);
    ft_printf("X: %X\n", unum);
    ft_printf("%%: %%\n");

    return 0;
}