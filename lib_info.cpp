//
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;


struct Song { 
    string title;
    int time;  // could also be a string
    int track;
};

struct Album {
    map <int, Song > songs; //key = track #
    string name;
    int time;
    int nsongs;  // optional variable but makes it easier
};

struct Artist {
    map <string, Album > albums; //key = artist name
    string name;
    int time;
    int nsongs;
};

int convertTime(string time) { //changes song time to seconds 
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

    if (fin.is_open()) { //check if file was properly opened
        map<string, Artist> artists;
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
                
                    currSong.time = convertTime(songTime); //call to time conversion function to convert time to seconds
                }

            //Populates map with data from the file and increment song count and time for each artist and album
            artists[currArtist.name].name = currArtist.name;    
            artists[currArtist.name].albums[currAlbum.name].songs[currSong.track] = currSong;
            artists[currArtist.name].nsongs += 1;

            artists[currArtist.name].time += currSong.time;
            artists[currArtist.name].albums[currAlbum.name].nsongs += 1;
            artists[currArtist.name].albums[currAlbum.name].time += currSong.time;
        }
        //TODO iterate through nested maps and output to the terminal in the proper format
            //Use nested for loops to iterate through the maps
            //Utilize printf to output the data in the desired format
        //TODO double check that the file properly compiles on hydra computers via SSH
            //test against gradescripts via vim
            //correct any formatting discrepancies

    } else { 
        cout << " FAILED ";
        return 1;
    }
    return 0;
}