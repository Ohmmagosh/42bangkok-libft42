// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    
    i = 0;
    if (dstsize <= 0)
        return (strlen(src));
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (strlen(src));
}

size_t  ft_countword(char const *s, char c)
{
    int i;
    int j;
    
    j = 0;
    i = 0;
    if (*s != '\0' && *s != c)
        j+=1;
    while (s[i])
    {
        if (s[i] == c && s[i+1] != c && s[i+1])
            j+=1;
        i++; 
    }
    return (j + 1);
}

size_t  ft_countcword(char const *s, char c)
{
    size_t  i;
    size_t  j;
    size_t  len;
    
    i = 0;
    j = 0;
    len = strlen(s);
    while(i < len && s[i])
    {
        if (s[i] == c)
        {  
            i++;
            break ;
        }
        i++;
        j++;
    }
    return (j+1);
}

char    *ft_getword(char *s,char c)
{
    char    *str;
    str = malloc(sizeof(char *) * ft_countcword(s, c) + 1);
    ft_strlcpy(str, s, ft_countcword(s, c));
    return (str);
}

char    **ft_split(char const *s, char c)
{
    char    **array;
    int i;
    int sl;
    
    i = 0;
    sl = ft_countword(s, c);
    array = (char *)malloc(ft_countword(s, c) * (sizeof(char *)));
    if (!array)
        return (NULL);
    while (*s == c)
        s++;
    while (i < sl)
    {
        array[i] = ft_getword(s, c); //return str
        s += ft_countcword(s, c);
        i++;
    }
    array[i] = NULL;
    return (array);
}
int main() {
    char    *str = "  helloo world aaa  ";
    char    **ar;
    int i = 0;
    ar = ft_split(str, ' ');
    while (i < 4)
    {
        printf("%s\n", ar[i]);
        i++;
    }
    printf(" 1 %s\n", ar[0]);
    printf(" 2 %s\n", ar[1]);
    printf(" 3 %s\n", ar[2]);
    printf(" 4 %s\n", ar[3]);
    
    
    // printf("Hello world");
    
    return 0;
}