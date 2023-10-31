//Konghwan Shin
//ECE 312
//Proj 8
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include "dirent.h"

using namespace std;

//Removes puct, characters, and changes everything to lowercase.
string cEssay(const string& essay) {
    string mEssay;
    for (char ch : essay) {
        switch (ch) {
            case 'A': case 'B': case 'C': case 'D': case 'E':
            case 'F': case 'G': case 'H': case 'I': case 'J':
            case 'K': case 'L': case 'M': case 'N': case 'O':
            case 'P': case 'Q': case 'R': case 'S': case 'T':
            case 'U': case 'V': case 'W': case 'X': case 'Y':
            case 'Z':
                mEssay += tolower(ch);
                break;
            case 'a': case 'b': case 'c': case 'd': case 'e':
            case 'f': case 'g': case 'h': case 'i': case 'j':
            case 'k': case 'l': case 'm': case 'n': case 'o':
            case 'p': case 'q': case 'r': case 's': case 't':
            case 'u': case 'v': case 'w': case 'x': case 'y':
            case 'z':
                mEssay += ch;
                break;
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
            case '\'':
                mEssay += ch;
                break;
            default:
                mEssay += ' ';
                break;
        }
    }
    return mEssay;
}

// Creates P word seq, and divides the essay
set<string> pSeque(const string& mEssay, int p) {
    set<string> seq;
    //gets string and changes
    istringstream iss(mEssay);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }
    for (size_t i = 0; i <= words.size() - p; ++i) {
        string sequence;
        for (int j = 0; j < p; ++j) {
            sequence += words[i + j];
            if (j < p - 1)
                sequence += " ";
        }
        seq.insert(sequence);
    }

    return seq;
}
//Read essay, fetch essay and if fetched wrong or if user input wrong direcotry gives an error message
//Print pairs.
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error: enter the correct directory file" << endl;
        return 1;
    }

    string directory = argv[1];
    int p = atoi(argv[2]);
    int m = atoi(argv[3]);

    vector<string> file;
    unordered_map<string, string> mEssays;
    unordered_map<string, set<string>> eSequence;

    DIR* dir;
    struct dirent* entry;

    dir = opendir(directory.c_str());
    if (dir == NULL) {
        cerr << "Error opening directory!!!!!!!!!!!, input the correct directory" << endl;
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == 8) {
            string filename = entry->d_name;
            ifstream infile(directory + "/" + filename);
            if (infile) {
                string line;
                string essay;
                while (getline(infile, line)) {
                    essay += line + " ";
                }
                string mEssay = cEssay(essay);
                mEssays[filename] = mEssay;
                file.push_back(filename);
            }
        }
    }
    closedir(dir);



    for (const string& filename : file) {
        string mEssay = mEssays[filename];
        set<string> seq = pSeque(mEssay, p);
        eSequence[filename] = seq;
    }
    vector<vector<int>> cMatr(file.size(), vector<int>(file.size(), 0));

    for (size_t i = 0; i < file.size(); i++) {
        for (size_t j = i + 1; j < file.size(); j++) {
            const set<string>& seq1 = eSequence[file[i]];
            const set<string>& seq2 = eSequence[file[j]];


            int same = 0;
            for (const string& seq : seq1) {
                if (seq2.count(seq) > 0){
                    same++;
                }
            }
            cMatr[i][j] = same;
            cMatr[j][i] = same;
        }
    }

    vector<pair<int, pair<string, string>>> sPair;
    for (size_t i = 0; i < file.size(); i++) {
        for (size_t j = i + 1; j < file.size(); j++) {
            if (cMatr[i][j] > 0) {
                sPair.push_back({ cMatr[i][j], { file[i], file[j] } });
            }
        }
    }

    sort(sPair.rbegin(), sPair.rend());


    int cPrint = 0;
    for (const auto& pData : sPair) {
        int count = pData.first;
        if (count > m) {
            const string& file1 = pData.second.first;
            const string& file2 = pData.second.second;
            cout << count << ": " << file1 << ", " << file2 << "." << endl;
            cPrint++;
        }
    }

    return 0;
}
