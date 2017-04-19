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
    Pair(string f,string s,int i){
        p = make_pair(f,s);
        point = i;
        tail = s.length();
    }

};
class sColsure{
public:
    vector <Pair> colsure;
    vector<sColsure*> scolsure;
    vector<char> linkchar;
    int Size=0;
    void addPair(Pair p){
        colsure.push_back(p);
        Size++;
    }
    void test(){
        for(int i=0;i<colsure.size();i++){
            cout<<colsure[i].p.first<<" "<<colsure[i].p.second<<" "<<colsure[i].point<<" "<<colsure[i].priority<<endl;
        }
    }
    bool exitPair(Pair fpair,int point){
        typedef vector<Pair>::iterator It;
        It it;
        it=colsure.begin();
            if(it->p.first==fpair.p.first&&it->p.second==fpair.p.second&&it->point==point){
                return true;
            }
        else{
        return false;

        }
    }
};
class bColsure{
public:
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
    vector<Pair> c_gramma;
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
//        }                cout<<"add new point :"<<newpoint<<endl;

    }
    void init_follow(){

    }
    void init_gramma(){


        Pair p("~","S",0);
        c_gramma.push_back(p);
        Pair p1("S","L=R",0);
        c_gramma.push_back(p1);
        Pair p2("S","R",0);
        c_gramma.push_back(p2);
        Pair p3("L","*R",0);
        c_gramma.push_back(p3);
        Pair p4("L","I",0);
        c_gramma.push_back(p4);
        Pair p5("R","L",0);
        c_gramma.push_back(p5);


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
        typedef vector<Pair>::iterator It;
        string left,right,tmp;
        char nextchar;
        int scolpointlocal,pairpoint;
        bool isin;
        sColsure scolsure;
        It it;
        init_gramma();
        sColsure *head = new sColsure();
        for(it=c_gramma.begin();it!=c_gramma.end();it++){
            left = it->p.first;
            right= it->p.second;
            Pair p(left,right,0);
            scolsure.addPair(p);
            cout<<left<<" "<<right<<endl;
        }
        bcol.addColsure(scolsure);
        //add linkchar
        for(int i=0;i<bcol.colsure[0].Size;i++){
            tmp = bcol.colsure[0].colsure[i].p.second;
            isin = false;
            for(int j=0;j<bcol.colsure[0].linkchar.size();j++){
                if(tmp[bcol.colsure[0].colsure[i].point] == bcol.colsure[0].linkchar[j]){
                    isin = true;
                    scolpointlocal = j;
                    break;
                }
            }
            if(isin==false){ //bcol中没有添加该链接导致出错
                bcol.colsure[0].linkchar.push_back(tmp[bcol.colsure[0].colsure[i].point]);
                sColsure *scol = new sColsure();
                sColsure addscol;
                int newpoint = bcol.colsure[0].colsure[i].point+1;
                Pair p(bcol.colsure[0].colsure[i].p.first,tmp,newpoint);
                scol->addPair(p);
                addscol.addPair(p);
                bcol.colsure[0].scolsure.push_back(scol);
                bcol.addColsure(addscol);
//                cout<<"add:"<<bcol.colsure[0].colsure[i].p.first<<"->"<<tmp<<","<<p.point<<endl;
//                cout<<"not in creat new"<<endl;
//                cout<<endl;
            }
            else{

                int newpoint = bcol.colsure[0].colsure[i].point+1;
                Pair p(bcol.colsure[0].colsure[i].p.first,tmp,newpoint);
                bcol.addColsure(p,scolpointlocal);
                bcol.colsure[0].scolsure[scolpointlocal]->addPair(p);
//                cout<<"add:"<<p.p.first<<"->"<<p.p.second<<","<<p.point<<endl;
//                cout<<"insert number:"<<scolpointlocal<<endl;
//                cout<<endl;
            }
        }
        for(int i=0;i<bcol.colsure[0].scolsure.size();i++){
            int scolsuresize = bcol.colsure[0].scolsure[i]->colsure.size();
            for(int j=0;j<scolsuresize;j++){
                if(bcol.colsure[0].scolsure[i]->colsure[j].point != bcol.colsure[0].scolsure[i]->colsure[j].p.second.length()){
//                cout<<"pair:"<<bcol.colsure[0].scolsure[i]->colsure[j].p.first<<"->"<<bcol.colsure[0].scolsure[i]->colsure[j].p.second<<endl;
//                cout<<"point:"<<bcol.colsure[0].scolsure[i]->colsure[j].point<<endl;
                    pairpoint = bcol.colsure[0].scolsure[i]->colsure[j].point;
                    nextchar = bcol.colsure[0].scolsure[i]->colsure[j].p.second[pairpoint];
//                cout<<"find char add :"<<nextchar<<endl;
                    vector<Pair> addPair;
                    addfollow(nextchar,addPair);
//                cout<<"add pair size:"<<addPair.size()<<endl;
                    for(int k=0;k<addPair.size();k++){
//                        cout<<addPair[k].p.first<<"->"<<addPair[k].p.second<<endl;
                        bcol.colsure[0].scolsure[i]->addPair(addPair[k]);
                        bcol.addColsure(addPair[k],i+1);
//                        cout<<addPair[k].p.first<<"->"<<addPair[k].p.second<<endl;
                    }
                }

            }
            buildcolsure(bcol.colsure[0].scolsure[i]);
            //add buildcolsure
        }
//        for(int i=0;i<bcol.colsure.size();i++){
//            for(int j=0;j<bcol.colsure[i].colsure.size();j++){
//                cout<<"each pair of colsure:"<<bcol.colsure[i].colsure[j].p.first<<"->"<<bcol.colsure[i].colsure[j].p.second<<","<<bcol.colsure[i].colsure[j].point<<endl;
//            }
//            cout<<endl;
//        }
//        cout<<bcol.colsure[0].scolsure.size()<<endl;
    }
    void addfollow(char c,vector<Pair> &res){
        typedef vector<Pair>::iterator It;
//        cout<<"to find char:"<<c<<endl;
        string firsttmp,secondtmp;
        It it;
        for(it=bcol.colsure[0].colsure.begin();it!=bcol.colsure[0].colsure.end();it++){
            firsttmp = it->p.first;
            if(c==firsttmp[0]){
                Pair p(firsttmp,it->p.second,0);
                res.push_back(p);
                secondtmp = it->p.second;
//                cout<<"add pair :"<<p.p.first<<","<<p.p.second<<","<<p.point<<endl;
                addfollow(secondtmp[0],res);
            }
        }
//        cout<<"not find char:"<<c<<endl;
//        cout<<"return res.size:"<<res.size()<<endl;
        return;

    }
    void buildcolsure(sColsure *&scol){
//        scol->test();
//        cout<<endl;
//        return;
        for(int i=0;i<scol->colsure.size();i++){
            if(scol->colsure[i].point!=scol->colsure[i].p.second.length()){
                int scolnum,pairpoint = scol->colsure[i].point+1;
                string findfirst,findsecond;
                findfirst = scol->colsure[i].p.first;
                findsecond = scol->colsure[i].p.second;
                Pair findpair(findfirst,findsecond,pairpoint);
                scolnum = bcol.exitPair(findpair,pairpoint);
                if(scolnum!=-1){
                    sColsure *linkcol = new sColsure();
                    *linkcol = bcol.colsure[scolnum];
                    scol->scolsure.push_back(linkcol);
                    scol->linkchar.push_back(findsecond[pairpoint-1]);
                    cout<<"add link"<<endl;
                    cout<<"findfirst:"<<findfirst<<endl;
                    cout<<"findsecond:"<<findsecond<<endl;
                    cout<<"point:"<<pairpoint<<endl;
                    cout<<"scolnum:"<<scolnum<<endl;
                    bcol.colsure[scolnum].test();
                    cout<<endl;

                    //add link
                }
                else{
                    sColsure *s = new sColsure();
                    sColsure adds;
                    s->addPair(findpair);
                    adds.addPair(findpair);
                    scol->linkchar.push_back(findsecond[pairpoint-1]);
                    scol->scolsure.push_back(s);
                    adds.linkchar.push_back(findsecond[pairpoint-1]);
                    adds.scolsure.push_back(s);
                    bcol.colsure.push_back(adds);
                    cout<<"creat new colsure"<<endl;
                    cout<<"findfirst:"<<findfirst<<endl;
                    cout<<"findsecond:"<<findsecond<<endl;
                    cout<<"point:"<<pairpoint<<endl;
                    cout<<"scolnum:"<<scolnum<<endl;
                    bcol.colsure.back().test();
                    cout<<endl;
                   // scol->scolsure.push_back();
                }


            }
        }
        for(int j=0;j<scol->scolsure.size();j++){
            buildcolsure(scol->scolsure[j]);
        }

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
