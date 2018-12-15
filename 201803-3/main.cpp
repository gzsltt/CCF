/* CCF201803-3 URLӳ�� */

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
    while(ps < lens && pt < lent) {//�ַ�����ƥ��
        if(t[pt] == s[ps]) {//��ƥ�� ��������ƥ��
            ps++, pt++;
        } else {//���˲�ƥ����±�

            // ƥ��<xxx>
            if(t[pt++] != '<')//�������<�� ���Ǵ���ģ�������һ��
                return false;
            if(flag)
                cout << ' ';

            if(t[pt] == 'i') {
                // ƥ��<int>
                bool ok = false;
                while(s[ps] && isdigit(s[ps])) {
                    if(s[ps] != '0')
                        ok = true;
                    if(flag && ok)
                        cout << s[ps];//�������
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            } else if(t[pt] == 's') {
                // ƥ��<str>
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
                // ƥ��<path>
                if(flag)
                    while(s[ps])
                        cout << s[ps++];
                return true;
            }
        }
    }

    return pt == lent && ps == lens;//�Ƿ�ƥ�䵽���һ���ַ�
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> r[i];//url�͹���ֱ���������ͬ���̻�����д洢
    for(int i = 0; i < m; i++) {
        cin >> s[i];}
for(int i = 0; i < m; i++) {
        bool flag = true;
        for(int j = 0; flag && j < n; j++)
            if(match(s[i], p[j], false)) {//���ж�
                flag = false;
                cout << r[j];
                match(s[i], p[j], true);//��������� ����еĻ�
            }

        if(flag)
            cout << "404";
        cout << endl;}

    return 0;
}
