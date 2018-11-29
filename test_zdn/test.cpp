#include <iostream>
#include <leveldb/db.h>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
    auto a=100;
    a++;
    cout<<"hello,world"<<endl;
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    options.block_size = 1024;
    leveldb::Status status = leveldb::DB::Open(options,"/tmp/leveldbtest-1000",&db);
    assert(status.ok());
    string value,key,name;
    leveldb::WriteOptions options1 = leveldb::WriteOptions();
    for(int i=0;i<1000;i++)
    {
        key = rand();
        value = rand();
        status = db->Put(options1,key,value);
        if(status.ok()) status = db->Get(leveldb::ReadOptions(),key,&name);
        if(status.ok()) printf("my name is %s\n",name);
    }
    
}