#include <iostream>
using namespace std;
bool next_balanced_sequence (string &s)
{
    int n = s.size();
    int depth = 0;
    for (int i = n - 1 ; i >= 0 ; --i) {
        if (s[i] == '(') {
            depth--;
        } else {
            depth++;
        }
        if (s[i] == '(' && depth > 0) {
            depth--;
            int open = (n - i - 1 - depth) / 2;
            int close = n - i - 1 - open;
            string Next = s.substr(0,i) + ')' + string(open,'(') + string(close,')');
            s.swap(Next);
            return true;
        }
    }
    return false;
}
int main ()
{
    return 0;
}