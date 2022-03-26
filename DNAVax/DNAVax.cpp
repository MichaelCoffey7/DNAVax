// DNAVax.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char xt[] = ".dna";
char selectedfile[24] = "";
long long int nucleotides = 0;
long long int position = 0;
int addnucleotide = 0;

class NucleotidePair {
public:
    char Nucleotide1;
    char Nucleotide2;
};

int GetNucleotides() {
    string line;
    long long int numlines = 0;

    ifstream reader(selectedfile);

    if (!reader)
    {
        cout << "No file selected" << endl;
        return 0;
    }


    while (!reader.eof())
    {
        getline(reader, line);
        numlines++;
    }

    reader.close();

    return numlines;
}

int MainMenu() {
    cout << "\nPlease select an option\n";
    cout << "0. Exit\n";
    cout << "1. Create a new strand\n";
    cout << "2. Load a strand\n";
    cout << "3. Add a nucleotide pair\n";
    cout << "4. Read a position\n";
    cout << "Currently selected file:" << selectedfile << endl;
    nucleotides = static_cast<long long>(GetNucleotides()) - 1;
    cout << "The number of nucleotides is:" << nucleotides << endl;


    int selection;
    cin >> selection;
    return selection;
}

int AddPair() {
    cout << "Writing nucleotide to file\n";
    cout << "0. Exit\n";
    cout << "1. adenine-thymine\n";
    cout << "2. thymine-adenine\n";
    cout << "3. cytosine-guanine\n";
    cout << "4. guanine-cytosine\n";
    cin >> addnucleotide;
    if (addnucleotide == 0) {
        return 0;
    }
    if (addnucleotide == 1) {
        string filename(selectedfile);
        fstream file;

        file.open(filename, std::ios_base::app | std::ios_base::in);
        if (file.is_open())
            file << "\nat";
        cout << "Done" << endl;

        return EXIT_SUCCESS;
    }
    if (addnucleotide == 2) {
        string filename(selectedfile);
        fstream file;

        file.open(filename, std::ios_base::app | std::ios_base::in);
        if (file.is_open())
            file << "\nta";
        cout << "Done" << endl;

        return EXIT_SUCCESS;
    }
    if (addnucleotide == 3) {
        string filename(selectedfile);
        fstream file;

        file.open(filename, std::ios_base::app | std::ios_base::in);
        if (file.is_open())
            file << "\ncg";
        cout << "Done" << endl;

        return EXIT_SUCCESS;
    }
    if (addnucleotide == 4) {
        string filename(selectedfile);
        fstream file;

        file.open(filename, std::ios_base::app | std::ios_base::in);
        if (file.is_open())
            file << "\ngc";
        cout << "Done" << endl;

        return EXIT_SUCCESS;
    }
    return 0;
}

int ReadPosition() {
    cout << "Select a position\n";
    cin >> position;
    cout << "Postion selected:" << position << endl;
    position++;
    fstream newfile;
    newfile.open(selectedfile, ios::in);
    if (newfile.is_open()) {
        string tp;
        long long int count = 0;
        while (getline(newfile, tp)) {
            count++;
            if (count == position) {
                if (tp == "at") {
                    cout << "adenine-thymine" << "\n";
                }
                if (tp == "ta") {
                    cout << "thymine-adenine" << "\n";
                }
                if (tp == "cg") {
                    cout << "cytosine-guanine" << "\n";
                }
                if (tp == "gc") {
                    cout << "guanine-cytosine" << "\n";
                }
            }
        }
        newfile.close();
    }
    return 0;
}

int CreateNew() {
    cout << "Creating a new strand\n";
    cout << "Enter a file name for this strand\n";
    char filename[20];
    cin >> filename;
    strcat_s(filename, xt);
    cout << "New file:" << filename << endl;
    ofstream MyFile(filename);
    MyFile << "DNAVax";
    MyFile.close();
    strncpy_s(selectedfile, filename, 24);
    return 0;
}

int LoadStrand() {
    cout << "Enter a file name to load\n";
    char filename[20];
    cin >> filename;
    strcat_s(filename, xt);
    cout << "Reading file:" << filename << endl;
    strncpy_s(selectedfile, filename, 24);
    return 0;
}

int main()
{
    cout << "Welcome to DNAVax\n";
    int selected = 10;
    while (selected != 0) {
        selected = MainMenu();
        if (selected == 1) {
            CreateNew();
        }
        if (selected == 2) {
            LoadStrand();
        }
        if (selected == 3) {
            AddPair();
        }
        if (selected == 4) {
            ReadPosition();
        }
    }
}
