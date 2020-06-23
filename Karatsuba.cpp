#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

typedef long int l;

string add(string X, string Y){
    int len = max(X.size(), Y.size());
    int carry = 0;
    int sum;
    string result;
    
    while(X.size()<len){
        X = "0" + X;
    }
    while(Y.size()<len){
        Y = "0" + Y;
    }
    
    for (int i=len-1;i>=0;i--){
        sum = (X[i]-'0') + (Y[i]-'0') + carry;
        //cout<<sum;
        carry = sum / 10;
        result.insert(0, to_string(sum % 10));
        //cout<<result[i];
    }
    if (carry){
        result = "1" + result;
    }
    int i=0;
    while(result[i]=='0'){
        i++;
    }
    result.erase(0,i);
    
    return result;
}
// To do X - Y
string substract(string X, string Y){
    int len = max(X.size(), Y.size());
    int diff;
    string result;
    
    while(X.size()<len){
        X = "0" + X;
    }
    while(Y.size()<len){
        Y = "0" + Y;
    }
    
    for (int i=len-1;i>=0;i--){
        diff = (X[i]-'0') - (Y[i]-'0');
        
        if (diff >= 0){
            result.insert(0, to_string(diff));
        }
        else {
            
            int j = i - 1;
            while(j>=0){
                //cout<<10+diff;
                if(X[j]!='0'){
                    X[j] = ((X[j]-'0')-1)+'0';
                    result.insert(0, to_string(10+diff));
                    break;
                }
                else {
                    X[j] = '9';
                    j++;
                }
                
            }
        }
    }
    
    // Clearing out the padded zeros 
    int i=0;
    while(result[i]=='0'){
        i++;
    }
    result.erase(0,i);
    
    return result;
}

string multiply(string s1, string s2){
    //cout<<"Multiplication of "<<s1<<" and "<<s2<<endl;
    int len1, len2, len;
    len1 = s1.size();
    len2 = s2.size();
    while(len1>len2){
        s2 = '0'+s2;
        len2++;
    }
    while(len2>len1){
        s1 = '0'+s1;
        len1++;
    }
    len = len1;
    
    if (len == 0) return 0;
    if (len == 1) return to_string((s1[0]-'0')*(s2[0]-'0'));
    
    int m = len/2;
    int sm = len-m;
    
    string L1 = s1.substr(0,m);
    string R1 = s1.substr(m,sm);
    string L2 = s2.substr(0,m);
    string R2 = s2.substr(m,sm);
    //cout<<L1<<" "<<R1<<" "<<L2<<" "<<R2<<endl;
    
    string x = multiply(L1, L2);
    //cout<<x<<"xx"<<L1<<endl;
    string y = multiply(R1, R2);
    //cout<<y<<"yy"<<endl;
    string z = multiply(add(L1, R1), add(L2, R2));
    string zf = substract(substract(z,y),x);
    
    for (int i=0; i<2*(sm); i++){
        x = x + "0";
    }

    for (int i=0; i<sm; i++){
        zf = zf + "0";
    }
    string result = add(add(x,y),zf);
    int i=0;
    while(result[i]=='0'){
        i++;
    }
    result.erase(0,i);
    
    return result;
}

int main() {
    string s1, s2;
    cin>>s1>>s2;
    //cout<<s1+s2;
    cout<<multiply(s1, s2);
}
