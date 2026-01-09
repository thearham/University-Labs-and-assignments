#include <iostream>
#include <fstream>
using namespace std;



int strLength(char * );
char *reverseSubStr(char * , char * );
int main(){
    char string[25], pat[10];
    ifstream inputFile("input.txt");

    cout << "Text = ";
    while (!inputFile.eof())
    {
        inputFile >> string;
        cout << string;
    }
        
    cout << "\nPat: ";
    cin >> pat;

    cout << reverseSubStr(pat, string);
    return 0;
}
int strLength(char * str){
    int i = 0;
    while (str[i]!= '\0')
    {
        i++;
    }
    return i;    
}

char *reverseSubStr(char * patt, char * txt)
{
    int M = strLength(patt);
    int N = strLength(txt);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            
            if (txt[i + j] != patt[j])
                break;
        
        if(j==M){           
           for (int a = 0; a < M; a++)
           {
            txt[i+a] = patt[M-a-1];
           }
        }
    }
    return txt;
}