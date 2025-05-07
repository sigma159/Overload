//#include <iostream>
//using namespace std;
//
//class Date {
//    int day;
//    int month;
//    int year;
//
//    int daysInMonth(int m, int y) const {
//        switch (m) {
//        case 2: return (isLeap(y) ? 29 : 28);
//        case 4: case 6: case 9: case 11: return 30;
//        default: return 31;
//        }
//    }
//
//    bool isLeap(int y) const {
//        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
//    }
//
//    bool lessThan(const Date& other) const {
//        if (year != other.year) return year < other.year;
//        if (month != other.month) return month < other.month;
//        return day < other.day;
//    }
//
//public:
//    Date() : day(1), month(1), year(2000) {}
//    Date(int d, int m, int y) : day(d), month(m), year(y) {}
//
//    void input() {
//        while (true) {
//            cout << "Enter day: ";
//            cin >> day;
//
//            cout << "Enter month: ";
//            cin >> month;
//
//            cout << "Enter year: ";
//            cin >> year;
//
//            if (month < 1 || month > 12) {
//                cout << "Invalid month! Please try again.\n";
//                continue;
//            }
//
//            int maxDay = daysInMonth(month, year);
//
//            if (day < 1 || day > maxDay) {
//                cout << "Invalid day for the given month! Please try again.\n";
//                continue;
//            }
//
//            break;
//        }
//    }
//
//
//    void print() const {
//        cout << day << "." << month << "." << year << endl;
//    }
//
//    int operator-(const Date& other) const {
//        Date d1 = *this;
//        Date d2 = other;
//        int counter = 0;
//
//        if (d2.lessThan(d1)) swap(d1, d2);
//
//        while (d1.lessThan(d2)) {
//            d1 = d1 + 1;
//            counter++;
//        }
//
//        return counter;
//    }
//
//    Date operator+(int addDays) const {
//        Date result = *this;
//        while (addDays > 0) {
//            int daysInCurrentMonth = daysInMonth(result.month, result.year);
//            if (result.day < daysInCurrentMonth) {
//                result.day++;
//            }
//            else {
//                result.day = 1;
//                result.month++;
//                if (result.month > 12) {
//                    result.month = 1;
//                    result.year++;
//                }
//            }
//            addDays--;
//        }
//        return result;
//    }
//};
//
//int main() {
//    Date d1, d2;
//    cout << "Enter the first date:\n";
//    d1.input();
//
//    cout << "Enter the second date:\n";
//    d2.input();
//
//    cout << "\nFirst date: "; d1.print();
//    cout << "Second date: "; d2.print();
//
//    int diff = d1 - d2;
//    cout << "Difference between dates: " << diff << " days\n";
//
//    int add;
//    cout << "\nHow many days to add to the first date? ";
//    cin >> add;
//
//    Date d3 = d1 + add;
//    cout << "New date after adding: ";
//    d3.print();
//
//    return 0;
//}
