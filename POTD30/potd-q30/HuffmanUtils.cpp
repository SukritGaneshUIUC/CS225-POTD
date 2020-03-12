#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <map>
#include <tuple>

using std::string;

void huffmanTreeMap(HuffmanNode * current, std::map<char, string> & theMap, string currentBinary){
  if (current->left_ == NULL && current->right_ == NULL) {
    theMap.insert(std::pair<char, string>(current->char_, currentBinary));
    // std::cout << "added: " << current->char_ << std::endl;
    return;
  }

  if (current->left_ != NULL) {
    huffmanTreeMap(current->left_, theMap, currentBinary + "0");
  }

  if (current->right_ != NULL) {
    huffmanTreeMap(current->right_, theMap, currentBinary + "1");
  }
}

map<char, string> huffmanTreeMap(HuffmanNode * huffmanTree){
    std::map<char, string> theMap;
    huffmanTreeMap(huffmanTree, theMap, "");
    return theMap;
}

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    HuffmanNode * current = huffmanTree;
    string x = "";
    for (char & c: binaryString) {
      if (current->left_ == NULL && current->right_ == NULL) {
        x += current->char_;
        current = huffmanTree;
      }

      if (c == '0') {
        current = current->left_;
      } else if (c == '1') {
        current = current->right_;
      }
    }
    x += current->char_;
    return x;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string x = "";
    std::map<char, string> huffmanMap = huffmanTreeMap(huffmanTree);
    for (const char & c: charString) {
      x += huffmanMap.at(c);
    }
    return x;
}
