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
            for (int i = a.size()-1; i > 0; i--) {
                digits.push_back(char(a[i]));
            }

            if (a.size() == 0) {
                digits.push_back('0');
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
        BigInt operator[](int i) { // index function
            
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
            cout << var.digits[-1];
            cout << endl;
        }
        friend BigInt operator+ (int, BigInt);
};

int main() {
    //main function
    //testUnit();
    BigInt myNum(356);
    cout << myNum;
    return 0;
}