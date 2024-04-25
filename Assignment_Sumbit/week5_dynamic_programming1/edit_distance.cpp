#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using std::string;

int min_3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int edit_distance(const string& str1, const string& str2)
{
    //write your code here
    int size_str1 = str1.size(), size_str2 = str2.size();
    vector<vector<int>> minimize(size_str2 + 1, vector<int>(size_str1 + 1));
    // set value for first row and fisrt column
    for (int i = 0; i < minimize[0].size(); i++)
    {
        minimize[0][i] = i;
    }
    for (int j = 1; j < minimize.size(); j++)
    {
        minimize[j][0] = j;
    }

    for (int i = 1; i < minimize.size(); i++)
    {
        for (int j = 1; j < minimize[0].size(); j++)
        {
            if (str1[j] == str2[i])
            {
                minimize[i][j] = min_3(minimize[i][j - 1], minimize[i - 1][j], minimize[i - 1][j - 1]);
            }
            else
            {
                minimize[i][j] = min_3(minimize[i][j - 1], minimize[i - 1][j], minimize[i - 1][j - 1]) + 1;
            }
        }
    }
    return minimize[size_str2][size_str1];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
