#include <iostream>

class chara {
    char* val;
    int len;
    
    public:
        chara(char c);
        chara(const char *str);
        chara(const chara& other);
        ~chara();

        int strlen() const;
        void add_chara(const chara& add_char);
        void search(const chara& target_char) const;
        void same_compar(const chara& target_char) const;
        void size_compar(const chara& target_char) const;
        void print() const;
};


chara::chara (char c){
    val = new char[1];
    val[0] = c;
    len = 1;
}
chara::chara (const char *str){
    len = 0;
    while (str[len] != '\0'){
        len++;
    }
    val = new char[len];
    for (int i = 0; i < len; i ++){
        val[i] = str[i];
    }
}
chara::chara(const chara& other) {
    len = other.len;
    val = new char[len];
    for (int i = 0; i < len; i++) {
        val[i] = other.val[i];
    }
}
chara::~chara (){
    delete[] val;
}

int chara::strlen() const {
    return len;
}

void chara::add_chara(const chara& add_char) {
    char* new_val = new char[len + add_char.len];
    for (int i = 0; i < len; i++) {
        new_val[i] = val[i];
    }
    for (int i = 0; i < add_char.len; i++) {
        new_val[len + i] = add_char.val[i];
    }
    delete[] val;
    val = new_val;
    len += add_char.len;
}

void chara::print() const {
    for (int i = 0; i < len; i++) {
        std::cout << val[i];
    }
    std::cout << std::endl;
}

int main() {
    chara a('A');
    chara b("Kch357");
    chara c("blog");
    b.add_chara(b);
    b.print();
    std::cout << b.strlen() << std::endl;

    return 0;
}