#pragma once
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

struct Log {
    string date;
    string time;
    string entry;
    string ubi; 
    string serie;
    string key;
    string newdate;
    Log();
    Log(string date, string time, string entry, string ubi, string newdate);
    bool operator<(Log log); 
    bool operator<=(Log log); 
    bool operator>(Log log); 
    bool operator>=(Log log); 
    bool operator==(Log log); 
    bool operator!=(Log log); 
    friend ostream& operator<<(ostream& os, Log log); 
};

Log::Log() {
    date = "";
    time = "";
    entry = "";
    ubi = "";
    serie = "";
    key = "";
}

Log::Log(string date, string time, string entry, string ubi, string newdate) {
    this -> newdate = newdate;
    this->date = date;
    this->time = time;
    this->entry = entry;
    this->ubi = ubi;
    this->serie = ubi.substr(0,3);
    this->key = ubi + "-" + date.substr(6,2) + "/" + date.substr(3,2) + "/" + date.substr(0,2) + "-" + time;
}

bool Log::operator<(Log log) {
    return this->key < log.key;
}

bool Log::operator<=(Log log) {
    return this->key <= log.key;
}

bool Log::operator>(Log log) {
    return this->key >= log.key;
}

bool Log::operator>=(Log log) {
    return this->key >= log.key;
}

bool Log::operator==(Log log) {
    return this->key < log.key;
}

bool Log::operator!=(Log log) {
    return this->key < log.key;
}

ostream& operator<<(ostream& os, Log log) {
    os << "UBI: " << log.ubi << " key: " << log.key;
    return os;
}