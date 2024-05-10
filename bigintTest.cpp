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
        BigInt fiboHelper(BigInt n, BigInt a = 0, BigInt b = 1) {
            if (n == 0) {
                return a;
            } else if (n == 1) {
                return b;
            } else {
                return fiboHelper(n-1, b, a + b);
            }
        }
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
            // pad bigints if length is different
            // a remove and this remove - used to remove excess zeroes after calculations are done
            int ar = 0;
            int tr = 0;
            if (digits.size() > a.size()) {
                while (digits.size() > a.size()) {
                    a.digits.push_back('0');
                    ar++;
                }
            } else {
                while (digits.size() < a.size()) {
                    digits.push_back('0');
                    tr++;
                }
            }

            // calculate sum into an int vector
            vector<int> sum;
            for (int i = 0; i < (*this).size(); i++) {
                sum.push_back((int((*this)[i]) - 48 + int(a[i]) - 48));
            }

            // add a zero in case the carry calculations add a digit
            sum.push_back(0);
            for (int i = 0; i < sum.size(); i++) {
                if (sum[i] > 9) {
                    sum[i] = sum[i] - 10;
                    sum[i+1] = sum[i+1] + 1;
                }
            }
            
            // reverse results to be in normal order, check if the added zero was used, set index to 1 if not
            reverse(sum.begin(), sum.end());
            int i = 0;
            if (sum[0] == 0) {
                i = 1;
            }
            // concatenate the vector as a string
            string fin;
            for (i; i < sum.size(); i++) {
                fin += to_string(sum[i]);
            }

            // removing excess zeroes
            while (ar > 0) {
                a.digits.pop_back();
                ar--;
            }
            while (tr > 0) {
                digits.pop_back();
                tr--;
            }

            // return a bigint made with the concatenated string
            return BigInt(fin);
        }

        BigInt operator- (BigInt a) {
            // pad bigints if length is different
            // a remove and this remove - used to remove excess zeroes after calculations are done
            int ar = 0;
            int tr = 0;
            if (digits.size() > a.size()) {
                while (digits.size() > a.size()) {
                    a.digits.push_back('0');
                    ar++;
                }
            } else {
                while (digits.size() < a.size()) {
                    digits.push_back('0');
                    tr++;
                }
            }

            // calculate diff into an int vector
            vector<int> diff;
            for (int i = 0; i < (*this).size(); i++) {
                diff.push_back((int((*this)[i]) - int(a[i])));
            }

            // "carry"
            for (int i = 0; i < diff.size(); i++) {
                if (diff[i] < 0) {
                    diff[i] = diff[i] + 10;
                    diff[i+1] = diff[i+1] - 1;
                }
            }
            
            // reverse results to be in normal order, check if first digit is 0, set index to 1 if it is
            reverse(diff.begin(), diff.end());
            int i = 0;
            if (diff[0] == 0) {
                i = 1;
            }

            // concatenate the vector as a string
            string fin;
            for (i; i < diff.size(); i++) {
                fin += to_string(diff[i]);
            }

            // removing excess zeroes
            while (ar > 0) {
                a.digits.pop_back();
                ar--;
            }
            while (tr > 0) {
                digits.pop_back();
                tr--;
            }

            // return a bigint made with the concatenated string
            return BigInt(fin);
        }
        BigInt operator- (int a) {
            return (*this) - BigInt(a);
        }
        BigInt operator* (BigInt a) {
            BigInt small = (*this);
            BigInt temp = a;

            if (small > temp) {
                small = temp;
                temp = (*this);
            }

            BigInt prod(temp);

            if (small > 1 && temp > 1) {
                for (BigInt i(0); a > (i+1); i++) {
                    prod = prod + temp;
                }
            }
            return prod;
        }
        BigInt operator/ (BigInt a) {
            BigInt result(0);
            BigInt temp = *this;
            while (temp > a) {
                result++;
                temp = temp - a;
                
            }
            return result;
        }
        BigInt operator% (BigInt a) {
            BigInt temp(*this / a);
            return *this - (a * (temp - 0));
        }
        // a++
        BigInt operator++(int a) {
            BigInt temp(*this);
            ++*this;
            return temp;
        }
        // ++a
        BigInt operator++() {
            *this = *this + BigInt(1);
            return *this;
        }
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
        BigInt fibo() { // calls fiboHelper
            return fiboHelper((*this));
        }
        BigInt fact() {
            BigInt temp(1);

            for (BigInt i(*this); i > 0; i--) {
                temp = temp * i;
            }
            return temp;
        }
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
        friend BigInt operator+ (int a, BigInt b) {
            return BigInt(a) + b;
        }

        // this function terminates without returning false on 100 == 0. maybe just have a check for diff length before loop
        bool operator==(int a) {
            BigInt temp(a);
            int i = 0;
            while (i < (*this).size() || i < temp.size()) {
                if ((*this)[i] != temp[i]) {
                    return false;
                }
                i++;
            }
            return true;
        }
        bool operator==(BigInt a) {
            int i = 0;
            while (i < (*this).size() || i < a.size()) {
                if ((*this)[i] != a[i]) {
                    return false;
                }
                i++;
            }
            return true;
        }
        bool operator!=(int a) {
            BigInt temp(a);
            int i = 0;
            while (i < (*this).size() || i < temp.size()) {
                if ((*this)[i] != temp[i]) {
                    return true;
                }
                i++;
            }
            return false;
        }
        bool operator!=(BigInt a) {
            int i = 0;
            while (i < (*this).size() || i < a.size()) {
                if ((*this)[i] != a[i]) {
                    return true;
                }
                i++;
            }
            return false;
        }

        // a--
        BigInt operator--(int a) {
            BigInt temp(*this);
            --*this;
            return temp;
        }
        // --a
        BigInt operator--() {
            *this = *this - BigInt(1);
            return *this;
        }

        bool operator>(BigInt a) {
            if ((*this).size() > a.size()) {
                return true;
            } else if ((*this).size() < a.size()) {
                return false;
            } else {
                for (int i = (*this).size(); i >= 0; i--) {
                    if (int(digits[i]) > int(a[i])) {
                        return true;
                    } else if (int(digits[i]) < int(a[i])){
                        return false;
                    }
                }
            }
            return false;
        } 
};

void testUnit() {
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
}

int main() {
    //main function
    testUnit();

    return 0;
}