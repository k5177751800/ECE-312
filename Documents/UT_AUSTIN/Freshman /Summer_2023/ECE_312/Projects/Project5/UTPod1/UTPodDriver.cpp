/* UTPod_driver.cpp
Demo Driver for the UTPod.

Konghwan Shin

 EE 312 10/16/18

This is a basic driver for the UTPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UTPod t;
    int result;



    Song s1("Hello", "Adele", 10);
    cout << "add result = ";
    result = t.addSong(s1);

    if (result == 0) {
        cout << "Successfully added song: " << endl;
    } else {
        cout << "Failed to add song\n\n" << endl;
    }
//    Song s1("Hello", "Adele", 10);
//    int result = t.addSong(s1);
//    cout << "result = " << result << endl;
//    t.showSongList();

//    Song s2("Beatles", "Hey Jude2", 5);
//    result = t.addSong(s2);
//    if (result == 0) {
//        cout << "Successfully added song\n" << endl;
//    } else {
//        cout << "Failed to add song\n\n" << endl;
//    }
    cout << "Current List:" << endl;
    t.showSongList();
    cout << endl;


    Song s2("Doja", "Central Cee", 90);
    cout << "Result: ";
    result = t.addSong(s2);
    if (result == 0) {
        cout << "Successfully added song: " << endl;
    } else {
        cout << "Failed to add song\n\n" << endl;
    }

    cout << "Current List:" << endl;
    t.showSongList();
    cout << endl;

    Song s3("Farewell", "Akmu", 6);
    result = t.addSong(s3);
    if (result == 0) {
        cout << "Successfully added song: " << endl;
    } else {
        cout << "Failed to add song\n\n" << endl;
    }
    cout << "Current List:" << endl;
    t.showSongList();
    cout << endl;


    Song s4("Element", "Pop Smoke", 19);
    result = t.addSong(s4);
    if (result == 0) {
        cout << "Successfully added song: " << endl;
    } else {
        cout << "Failed to add song\n\n" << endl;
    }
    cout << "Current List:" << endl;
    t.showSongList();
    cout << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    if (result == 0) {
        cout << "Successfully added song: " << endl;
    } else {
        cout << "Failed to add song\n\n" << endl;
    }
    cout << "Current List:" << endl;
    t.showSongList();
    cout << endl;


    result = t.removeSong(s2);
    if (result == 0){
        cout << "Successfully Deleted"<<endl;
    } else{
        cout << "delete FAILED: "<<endl;
    }
    result = t.removeSong(s1);
    if (result == 0){
        cout << "Successfully Deleted"<<endl;
    } else{
        cout << "delete FAILED: "<<endl;
    }

//    result = t.addSong(s5);
//    cout << "add result = " << result << endl;
//    result = t.addSong(s2);
//    cout << "add result = " << result << endl;
//    result = t.addSong(s3);
//    cout << "add result = " << result << endl;


    t.showSongList();

    cout << "\nSort result: ";
    t.sortSongList();
    cout << endl;
    t.showSongList();

    cout << "\nShuffle result: "<< endl;
    t.shuffle();
    t.showSongList();



    cout << "memory remaining= " << t.getRemainingMemory() << endl;


}
//print the updated list after success.