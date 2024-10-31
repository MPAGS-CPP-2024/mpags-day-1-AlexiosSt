#include<iostream>
#include<string>

using namespace std;

int main(){
    
    string out_str{""};
    char in_char{'x'};
    cout<<"Give me some chars!"<<endl;
    cout<<"[INFO: Press Enter and then Ctrl+D to terminate your input!]"<<endl;

    while(cin>>in_char){
        
        cout<<"You gave me char: "<<in_char<<endl;

        if (isalpha(in_char)){              //info: isdigit() checks for numerical char
            if (islower(in_char)){
                out_str+=toupper(in_char);
            }
            else out_str+=in_char;
            continue;
        }
        switch(in_char){
                case '0': out_str+=" ZERO"; break;
                case '1': out_str+=" ONE"; break;
                case '2': out_str+=" TWO"; break;
                case '3': out_str+=" THREE"; break;
                case '4': out_str+=" FOUR"; break;
                case '5': out_str+=" FIVE"; break;
                case '6': out_str+=" SIX"; break;
                case '7': out_str+=" SEVEN"; break;
                case '8': out_str+=" EIGHT"; break;
                case '9': out_str+=" NINE"; break;
                default: break;
        }
    }
    
    cout<<"You string is "<<out_str<<" !!!\n===done==="<<endl;
    return 0;
}