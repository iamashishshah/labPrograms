#include <stdio.h>

#define MAX 100

// Prototype
int StringMatch(char[], char[], char[], char[]);

// Main function
int main()
{
    char s[MAX] = {0}, p[MAX] = {0}, r[MAX] = {0}, final[MAX] = {0};
    int found;

    printf("Enter Source String : \n");
    fgets(s, sizeof(s), stdin);
    printf("Enter Pattern String : \n");
    fgets(p, sizeof(p), stdin);
    printf("Enter Replace String : \n");
    fgets(r, sizeof(r), stdin);

    found = StringMatch(s, p, r, final);

    if (found == 1)
    {
        printf("The Final String is : \n");
        puts(final);
    }
    else
        printf("Search string Not Found\n");

    return 0;
}

// StringMatch function definition
int StringMatch(char s[], char p[], char r[], char f[])
{
    int i, j, k, m, t; // i-index src, j-index pattern, k-index replace, t-index final
    int found = 0;
    j = m = i = t = 0;

    while (s[i] != '\0')
    {
        if (s[m++] == p[j++]) // check for matching
        {
            if (p[j] == '\0') // pattern found
            {
                // copy replace string in final string
                for (k = 0; r[k] != '\0'; k++, t++)
                    f[t] = r[k];
                j = 0;
                i = m;
                found = 1;
            }
        }
        else // mismatch
        {
            f[t++] = s[i++];
            m = i;
            j = 0;
        }
    }
    return found;
}
