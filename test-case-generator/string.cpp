#include <bits/stdc++.h>
using namespace std;   

string gen_random(const int len, const int mode, const int num) {
    string alphaNum;
    switch (mode)
    {
        case 0:
            alphaNum = "abcdefghijklmnopqrstuvwxyz";
            break;
        case 1:
            alphaNum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            break;
        case 2:
            alphaNum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
            break;
        case 3:
            alphaNum.reserve(num);
            for(int i=0;i<num;i++){ char c = 'a'+i; alphaNum+=c; }
            break;
        default:
            break;
    }
    string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphaNum[rand() % (alphaNum.size())];
    }
    
    return tmp_s;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv[1] length of the string
 * @param argv[2] lowercase/upperlower/alphanumeric/somechars 
 * @param argv[3] number of characters
 * @return int 
 */
int main(int argc, char *argv[]) {
    srand(time(NULL));     

    int n = stoi(argv[1]); int mode = 0; int num = 26;
    
    if(argc >= 3){
        mode = stoi(argv[2]);
        if(mode ==3){
            num = stoi(argv[3]);
        }
    }

    cout << gen_random(n, mode, num) << endl;

    return 0;
}