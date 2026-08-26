//
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;


struct Song { 
    string title;
    int time;  // could also be a string
    int track;
};

struct Album {
    map <int, Song > songs;
    string name;
    int time;
    int nsongs;  // optional variable but makes it easier
};

struct Artist {
    map <string, Album > albums;
    string name;
    int time;
    int nsongs;
};

int convertTime(string time) { //changes song time to seconds to be converted back later
    int totalSeconds, minutes, seconds;
    replace(time.begin(), time.end(), ':', ' ');
    stringstream duration(time);

    if (duration >> minutes >> seconds) {
        totalSeconds = (minutes * 60) + seconds;
    }
    return totalSeconds;
}

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    string line;

    if (fin.is_open()) { //check if file was properly openned
        while (getline(fin, line)) {
            stringstream ss(line); //feed each line into the string stream to be parsed
            Song currSong;
            Album currAlbum;
            Artist currArtist;

            string songTime, genre;
            while (ss >> currSong.title >> songTime >> 
                currArtist.name >> currAlbum.name >> genre >> currSong.track) {
                    replace(currSong.title.begin(), currSong.title.end(),'_',' '); //replaces underscores after data is read in
                    replace(currArtist.name.begin(), currArtist.name.end(),'_',' ');
                    replace(currAlbum.name.begin(), currAlbum.name.end(),'_',' ');
                
                    currSong.time = convertTime(songTime);
                    //Test to make sure everything works cause this was lowk alot
                    cout << currSong.title << " " << currSong.time << " " << currArtist.name << " " 
                    << currAlbum.name << " " << genre << " " << currSong.track << endl;
                }
        }
    } else { 
        cout << " FAILED ";
        return 1;
    }
    return 0;
}