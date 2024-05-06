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


using namespace std;

class BigInt {
    private:
        vector<char> digits;
        BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1);
    public:
        BigInt();
        BigInt(int a) {
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
            if (a.length() == 0) {
                digits.push_back('0');
            } else {
                for (int i = a.length()-1; i >= 0; i--) {
                    digits.push_back(char(a[i]));
                }
            }

            
        }

        BigInt operator+ (BigInt a) {
            vector<int> temp = {};
            vector<int> carry;
            int loop;
            if (digits.size() > a.size()) {
                while (digits.size() > a.size()) {
                    a.digits.push_back('0');
                }
            } else {
                while (digits.size() < a.size()) {
                    digits.push_back('0');
                }
            }

            for (int i = 0; i < digits.size(); i++) {
                temp.push_back(char(digits[i] + a.digits[i]));
            }

            for (int i = 0; i < temp.size(); i++) {
                if (int(temp[i]) > 9) {
                    temp[i] = char(int(temp[i]) - 10);
                    temp[i+1] = char(int(temp[i+1]) + 1);
                }
            }
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
            for (int i : digits) {
                cout << i;
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

int main() {
    //main function
    //testUnit();
    BigInt myNum("12345678901234567890");
    cout << myNum << endl;
    return 0;
}