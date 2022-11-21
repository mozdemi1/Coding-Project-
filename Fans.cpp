#include "Parser.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include<bits/stdc++.h>
#include <getopt.h>
using namespace std;




void func(string line3) {
    fstream n2;
    n2.open(line3, ios::in);
    if (n2.is_open()) {
        string m;
        while (getline(n2, m)) {
            Parser pp(m);
            if (pp.getArg1() == "Quit") {
                
                cout << endl;
                exit(1);
            }
            if (pp.getArg1() == "Load") {
            
            string LoadFileName = pp.getArg2();
            fstream cu;
            cu.open(LoadFileName, ios::in);
            if(cu.is_open()) {
                string l;
                int p;
                while (getline(cu, l)) {
                    Parser ps(l);
                    cout << l << endl;
                }
            cu.close();
            }
            else {
                cout << "file couldn't open" << endl;
                exit(1);
                }
            }

            if (pp.getArg1() == "Process") {
                string lm = pp.getArg2();
                func(lm);
            }

        }
    n2.close();
    }
    else {
        cout << "ERROR: Problem occured while opening file" << endl;
        exit(1);
    }
    
}



int main(int argc, char *argv[]) {
   
    string line;  
    string command;  
   
    int opt;
    int flags = 0;  
    string nsecs;  
    int tfnd = 0;
    
    while ((opt = getopt(argc, argv, "oi:")) != -1) {
        switch (opt) {
        case 'o':
            flags = 1;
            break;
        case 'i':
            nsecs = optarg;
            tfnd = 1;
            break;
        default:
           cout << "error" << endl; 
        }
    }

    

    string fname = nsecs;
    fstream n;
    n.open(fname, ios::in);
    if (n.is_open()) {
        string l;
        int parameter;
        while (getline(n, l)) {
            Parser cm(l);
            cout << l << endl;
        }
        n.close();
    }
    else {
        cout << "file not found..." << endl;
        return 1;
    }

    while(1) {
        cout << endl << "Enter a command:" << endl;
        cout<<"Choose from"<<endl;
        cout << 
	      "   Load <input-filename>" << std::endl << 
	      "   Show <fan-id>" << std::endl << 
	      "   Spend <fan-id> <dollars>" << std::endl << 
          "   Remove <fan-id>" <<std::endl<<
          "   Process <commands-filename>" <<std::endl<<
	      "   Quit";
        cout << endl;
        cout << ": ";

        getline(cin, line);
        Parser op(line);

        if (op.getArg1() == "Quit") {
            cout << endl;
            break; 
        }

        if (op.getArg1() == "Load") {
            string loadName = op.getArg2();
            fstream load;
            load.open(loadName, ios::in);
            if (load.is_open()) {
                string line2;
                while (getline(load, line2)) {
                    Parser c(line2);
                    cout << line2 << endl;
                    // v.push_back(line2)
                }
                load.close();
            }
            else {
                cout << "file not found..." << endl;
                return 1;
            }
        }

        if (op.getArg1() == "Process") {
            string proc = op.getArg2();
            func(proc);
        }





    }
    
    
   return 0;
}





   

   

