#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int main(int argc, char* argv[]){
    
    const vector<string> cmdLineArgs{argv, argv+argc};
    const size_t nCmdLineArgs{cmdLineArgs.size()};
    bool helpRequested{false};
    bool versionRequested{false};
    string inputFile{""};
    string outputFile{""};

    //now let's loop over the cmd line args!
    //the first is always the program, so skip that!
    for (size_t i{1}; i<nCmdLineArgs; i++){
        if (cmdLineArgs[i]=="-h" || cmdLineArgs[i]=="--help"){
            helpRequested=true;
        }
        else if (cmdLineArgs[i]=="-v" || cmdLineArgs[i]=="--version"){
            versionRequested=true;
        }
        else if (cmdLineArgs[i]=="-i"){
            if (i==nCmdLineArgs-1){
                cerr<<"[error] You must specify a file name as -i argument!\n";
                return 1;}
            else{
                inputFile=cmdLineArgs[i+1];
                i++;} //move past the file name
        }
        else if (cmdLineArgs[i]=="-o"){
            if (i==nCmdLineArgs-1){
                cerr<<"[error] You must specify a file name as -o argument!\n";
                return 1;}
            else{
                outputFile=cmdLineArgs[i+1];
                i++;} //move past the file name
        }
        else{
            cerr<<"[error] Unkown argument '"<<cmdLineArgs[i]<<"' has been passed!\n";
            return 1;
        }
    }

    if (helpRequested){
        cout
            << "Usage: mpags-cipher [-h/--help] [-v/--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  -v|--version     Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n";
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    if (versionRequested){
        cout<<"v1.2.0"<<endl;
        return 0; //like help, we exit just with the version output
    }

    if (!inputFile.empty()){  //input file not implemented yet!
        cerr<<"[warning] input from file ("<<inputFile<<") not implemented yet!"
            <<" Using stdin for now!\n";
    }

    string out_str{""};
    char in_char{'x'};
    cout<<"Give me some chars!"<<endl;
    cout<<"[INFO: Press Enter and then Ctrl+D to terminate your input!]"<<endl;

    while(cin>>in_char){
        
        ///cout<<"You gave me char: "<<in_char<<endl;

        if (isalpha(in_char)){              //info: isdigit() checks for numerical char
            if (islower(in_char)){
                out_str+=toupper(in_char);
            }
            else out_str+=in_char;
            continue;
        }
        switch(in_char){
                case '0': out_str+="ZERO"; break;
                case '1': out_str+="ONE"; break;
                case '2': out_str+="TWO"; break;
                case '3': out_str+="THREE"; break;
                case '4': out_str+="FOUR"; break;
                case '5': out_str+="FIVE"; break;
                case '6': out_str+="SIX"; break;
                case '7': out_str+="SEVEN"; break;
                case '8': out_str+="EIGHT"; break;
                case '9': out_str+="NINE"; break;
                default: break;
        }
    }
    
    if (!outputFile.empty()){  //output file not implemented yet!
        cerr<<"[warning] output to file ("<<outputFile<<") not implemented yet!"
            <<" Using stdout for now!\n";
    }

    cout<<"Your string is: "<<out_str<<"\n===DONE!==="<<endl;
    return 0;
}