
#include<iostream>
#include<fstream>
#include"prog2_3.hpp"
using namespace std;
int main(int argc,char** argv){
    cout << "Assignment #2-4, Anthony Reese, areese@sdsu.edu" << endl;
    if(argc!=2){
        cout<<"This program expects a single command line argument."<<endl;
        return -1;
    }

    int lineNum=0;
    vector<string> tokens;
    Parser parse;
    Tokenizer token;
        
    try{
    fstream file(argv[1]);
            while(!file.eof()){
        lineNum++;
                string s;
                getline(file,s);
        token.Tokenize(s);
        }
        
    }catch(string error){
        cout<<"Error on line "<<lineNum<<": "<<error<<endl;
          return -1;
        }
    
    tokens=token.GetTokens();
    if(parse.Parse(tokens)){
        for(int i=0;i<tokens.size();i++){
            stringstream ss(tokens[i]);
            int count=0;
            string temp;
            while(getline(ss,temp,' ')){
                count++;
            if(temp.find_first_not_of("0123456789")==string::npos){
                stringstream sstemp(temp);
                int num;
                sstemp>>num;

                cout<<","<<num;
            }
            else{
                if(count>1)
                cout<<","<<temp;
                else cout<<temp;
                    }
                    }
                cout<<endl;
                }
            }
            else{
    cout<<"Parse error on line "<<parse.lineNum+1<<": "<<tokens[parse.lineNum]<<endl;
            }
        
        

    return 0;
}

