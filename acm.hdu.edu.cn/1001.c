#include <stdio.h>

int binary(int start , int end){
    if ( start == end ){
        return start;
    }
    if ( start + 1 == end){
        return start + end;
    }
    int left = (end - start + 1) / 2;
    return binary(start , start + left) + binary(start + left + 1 , end);
    
}

int main()
{
    int n;
    while( scanf("%d" , &n) != EOF ){
        printf("%d\n\n" , binary( 1 , n));
    }
    return 0;
}