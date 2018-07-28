//
// Created by Lyosha12 on 27.07.2018.
//

#ifndef SNAKE_MUSICPLAYER_HPP
#define SNAKE_MUSICPLAYER_HPP


#include <string>
#include <vector>

#include <SFML/Audio.hpp>

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#include "Utility/Timer.hpp"

class MusicPlayer {
    // Проигрывает длительную wav-музыку.

  public:
    MusicPlayer(fs::path music_dir): music_dir(music_dir) {
        loadNames(music_dir);
    }
    
    void play_rand() {
        if(preparePlay(randMusic())) {
            cur_music.play();
            music_timer.reset();
        }
    }
    
  private:
    void loadNames(fs::path music_dir) {
        for(fs::directory_entry& file: fs::directory_iterator(music_dir)) {
            if(fs::is_regular_file(file) && fs::extension(file) == ".wav")
                music_names.push_back(file.path().filename().string());
        }
    }
    void tryUpdatePlaylist() {
        time_t cur_update_directory = fs::last_write_time(music_dir);
        if(cur_update_directory != last_update_directory) {
            loadNames(music_dir);
            last_update_directory = cur_update_directory;
        }
    }
    bool openMusic(std::string const& music_name) {
        bool isOpen = cur_music.openFromFile(music_dir.string() + music_name);
        music_timer.setInterval<std::chrono::microseconds>(
            cur_music.getDuration().asMicroseconds()
        );
        
        return isOpen;
    }
    bool preparePlay(std::string const& music_name) {
        if(!music_timer.isIntervalExpire()){
            return false;
        }
    
        tryUpdatePlaylist();
        return openMusic(music_name);
    }
    
    std::string const& randMusic() {
        size_t rand_music_number = rand() % music_names.size();
        return music_names[rand_music_number];
    }
    
  
  private:
    std::vector<std::string> music_names;
    fs::path music_dir;
    time_t last_update_directory = fs::last_write_time(music_dir);
    
    sf::Music cur_music;
    Timer<> music_timer;
};


#endif //SNAKE_MUSICPLAYER_HPP
