#ifndef CELLVCC_H

#define CELLVCC_H

#include "Cell/Cell.h"

class CellVcc: public Cell
{
public:

  using Cell::measurePin;
  using Cell::setup;
  float measurePin();
  void setup();
};

#endif /* end of include guard: CELLVCC_H
 */
