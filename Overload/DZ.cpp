#include <iostream>
using namespace std;

class Date {
    int day, month, year;

    int daysInMonth(int m, int y) const {
        switch (m) {
        case 2: return (isLeap(y) ? 29 : 28);
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
        }
    }

    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    bool lessThan(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void input() {
        cin >> *this;
    }

    void print() const {
        cout << *this;
    }

    void addOneDay() {
        *this = *this + 1;
    }

    Date operator++(int) {
        Date temp = *this;
        *this = *this + 1;
        return temp;
    }

    Date& operator++() {
        *this = *this + 1;
        return *this;
    }

    Date operator--(int) {
        Date temp = *this;
        *this = *this - 1;
        return temp;
    }

    Date& operator--() {
        *this = *this - 1;
        return *this;
    }

    Date operator+(int addDays) const {
        Date result = *this;
        while (addDays-- > 0) {
            int maxDay = result.daysInMonth(result.month, result.year);
            if (result.day < maxDay)
                result.day++;
            else {
                result.day = 1;
                result.month++;
                if (result.month > 12) {
                    result.month = 1;
                    result.year++;
                }
            }
        }
        return result;
    }

    Date operator-(int subDays) const {
        Date result = *this;
        while (subDays-- > 0) {
            if (result.day > 1)
                result.day--;
            else {
                result.month--;
                if (result.month < 1) {
                    result.month = 12;
                    result.year--;
                }
                result.day = result.daysInMonth(result.month, result.year);
            }
        }
        return result;
    }

    int operator-(const Date& other) const {
        Date d1 = *this;
        Date d2 = other;
        int counter = 0;

        if (d2.lessThan(d1)) swap(d1, d2);
        while (d1.lessThan(d2)) {
            d1 = d1 + 1;
            counter++;
        }

        return counter;
    }

    Date& operator=(const Date& other) {
        if (this != &other) {
            day = other.day;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    Date& operator+=(int days) {
        *this = *this + days;
        return *this;
    }

    Date& operator-=(int days) {
        *this = *this - days;
        return *this;
    }

    bool operator()() const {
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > daysInMonth(month, year)) return false;
        return true;
    }

    friend bool operator==(const Date& a, const Date& b);
    friend bool operator!=(const Date& a, const Date& b);
    friend bool operator<(const Date& a, const Date& b);
    friend bool operator>(const Date& a, const Date& b);

    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
};

bool operator==(const Date& a, const Date& b) {
    return a.day == b.day && a.month == b.month && a.year == b.year;
}

bool operator!=(const Date& a, const Date& b) {
    return !(a == b);
}

bool operator<(const Date& a, const Date& b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

bool operator>(const Date& a, const Date& b) {
    return b < a;
}

ostream& operator<<(ostream& out, const Date& d) {
    out << (d.day < 10 ? "0" : "") << d.day << "."
        << (d.month < 10 ? "0" : "") << d.month << "."
        << d.year;
    return out;
}

istream& operator>>(istream& in, Date& d) {
    while (true) {
        cout << "Enter day: "; in >> d.day;
        cout << "Enter month: "; in >> d.month;
        cout << "Enter year: "; in >> d.year;

        if (d()) break;
        else cout << "Invalid date! Try again.\n";
    }
    return in;
}

int main() {
    Date d1, d2;
    cout << "Enter first date:\n"; cin >> d1;
    cout << "Enter second date:\n"; cin >> d2;

    cout << "\nFirst date: " << d1 << "\n";
    cout << "Second date: " << d2 << "\n";

    cout << "\nDate difference: " << (d1 - d2) << " days\n";

    cout << "\nIncrementing first date: " << d1++ << " -> " << d1 << "\n";
    cout << "Decrementing second date: " << d2-- << " -> " << d2 << "\n";

    int days;
    cout << "\nHow many days to add to the first date? ";
    cin >> days;

    d1 += days;
    cout << "New first date: " << d1 << "\n";

    return 0;
}
