#include <iostream>
#include <vector>
#include<string.h>
#include<fstream>
#include<map>
#include <utility>
#include <sstream>
using namespace std;
class lexical_analysis{
private:
    char *key[6]={"while","if","else","for","int","main"};
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
class symbol{
public:
        string name;
        string type;
        int value;
        int size;
};
class symbolTable{
public:
    vector<symbol> symbolTable;
};
class semantic_analysis{
private:
    vector<symbolTable> symbolTables;
public:
    void addSymbolTable(symbolTable newSymbolTable){
        symbolTables.push_back(newSymbolTable);
    }
    int findSymbol(string fname,string ftype){
        for(int i=symbolTables.size()-1;i>=0;i--){
            for(int j=0;j<symbolTables[i].symbolTable.size();j++){
                if(fname==symbolTables[i].symbolTable[j].name&&ftype==symbolTables[i].symbolTable[j].type){
                    return i;
                }
            }
        }
        return -1;
    }
    void addSymbol(symbol newSymbol){
        symbolTables.back().symbolTable.push_back(newSymbol);
    }


};
class Pair{
public:
    pair<string,string> p;
    vector<string> follow;
    int priority=0;
    int point=0;
    int tail;
    Pair(string f,string s,int i){
        p = make_pair(f,s);
        point = i;
        tail = s.length()-1;
    }

};
class sColsure{
public:
    vector <Pair> colsure;
    vector<sColsure*> scolsure;
    vector<string> tag;
    vector<char> linkchar;
    int I;
    int Size=0;
    void addPair(Pair p){
        colsure.push_back(p);
        Size++;
    }
    void test(){
        for(int i=0;i<colsure.size();i++){
            cout<<colsure[i].p.first<<" "<<colsure[i].p.second<<" "<<colsure[i].point<<" "<<colsure[i].priority<<" ";
            cout<<"follow:";
            for(int j=0;j<colsure[i].follow.size();j++){
                cout<<colsure[i].follow[j]<<" ";
            }
            cout<<endl;

        }
    }
    bool exitPair(Pair fpair,int point){
        typedef vector<Pair>::iterator It;
        It it;
        it=colsure.begin();
        if(it->p.first==fpair.p.first&&it->p.second==fpair.p.second&&it->point==point&&it->follow==fpair.follow){
//            cout<<"test exist:"<<fpair.p.first<<"->"<<fpair.p.second<<","<<fpair.point<<endl;
            return true;
        }
        else{
        return false;

        }
    }
};
class bColsure{
public:
    vector<sColsure> colsure;
    int I=1;
    int reduceTo(Pair p,bColsure b){
        for(int i=0;i<b.colsure[0].colsure.size();i++){
            if(b.colsure[0].colsure[i].p.first==p.p.first&&b.colsure[0].colsure[i].p.second==p.p.second){
                return i;
            }
        }
    }
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
    vector<vector<string> > action,Goto;
    vector<int> stateStack;
    vector<string> inputStack;
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

    void init_gramma(){


        Pair p("~","S",0);
        c_gramma.push_back(p);
        c_gramma[0].follow.push_back("#");
        Pair p1("S","im()B",0);
        c_gramma.push_back(p1);

        Pair p2("B","{T",0);
        c_gramma.push_back(p2);

        Pair p3("T","CT",0);
        c_gramma.push_back(p3);
        Pair p4("T","}",0);
        c_gramma.push_back(p4);
        Pair p5("C","D",0);
        c_gramma.push_back(p5);
        Pair p6("C","A",0);
        c_gramma.push_back(p6);
        Pair p7("C","F",0);
        c_gramma.push_back(p7);
        Pair p8("D","iR;",0);
        c_gramma.push_back(p8);
        Pair p9("D","bR;",0);
        c_gramma.push_back(p9);
        Pair p10("A","R=V;",0);
        c_gramma.push_back(p10);
        Pair p11("V","R+V",0);
        c_gramma.push_back(p11);
        Pair p12("V","R-V",0);
        c_gramma.push_back(p12);
        Pair p13("V","R*V",0);
        c_gramma.push_back(p13);
        Pair p14("V","R/V",0);
        c_gramma.push_back(p14);
        Pair p15("V","(V)",0);
        c_gramma.push_back(p15);
        Pair p16("V","R",0);
        c_gramma.push_back(p16);
        Pair p17("F","W",0);
        c_gramma.push_back(p17);
        Pair p18("F","E",0);
        c_gramma.push_back(p18);
        Pair p19("F","L",0);
        c_gramma.push_back(p19);
        Pair p20("W","h(R)B",0);
        c_gramma.push_back(p20);
        Pair p21("E","f(R)B",0);
        c_gramma.push_back(p21);
        Pair p22("E","e(R)BlB",0);
        c_gramma.push_back(p22);
        Pair p23("E","r(AR;A)B",0);
        c_gramma.push_back(p23);
        Pair p24("R","I",0);
        c_gramma.push_back(p24);

        for(int i=1;i<17;i++){
            c_gramma[i].follow.push_back("#");
        }

        terminate.push_back("i");
        terminate.push_back("m");
        terminate.push_back(";");
        terminate.push_back("h");
        terminate.push_back("f");
        terminate.push_back("e");
        terminate.push_back("l");
        terminate.push_back("r");
        terminate.push_back(")");
        terminate.push_back("(");
        terminate.push_back("b");
        terminate.push_back("}");
        terminate.push_back("{");
        terminate.push_back("+");
        terminate.push_back("-");
        terminate.push_back("*");
        terminate.push_back("/");
        terminate.push_back("=");
        terminate.push_back("I");
        terminate.push_back("#");

        disterminate.push_back("S");
        disterminate.push_back("B");
        disterminate.push_back("T");
        disterminate.push_back("C");
        disterminate.push_back("D");
        disterminate.push_back("A");
        disterminate.push_back("F");
        disterminate.push_back("V");
        disterminate.push_back("W");
        disterminate.push_back("E");
        disterminate.push_back("L");
        disterminate.push_back("R");


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
            p.follow = it->follow;
            scolsure.addPair(p);
            cout<<left<<" "<<right<<endl;
        }
        bcol.addColsure(scolsure);
        bcol.colsure[0].I = bcol.I;
        bcol.I++;
        //add linkchar
        //cout<<"size:"<<bcol.colsure[0].colsure.size()<<endl;
        for(int i=0;i<bcol.colsure[0].colsure.size();i++){
                init_follow(i);
        }
//        for(int i=0;i<bcol.colsure[0].colsure.size();i++){
//            cout<<"follow:";
//            for(int j=0;j<bcol.colsure[0].colsure[i].follow.size();j++){
//                cout<<bcol.colsure[0].colsure[i].follow[j];
//            }
//            cout<<endl;
//        }
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
            if(isin==false){
                bcol.colsure[0].linkchar.push_back(tmp[bcol.colsure[0].colsure[i].point]);
                sColsure *scol = new sColsure();
                sColsure addscol;
                int newpoint = bcol.colsure[0].colsure[i].point+1;
                Pair p(bcol.colsure[0].colsure[i].p.first,tmp,newpoint);
                p.follow.assign(bcol.colsure[0].colsure[i].follow.begin(),bcol.colsure[0].colsure[i].follow.end());
                addscol.addPair(p);
                addscol.I = bcol.I;
                bcol.I++;
                *scol = addscol;
                bcol.colsure[0].scolsure.push_back(scol);
                bcol.colsure[0].tag.push_back("create");
                bcol.addColsure(addscol);
//                cout<<"add:"<<bcol.colsure[0].colsure[i].p.first<<"->"<<tmp<<","<<p.point<<endl;
//                cout<<"not in creat new"<<endl;
//                cout<<"creat number:"<<bcol.colsureNum()-1<<endl;
//                cout<<endl;
            }
            else{
                int newpoint = bcol.colsure[0].colsure[i].point+1;
                Pair p(bcol.colsure[0].colsure[i].p.first,tmp,newpoint);
                p.follow.assign(bcol.colsure[0].colsure[i].follow.begin(),bcol.colsure[0].colsure[i].follow.end());
                bcol.addColsure(p,scolpointlocal+1);
                bcol.colsure[0].scolsure[scolpointlocal]->addPair(p);
//                cout<<"add:"<<p.p.first<<"->"<<p.p.second<<","<<p.point<<endl;
//                cout<<"insert number:"<<scolpointlocal<<endl;
//                cout<<endl;
            }
        }
        for(int i=0;i<bcol.colsure[0].scolsure.size();i++){
            int scolsuresize = bcol.colsure[0].scolsure[i]->colsure.size();
            vector<string> f;
            f.assign(bcol.colsure[0].scolsure[i]->colsure[0].follow.begin(),bcol.colsure[0].scolsure[i]->colsure[0].follow.end());
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
                        addPair[k].follow.assign(f.begin(),f.end());
                        bcol.colsure[0].scolsure[i]->addPair(addPair[k]);
                        bcol.addColsure(addPair[k],i+1);
//                        cout<<addPair[k].p.first<<"->"<<addPair[k].p.second<<endl;
                    }
                }

            }
        }
       // init_follow();
//        for(int i=0;i<bcol.colsure[0].scolsure.size();i++){
//            cout<<"scolsure:"<<i<<endl;
//            bcol.colsure[0].scolsure[i]->test();
//        }
        for(int i=0;i<bcol.colsure[0].scolsure.size();i++){
            cout<<"build i:"<<i<<endl;
            buildcolsure(bcol.colsure[0].scolsure[i]);
        }
        init_action_goto();
        sColsure *root = new sColsure();
        *root =  bcol.colsure[0];
        build_action_goto(root);
//        printfActionGoto();
//        for(int i=0;i<bcol.colsure[0].scolsure.size();i++){
//            cout<<"print i:"<<i<<endl;
//            printflink(bcol.colsure[0].scolsure[i]);
//        }
//         cout<<bcol.I<<endl;
    }
    bool isterminate(char s){
        string tmp;
        tmp = s;
        for(int i=0;i<terminate.size();i++){
            if(tmp==terminate[i]){
                return true;
            }
        }
        return false;
    }
    void printflink(sColsure *p){
        cout<<"p->scolsure.size:"<<p->scolsure.size()<<endl;
        if(p->scolsure.size()==0){
            for(int i=0;i<p->colsure.size();i++){
                cout<<"pair:"<<p->colsure[i].p.first<<"->"<<p->colsure[i].p.second<<","<<p->colsure[i].point<<" ";
                cout<<"follow:";
                for(int j=0;j<p->colsure[i].follow.size();j++){
                    cout<<p->colsure[i].follow[j];
                }
                cout<<endl;
            }
            cout<<"I:"<<p->I<<endl;
            cout<<endl;
            return;
        }
        else{
            for(int i=0;i<p->colsure.size();i++){
                cout<<"pair:"<<p->colsure[i].p.first<<"->"<<p->colsure[i].p.second<<","<<p->colsure[i].point<<" ";
                cout<<"follow:";
                for(int j=0;j<p->colsure[i].follow.size();j++){
                    cout<<p->colsure[i].follow[j];
                }
                cout<<endl;
                cout<<"linkchar:"<<endl;
                for(int j=0;j<p->linkchar.size();j++){
                    cout<<p->linkchar[j];
                }
                cout<<endl;
                cout<<"I:"<<p->I<<endl;
            }
            cout<<endl;
            for(int j=0;j<p->scolsure.size();j++){
                cout<<p->tag[j]<<endl;
                if(p->tag[j]=="create"){
                    printflink(p->scolsure[j]);
                }
            }
        }
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
    void buildcolsure(sColsure *scol){
        if(scol->colsure[0].p.second.length()==scol->colsure[0].point){
            return;
        }
        else{
            for(int i=0;i<scol->colsure.size();i++){
                if(scol->colsure[i].p.second.length()!=scol->colsure[i].point){
                    int findnum;
                    Pair p(scol->colsure[i].p.first,scol->colsure[i].p.second,scol->colsure[i].point+1);
                    p.follow.assign(scol->colsure[i].follow.begin(),scol->colsure[i].follow.end());
                    findnum = bcol.exitPair(p,scol->colsure[i].point+1);
                    if(findnum==-1){
                        sColsure *newscol = new sColsure();
                        sColsure scolsure;
                        scolsure.addPair(p);
                        vector <Pair> addPair;
                        addfollow(scolsure.colsure[0].p.second[scolsure.colsure[0].point],addPair);
                        if(addPair.size()!=0){
                            for(int i=0;i<addPair.size();i++){
                                addPair[i].follow.assign(p.follow.begin(),p.follow.end());
                                scolsure.colsure.push_back(addPair[i]);
                            }
                        }
//                        cout<<"creat:"<<addPair.size()+1<<endl;
//                        cout<<p.p.first<<"->"<<p.p.second<<","<<p.point<<endl;
                        scolsure.I = bcol.I;
                        bcol.I++;
                        *newscol = scolsure;
                        scol->scolsure.push_back(newscol);
                        scol->linkchar.push_back(scol->colsure[i].p.second[scol->colsure[i].point]);
                        scol->tag.push_back("create");
                        bcol.addColsure(scolsure);
                    }
                    else{
                        if(scol->exitPair(p,p.point)){
                            scol->linkchar.push_back(scol->colsure[i].p.second[scol->colsure[i].point]);
                            scol->tag.push_back("linkself");
                            scol->scolsure.push_back(scol);
//                            cout<<"linkself:"<<p.p.second[p.point]<<endl;
//                            cout<<p.p.first<<"->"<<p.p.second<<","<<p.point<<endl;
//                            cout<<"self:"<<scol->colsure[0].p.second[scol->colsure[0].point]<<endl;
//                            cout<<scol->colsure[0].p.first<<"->"<<scol->colsure[0].p.second<<","<<scol->colsure[0].point<<endl;
                        }
                        else{
                            sColsure *newscol = new sColsure();
                            *newscol = bcol.colsure[findnum];
//                            cout<<"linkexist"<<endl;
//                            cout<<p.p.first<<"->"<<p.p.second<<","<<p.point<<endl;
                            scol->scolsure.push_back(newscol);
                            scol->linkchar.push_back(scol->colsure[i].p.second[scol->colsure[i].point]);
                            scol->tag.push_back("linkexist");
                        }
                    }
                }
            }
            for(int i=0;i<scol->scolsure.size();i++){
                if(scol->tag[i]=="create"){
                    buildcolsure(scol->scolsure[i]);
                }
            }
        }
    }
    void init_follow(int k){
        if(k==bcol.colsure[0].colsure.size()){
            return;
        }
         else{
            string next,nextchar;
            vector<string> tmp;
            next = bcol.colsure[0].colsure[k].p.second[bcol.colsure[0].colsure[k].point];
            tmp.assign(bcol.colsure[0].colsure[k].follow.begin(),bcol.colsure[0].colsure[k].follow.end());
            if(bcol.colsure[0].colsure[k].point!=bcol.colsure[0].colsure[k].p.second.length()-1){
                if(isterminate(bcol.colsure[0].colsure[k].p.second[bcol.colsure[0].colsure[k].point+1])){
                    nextchar = bcol.colsure[0].colsure[k].p.second[bcol.colsure[0].colsure[k].point+1];
                    tmp.push_back(nextchar);
                }
            }
            for(int i=0;i<bcol.colsure[0].colsure.size();i++){
                if(bcol.colsure[0].colsure[i].p.first==next){
                    if(bcol.colsure[0].colsure[i].follow.empty()){
                        bcol.colsure[0].colsure[i].follow.assign(tmp.begin(),tmp.end());
                    }
                }
            }
            init_follow(k+1);

        }
    }
    void init_action_goto(){
        for(int i=0;i<terminate.size();i++){
            vector<string> ai;
            string block="empty";
            ai.push_back(terminate[i]);
            for(int j=0;j<bcol.I;j++){
                ai.push_back(block);
            }
            action.push_back(ai);
        }
        for(int i=0;i<disterminate.size();i++){
            vector<string> gi;
            string block="empty";
            gi.push_back(disterminate[i]);
            for(int j=0;j<bcol.I;j++){
                gi.push_back(block);
            }
            Goto.push_back(gi);
        }
    }
    void build_action_goto(sColsure *scol){
        if(scol->colsure.size()==1&&scol->colsure[0].point == scol->colsure[0].tail+1&&scol->colsure[0].p.first=="~"){
           for(int i=0;i<action.size();i++){
                if(action[i][0]=="#"){
                    action[i][scol->I] = "acc";
                    return;
                }
           }
        }
        if(scol->colsure.size()==1&&scol->colsure[0].point == scol->colsure[0].tail+1){
            int num = bcol.reduceTo(scol->colsure[0],bcol);
            string tmp = "r";
            string state = tmp + numtostring(num);
            for(int i=0;i<action.size();i++){
                action[i][scol->I] = state;
            }
//            cout<<"state:"<<state<<endl;
//            cout<<"end "<<scol->I<<endl;
            return;
        }
        else{
            for(int i=0;i<scol->scolsure.size();i++){
                char st = scol->linkchar[i];
                if(isterminate(st)){
                    string tmp = "s";
                    string state = tmp + numtostring(scol->scolsure[i]->I);
                    for(int j=0;j<action.size();j++){
                        if(chartostring(scol->linkchar[i])==action[j][0]){
                            action[j][scol->I] = state;
                            break;
                        }
                    }
//                    cout<<"state:"<<state<<endl;
//                    cout<<"from "<<scol->I<<" to "<<scol->scolsure[i]->I<<endl;

                }
                else{
                    string state = numtostring(scol->scolsure[i]->I);
                    for(int j=0;j<Goto.size();j++){
                        if(chartostring(scol->linkchar[i])==Goto[j][0]){
                            Goto[j][scol->I] = state;
                            break;
                        }

                    }
//                    cout<<"state:"<<state<<endl;
//                    cout<<"from "<<scol->I<<" to "<<scol->scolsure[i]->I<<endl;
                }
                if(scol->tag[i]=="create"){
                    build_action_goto(scol->scolsure[i]);
                }
                else if(scol->tag[i]=="linkself"){
                    continue;
                }
                else if(scol->tag[i]=="linkexist"){
                    continue;
                }
            }
        }
    }
    void printfActionGoto(){
        int i,j;
        for(i=0;i<action[0].size();i++){
            cout<<"action:"<<i<<" ";
            for(j=0;j<action.size();j++){
                cout<<action[j][i]<<" ";
            }
            cout<<"goto  ";
            for(j=0;j<Goto.size();j++){
                cout<<Goto[j][i]<<" ";
            }
            cout<<endl;
        }
    }
    string numtostring(int n){
        stringstream s;
        s<<n;
        return s.str();
    }
    string chartostring(char c){
        stringstream s;
        s<<c;
        return s.str();
    }
    int stringtonum(string s){
        int n;
        stringstream ss(s);
        ss>>n;
        //cout<<"stringtonum:"<<s<<" to "<<n<<endl;
        return n;
    }
    void analysisLexical(string s){
        string endChar = "#",nextState;
        char nowPointer;
        int state;
        s += endChar;
        stateStack.push_back(1);
        for(int i=0;i<s.length();){
            cout<<"checkInput:"<<s<<endl;
            nowPointer = s[i];
            cout<<"checknowPointer:"<<nowPointer<<endl;
            state = stateStack.back();
            cout<<"state:"<<state<<endl;
            if(isterminate(nowPointer)){
                cout<<"in if"<<endl;
                nextState = checkAction(state,nowPointer);
            }
            else{
                nextState = checkGoto(state,chartostring(nowPointer));
            }
            cout<<"nextState:"<<nextState<<endl;
//            cout<<"stateStack:";
//            for(int j=0;j<stateStack.size();j++){
//                cout<<stateStack[j]<<" ";
//            }
//            cout<<"nowpointer:"<<nowPointer<<endl;
//            cout<<"nextState:"<<nextState<<endl;

              cout<<"inputStack:";
              for(int j=0;j<inputStack.size();j++){
                cout<<inputStack[j]<<" ";
              }
              cout<<endl;
              cout<<"nowPointer:"<<nowPointer<<endl;
            if(nextState[0]=='s'){
                stateStack.push_back(returnState(nextState));
                inputStack.push_back(chartostring(nowPointer));
            }
            else if(nextState[0]=='r'){
                int popNum,gotoNextState;
                string gotoState;
                popNum=bcol.colsure[0].colsure[returnState(nextState)].p.second.length();
                cout<<"reduction:"<<bcol.colsure[0].colsure[returnState(nextState)].p.first<<"->"<<bcol.colsure[0].colsure[returnState(nextState)].p.second<<endl;
                while(popNum!=0){
                    stateStack.pop_back();
                    inputStack.pop_back();
                    popNum--;
                }
                inputStack.push_back(bcol.colsure[0].colsure[returnState(nextState)].p.first);
                gotoState = checkGoto(stateStack.back(),inputStack.back());
                gotoNextState = stringtonum(gotoState);
                stateStack.push_back(gotoNextState);
                i--;
            }
            else if(nextState=="acc"){
                cout<<"acc Lexical"<<endl;
                return;
            }
            else if(nextState=="empty"){
                cout<<"error Lexical"<<endl;
                return;
            }
            else{
                stateStack.push_back(stringtonum(nextState));
                inputStack.push_back(chartostring(nowPointer));
            }
            i++;
            cout<<endl;
        }
    }
    int returnState(string s){
        int n;
        string tmp;
        for(int i=1;i<s.length();i++){
            tmp += s[i];
        }
        stringstream ss(tmp);
        ss>>n;
        return n;
    }
    string checkAction(int state,char findChar){
        string tmp;
        tmp = chartostring(findChar);
        for(int i=0;i<action.size();i++){
            if(action[i][0]==tmp){
                return action[i][state];
            }
        }
    }
    string checkGoto(int state,string findChar){
        for(int i=0;i<Goto.size();i++){
            if(Goto[i][0]==findChar){
//                cout<<"Goto[i][0]:"<<Goto[i][0]<<endl;
//                cout<<"state:"<<state<<endl;
                return Goto[i][state];
            }
        }
    }
public:
    grammatical_analysis(string s){
        init_colsure();
        analysisLexical(s);
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
//    lexical_analysis la(t);scol->colsure[i].point!=scol->colsure[i].p.second.length()
//    cout<<"lexical analysis:"<<la.error<<endl;
    string testtmp = "im(){iI;I=I;r(I=I;I;I=I;){h(I){}}}";
    grammatical_analysis ga(testtmp);


    return 0;
}
