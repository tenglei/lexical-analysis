#include <iostream>
#include <vector>
#include<string.h>
#include<fstream>
#include<map>
#include <utility>
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
class Pair{
public:
    pair<string,string> p;
    int priority;
    int point=0;
    int tail;
    Pair(string s,string t,int i){
        p = make_pair(s,t);
        point = i;
        tail = t.length();
    }

};
class sColsure{
public:
    vector <Pair> colsure;
    void addPair(Pair p){
        colsure.push_back(p);
    }
    void test(){
        for(int i=0;i<colsure.size();i++){
            cout<<colsure[i].p.first<<" "<<colsure[i].p.second<<" "<<colsure[i].point<<" "<<colsure[i].priority<<endl;
        }
    }
    bool exitPair(Pair fpair,int point){
        typedef vector<Pair>::iterator It;
        It it;
        for(it=colsure.begin();it!=colsure.end();it++){
            if(it->p.first==fpair.p.first&&it->p.second==fpair.p.second&&it->point==point){
                return true;
            }
        }
        return false;
    }
};
class bColsure{
private:
    int exitPair(Pair fpair,int point){
        typedef vector<sColsure>::iterator It;
        It it;
        int num=0;
        for(it=colsure.begin();it!=colsure.end();it++){
             if(it->exitPair(fpair,point)){
                return num;
             }
             num++;
        }
        return -1;
    }
public:
    vector<sColsure> colsure;
    void addColsure(sColsure col){
        colsure.push_back(col);
    }
    void addColsure(Pair p,int i){
        colsure[i].addPair(p);
    }
    int colsureNum(){
        return colsure.size();
    }
};
class grammatical_analysis{
private:
    bColsure bcol;
    multimap<string,string> c_gramma;
    vector<string> terminate;
    vector<string> disterminate;
    multimap<string,string> first;
    multimap<string,string> follow;
    void init_first(){
        typedef multimap<string,string>::iterator c_grammaMapItor;
        typedef multimap<string,string>::iterator It;
        It it;
//        for(it=c_gramma.begin();it!=c_gramma.end();it++){
//            cout<<it->first<<endl;
//            cout<<it->second<<endl;
////            pair<c_grammaMapItor,c_grammaMapItor>pos = c_gramma.equal_range(it->first);
////            while(pos.first!=pos.second){
////                cout<<pos.first->second<<endl;
////                ++pos.first;
////            }
//            //循环查找first集合即可
//          //  first.insert(pair<string,string>());
//            cout<<endl;
//        }
    }
    void init_follow(){

    }
    void init_gramma(){




        c_gramma.insert(pair<string,string>("E","E+T"));
        c_gramma.insert(pair<string,string>("E","E-T"));
        c_gramma.insert(pair<string,string>("E","T"));
        c_gramma.insert(pair<string,string>("T","T*F"));
        c_gramma.insert(pair<string,string>("T","T/F"));
        c_gramma.insert(pair<string,string>("T","F"));
        c_gramma.insert(pair<string,string>("F","(E)"));
        c_gramma.insert(pair<string,string>("F","id"));


        terminate.push_back("+");
        terminate.push_back("*");
        terminate.push_back("-");
        terminate.push_back("/");

        disterminate.push_back("E");
        disterminate.push_back("T");
        disterminate.push_back("F");


        init_first();
        init_follow();
    }
    void init_colsure(){
        typedef multimap<string,string>::iterator It;
        string left,right;
        sColsure scolsure;
        It it;
        init_gramma();
        sColsure *head = new sColsure();
        for(it=c_gramma.begin();it!=c_gramma.end();it++){
            left = it->first;
            right= it->second;
            Pair p(left,right,0);
            scolsure.addPair(p);
            cout<<left<<" "<<right<<endl;
        }
        bcol.addColsure(scolsure);

    }
public:
    grammatical_analysis(){
        init_colsure();
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

    grammatical_analysis ga;


    return 0;
}
