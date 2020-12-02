This is the Hash-Map portion of a Word-Frequency count Application. I wrote the Iterator.cpp and HashMap.cpp files. 

The app opens the AliceInWonderland.txt file (main() assumes it to be in "default location) and then parses the individaul words from that file.
Each word is added to the Hash-Map with the GetKeyValue() and SetKeyValue() member functions. The text word is the key and is set by
SetKeyValue() which adds the key to the map and sets its initial count to 1. When the same key is processd, GetKeyValue() returns what the current 
count is and then a call to SetKeyValue() will increment the count by one. The Hash-Map is found in HashMap.cpp.

When the entire text of Alice in Wonderland is added to the map, the 15 most frequently occuring words are found an displayed.
The FindLargestWordCount() function in Main.cpp does this by iterating over all keys in the map to finds the one with the largest value.
The iterator performing the work is found in Iterator.cpp.
