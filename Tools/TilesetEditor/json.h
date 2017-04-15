#ifndef __JSON_H_INCLUDED
#define __JSON_H_INCLUDED

#include <string>
#include <vector>


enum json_type{
    OBJECT,
    STRING,
    NUMBER,
    BOOLEAN,
    NULL_T
};


class json{
    std::vector<json> contents;
    std::string key;
    std::string value;
    int number;
    bool truth;
    json_type type;
    void init(std::vector<std::string>::iterator&);
  public:
    json (char*);
    json();
    int getType();
    std::string getKey();
    std::string getValue();
    int getNum();
    std::vector<json> getContents();
    bool getTruth();
};

#endif // __JSON_H_INCLUDED
