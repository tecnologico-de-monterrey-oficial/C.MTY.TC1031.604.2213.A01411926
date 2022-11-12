#pragma once
#include <cstring>
using namespace std;

struct Log {
    string date;
    string time;
    string entry;
    string ubi;
    string key;
    Log();
    Log(string date, string time, string entry, string ubi);
    bool operator<(Log log);
    bool operator>(Log log);
    bool operator<=(Log log);
    bool operator>=(Log log);
    bool operator==(string value);
    bool operator==(Log value);
};
Log::Log(){
}
Log::Log(string date, string time, string entry, string ubi){
    this->date = date;
    this->time = time;
    this->entry = entry;
    this->ubi = ubi;
    string newdate = date.substr(6,4) + date.substr(3,2) + date.substr(0,2);
    this->key = ubi + "-" + newdate + "-" + time;
}
bool Log::operator<(Log log){
    return this->key < log.key;
}
bool Log::operator>(Log log){
    return this->key > log.key;
}
bool Log::operator==(string value){
    return strcmp(this->ubi.c_str(), value.c_str())==0;
}
bool Log::operator==(Log value){
    return strcmp(this->ubi.c_str(), value.ubi.c_str())==0;
}