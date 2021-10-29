#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int globalscore = 0;
int globalgamestate = 0;

void Move(char x, vector<vector<int>>& Arr, int& score, int& change) {
    vector<int> Temp;
    vector<int> Prev;
    int real, changed;
    change = 0;

    switch (x) {
    case 'w':
        for (int i = 0; i < 4; i++) {   //for 4 columns/rows
            real = 0;
            for (int j = 0; j < 4; j++) {    //for every tile of a row/column
                Temp.push_back(Arr[j][i]);   //save into temp memory
                Prev.push_back(Arr[j][i]);   //to compare what was previous row/column
                Arr[j][i] = 0;               //row/column set to 0
            }
            for (int j = 0; j < 4; j++) {   //for every tile input a new value
                changed = 1;
                if (Temp[0] > 0) {
                    if (Arr[real][i] == Temp[0]) {
                        Arr[real][i] *= 2;
                        globalscore += Arr[real][i];
                    }
                    else if (Arr[real][i] == 0) {
                        Arr[real][i] = Temp[0];
                    }
                    else {
                        real++;
                        changed = 0;
                        j--;
                    }
                }
                if (changed == 1) Temp.erase(Temp.begin());
            }
            for (int j = 0; j < 4; j++) {   //compares if anything changed
                if (Arr[j][i] != Prev[j]) change = 1;
                //cout << Arr[j][i] << " " << Prev[j] << endl;
            }
            for (int j = 0; j < 4; j++) Prev.erase(Prev.begin());
        }
        break;

    case 's':
        for (int i = 0; i < 4; i++) {
            real = 3;
            for (int j = 3; j >= 0; j--) {
                Temp.push_back(Arr[j][i]);
                Prev.push_back(Arr[j][i]);
                Arr[j][i] = 0;

            }
            for (int j = 3; j >= 0; j--) {
                changed = 1;
                if (Temp[0] > 0) {
                    if (Arr[real][i] == Temp[0]) {
                        Arr[real][i] *= 2;
                        globalscore += Arr[real][i];
                    }
                    else if (Arr[real][i] == 0) {
                        Arr[real][i] = Temp[0];
                    }
                    else {
                        real--;
                        changed = 0;
                        j++;
                    }
                }
                if (changed == 1) Temp.erase(Temp.begin());
            }
            for (int j = 3; j >= 0; j--) {
                if (Arr[j][i] != Prev[j]) change = 1;
            }
            for (int j = 0; j < 4; j++) Prev.erase(Prev.begin());

        }
        break;

    case 'd':
        for (int i = 0; i < 4; i++) {
            real = 3;
            for (int j = 3; j >= 0; j--) {
                Temp.push_back(Arr[i][j]);
                Prev.push_back(Arr[i][j]);
                Arr[i][j] = 0;
            }
            for (int j = 3; j >= 0; j--) {
                changed = 1;
                if (Temp[0] > 0) {
                    if (Arr[i][real] == Temp[0]) {
                        Arr[i][real] *= 2;
                        globalscore += Arr[i][real];
                    }
                    else if (Arr[i][real] == 0) {
                        Arr[i][real] = Temp[0];
                    }
                    else {
                        real--;
                        changed = 0;
                        j++;
                    }
                }
                if (changed == 1) Temp.erase(Temp.begin());
            }
            for (int j = 3; j >= 0; j--) {
                if (Arr[i][j] != Prev[j]) change = 1;
            }
            for (int j = 0; j < 4; j++) Prev.erase(Prev.begin());

        }
        break;

    case 'a':
        for (int i = 0; i < 4; i++) {
            real = 0;
            for (int j = 0; j < 4; j++) {
                Temp.push_back(Arr[i][j]);
                Prev.push_back(Arr[i][j]);

                Arr[i][j] = 0;
            }
            for (int j = 0; j < 4; j++) {
                changed = 1;
                if (Temp[0] > 0) {
                    if (Arr[i][real] == Temp[0]) {
                        Arr[i][real] *= 2;
                        globalscore += Arr[i][real];
                    }
                    else if (Arr[i][real] == 0) {
                        Arr[i][real] = Temp[0];
                    }
                    else {
                        real++;
                        changed = 0;
                        j--;
                    }
                }
                if (changed == 1) Temp.erase(Temp.begin());
            }
            for (int j = 0; j < 4; j++) {
                if (Arr[i][j] != Prev[j]) change = 1;
            }
            for (int j = 0; j < 4; j++) Prev.erase(Prev.begin());

        }
        break;

    default:
        break;
    }
}

void NewTile(vector<vector<int>>& Arr) {

    int full = 1;

    for (int i = 0; i < 16; i++) {
        if (Arr[i / 4][i % 4] == 0) {
            full = 0;
            break;
        }
    }

    int x, y, z;
    if (full == 0) {
        for (int i = 0; i < 100; i++) {
            x = rand() % 4;
            y = rand() % 4;
            z = rand() % 2 + 1;
            //cout << x << " " << y << " " << z << "\n";
            if (Arr[x][y] == 0) {
                Arr[x][y] = z * 2;
                break;
            }

        }
    }
    else globalgamestate = 1;
}

void Screen(vector<vector<int>>& Arr) {

    /*for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << Arr[i][j];
        }
        cout << "\n";
    }
    cout << "\n";*/

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "Score: " << globalscore << "\n\n";
    for (int i = 0; i < 4; i++) {
        cout << " ---------------------------------" << endl;
        cout << " |       |       |       |       |" << endl;
        for (int j = 0; j < 4; j++) {
            cout << " |" << setw(6) << Arr[i][j];
        }
        cout << " |" << endl;
        cout << " |       |       |       |       |" << endl;

    }
    cout << " ---------------------------------" << endl;

}

int main()
{
    srand(time(NULL));

    int score = 0, change;
    char x;
    vector<vector<int>> Arr(4, vector<int>(4));
start:
    globalgamestate = 0;
    globalscore = 0;

    cout << "CONTROLS:\n";
    cout << "W - MOVE TILES UP\nA - LEFT\nS - DOWN\nD - RIGHT\n";
    cout << "\n PRESS ANY KEY TO START";

    x = _getch();

    for (auto& sub : Arr) {
        fill(sub.begin(), sub.end(), 0);
    }
    NewTile(Arr);
    NewTile(Arr);
    while (globalgamestate == 0) {
        Screen(Arr);
        x = _getch();
        Move(x, Arr, score, change);
        if (change == 1) NewTile(Arr);
        //NewTile(Arr);
    }

    cout << "GAME OVER       SCORE: " << globalscore;
    cout << "\n\nPRESS C TO EXIT";
    cout << "\nPRESS R TO RESTART";

    while (true) {
        x = _getch();
        if (x == 'c') break;
        else if (x == 'r') goto start;
    }
}