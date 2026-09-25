#include <iostream>

class string {
    char *str;
    int len;

    public:
        string(char c, int n); // 문자 c 가 n 개 있는 문자열로 정의
        string(const char *s);
        string(const string &s);
        ~string();

        void add_string(const string &s); // str 뒤에 s 를 붙인다.
        void copy_string(const string &s); // str 에 s 를 복사한다.
        int strlen(); // 문자열 길이 리턴
};

string::string(char c, int n) {
    str = new char[n];
    for (int i = 0; i < n; i++) {
        str[i] = c;
    }
    len = n;
}
string::string(const char *s) {
    len = 0;
    while (s[len] != '\0') {
        len++;
    }
    str = new char[len];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }
}
string::string(const string& s) {
    str = new char[s.len];
    for (int i = 0; i < s.len; i++) {
        str[i] = s.str[i];
    }
    len = s.len;
}
string::~string() {
    for (int i = 0; i < len; i++) {
        std::cout << "'" << str[i];
    }
    std::cout << "' string이 제거 되었습니다." << std::endl;
    delete[] str;
}

void string::add_string(const string &s){
    char *new_str = new char[len + s.len];
    for (int i = 0; i < len; i++) {
        new_str[i] = str[i];
    }
    for (int i = len; i < len + s.len; i++){
        new_str[i] = s.str[i - len];
    }
    delete[] str;
    str = new_str;
    len += s.len;
}
void string::copy_string(const string &s){
    if (this == &s) return;

    delete[] str;
    str = new char[s.len];
    for (int i = 0; i < s.len; i++) {
        str[i] = s.str[i];
    }
    len = s.len;
}
int string::strlen() {
    return len;
}

int main() {
    string A('k', 7);
    string B("ASD");
    string C(A);

    std::cout << A.strlen() << std::endl
            << B.strlen() << std::endl
            << C.strlen() << std::endl;
    A.add_string(B);
    std::cout << A.strlen() << std::endl;
    A.copy_string(B);
    std::cout << A.strlen() << std::endl;
}