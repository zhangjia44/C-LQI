//
//  main.cpp
//  readByte
//
//  Created by 江昊天 on 2018/6/29.
//  Copyright © 2018年 江昊天. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    ofstream outfile;
    ifstream infile;
    outfile.open("symbol3_add0",ios::binary);
    infile.open("symbol3_afterwebee", ios::binary);
    for(int i = 0; i < 28 + 27; i++)
        outfile << '\0';

    infile.seekg( 0 , ios::end );
    unsigned long len = infile.tellg();

    char* buffer = new char[len];
    infile.seekg(0,ios::beg);
    infile.read(buffer,len);
    for(int i = 0; i < len; i++)
        outfile << buffer[i];
    delete [] buffer;
    infile.close();
    outfile.close();
    // insert code here...
    return 0;
}
