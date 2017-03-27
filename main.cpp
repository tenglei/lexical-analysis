#include <iostream>
#include <vector>
#include<string.h>
#include<fstream>
#include<map>
using namespace std;
class lexical_analysis{
private:
    char *key[6]={"while","if","else","for","variable","main"};
    char token[50];
    int pt_token;
    int pt_tmp;
    int line;
public:
    int error;
        lexical_analysis(string tmp){
        line = 0;
        int i,j,k,syn;
        bool nt_letter=false;
        pt_token = 0;
        pt_tmp = 0;
        i=50;
        for(i=0;i<50;i++){
            token[i] = NULL;
        }
        while(tmp[pt_tmp]!='#'||tmp[pt_tmp]!='\0'){
            while(tmp[pt_tmp]==' '){
                nt_letter=false;
                pt_token =0;
                i=50;
                for(i=0;i<50;i++){
                    token[i] = NULL;
                }
                pt_tmp++;
        }
            while(tmp[pt_tmp]!=' '){
                if(tmp[pt_tmp]=='\n'){
                    line++;
                }
                if((tmp[pt_tmp]>='a'&&tmp[pt_tmp]<='z')||(tmp[pt_tmp]>='A'&&tmp[pt_tmp]<='Z')){
                    while((tmp[pt_tmp]>='a'&&tmp[pt_tmp]<='z')||(tmp[pt_tmp]>='A'&&tmp[pt_tmp]<='Z')||(tmp[pt_tmp]>='0'&&tmp[pt_tmp]<='9')){
                        token[pt_token++] = tmp[pt_tmp++];
                    }
                    nt_letter = false;
                    for(i=0;i<6;i++){
                        if(strcmp(token,key[i])==0){
                            syn=i+1;
                            cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                            nt_letter=true;
                            break;
                        }
                    }
                    if(!nt_letter){
                        syn = 7;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                    }
                    i=50;
                    for(i=0;i<50;i++){
                        token[i] = NULL;
                    }
                    pt_token = 0;
                }
                else if(tmp[pt_tmp]>='0'&&tmp[pt_tmp]<='9'){
                    while(tmp[pt_tmp]>='0'&&tmp[pt_tmp]<='9'){
                        token[pt_token++] = tmp[pt_tmp++];
                    }
                    syn = 8;
                    cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                    i=50;
                    for(i=0;i<50;i++){
                        token[i] = NULL;
                    }
                    pt_token = 0;
                }
                else{
                    switch(tmp[pt_tmp]){
                    case '=':
                        token[pt_token++] = tmp[pt_tmp];
                        if(tmp[pt_tmp+1]=='='){
                            syn = 14;
                            token[pt_token] = tmp[++pt_tmp];
                            cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        }
                        else{
                            syn = 13;
                            cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        }
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '>':
                        token[pt_token++] = tmp[pt_tmp];
                        if(tmp[pt_tmp+1]=='='){
                            syn = 14;
                            token[pt_token] = tmp[++pt_tmp];
                            cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        }
                        else{
                            syn=15;
                            cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        }
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '<':
                        token[pt_token++] = tmp[pt_tmp];
                        if(tmp[pt_tmp+1]=='='){
                            syn = 18;
                            token[pt_token] = tmp[++pt_tmp];
                            cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        }
                        else{
                            syn=16;
                            cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        }
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '*':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 9;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '/':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 10;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '-':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 11;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '+':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 12;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case ';':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 19;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '(':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 20;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case ')':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 21;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '{':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 22;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '}':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 23;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case ',':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 24;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        break;
                    case '#':
                        token[pt_token++] = tmp[pt_tmp];
                        syn = 0;
                        cout<<"("<<line<<","<<syn<<","<<token<<")"<<endl;
                        i=50;
                        for(i=0;i<50;i++){
                            token[i] = NULL;
                        }
                        pt_token = 0;
                        pt_tmp++;
                        error= 0;
                        return;
                    case '\n':
                        pt_tmp++;
                        break;
                    default:
                        token[pt_token++] = tmp[pt_tmp];
                        cout<<"("<<line<<","<<"Sign error"<<","<<token<<")"<<endl;
                        error = -2;
                        return ;
                }


            }
          if(tmp[pt_tmp]=='#'){
                cout<<"("<<line<<","<<syn<<","<<tmp[pt_tmp]<<")"<<endl;
                    error  = 0;
                    return ;
                }
          else if(pt_tmp==(tmp.length())){
                cout<<"("<<line<<","<<"No_End error"<<","<<token<<")"<<endl;
                error = -1;
                return ;
          }
        }
    }
    }
};
class grammatical_analysis{
private:
    map<string,string> c_gramma;
    map<string,string> first;
    map<string,string> follow;
    void init_first(){

    }
    void init_follow(){

    }
    void init_gramma(){
        map<string,string> terminate_or_disterminate;
        terminate_or_disterminate.insert(pair<string,string>("terminate","+"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","-"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","*"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","/"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","id"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","("));
        terminate_or_disterminate.insert(pair<string,string>("terminate",")"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","int"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","void"));
        terminate_or_disterminate.insert(pair<string,string>("terminate","="));

        terminate_or_disterminate.insert(pair<string,string>("disterminate","T"));
        terminate_or_disterminate.insert(pair<string,string>("disterminate","F"));
        terminate_or_disterminate.insert(pair<string,string>("disterminate","E"));
        terminate_or_disterminate.insert(pair<string,string>("disterminate","TYPE"));

        c_gramma.insert(pair<string,string>("type","int|void"));
        c_gramma.insert(pair<string,string>("E","=T"));
        c_gramma.insert(pair<string,string>("T","T+F|T*F|T"));
        c_gramma.insert(pair<string,string>("F","T|id"));
    }
};
int main(){
    //string tmp = "main {variable k,i=0;if(i==60){k=1;} else{  k = 51;}  } while(i){i = i-1;} for(i=0;i <=3;i = i+1){k = k+1} #";
    ifstream op("test.txt");
    string test,t;
    while(getline(op,test)){
        t += test+'\n';
    }

//    cout<<t;
//    lexical_analysis la(t);
//    cout<<"lexical analysis:"<<la.error<<endl;


    return 0;
}
