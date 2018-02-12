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

    //��ȡָ��section��ָ��key��ֵ
    string key_val = "";
    RET = ini.getValue("COMMON","DB",key_val);

    //��ȡָ��section��ע�͵�ֵ
    RET = -1;
    string section_comment = "";
    RET = ini.getSectionComment("COMMON", section_comment);

    //�޸�section��ע�Ͳ����浽��һ���ļ�
    RET = -1;
    string section_comment_post = "�޸���section��ע��";
    RET = ini.setSectionComment("COMMON", section_comment_post);
    RET = ini.saveas("test1.ini");

    //�޸�section��ĳ��keyֵ��ע�Ͳ����浽��һ���ļ�
    RET = -1;
    string key_comment_post = "�޸���key��ע��";
    RET = ini.setValue("COMMON", "DB","�޸ĵ�ֵ", key_comment_post);
    //ɾ��ĳ��key
    //ini.deleteKey("COMMON", "DB");
    RET = ini.saveas("test2.ini");


    return 0;
}
