#ifndef _INIFILE_H
#define _INIFILE_H

#pragma warning(disable : 4786)
#include <map>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
//*********************************************************
//section��map���棬�����ظ���key-val��vector���棬���ظ���
//*********************************************************
namespace inifile
{
    const int RET_OK  = 0;
    const int RET_ERR = -1;
    const string delim = "\n";

    struct IniItem {
        string key;
        string value;
        string comment;
    };

    struct IniSection {
        typedef vector<IniItem>::iterator iterator;
        iterator begin() {
            return items.begin();
        }
        iterator end() {
            return items.end();
        }

        string name;
        string comment;
        vector<IniItem> items;
    };

    class IniFile
    {
    public:
        IniFile();
        ~IniFile() {
            release();
        }

    public:
        typedef map<string, IniSection *>::iterator iterator;

        iterator begin() {
            return sections_.begin();
        }
        iterator end() {
            return sections_.end();
        }
    public:
        //*********************************************************
        //�ж��Ƿ��ж�Ӧ��section��key��
        //*********************************************************
        bool hasSection(const string &section) ;
        bool hasKey(const string &section, const string &key) ;

        //*********************************************************
        //��-��ȡ-�����ļ���
        //*********************************************************
        /* �򿪲�����һ����Ϊfname��INI�ļ� */
        int load(const string &fname);
        /*�����ݱ��浽��ǰ�ļ�*/
        int save();
        /*��������浽һ����Ϊfname���ļ�*/
        int saveas(const string &fname);
    
        //*********************************************************
        //��ȡ��
        //*********************************************************
        /*��ȡsection��һ����Ϊkey��ֵ,��������string�͵�ֵ*/
        string getStringValue(const string &section, const string &key, int &ret);
        /*��ȡsection��һ����Ϊkey��ֵ,��������int�͵�ֵ*/
        int getIntValue(const string &section, const string &key, int &ret);
        /*��ȡsection��һ����Ϊkey��ֵ,��������double�͵�ֵ*/
        double getDoubleValue(const string &section, const string &key, int &ret);
    
        /*��ȡsection��һ����Ϊkey��ֵ,����ֵ����value��*/
        int getValue(const string &section, const string &key, string &value);
        /*��ȡsection��һ����Ϊkey��ֵ,����ֵ����value��,��ע�͸���comment��*/
        int getValue(const string &section, const string &key, string &value, string &comment);
    
        /*��ȡsection���м�Ϊkey��ֵ,����ֵ����values��vector��*/
        int getValues(const string &section, const string &key, vector<string> &values);
        /*��ȡsection���м�Ϊkey��ֵ,����ֵ����values��vector��,,��ע�͸���comments��vector��*/
        int getValues(const string &section, const string &key, vector<string> &value, vector<string> &comments);
    
        /* ��ȡsection��ע�� */
        int getSectionComment(const string &section, string &comment);

        //*********************************************************
        //���á�
        //*********************************************************
        /* ����section��ע�� */
        int setSectionComment(const string &section, const string &comment);
        /*ͬʱ����keyֵ��ע��*/
        int setValue(const string &section, const string &key, const string &value, const string &comment = "");

        //*********************************************************
        //ɾ����
        //*********************************************************
        /*ɾ��section*/
        void deleteSection(const string &section);
        /*ɾ���ض�section���ض�key*/
        void deleteKey(const string &section, const string &key);

        //*********************************************************
        //ע�ͷ���
        //*********************************************************
        /*��ȡע�ͱ�Ƿ��б�*/
        void getCommentFlags(vector<string> &flags);
        /*����ע�ͱ�Ƿ��б�*/
        void setCommentFlags(const vector<string> &flags);

    private:
        //*********************************************************
        //�����ڲ�������
        //*********************************************************
        /*ȥ��str�����c�ַ�*/
        static void trimleft(string &str, char c = ' ');
        /*ȥ��strǰ���c�ַ�*/
        static void trimright(string &str, char c = ' ');
        /*ȥ��strǰ��ͺ���Ŀո��,Tab���ȿհ׷�*/
        static void trim(string &str);
 
        IniSection *getSection(const string &section = "");
        void release();
        int getline(string &str, FILE *fp);
        bool isComment(const string &str);
        bool parse(const string &content, string &key, string &value, char c = '=');
        //for dubug
        void print();

    private:
        map<string, IniSection *> sections_;
        string fname_;
        vector<string> flags_;
    };
}

#endif
