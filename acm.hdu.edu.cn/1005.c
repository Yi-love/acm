#include <stdio.h>

int sequence(int a , int b , int n)
{
    if ( n == 1 || n == 2 ){
        return 1;
    }
    
    a %= 7;
    b %= 7;
    int i = 3 , sum = 0;
    int start =  1 , end = 1;
    while( i <= n ){
        sum = (a * start + b * end) % 7;
        end = start;
        start = sum;
        i ++;
    }
    return sum;
}

int main()
{
    int a , b , n;
    while( scanf("%d %d %d" , &a , &b , &n) != EOF ){
        if ( a == 0 && b == 0 && n == 0 ) {
            return 0;
        }
        printf("%d\n" , sequence(a, b , n % 49));    
    }
    return 0;
}