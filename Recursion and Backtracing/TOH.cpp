// Tower of Hanoi problem.

#include <iostream>
using namespace std;

void TOH(int n, string source, string destination, string helper)
{
    if (n == 1)
    {
        cout << n << " move from " << source << " to " << destination << endl;
        return;
    }
    TOH(n - 1, source, helper, destination);
    cout << n << " move from " << source << " to " << destination << endl;
    TOH(n - 1, helper, destination, source);
}

int main()
{
    int n;
    cin >> n;
    string s, d, h;
    cout << " Enter source,destination,helper" << endl;
    cin >> s >> d >> h;
    TOH(n, s, d, h);

    return 0;
}