#include <iostream>
#include <stack>
#include <string>
using namespace std;

string match(string open)
{
    if (open == "(") return ")";
    if (open == "[") return "]";
    if (open == "{") return "}";
    if (open == "<") return ">";
    if (open == "(*") return "*)";
    return "";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        stack<string> stack;
        bool error = false;
        int pos = 1;

        for (int i = 0; i < line.size();)
        {
            string token;

            if (i + 1 < line.size() && line[i] == '(' && line[i + 1] == '*')
            {
                token = "(*";
                i += 2;
            }
            else if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == ')')
            {
                token = "*)";
                i += 2;
            }
            else
            {
                token = line.substr(i, 1);
                i++;
            }

            if (token == "(" || token == "[" || token == "{" || token == "<" || token == "(*")
            {
                stack.push(token);
            }
            else if (token == ")" || token == "]" || token == "}" || token == ">" || token == "*)")
            {
                if (stack.empty() || match(stack.top()) != token)
                {
                    cout << "NO " << pos << endl;
                    error = true;
                    break;
                }
                else
                {
                    stack.pop();
                }
            }
            pos++;
        }
        if (!error)
        {
            if (stack.empty()) cout << "YES" << endl;
            else cout << "NO " << pos << endl;
        }
    }
}
