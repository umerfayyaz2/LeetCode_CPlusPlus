#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        return build(s) == build(t);
    }

private:
    string build(string s)
    {
        string ans = "";
        for (char c : s)
        {
            if (c != '#')
            {
                ans.push_back(c);
            }
            else if (!ans.empty())
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s1 = "ab#c";
    string s2 = "ad#c";
    bool result = solution.backspaceCompare(s1, s2);
    cout << "Result of backspace comparison: " << (result ? "true" : "false") << endl;
    return 0;
}
