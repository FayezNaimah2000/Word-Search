#include <iostream>
#include <vector> 
#include <cstdlib>
#include <string.h>
using namespace std;
 
bool Diagnol4(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
    if (((words + t) < x) && ((words + f) < y)) {
        for (int i = 0; i < words; i++){
            if (matrix [t + i][f + i] != word[i]){
              return false;
             
            }
        }
        return true;
    }
    return false; 
}
bool Diagnol3(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
    if (((words + f) < y) && ((t - words) >= 0)) {
        for (int i = 0; i < words; i++){
            if (matrix [t-i][f + i] != word[i]){
              return false;
            }
        }
        return true;
    }
    return false; 
}
bool Diagnol2(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
   if (((words + t) < (x)) && ((f - words) >= 0)) {
        for (int i = 0; i < words; i++){
            if (matrix [t+i][f - i] != word[i]){
             return false;
            }
        }
        return true;
    }
    return false; 
}
bool Diagnol1(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
   if ( ((f - words) >= 0) && ((t - words) >= 0)) {
        for (int i = 0; i < words; i++){
            if (matrix [t-i][f - i] != word[i]){
             return false;
            }
        }
        return true;
    }
    return false; 
}
bool RightToLeft(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
    if (((f - words) >= 0)) {
        for (int i = 0; i < words; i++){
            if (matrix [t][f - i] != word[i]){
           return false;
            }
        }
        return true;
    }
    return false; 
}
bool LeftToRight(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
    if (((words + f) <= (y))) {
        for (int i = 0; i < words; i++){
            if (matrix [t][f + i] != word[i]){
              return false;
            }
        }
        return true;
    }
    return false; 
}
bool DownToUp(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
    if (((t - words) >= 0)) {
        for (int i = 0; i < words; i++){
            if (matrix [t - i][f] != word[i]){
                return false;
            }
        }
        return true;
    }
    return false; 
}
bool UpToDown(vector< vector<char> > &matrix, char *word, int t, int f, int x, int y) {
    int words = strlen(word);
    if (((words + t) < (x))) {
        for (int i = 0; i < words; i++){ 
            if (matrix [t + i][f] != word[i]){
                return false;
            }
        }
        return true;
    }
    return false; 
}

void print(vector< vector<char> > &matrix, vector<vector < int > > &fake, int x, int y){
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            if(fake[i][j] == 0){
                matrix[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
}

void check (vector< vector<char> > &matrix, char *word [], int x, int y, int argc) {
    vector<vector < int > > fake;
    fake.resize(x);
    for (int i = 0; i < fake.size(); i++) {
        fake[i].resize(y);
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++){
           fake[i][j] = 0;
           
        }
    }
    
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (UpToDown(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){ 
                        fake[i + f][j] = 1;  
                       
                    }
                }
            }
        }
    } 
    
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (DownToUp(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){
                        fake[i - f][j] = 1; 
                    }
                }
            }  
        }
    }
     
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (LeftToRight(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){
                        fake[i][j + f] = 1; 
                    }
                }      
            }
        }
    }
   
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (RightToLeft(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){
                        fake[i][j - f] = 1; 
                    }
                }     
            } 
        }
    } 
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (Diagnol1(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){
                        fake[i-f][j - f] = 1; 
                    }
                }     
            } 
        }
    }
    
    
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (Diagnol2(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){
                        fake[i + f][j - f] = 1;
                    } 
                } 
            } 
        }
    }
    
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (Diagnol3(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){
                        fake[i - f][j + f] = 1;
                    } 
                } 
            } 
        }
    }
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            for (int z = 1; z < argc; z++){
                if (Diagnol4(matrix, word[z], i, j, x, y) == true){
                    for (int f = 0; f < strlen(word[z]); f++){
                        fake[i + f][j + f] = 1; 
                    }
                } 
            } 
        }
    } 
    print(matrix, fake, x, y); 
}

int main(int argc, char *argv[]){
    int x;   
    int y;
    cin >> x;
    cin >> y; 
    vector<vector < char > > test;
    test.resize(x);
    for (int i = 0; i < test.size(); i++)
    {
        test[i].resize(y);
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++){
           cin >> test[i][j];
        }
    }
    check(test, argv, x, y, argc);
}