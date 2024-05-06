// Author: Arnav Mishra
// CECS 325-02 Prog 6
// Due 05/09/2024

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <ostream>
#include <vector>
#include <math.h>
#include <iomanip>


using namespace std;

class BigInt {
    private:
        vector<char> digits;
        BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1);
    public:
        BigInt() {}
        BigInt(int a) {
            digits = {};
            if (a == 0) {
                digits.push_back('0');
            }
            while (a > 0) {
                int i = a % 10;
                char temp = to_string(i)[0];
                digits.push_back(temp);
                a = a / 10;
            }
        }
        BigInt(string a) {
            digits = {};
            if (a.length() == 0) {
                digits.push_back('0');
            } else {
                for (int i = a.length()-1; i >= 0; i--) {
                    digits.push_back(char(a[i]));
                }
            }

            
        }

        BigInt operator+ (BigInt a) {
            BigInt ret;
            vector<int> temp;
            vector<int> carry;
            if (digits.size() > a.size()) {
                while (digits.size() > a.size()) {
                    a.digits.push_back('0');
                }
            } else {
                while (digits.size() < a.size()) {
                    digits.push_back('0');
                }
            }

            cout << *this << endl;
            cout << a << endl;


            for (int i = 0; i < digits.size(); i++) {
                cout << "c: " << int(digits[i]) - 48 + int(a.digits[i]) - 48 << endl;
                temp.push_back((int(digits[i]) - 48 + int(a.digits[i]) - 48));
                cout << temp[i] << endl;
            }

            temp.push_back(0);
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] > 9) {
                    cout << "!" << endl;
                    temp[i] = temp[i] - 10;
                    temp[i+1] = temp[i+1] + 1;
                }
            }
            
            reverse(temp.begin(), temp.end());
            int i = 0;
            if (temp[0] == 0) {
                i = 1;
            }
            string fin;
            for (i; i < temp.size(); i++) {
                fin += to_string(temp[i]);
            }
            ret = fin;
            return ret;
        }
        BigInt operator- (BigInt);
        BigInt operator- (int);
        BigInt operator* (BigInt);
        BigInt operator/ (BigInt);
        BigInt operator% (BigInt);
        BigInt operator++(int);
        BigInt operator++( );
        char operator[](int i) { // index function
            return digits[i];
        }

        void print() {
            vector<char>::iterator itr;
            for (itr = digits.end()-1; itr >= digits.begin(); itr--) {
                cout << *itr;
            }
            cout << endl;
        }
        int size() {
            int count = 0;
            for(int i : digits) {
                count++;
            }
            return count;
        }
        BigInt fibo(); // calls fiboHelper
        BigInt fact();
        friend ostream& operator<<(ostream& out, const BigInt& var) {
            vector<char>::const_iterator itr;

            if (var.digits.size() < 13) {
                for (itr = var.digits.end()-1; itr >= var.digits.begin(); itr--) {
                    out << *itr;
                }
            } else {
                out << var.digits[var.digits.size()-1] << '.';
                for (itr = var.digits.end()-2; itr > var.digits.end()-8; itr--) {
                    out << *itr;
                }
                out << 'e' << var.digits.size()-1;
            }
            return out;
        }
        friend BigInt operator+ (int, BigInt);
};

/*void testUnit() {
    int space = 10;
    cout << "\a\nTestUnit:\n"<<flush;
    system("whoami");
    system("date");
    // initialize variables
    BigInt n1(25);
    BigInt s1("25");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);
    BigInt fibo(12345);
    BigInt fact(50);
    BigInt imax = INT_MAX;
    BigInt big("9223372036854775807");
    // display variables
    cout << "n1(int) :"<<setw(space)<<n1<<endl;
    cout << "s1(str) :"<<setw(space)<<s1<<endl;
    cout << "n2(int) :"<<setw(space)<<n2<<endl;
    cout << "s2(str) :"<<setw(space)<<s2<<endl;
    cout << "n3(n2) :"<<setw(space)<<n3<<endl;
    cout << "fibo(12345):"<<setw(space)<<fibo<<endl;
    cout << "fact(50) :"<<setw(space)<<fact<<endl;
    cout << "imax :"<<setw(space)<<imax<<endl;
    cout << "big :"<<setw(space)<<big<<endl;
    cout << "big.print(): "; big.print(); cout << endl;
    cout << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<<endl;
    cout << "fibo("<<fibo<<") = "<<fibo.fibo() << endl;
    cout << "fact("<<fact<<") = "<<fact.fact() << endl;
    cout << "10 + n1 = " << 10+n1 << endl;
    cout << "n1 + 10 = " << n1+10 << endl;
    cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<<endl;
    cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<<endl;
    cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<<endl;
    cout << "s2 * big = ? --> "<< s2 * big<<endl;
    cout << "big * s2 = ? --> "<< big * s2<<endl;
}*/

int main() {
    //main function
    //testUnit();
    BigInt myNum("01");
    BigInt yourNum(900);
    cout << myNum << endl;
    cout << yourNum << endl;
    cout << (myNum + yourNum) << endl;
    return 0;
}