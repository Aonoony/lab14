#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[N][M]){
    for(int i = 0; i<72; i++) cout << '-';
    cout << endl;
    for(int m = 0; m<30; m++){
        cout << '|';
        for(int n = 0; n<70; n++){
            if(image[m][n] == 0) cout << ' ';
            else if(image[m][n] == 1) cout << '*';
        }
        cout << '|' << endl;
    }
    for(int j = 0; j<72; j++) cout << '-';
    cout << endl;
}

void updateImage(bool image[N][M], int x, int y, int z){
    for(int k = 0; k<30; k++){
        for(int l = 0; l<70; l++){
            if(sqrt(pow(k-y, 2)+pow(l-z, 2)) <= x-1) image[k][l] = 1;
        }
    }
}
