#include "stdafx.h"

//string lcs(char* str1, char* str2)
// {
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//    int result = 0;
//    int** mat = (int**)calloc(len1 + 1, sizeof(int*));
//    for (int i = 0; i <= len1; i++)
//        mat[i] = (int*)calloc(len2 + 1, sizeof(int));
//    for (int i = 0; i <= len1; i++)
//    {
//        for (int j = 0; j <= len2; j++)
//        {
//            if (i == 0 || j == 0)
//                mat[i][j] = 0;
//            else if (str1[i - 1] == str2[j - 1])
//            {
//                mat[i][j] = 1 + mat[i - 1][j - 1];
//                result = max(result, mat[i][j]);
//            }
//            else
//                mat[i][j] = 0;
//        }
//    }
//    if (result == 0) {
//        for (int i = 0; i <= len1; i++)
//            free(mat[i]);
//        free(mat);
//  return "";
//    }
//      
//    int index = result;
//    string lcs = string(index, ' ');
//    for (int i = len1;i >= 0;i--) {
//        for (int j = len2;j >= 0;j--) {
//            if (mat[i][j] == result) {
//                lcs[index - 1] = str1[i - 1];
//                for (int m = 0;m < result - 1;m++) {
//                    i -= 1;
//                    j -= 1;
//                    index--;
//                    lcs[index - 1] = str1[i - 1];
//                }
//                break;
//            }
//        }
//    }
//
//    for (int i = 0; i <= len1; i++)
//        free(mat[i]);
//    free(mat);
//
//    //cout << "LCS of " << str1 << " and " << str2 << " is " << lcs;
//    return lcs;
//}
void lcs(char* search, char* lookahead, int* index, int* length)
{
    if ( search == "" || lookahead == "")
    {
        *index = 0;
        *length = 0;
        return;
    }
    int count = 0, index1 = 0, max = 0, inedxMax = 0,m;
    for (int i = 0, j = 0; i <= strlen(search); i++)
    {
        if (search[i] == lookahead[0])
        {
            int j;
            index1 = i;
            count++;
            for (m = 1, j = i + 1;j < strlen(search);j++)
            {
                if (search[j] == lookahead[m])
                {
                    count++;
                    m++;
                }
                else
                    break;
            }
            int i = 0;
            if (j == strlen(search))
            {
                int i = 0;
                while (search[i] == lookahead[m]||search[strlen(search)-1]==lookahead[m])
                {
                    count++;
                    i++;
                    m++;
                    if (i == strlen(search))
                        i = 0;
                }
            }
            if (count > max)
            {
                max = count;
                inedxMax = index1;
            }
            count = 0;
        }
    }
    *index = inedxMax;
    *length = max;
}

string stringOfLcs(char* search,char* lookahead)
{    
    int index = 0, length = 0,i;
    lcs(search, lookahead, &index, &length);
    string res = "";
    int m=0;
    for ( i = index;length != 0;i++)
    { 
        if (i == strlen(search))
        { 
            res += res[m];
            m++;
            length--;

        }
        else
        {
       res += search[i];
        length--;
        } 
    }
    return res;
}