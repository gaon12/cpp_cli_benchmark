@echo off
ffmpeg -fflags +discardcorrupt -i abcd.mp4 -vf "yadif=0:-1:0,scale=1920:1080" -c:v libx264 -preset:v veryfast -crf 22 -movflags +faststart -c:a aac -b:a 160k output.mp4
