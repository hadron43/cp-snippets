/*
 * Author : @hadron43
 * Email : hadron43@yahoo.com
 * 
 * CPP to JSON string Converter
 * This prgram does the following task:
 * 
 * Read from input.txt =>
 * Parse to json string =>
 * store it in output.txt
 */
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string line;

ifstream in;
ofstream out;

void open_files() {
    in.open("input.txt");
    out.open("output.txt");
}

void close_files() {
    in.close();
    out.close();
}

void fetch_next() {
    getline(in, line);
    // cerr<<"Fetched: "<<line<<endl;
}

void flush(string end = "\n") {
    line = line + end;
    out<<line;
}

int main() {
    open_files();

    line = "[";
    flush();
    while(in) {
        fetch_next();
        string temp = "";
        for(char ch : line) {
            if(ch == 9)
                temp += "\\t";
            else
                temp += ch;
        }
        line = "\t\"" + temp + "\"";
        (in) ? flush(",\n") : flush();
    }
    line = "]";
    flush();
}
