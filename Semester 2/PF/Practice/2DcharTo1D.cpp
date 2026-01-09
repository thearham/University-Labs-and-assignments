#include <iostream>
using namespace std;

void twoDToOneD(char twoDArr[][7], int rows, int cols, char* oneDArr) {
    int oneDIndex = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (twoDArr[i][j] == '\0') {
                break;
            }
            oneDArr[oneDIndex++] = twoDArr[i][j];
        }
        oneDArr[oneDIndex++] = '$';
    }
    oneDArr[oneDIndex - 1] = '\0'; 
}

int main(){
    char twoDArr[][7] = {{'b', 'a', 't', 'h','\0'},
                           {'c', 'a', 't','\0'},
                           {'J', 'a', 'c', 'k', 'a','l','\0'},
                           {'L', 'a', 'z', 'y','\0'}};
    int rows = 4;
    int cols = 7;
    char oneDArr[30];
    twoDToOneD(twoDArr, rows, cols, oneDArr);

    for (int i = 0; oneDArr[i] != '\0'; i++)
    {
        cout << oneDArr[i];
    }
    

    
    return 0;
}