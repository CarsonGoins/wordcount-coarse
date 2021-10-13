#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

#include "Dictionary.cpp"
#include "MyHashtable.cpp"

//Tokenize a string into individual word, removing punctuation at the
//end of words

std::vector<std::vector<std::string>> tokenizeLyrics(const std::vector<std::string> files) {
  std::vector<std::vector<std::string>> ret;

  for(auto filename : files) {
    //std::cout<<"reading "<<filename<<"\n";
    std::vector<std::string> my_vect;
    std::ifstream in (filename);

    std::string line;

    //For each line
    while (getline(in, line, '\n')) {
      //Skip all like starting with [
      if (line[0] == '[')
        continue;

      std::stringstream ssline (line);
      //For all words
      while (ssline) {
        std::string word;
        ssline >> word;
        if (ssline) {
          //remove punctuation at the end of word
          while (word.length() > 0
                 && std::ispunct(word[word.length() - 1])) {
            word.pop_back();
          }
          my_vect.push_back(word);
        }
      }
    }
    //std::cout<<"read "<<my_vect.size()<<" words\n";
    ret.push_back(my_vect);
  }
  return ret;
}

void function(std::string& w, std::mutex& mut) {
  MyHashtable<std::string, int> ht;
  Dictionary<std::string, int>& dict = ht;
  mut.lock();
    int count = dict.get(w);
    ++count;
    dict.set(w, count);
    mut.unlock();
  }

int main(int argc, char **argv)
{
  if (argc < 4) {
    std::cerr<<"usage: ./main <sources> <testword> <threshold>"<<std::endl;
    return -1;
  }

  // Parse Command Line
  std::string source = argv[1];
  std::string testWord = argv[2];
  int32_t thresholdCount = std::stoi(argv[3]);

  // Obtain List of Files
  std::vector<std::string> files;
  std::ifstream in (source);
  std::string line;
  while (getline(in, line, '\n')) {
    files.push_back(line);
  }

  // Tokenize Lyrics
  auto wordmap = tokenizeLyrics(files);

  MyHashtable<std::string, int> ht;
  Dictionary<std::string, int>& dict = ht;
  // std::vector<std::thread> thread;
  // std::mutex mutex;

  // write code here

 // Start Timer                                                                
   auto start =std::chrono::steady_clock::now();

   std::vector<std::thread> myThreads;
   std::mutex mu;
// for (auto & filecontent: wordmap) {
//      for (auto & w : filecontent) {
//        std::thread myThreads(function, std::ref(w));
//        myThreads.push_back(std::move(myThreads));
//        mutex1.unlock();
//      }
//    }
   // int val = 0;
   // for (int i=0; i < 16; ++i)
   //   {
   //     myThreads.push_back(std::move(myThreads))
   //   }
  
    for (auto & filecontent: wordmap) {
      for (auto & w : filecontent) {
	std::thread myThreads (function, std::ref(w), std::ref(mu));
	myThreads.push_back(std::move(myThreads));
      }
    }

// Stop Timer                                                                 
  auto stop = std::chrono::steady_clock::now();
  std::chrono::duration<double> time_elapsed = stop-start;

  // Check Hash Table Values 
  /* (you can uncomment, but this must be commented out for tests)
  for (auto it : dict) {
    if (it.second > thresholdCount)
      std::cout << it.first << " " << it.second << std::endl;
  }
  */

  // Do not touch this, need for test cases
  std::cout << ht.get(testWord) << std::endl;

  return 0;
}
