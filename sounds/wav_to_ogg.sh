for file in *.wav
  do ffmpeg -i "${file}" "${file/%wav/ogg}"
done
