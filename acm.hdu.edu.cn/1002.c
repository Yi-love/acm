
#include <stdio.h>
#include <string.h>
 
void PrintNum(int sum[] , int len)
{
    int i;
    for(i = len - 1 ; i >= 0 ; i --){
        printf("%d",sum[i]);
    }
}
 
void Add(char a[] , int len_a , char b[] , int len_b)
{
    int k = 0 , c = 0;
    int max_len = len_a > len_b ? len_a : len_b;
    int sum[1010];
    for( ; len_b >= 0 ; ){///---a+b
        sum[k ++] = (a[len_a --] + b[len_b --] - 96 + c) % 10;
        c = (a[len_a + 1] + b[len_b + 1] - 96 + c) > 9 ? 1 : 0;
    }
    while(len_a > -1){///-----复制a
            sum[k ++] = (a[len_a] - 48 + c) % 10;
            c = (a[len_a] - 48 + c) > 9 ? 1 : 0;
            len_a --;
    }
    if(c > 0){
        sum[k ++] = 1;
    } 
    PrintNum(sum , k);
}
 
int main()
{
    int n , i = 1;
    char a[1010] , b[1010];

    scanf("%d" , &n);

    while( i <= n ){
        scanf("%s %s" , a , b);
        printf("Case %d:\n" , i);
        printf("%s + %s = " , a , b);
        
        int len_a = strlen(a);
        int len_b = strlen(b);
        if(len_a >= len_b){
            Add(a , len_a-1 ,  b ,  len_b-1);
        }  
        else{
            Add(b , len_b-1 ,  a ,  len_a-1);
        }
        i ++;
        if ( i <= n ){
            printf("\n\n");
        }else{
            printf("\n");
        }
    }
    return 0;
}