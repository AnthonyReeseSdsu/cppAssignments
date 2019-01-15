
#include"prog2_1.hpp"
class Parser{
public:
    Parser();
    ~Parser();
    bool Parse(vector<string> tokens);
    int lineNum;
};
