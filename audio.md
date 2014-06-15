
## sfml audio support

SFML does not support mp3 formats due to licensing costs.

Fortunately you can convert mp3's to a supported format with tools like ffmpeg via command line.

Ideally you will want to drop any album art, and to use the vorbis lib you may have to reduce the strictness.

Here is the command to convert mp3 to ogg:

    ffmpeg -i my.mp3 -vn -codec:a vorbis -strict -2 my.ogg

