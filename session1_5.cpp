#include <bits/stdc++.h>
using namespace std;

void Winner(int r, int c, vector<vector<int>>JusticeLeague, vector<vector<int>>Villains) {
    int j = 0; // Score for Justice League
    int v = 0; // Score for Villains

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            if (JusticeLeague[i][k] > Villains[i][k]) {
                j++; // Justice League wins in that area
            } else if (JusticeLeague[i][k] < Villains[i][k]) {
                v++; // villains wins in that area
            } else {
                j++; // Tie for that area
                v++;
            }
        }
    }

    if (j > v) {
        cout << "Justice League" << endl; // The Winner team is Justice League
    } else if (j < v) {
        cout << "Villains" << endl;  // The winner team is Villains
    } else {
        cout << "Tie" << endl;  // Tie
    }
}

int main() {
    int r, c; //number of rows and columns
    cin >> r >> c; 

    vector<vector<int>> JusticeLeague(r, vector<int>(c));
    vector<vector<int>> Villains(r, vector<int>(c));

    for (int i = 0; i < r; i++) {   
        for (int j = 0; j < c; j++) {
            cin >> JusticeLeague[i][j];  //elements for Justice League matrix
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> Villains[i][j];  //elements for Villains matrix
        }
    }

    Winner(r, c, JusticeLeague, Villains); 
    return 0;
}
