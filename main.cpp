
#include <iostream>
#include <cstring>
using namespace std;

int Add(int, int); // adds two integers
double Add(double, double); // adds two doubles
char *Add(char str1[], char str2[]); // adds two C-strings (char arrays)

int main() {
    // note: overloaded functions can have same or different return types but *must* have different parameters
    /* test Add(int, int) */
    int a1 = 0, a2 = 0;
    cout << "Enter two integer numbers to add: ";
    cin >> a1;
    cin >> a2;
    cout << "Sum: " << Add(a1, a2) << endl;
    /* test Add(double, double) */
    double x = 0, y = 0;
    cout << "Enter two floating-point numbers to add: ";
    cin >> x;
    cin >> y;
    cout << "Sum: " << Add(x, y) << endl;
    // cin.ignore(256); // used so that getline() isn't skipped over
    /* test Add(char*, char*) */
    char sentence1[100], sentence2[100];
    cout << "Enter sentence 1: ";
    cin.getline(sentence1, 100);
    cin.ignore(256, '\n');
    cout << "Enter sentence 2: ";
    cin.getline(sentence2, 100);
    cout << "Final sentence: " << Add(sentence1, sentence2) << endl;
    return 0;
}

int Add(int a, int b) {
    return a+b;
}

double Add(double n1, double n2) {
    return n1+n2;
}

char *Add(char str1[], char str2[]) {
    /* todo: finish this function */
    // we can't exactly add/concatenate C-strings typically
    // strcat(*dest, *src): appends copy of 'src' string to end of 'dest' str. Let's use this
    strcat(str1, str2);
    return str1; // str1 should now have str2 added to it
}