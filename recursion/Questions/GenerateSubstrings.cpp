# include<bits/stdc++.h>
using namespace std;

void genSubStr(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }

    char c = s[0];
    string ros =  s.substr(1);

    genSubStr(ros, ans);
    genSubStr(ros, ans+c);
}

int main(){
    genSubStr("ABC","");
    
    return 0;
}