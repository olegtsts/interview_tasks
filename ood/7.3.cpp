#include <string>
#include <list>
#include <vector>

//display song
//create playlist
//cd selector
//track selector
//cd
struct Song {
    std::string name;
};
class SongListing {
protected:
    std::list<Song> songs_;
public:
    void AddSong(const Song& song) {
        songs_.push_back(song);
    }

    std::list<Song> GetSongList() const {
        return songs_;
    }
};
class PlayList : public SongListing {
};
class CD: public SongListing {
};
class JukeBox {
private:
    std::list<Song> playing_queue_;
    std::vector<PlayList> playlists_;
    CD* cd_;
public:
    JukeBox()
    : playlists_(), cd_(nullptr)
    {}

    PlayList* AddPlayList() {
        //Create new PlayList,
        //return pointer to it
    }

    void InsertCD(CD* cd) {
        //replace playing queue with cds playlist
    }
    void RemoveCD(CD* cd) {
        //clear playing queue
    }
    void ChoosePlayList(const size_t index) {
        //Change playing_queue to playlists queue
    }
};
