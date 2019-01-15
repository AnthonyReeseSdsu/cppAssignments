
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Tokenizer
{
private:
    vector<string> *tokens;
public:
    Tokenizer();
    ~Tokenizer();
    void Tokenize(string);
    vector<string> GetTokens();
};
