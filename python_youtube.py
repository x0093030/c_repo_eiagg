import os
from pytube import YouTube

CURRENT_DIR = os.getcwd()
DOWNLOAD_FOLDER = CURRENT_DIR
video_url = "https://www.youtube.com/watch?v=sPNI8fpWklg"
video_obj = YouTube(video_url)

#stream = video_obj.streams.get_audio_only()
stream = video_obj.streams.get_highest_resolution()
#stream = video_obj.streams.get_lowest_resolution()
stream.download(DOWNLOAD_FOLDER)

print('='*77)
print (DOWNLOAD_FOLDER)
