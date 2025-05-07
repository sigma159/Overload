#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
    string data;

public:
    MyString(const string& str = "") : data(str) {}

    void print() const {
        cout << data << endl;
    }

    MyString operator*(const MyString& other) const {
        string result;

        for (char c : data) {
            if (other.data.find(c) != string::npos && result.find(c) == string::npos) {
                result += c;
            }
        }

        return MyString(result);
    }

    void input() {
        cout << "Введіть рядок: ";
        getline(cin, data);
    }
};

int main() {
    MyString str1, str2;

    str1.input();
    str2.input();

    MyString intersection = str1 * str2;

    cout << "Перетин рядків: ";
    intersection.print();

    return 0;
}
