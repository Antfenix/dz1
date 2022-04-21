#include<iostream>
#include<Windows.h>





using namespace std;

const int N = 8;

void Horse(int[][N], int, int, int);

int moveX[8] = { -2,-1,1,2,2,1,-1,-2 };
int moveY[8] = { -1,-2,2,1,-1,-2,2,1 };
int X[N * N];
int Y[N * N];

void Horse(int arr[][N], int sx, int sy, int k) {

    int sxn, syn;
    k++;
    arr[sy][sx] = k;
    if (k >= N * N) return;

    for (int i = 0; i < 8; i++) {
        sxn = sx + moveX[i];
        syn = sy + moveY[i];

        if (sxn >= 0 && sxn < N && syn >= 0 && syn < N && arr[syn][sxn] == 0) {
            sx = sxn;
            sy = syn;
            X[k - 1] = sx;
            Y[k - 1] = sy;
            Horse(arr, sx, sy, k);
        }
    }


}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[N][N];

    int k = 0;
    int StepX, StepY;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = 0;

    cout << "Первая точка по x 1-8 ->";
    cin >> StepX;
    cout << "Первая точка по y 1-8 ->";
    cin >> StepY;
    cout << endl;

    Horse(arr, StepX - 1, StepY - 1, k);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << "\t";
        cout << "\n\n\n";
    }

}
