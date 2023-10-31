/*Konghwan Shin
 *ECE 312
 *
 */
#include "UTPod.h"
#include "Song.h"

#include "stdio.h"
#include <cstdlib>
#include <iostream>
#include "ctime"





//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UTPod::UTPod() {
    memSize = MAX_MEMORY;
    songs = nullptr;
}

UTPod::UTPod(int size) {
    if (size >= MAX_MEMORY) {
        memSize = MAX_MEMORY;
    } else if (size > 0) {
        memSize = size;
    } else {
        memSize = MAX_MEMORY;
    }
    songs = nullptr;
}

int UTPod::addSong(Song const &s) {
    if (getTotalMemory() + s.getSize() > memSize) {
        return NO_MEMORY;
    }

    SongNode* newSong = new SongNode;
    newSong->s = s;
    newSong->next = nullptr;

    if (songs == nullptr) {
        songs = newSong;
    } else {
        SongNode* current = songs;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newSong;
    }

    return SUCCESS;
}

int UTPod::removeSong(Song const &s) {
    if (songs == nullptr) {
        return NO_MEMORY;
    }

    if (songs->s == s) {
        SongNode *temp = songs;
        songs = songs->next;
        delete temp;
        return SUCCESS;
    }
    SongNode *cur = songs;
    while (cur->next != nullptr) {
        if (cur->next->s == s) {
            SongNode *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            return SUCCESS;
        }
        cur = cur->next;
    }
    return NO_MEMORY;
}

void UTPod::shuffle() {
    std::srand(std::time(0));

    int numSongs = 0;
    SongNode* current = songs;
    while (current != nullptr) {
        numSongs++;
        current = current->next;
    }

    for (int i = numSongs - 1; i > 0; i--) {
        int j = std::rand() % (i + 1);

        if (i != j) {
            SongNode* current = songs;
            SongNode* node_i = nullptr;
            SongNode* node_j = nullptr;

            for (int k = 0; k <= i; k++) {
                if (k == i) node_i = current;
                if (k == j) node_j = current;
                current = current->next;
            }

            std::swap(node_i->s, node_j->s);
        }
    }
}

void UTPod::showSongList() {
    SongNode* cur = songs;
    while (cur != nullptr) {
        Song tmp = cur->s;
        if (!tmp.getTitle().empty()) {
            std::cout << "Name: " << tmp.getTitle() << ", Artist: " << tmp.getArtist() << ", size: " << tmp.getSize()
                      << " MB" << std::endl;
        }
        cur = cur->next;
    }
}

void UTPod::sortSongList() {
    if (songs == nullptr || songs->next == nullptr) {
        return;
    }

    bool swapped;
    SongNode* current;
    SongNode* last = nullptr;

    do {
        swapped = false;
        current = songs;

        while (current->next != last) {
            if (current->s > current->next->s) {
                std::swap(current->s, current->next->s);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void UTPod::clearMemory() {
    SongNode* current = songs;

    while (current != nullptr) {
        SongNode* next = current->next;
        delete current;
        current = next;
    }

    songs = nullptr;
}

int UTPod::getTotalMemory() {
    int totalMemory = 0;
    for (SongNode* currentNode = songs; currentNode != nullptr; currentNode = currentNode->next) {
        totalMemory += currentNode->s.getSize();
    }
    return totalMemory;
}

int UTPod::getRemainingMemory() {
    return memSize - getTotalMemory();
}

UTPod::~UTPod() {
    clearMemory();
}