#include "libft.h"

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
        array[i] = ft_getword(s, c);
        s += ft_countcword(s, c);
        i++;
    }
    array[i] = NULL;
    return (array);
}
