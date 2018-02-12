#include <iostream>
#include "inifile.h"

using namespace std;
using namespace inifile;

int main(int argc, char *argv[])
{
    IniFile ini;
    string filepath = "test.ini";
    ini.load(filepath);
    int RET = -1;

    //获取指定section的指定key的值
    string key_val = "";
    RET = ini.getValue("COMMON","DB",key_val);

    //获取指定section的注释的值
    RET = -1;
    string section_comment = "";
    RET = ini.getSectionComment("COMMON", section_comment);

    //修改section的注释并保存到另一个文件
    RET = -1;
    string section_comment_post = "修改了section的注释";
    RET = ini.setSectionComment("COMMON", section_comment_post);
    RET = ini.saveas("test1.ini");

    //修改section的某个key值和注释并保存到另一个文件
    RET = -1;
    string key_comment_post = "修改了key的注释";
    RET = ini.setValue("COMMON", "DB","修改的值", key_comment_post);
    //删除某个key
    //ini.deleteKey("COMMON", "DB");
    RET = ini.saveas("test2.ini");


    return 0;
}
