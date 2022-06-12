#include "dinamic.h"

template <class T>
void Print(T someList) {
    for (auto& x : someList) cout << " " << x;
    cout << endl;
}

void Dinamic::Read(vector<int> input)
{
    if (input.size() == 0)
    {
        cout << "Vector don't input" << endl;
        exit(0);
    }
    else
        ReadInput = input;
}

void Dinamic::Find()
{
    vector<int> d(ReadInput.size());
    vector<int> index;
    int pos = 0;
    for (int i = 0; i < ReadInput.size(); i++)
    {
        index.push_back(0);
    }
    for (int i = 0; i < ReadInput.size(); i++) {
        d[i] = 1;
        index[i] = -1;
        for (int j = 0; j < i; j++)
            if (ReadInput[j] - ReadInput[i] == 2 && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                index[i] = j;
            }
    }
    int l = d[0];
    for (int i = 0; i < ReadInput.size(); i++)
        if (d[i] > l) {
            pos = i;
            l = d[i];
        }
    while (pos != -1) {
        Result.push_back(ReadInput[pos]);
        pos = index[pos];
    }
    reverse(Result.begin(), Result.end());
}

void Dinamic::print()
{
    cout << " Dinamic O(n^2) algorithm : ";
    Print(Result);
}
