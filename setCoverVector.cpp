#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
#include <iterator>
#include <iostream>
using namespace std;
// function to sort a vector of pairs based on the second element
bool sortBySecond(const pair<vector<int>, int> &a, const pair<vector<int>, int> &b)
{
    return (a.second < b.second);
}
int main()
{
    vector<int> U = {1, 2, 3, 4, 5};
    cout << "Universal Set: ";
    for (int i = 0; i < U.size(); i++)
    {
        cout << U[i] << " ";
    }
    vector<vector<int>> S;
    vector<int> s1 = {4, 1, 3};
    vector<int> s2 = {2, 5};
    vector<int> s3 = {1, 4, 3, 2};
    S.push_back(s1);
    S.push_back(s2);
    S.push_back(s3);
    vector<int> cost = {5, 10, 3};
    vector<int> C;
    vector<float> alpha;
    for (int i = 0; i < 3; i++)
    {
        float val = (float)cost[i] / (float)S[i].size();
        alpha.push_back(val);
    }
    vector<pair<vector<int>, float>> v; // pair of {set, alpha}
    for (int i = 0; i < 3; i++)
    {
        v.push_back(make_pair(S[i], alpha[i]));
    }
    sort(v.begin(), v.end(), sortBySecond);
    int total = 0;
    vector<int> setIndices;
    while (!U.empty())
    {
        vector<int> Si = v.front().first; // get the subset with the smallest alpha
        float alp = v.front().second;
        v.erase(v.begin());
        bool covered = false;
        for (int j = 0; j < Si.size(); j++)
        { // check if element is already covered
            if (find(U.begin(), U.end(), Si[j]) != U.end())
            {
                // total += alp*Si.size();
                covered = true;
                U.erase(find(U.begin(), U.end(), Si[j])); // remove the covered element from U
                // break;
            }
        }
        if (covered)
        {
            total += alp * Si.size(); // add the set's price to total cost
            auto it = find(S.begin(), S.end(), Si);
            setIndices.push_back(distance(S.begin(), it) + 1);
        }
    }
    cout << "\nGiven subsets: ";
    for (int i = 0; i < S.size(); i++)
    {
        cout << endl;
        cout << "S" << i + 1 << " = ";
        vector<int> p = S[i];
        for (int j = 0; j < S[i].size(); j++)
        {
            cout << p[j] << " ";
        }
    }
    cout << "\nCost of each subset: ";
    for (int i = 0; i < cost.size(); i++)
    {
        cout << cost[i] << " ";
    }
    cout << "\n\nThe sets taken into consideration are: ";
    for (int i = 0; i < setIndices.size(); i++)
    {
        cout << "S" << setIndices[i] << " ";
    }
    cout << "\nThe minimum set cost is: " << total << endl;
    return 0;
}