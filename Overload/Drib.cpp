#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    static int count;

    int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    static int getCount() {
        return count;
    }

    Fraction() : numerator(0), denominator(1) {
        count++;
    }

    Fraction(int num) : numerator(num), denominator(1) {
        count++;
    }

    Fraction(int num, int den) : Fraction(num) {
        if (den == 0) {
            cout << "Помилка: знаменник не може бути нульовим. Встановлено 1." << endl;
            denominator = 1;
        }
        else {
            denominator = den;
        }
        reduce();
    }

    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {
        count++;
    }

    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;
        cout << "Введіть знаменник: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Знаменник не може бути нульовим. Встановлено 1." << endl;
            denominator = 1;
        }
        reduce();
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    // --- Перевантажені оператори ---
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator,
            denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Помилка: ділення на нуль. Повертається дріб 0/1." << endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator * other.denominator,
            denominator * other.numerator);
    }
};

int Fraction::count = 0;


int main() {
    Fraction a, b, result;
    char op;

    cout << "Введіть перший дріб:\n";
    a.input();

    cout << "Введіть другий дріб:\n";
    b.input();

    cout << "Виберіть дію (+ - * /): ";
    cin >> op;

    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        cout << "Невідома операція." << endl;
        return 1;
    }

    cout << "Результат: ";
    result.display();

    cout << "\nКількість створених екземплярів класу Fraction: " << Fraction::getCount() << endl;

    return 0;
}
