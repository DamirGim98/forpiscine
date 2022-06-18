#include <stdio.h>
#include <stdlib.h>

char *diamond (int n)
{
    char * string = (char *)malloc(n*n*sizeof(char));
    int i = 0,space = 32, star = 42, newline = 10,index = 0;
    int m_spaces = n/2;
    int m_stars = 1;
    while(m_stars <= n)
    {
        for (;i<index + m_spaces;i++)
        {
            string[i] = space;
        }
        index = i;
        for(;i < index + m_stars;i++)
        {
            string[i] = star;
        }
        string[i] = newline;
        m_spaces = m_spaces - 1;
        m_stars = m_stars + 2;
        i++;
        index = i;
    }
    m_spaces = m_spaces + 2;
    m_stars = m_stars - 4;
    while(m_stars > 0)
    {
        for (;i<index + m_spaces;i++)
        {
            string[i] = space;
        }
        index = i;
        for(;i < index + m_stars;i++)
        {
            string[i] = star;
        }
        string[i] = newline;
        m_spaces = m_spaces + 1;
        m_stars = m_stars - 2;
        i++;
        index = i;
    }
    string[i] = '\0';
	return string;
}

int main(void)
{
    printf("%s",diamond(7));
    
    return 0;
}