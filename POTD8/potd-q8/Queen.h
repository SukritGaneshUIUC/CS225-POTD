#pragma once
#include "Piece.h"
#include <string>

class Queen : public Piece::Piece{
public:
  std::string getType();
};
