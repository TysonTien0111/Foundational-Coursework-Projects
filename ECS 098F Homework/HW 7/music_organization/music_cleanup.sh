#!/usr/bin/bash

directory=$2

getArtistName() {
    # I wrote this one to take one argument and set a global variable to the 
    # artist's name with whitespace removed
    # Note that this is where you'll want/need to use ffprobe
}

getSongName() {
    # Same deal as getArtistName but with the song name
    # Note that this is where you'll want/need to use ffprobe
}

doConversion() {
    # This function performs the conversion on a single file
}

# Takes one argument, that being a directory
TARGET_DIR=$1

# Now we should iterate over every file in the directory and do the conversion
# for each file
