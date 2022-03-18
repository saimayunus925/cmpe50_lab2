
#include <iostream>
#include <cstring>
using namespace std;

int Add(int, int); // adds two integers
double Add(double, double); // adds two doubles
char *Add(char str1[], char str2[]); // adds two C-strings (char arrays)

void reverse_str(char *str1); // print out chars of 'str1' in reverse order

void part3(); // function for Part 3 (calculating grades)

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
    cin.ignore(256, '\n'); // used so that getline() isn't skipped over
    /* test Add(char*, char*) */
    char sentence1[100], sentence2[100];
    cout << "Enter sentence 1: ";
    cin.getline(sentence1, 100);
    cout << "Enter sentence 2: ";
    cin.getline(sentence2, 100);
    cout << "Final sentence: " << Add(sentence1, sentence2) << endl;
    // part 2: reverse a char array
    char sentence[10]; // step 1: create char array that stores up to 10 letters
    int size = 0; // step 2: declare 'size' variable for the array length, incr. it by 1 every time we read a char from console
    char c = '\0'; // char variable for step 3
    // step 3: while c is != '.', read in one char from the console at a time into c.
    cout << "Enter a character: ";
    cin.get(c);
    while (c != '.' && size < 10) {
        cout << "Enter a character: ";
        cin.get(c);
        if (c == '.') break; // if c is '.', exit loop and go to step 3
        // else if size is out of array range, print an error msg and exit
        else if (size >= 10) { cout << "ERROR - array index out of range." << endl; exit(1);}
        else {
            // else (c != '.' and size is w/in range), copy c to current array element
            // and move to next element by increasing 'size'
            sentence[size] = c;
            size++;
        }
    }
    reverse_str(sentence); // part 3:
    cout << "Enter a string: ";
    cin.getline(sentence, 100);
    cout << "Reversed string: ";
    reverse_str(sentence);
    return 0;
}

int Add(int a, int b) {
    return a+b;
}

double Add(double n1, double n2) {
    return n1+n2;
}

char *Add(char str1[], char str2[]) {
    // we can't exactly add/concatenate C-strings typically
    // strcat(*dest, *src): appends copy of 'src' string to end of 'dest' str. Let's use this
    strcat(str1, str2);
    return str1; // str1 should now have str2 added to it
}

void reverse_str(char *str1) {
    // we can't print from the last index (strlen(str1)) to 0 b/c all C-strings have a null '\0' char
    // but we can print from (strlen(str1) - 1) to 0 b/c the former is the last letter in the str
    for (int i = strlen(str1) - 1; i >= 0; i--)
        cout << str1[i];
    cout << endl;
}

void part3() {
    double val[2][8]; // step 1: declare a 2D double array (0th row is for HW and 1st row is for exams)
    // 6th-8th columns of 0th row are used for best/worst/avg HW scores
    // 6th-8th columns of 1st row are used for best/worst/avg exam scores
    for (int i = 0; i < 5; i++) {
        // steps 2 and 3: loop five times to input each HW assignment (val[0][0-4]) and exam (val[1][0-4])
        cout << "Enter a HW assignment score: ";
        cin >> val[0][i];
        cout << "Enter an exam score: ";
        cin >> val[1][i];
    }
    // skip step 4 b/c we declared val[2[8]
    // step 5a: find best HW score by comparing each score w/ 'best' (0th row, 5th column).
    // If an assignment is > 'best', update 'best' to be that assignment. Do the same for the best exam.
    for (int i = 0; i < 5; i++) { // i = 0-4 (score rows)
        for (int j = 0; j < 2; j++)  // j = 0 (HW), then j = 1 (exams)
            if (val[j][i] > val[j][5]) val[j][5] = val[j][i];
    }
    // step 6a: same as 5a, but compare each score with 'worst' (0th row, 6th column).
    // If an assignment is < 'worst', update 'worst' to be that assignment. Do the same for the worst exam.
    for (int i = 0; i < 5; i++) { // i = 0-4 (score rows)
        for (int j = 0; j < 2; j++)  // j = 0 (HW), then j = 1 (exams)
            if (val[j][i] < val[j][6]) val[j][6] = val[j][i];
    }
    // step 7a: find the avg by adding the 5 scores and dividing by 5. Do this for HW (0th row, 7th column),
    // and do it for exams (1st row, 7th column).
    double hw_avg = 0, exams_avg = 0;
    for (int i = 0; i < 5; i++) {
        hw_avg += val[0][i];
        exams_avg += val[1][i];
    }
    hw_avg /= 5; exams_avg /= 5;
    // todo: step 8 - output scores in specified format
}