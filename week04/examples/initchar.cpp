#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char rabbit[16] = {'P', 'e', 't', 'e', 'r'};
    cout << "String length is " << strlen(rabbit) << endl;
    for(int i = 0; i < 16; i++)
        cout << i << ":" << +rabbit[i] << "(" << rabbit[i] << ")" << endl;

    char bad_pig[9] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g'};
    char good_pig[10] = {'P', 'e', 'p', 'p', 'a', ' ', 'P', 'i', 'g', '\0'};

    cout << "Rabbit is (" << rabbit << ")" << endl;
    cout << "Pig's bad name is (" << bad_pig << ")" << endl; 
    cout << "Pig's good name is (" << good_pig << ")" << endl; 

    char name[10] = {'Y', 'u', '\0', 'S', '.', '0'};
    cout << strlen(name) << endl;

    wchar_t chinese_name1[] = L"张云翔";
    char16_t chinese_name2[] = u"张云翔";
    char32_t chinese_name3[] = U"张云翔";
    
    cout<<"sizeof wchar_t: "<<sizeof(wchar_t)<<endl;
    cout<<chinese_name1<<endl;
    cout<<chinese_name2<<endl;
    cout<<chinese_name3<<endl;

    return 0;
}