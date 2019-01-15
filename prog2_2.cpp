
#include<iostream>
#include<fstream>
#include"prog2_1.hpp"
using namespace std;

int main(int argc,char** argv){
    cout << "Assignment #2-2, Anthony Reese, areese@sdsu.edu" << endl;
    if(argc!=2){
        cout<<"This program expects a single command line argument"<<endl;
        return -1;
    }
    int lineNum=0;
    try{
        fstream file(argv[1]);
        Tokenizer token;
        while(!file.eof()){
            lineNum++;
            string s;
                   getline(file, s);
            token.Tokenize(s);
        }

        vector<string> tokens = token.GetTokens();
        for(int i=0;i<tokens.size();i++){
            stringstream ss(tokens[i]);
            int c=0;
            string temp;                
            while(getline(ss,temp,' ')){
            if(temp.find_first_not_of("0123456789")==string::npos){
                stringstream sstemp(temp);
                int num;
                sstemp>>num;

                cout<<","<<num;
            }
                        else{
                cout<<temp;
            }
        }
            cout<<endl;
    }
}    catch(string error){
        cout<<"Error on line "<<lineNum<<": "<<error<<endl;
    }

    return 0;
}
