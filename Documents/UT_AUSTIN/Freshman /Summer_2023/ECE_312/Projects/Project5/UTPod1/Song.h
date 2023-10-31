/*Konghwan Shin
 *ECE 312
 *
 */

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
#include <string>

class Song {
private:
    std::string title;
    std::string artist;
    int size;

public:
    Song();

    Song(const std::string &title, const std::string &artist, int size);

    void setTitle(const std::string &title);
    std::string getTitle() const;

    void setArtist(const std::string &artist);
    std::string getArtist() const;

    void setSize(int size);
    int getSize() const;


    bool operator ==(const Song &rhs);
    bool operator <(const Song &rhs);
    bool operator >(const Song &rhs);
};
#endif