#include <stdio.h>
#include <stdlib.h>

void get_sub_arr(int arr[] , int len){
    int i;
    int start = 0;
    int end = 0;
    int max = arr[0];
    int temp = 0;

    int k = 0;

    for ( i = 0 ; i < len ; i ++ ){
        temp += arr[i];
        if ( temp > max ){
            start = k;
            end = i;
            max = temp;
        }
        if ( temp < 0 ){
            if ( i < len - 1 ){
                k = i + 1;
            }
            temp = 0;
        }
    }
    
    printf("%d %d %d\n" , max , start + 1 , end + 1);
}


int main()
{
    int n , i;
    scanf("%d" , &n);
    for ( i = 0 ; i < n ; i++ ){
        int m , j;
        scanf("%d" , &m);
        int *arr;
        arr = (int*)malloc( m * sizeof(int) );
        for ( j = 0 ; j < m ; j++ ){
            scanf("%d" , &arr[j]);
        }
        printf("Case %d:\n" , i + 1);
        get_sub_arr(arr , m);
        if ( i < n - 1 ){
            printf("\n");
        }
        free(arr); 
    }
    return 0;
}