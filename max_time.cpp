#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

void tokenize(vector<string> &out, string &time) {
    char *token = strtok(const_cast<char *> (time.c_str()), ":");
    while (token != nullptr) {
        cout << "token = " << token << endl;
        out.push_back( string(token));
        token = strtok(NULL, ":");
    }
}

string getMaxTime(string &time) {
    // split to hour and minute, for hour:
    vector<string> out;
    tokenize(out, time); 

    string hour = out[0], minute = out[1];
    string get_hour = hour, get_miunte = minute;

    if (hour[0] == '?' && hour[1] == '?') {
        get_hour = "23";
    } else if (hour[0] == '?') {
        if (hour[1] >= '4') {
            get_hour[0] = '1';
        } else {
            get_hour[0] = '2';
        }
        get_hour[1] = hour[1];

    } else if (hour[1] == '?') {

        if (hour[0] == '2') {
            // 23
            get_hour[1] = '3';
        } else {
            // let hour[1] = '9'
            get_hour[0] = hour[0];
            get_hour[1] = '9';
        }
    }

    if (minute[0] == '?' && minute[1] == '?') {
        get_miunte = "59";

    } else if (minute[0] == '?') {
        get_miunte[0] = '5';
        
    } else if (minute[1] == '?') {
        get_miunte[1] = '9';
    }

    return get_hour+":" + get_miunte;
}

int main() {

    string s("2?:5?");
    
    auto res = getMaxTime(s);

    cout << res << endl;
    return 0;
}
