#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <array>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int N, M;
int U[MAX_N];
int S[MAX_M][MAX_N];
int cost[MAX_M];
bool covered[MAX_N];

// function to find the set with the smallest alpha
int findSmallestAlphaSet() {
    int smallestAlphaSet = -1;
    float smallestAlpha =INT_MAX;

    for (int i = 0; i < M; i++) {
        if (cost[i] == -1) continue;

        float alpha = (float) cost[i] / (float) N;
        if (alpha < smallestAlpha) {
            smallestAlpha = alpha;
            smallestAlphaSet = i;
        }
    }

    return smallestAlphaSet;
}

int main() {
    cout << "Enter the number of elements in universal set U: ";
    cin >> N;

    cout << "Enter the elements in universal set U: ";
    for (int i = 0; i < N; i++) {
        cin >> U[i];
    }

    cout << "Enter the number of subsets: ";
    cin >> M;

    cout << "Enter the subsets and their costs:" << endl;
    for (int i = 0; i < M; i++) {
        int len;
        cout << "Enter the length of subset S" << i + 1 << ": ";
        cin >> len;

        cout << "Enter the elements of subset S" << i + 1 << ": ";
        for (int j = 0; j < len; j++) {
            cin >> S[i][j];
        }

        cout << "Enter the cost of subset S" << i + 1 << ": ";
        cin >> cost[i];
    }

    int totalCost = 0;
    list<int> solutionSet;

    while (true) {
        int smallestAlphaSet = findSmallestAlphaSet();
        if (smallestAlphaSet == -1) break;

        for (int i = 0; i < N; i++) {
            if (covered[i]) continue;

            bool found = false;
            for (int j = 0; j < sizeof(S[smallestAlphaSet]) / sizeof(int); j++) {
                if (S[smallestAlphaSet][j] == U[i]) {
                    found = true;
                    break;
                }
            }

            if (found) {
                covered[i] = true;
                totalCost += cost[smallestAlphaSet];
            }
        }

        solutionSet.push_back(smallestAlphaSet + 1);
        cost[smallestAlphaSet] = -1;
    }

    cout << "Solution set: ";
    for (auto i : solutionSet) {
        cout << "S" << i << " ";
    }
    cout << endl;

    cout << "Total cost: " << totalCost << endl;

    return 0;
}
