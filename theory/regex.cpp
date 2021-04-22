/*
    Some theory and examples about regular expression
*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

string cor_spa(vector<string> p, int s, int amountOfSpaces)
{
    string res = "";
    long long maxl = 16;

    for (int i = 0; i < p.size(); i++)
        if (maxl < p[i].size())
            { maxl = p[i].size(); }

    for (int i = 0; i < maxl + amountOfSpaces - s; i++)
        res += " ";

    return res;
}

int main()
{
    /*

    .  - any symbol
    [] - any of symbols inside brackets
    $  - end of string
    ^  - beginning of string
    \d - any digit
    \D - not a digit
    \s - any space
    \s - not a space
    \w - some letter, digit or "_"
    \W - not a \w, heh
    \  - some subsidiary regular symbol, like "$", but like a simple character

    [^n]   - any symbol, but not "n"
    [a-d]  - some symbol in interval a-d (a,b,c,d)
    n[4]   - symbol "n" 4 times
    n[4,6] - symbol "n" 4,5 or 6 times
    n*     - symbol "n" [0-oo] times
    n+     - symbol "n" [1-oo] times
    n?     - symbol "n" [0-1] times
    (a|b)  - symbol "a" or "b"

    */

    //
    //Example: regular expression for phone number with Russian country code
    //


    vector<string> p = { "+7(800)555-35-35",
                         "+7 800 555 35 35",
                         "+78005553535",
                         "8(800)555-35-35",
                         "8 800 555 35 35",
                         "88005553535",
                         "8 800 5553535",
                         "+88005553535",
                         "+7(800 555-35-35"};

    regex reg = regex("((\\+7|8)\\s?\\d{3}\\s?\\d{3}\\s?\\d{2}\\s?\\d{2}|(\\+7|8)\\(\\d{3}\\)\\d{3}-\\d{2}-\\d{2})");

    for (auto e: p)
        cout << e << ":" << cor_spa(p, e.size(), 1) << (regex_match(e.c_str(), reg) ? "true" : "false") << "\n";

    return 0;
}
