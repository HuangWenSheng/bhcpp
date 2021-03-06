#include <iostream>
#include <fstream> // 'f' -> 'file'

using namespace std;

istream& skip_comma ( istream& str )
{
    char c = str.peek();

    if (c == ',')
    {
        return str.ignore();
    }

    return str;
}

int main()
{
    ofstream ofs;

    ofs.open("./hello_file_stream.txt");

    ofs << "Hello world!" << endl;
    ofs << "11,22,33" << endl << "44" << endl;
    ofs << "1 2" << endl;

    ofs.close();

    ifstream ifs;

    ifs.open("./hello_file_stream.txt");

    if (!ifs)
    {
        cout << "open file fail!" << endl;
    }
    else
    {
        string line;

        getline(ifs, line);

        cout << line << endl;

        int n1,n2,n3,n4;

        ifs >> n1 >> skip_comma >> n2 >> skip_comma >> n3;
        cout << n1 << ", " << n2 << ", " << n3 << endl;
        ifs >> n4;
        cout << n4 << endl;

        n1 = n2 = -1;
        string spaces;
        //char c;
        ifs >> n1;

        ifs.unsetf(ios::skipws);
        ifs >> spaces;

        ifs.setf(ios::skipws);
        ifs >> n2;
        cout << n1 << "," << spaces << n2 << endl;
    }

    return 0;
}
