/* CCF201803-3 URL映射 */

#include <iostream>
#include <ctype.h>

using namespace std;

const int N = 100;
string p[N], r[N], s[N];

bool match(string& s, string& t, bool flag)
{
    int lent = t.size();
    int lens = s.size();
    int ps = 0, pt = 0;
    while(ps < lens && pt < lent) {//字符串的匹配
        if(t[pt] == s[ps]) {//若匹配 则向后继续匹配
            ps++, pt++;
        } else {//到了不匹配的下标

            // 匹配<xxx>
            if(t[pt++] != '<')//如果不是<字 则是错误的，返回下一个
                return false;
            if(flag)
                cout << ' ';

            if(t[pt] == 'i') {
                // 匹配<int>
                bool ok = false;
                while(s[ps] && isdigit(s[ps])) {
                    if(s[ps] != '0')
                        ok = true;
                    if(flag && ok)
                        cout << s[ps];//输出参数
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            } else if(t[pt] == 's') {
                // 匹配<str>
                bool ok = false;
                while(s[ps] && s[ps] != '/') {
                    ok = true;
                    if(flag)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            } else if(t[pt] == 'p') {
                // 匹配<path>
                if(flag)
                    while(s[ps])
                        cout << s[ps++];
                return true;
            }
        }
    }

    return pt == lent && ps == lens;//是否匹配到最后一个字符
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> r[i];//url和规则分别用两个不同的商户组进行存储
    for(int i = 0; i < m; i++) {
        cin >> s[i];}
for(int i = 0; i < m; i++) {
        bool flag = true;
        for(int j = 0; flag && j < n; j++)
            if(match(s[i], p[j], false)) {//先判断
                flag = false;
                cout << r[j];
                match(s[i], p[j], true);//再输出参数 如果有的话
            }

        if(flag)
            cout << "404";
        cout << endl;}

    return 0;
}
