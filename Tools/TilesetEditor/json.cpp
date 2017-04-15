#include <string>
#include <vector>
#include <iostream>

#include "json.h"


json::json(char* contents){
    std::vector<std::string> tokens;
    std::string current_token = contents;
    int size = current_token.length();
    for (int i = 0; i < size; i++){
        if (contents[i] == '{'){
            tokens.push_back("{");
        } else if (contents[i] == '}'){
            tokens.push_back("}");
        } else if (contents[i] == ','){
            tokens.push_back(",");
        } else if (contents[i] == ':'){
            tokens.push_back(":");
        } else if (contents[i] == '"'){
            current_token = "\"";
            for (int j = i+1; contents[j] != '"'; j++){
                current_token.push_back(contents[j]);
                i = j + 1;
            }
            current_token.push_back('"');
            tokens.push_back(current_token);
        } else if ((contents[i] - '0' >= 0) && (contents[i] - '0' < 10)){
            current_token = "";
            for (; (contents[i] - '0' >= 0) && (contents[i] - '0' < 10); i++){
                current_token.push_back(contents[i]);
            }
            tokens.push_back(current_token);
            i--;
        } else if (contents[i] == 't'){
            tokens.push_back("true");
            i += 3;
        } else if (contents[i] == 'f'){
            tokens.push_back("false");
            i += 4;
        } else if (contents[i] == 'n'){
            tokens.push_back("null");
            i += 3;
        }
    }
    std::vector<std::string>::iterator iter = tokens.begin();
    this->init(iter);
}

json::json(){};


void json::init(std::vector<std::string>::iterator &iter){
    if (*iter != "{"){
        this->key = *iter;
        iter++;
        iter++;
    }
    if (*iter == "{"){
        this->type == OBJECT;
        iter++;
        while (*iter != "}"){
            json content;
            content.init(iter);
            this->contents.push_back(content);
            if (*iter != "}"){
                iter++;
            }
        }
    } else if (*iter == "false"){
        this->type == BOOLEAN;
        this->truth = false;
    } else if (*iter == "true"){
        this->type == BOOLEAN;
        this->truth = true;
    } else if (*iter == "null"){
        this->type == NULL_T;
    } else if ((*iter).at(0) == '"'){
        this->type == STRING;
        this->value = *iter;
    } else {
        this->type == NUMBER;
        this->value = std::stoi(*iter);
    }
    iter++;
}

std::string json::getKey(){
    return this->key;
}

std::string json::getValue(){
    return this->value;
}

int json::getNum(){
    return this->number;
}

std::vector<json> json::getContents(){
    return this->contents;
}

bool json::getTruth(){
    return this->truth;
}
