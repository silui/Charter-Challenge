#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int CIDRreturn(const string &inputarg)
{
    int returnThis = 0;
    vector<string> result;
    stringstream ss(inputarg);
    string token;
    bool encouterzero = false;
    short mask = 0b10000000;
    while(getline(ss,token,'.'))
    {
        short temp = stoi(token);
        if(temp>255)
            return -1;
        for(int i=0; i<8;i++)
        {
            if((temp&mask) > 0)
                if(encouterzero==true)
                    return -1;
                else
                    returnThis++;
            else
                encouterzero = true;
            temp = temp<<1;
        }
    }
    return returnThis;
}

int main()
{
    cout<<CIDRreturn("255.255.255.0")<<endl;
    return 0;
}