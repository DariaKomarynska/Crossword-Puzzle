#include "Dictionary.h"

int main()
{
    fstream fs;
    Dictionary dict_a; // create an object

    fs >> dict_a; // load dictioanary from file

    cout << dict_a << endl; // print dictionary in console
    dict_a.remove_word("apple");
    cout << dict_a << endl;

    fs << dict_a; // save dictionary in file
    // menu(dict_a);
    return 0;
}
