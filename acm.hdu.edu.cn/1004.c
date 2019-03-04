#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int m;
    while( scanf("%d" , &m) != EOF ){
        if ( m == 0 ){
            return 0;
        }
        char **str;
        int * arr;
        int i , j;
        
        arr = (int *)malloc( m * sizeof(int));
        str = (char **)malloc(m * sizeof(char *));
        
        for ( i = 0 ; i < m ; i++ ){
            str[i] = malloc(16 * sizeof(char));
            arr[i] = 0;
        }
        
        for ( i = 0 ; i < m ; i++ ){
            scanf("%s" , str[i]);
        }
        int max = 0;
        int k = 0;

        for ( i = 0 ; i < m - 1 ; i++ ){
            for( j = i + 1 ; j < m ; j++ ){
                if ( strcmp(str[i] , str[j]) == 0 ){
                    arr[i] += 1;
                }
            }
            if ( arr[i] > max ){
                max = arr[i];
                k = i;
            }
        }

        printf("%s\n" , str[k]);

        for ( i = 0 ; i < m ; i++ ){
            free(str[i]); 
        }
        free(str);
        free(arr);
    }
    
    return 0;
}

