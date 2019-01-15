#include"prog2_3.hpp"
    
Parser::Parser(){
    lineNum=0;
}
Parser::~Parser() {

}
bool Parser::Parse(vector<string> tokens){
    for(int i=0;i<tokens.size();i++){
       if(tokens[i].substr(0,3)=="get"){
            if(tokens[i].length()<4){
                lineNum=i;
                return false;
            }
            if(tokens[i].substr(4).find_first_not_of("0123456789")!=string::npos){
                lineNum=i;
                return false;
            }
        }
        
        else if(tokens[i].substr(0,4)=="push" || tokens[i].substr(0,4)=="save"){
            if(tokens[i].length()<5){
                lineNum=i;
                return false;
            }
            if(tokens[i].substr(5).find_first_not_of("0123456789")!=string::npos){
                lineNum=i;
                return false;
            }
        }
        
        else if(tokens[i].substr(0,4)=="skip"){
            if(tokens[i].length()>4){
                lineNum=i;
                return false;
            }
        }
        
       else if(tokens[i].substr(0,3)=="mul" || tokens[i].substr(0,3)=="div" || tokens[i].substr(0,3)=="mod" ||                                      tokens[i].substr(0,3)=="pop" || tokens[i].substr(0,3)=="add" || tokens[i].substr(0,3)=="sub"){
            if(tokens[i].length()>3){
                lineNum=i;
                return false;
            }
        }
        
    }
    return true;
}
