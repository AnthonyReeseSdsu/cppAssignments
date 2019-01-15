#include<iostream>
#include"prog2_1.hpp"

Tokenizer::Tokenizer(){
    this->tokens=new vector<string>();
}

Tokenizer::~Tokenizer(){
    delete this->tokens;
}

void Tokenizer::Tokenize(string str){
    stringstream ss(str);
    string token;              
    bool valid;     
    while(getline(ss,token,' ')){
        if(token=="push" || token=="pop" || token=="add" || token=="sub" || token=="mul" || token=="div"|| token=="mod" || token=="skip" ||                               token=="save" || token=="get")
        valid=true;
        
        else if(token.find_first_not_of("0123456789")==string::npos)//check if int
        valid=true;
        
        else {                 //throw error
        valid=false;
        string message="Unexpected token: ";
        message+=token;            throw message;
        }
    }
    if(valid)
        tokens->push_back(str);
}

vector<string> Tokenizer::GetTokens(){
    if(tokens->size()==0)          
        throw "No tokens";
    else {
        return *tokens;
    }
    
}
