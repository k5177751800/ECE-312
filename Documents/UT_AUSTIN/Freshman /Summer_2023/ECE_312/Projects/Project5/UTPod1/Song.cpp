/*Konghwan Shin
 *ECE 312
 *
 */
#include "Song.h"
#include <cstdlib>

Song::Song() {
    title = "";
    artist = "";
    size = 0;
}

Song::Song(const std::string &title, const std::string &artist, int size)
        : title(title), artist(artist), size(size) {
}

void Song::setTitle(const std::string &title) {
    this->title = title;
}

std::string Song::getTitle() const {
    return title;
}

void Song::setArtist(const std::string &artist) {
    this->artist = artist;
}

std::string Song::getArtist() const {
    return artist;
}

void Song::setSize(int size) {
    this->size = size;
}

int Song::getSize() const {
    return size;
}

bool Song::operator ==(const Song &rhs) {
    return (title == rhs.title && artist == rhs.artist && size == rhs.size);
}

bool Song::operator <(const Song &rhs) {
    if(artist < rhs.artist) {
        return true;
    }
    else if(artist == rhs.artist) {
        if(title < rhs.title) {
            return true;
        }
        else if(title == rhs.title) {
            if(size < rhs.size) {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator >(const Song &rhs) {
    if (artist != rhs.artist) {
        return artist > rhs.artist;
    } else if (title != rhs.title) {
        return title > rhs.title;
    } else {
        return size > rhs.size;
    }

}