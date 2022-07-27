#include "stdafx.h"

string lcs(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int result = 0;
    int** mat = (int**)calloc(len1 + 1, sizeof(int*));
    for (int i = 0; i <= len1; i++)
        mat[i] = (int*)calloc(len2 + 1, sizeof(int));
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
                mat[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
            {
                mat[i][j] = 1 + mat[i - 1][j - 1];
                result = max(result, mat[i][j]);
            }
            else
                mat[i][j] = 0;
        }
    }
    //for (int i = 0;i < 8;i++)
    //{
    //    for (int j = 0;j < 8;j++)
    //    {

    //        cout << mat[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    int index = result;
    string lcs = string(index, ' ');
    for (int i = len1;i >= 0;i--) {
        for (int j = len2;j >= 0;j--) {
            if (mat[i][j] == result) {
                lcs[index - 1] = str1[i - 1];
                for (int m = 0;m < result - 1;m++) {
                    i -= 1;
                    j -= 1;
                    index--;
                    lcs[index - 1] = str1[i - 1];
                }
                break;
            }
        }
    }

    for (int i = 0; i <= len1; i++)
        free(mat[i]);
    free(mat);

    //cout << "LCS of " << str1 << " and " << str2 << " is " << lcs;
    return lcs;
}
