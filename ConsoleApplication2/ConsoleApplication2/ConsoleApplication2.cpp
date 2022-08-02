#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;


void Lcs(string search, string lookahead, int* ofset, int* length)
{
      if ((search.find(lookahead[0]) == std::string::npos) || search == "" || lookahead == "")
      {
          *ofset = 0;
          *length = 0;
           return;
      }int m;
      int len1 = search.length();
      int len2 = lookahead.length();
      int count = 0, index = 0, max = 0, inedxMax = 0;
      int* arr = new int[len1] {0};
      for (int i = 0, j = 0; i <= len1; i++)
      {
          if (search[i] == lookahead[0])
          {
              int j;
              index = i;
              count++;
;              for (m = 1, j = i + 1;j < len1;j++)
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
              if (j == len1)
              {
                  int i = 0;
                  while (search[i] == lookahead[m])
                  {
                      count++;
                      i++;
                      m++;
                      if (i == len1)
                          i = 0;
                  }
              }
              if (count > max)
              {
                  max = count;
                  inedxMax = index;
              }
              count = 0;
          }
      }
      *ofset = inedxMax;
      *length = max;
}
   

int main() {
    int length, ofset;
    string search = "abcaba";
    string lookahead = "aac";
    Lcs(search, lookahead, &ofset, &length);
    cout << length << "\n";
    cout <<  ofset << "\n";

}
//string stringOfLcs(char* str1, char* str2)
//{
//}
string stringOfLcs(string search, string lookahead)
{
    int index = 0, length = 0;
    lcs(search, lookahead, &index, &length);
    string res = "";
    for (int i = index;i++;length != 0)
    {
        if (i == search.length())
            i = 0;
        res += search[i];
        length--;

    }
    return res;
}