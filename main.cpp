#include <iostream>
#include <sstream>
using namespace std;

//accept CIDR IP return bit mask
//return -1 if netmask is invalid 
int netmask_to_bits(const string &inputarg)
{
    int returnThis = 0;
    stringstream ss(inputarg);
    string token;
    bool encouterzero = false;
    short mask = 0b10000000;
    //interate through each clause seperated by period
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
            //shift clause left 8 times to do comparason
            temp = temp<<1;
        }
    }
    return returnThis;
}

int main()
{
    cout<<netmask_to_bits("255.255.255.128")<<endl;
    return 0;
}