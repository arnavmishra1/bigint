// Author: Arnav Mishra
// CECS 325-02 Prog 6
// Due 05/09/2024

// I certify that this program is my own original work.
// I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

class BigInt {
    private:
        vector<char> digits;
        BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1);
    public:
        BigInt();
        BigInt(int a) {
            digits = {};
            int multiplier = 10;
            int size = to_string(a).length();
            cout << size;
            for(int i = 0; i < size; i++) {
                cout << a % ( multiplier * 10^i ) << endl;
                digits.push_back( a % ( multiplier * 10^i ) );
            }
        }
        BigInt(string);

        BigInt operator+ (BigInt);
        BigInt operator- (BigInt);
        BigInt operator- (int);
        BigInt operator* (BigInt);
        BigInt operator/ (BigInt);
        BigInt operator% (BigInt);
        BigInt operator++(int);
        BigInt operator++( );
        BigInt operator[](int i) { // index function
            return digits[-1-i];
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
            cout << var << endl;
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