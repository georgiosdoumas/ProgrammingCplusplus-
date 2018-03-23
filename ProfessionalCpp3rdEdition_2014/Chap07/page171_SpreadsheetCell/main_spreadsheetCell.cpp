#include <iostream>
#include <memory>
#include "Spreadsheetcell.h"

int main()
{
  SpreadsheetCell myCell, anotherCell;  // default constructor is used
  myCell.setValue(6);
  anotherCell.setString("3.2");
  cout << "myCell: " << myCell.getValue() << endl;
  cout << "anotherCell as string: " << anotherCell.getString() << " and as value:" << anotherCell.getValue() << endl;
  anotherCell.setString("11.2");
  cout << "Changed anotherCell, as string: " << anotherCell.getString() << " and as value:" << anotherCell.getValue() << endl;
  anotherCell = myCell;      // assignement operator used
  cout << "Made anotherCell equal to myCell : " << anotherCell.getString() << " and as value:" << anotherCell.getValue() << endl;
  SpreadsheetCell copiedCell(myCell);     // copy constructor called
  cout << "copiedCell equal to myCell : " << copiedCell.getString() << " and as value:" << copiedCell.getValue() << endl;

  double initval = 3.7;
  SpreadsheetCell* myCellp = new SpreadsheetCell(initval);
  SpreadsheetCell* my_Cellp = new SpreadsheetCell;  //new SpreadsheetCell();   is also accepted
  my_Cellp->setString("22.1");
  cout << "myCellp: " << myCellp->getValue() << ", OR as string: " << myCellp->getString() << endl;  // string is empty!
  cout << "my_Cellp: " << my_Cellp->getValue() << ", or as string: " << my_Cellp->getString() << endl;
  myCellp->setValue(3.9);
  cout << "After setting its value to a new value,myCellp: " << myCellp->getValue() << ", or as string: " << myCellp->getString() << endl;
  delete myCellp; myCellp = nullptr;
  SpreadsheetCell* emptyCellp = nullptr;
  emptyCellp = new SpreadsheetCell("13.2");
  cout << "initially empty cell: " << emptyCellp->getValue() << ", or as string: " << emptyCellp->getString() << endl;
  delete emptyCellp; emptyCellp = nullptr;

  auto smartCellp1 = std::make_unique<SpreadsheetCell>();  // the () must exist in the end, else it will not compile! 
  std::unique_ptr<SpreadsheetCell> smartCellp2(new SpreadsheetCell);
  smartCellp1->setValue(4.7);
  smartCellp2->setString("5.7");
  cout << "smartCellp1: " << smartCellp1->getValue() << ", or as string: " << smartCellp1->getString() << endl;
  cout << "smartCellp2: " << smartCellp2->getValue() << ", or as string: " << smartCellp2->getString() << endl;
  smartCellp1->setValue(4.9);
  //smartCellp1 = smartCellp2;        // We can NOT do this assgnement, does not compile
  smartCellp2->setString("5.9");
  cout << "Changed value of smartCellp1: " << smartCellp1->getValue() << ", or as string: " << smartCellp1->getString() << endl;
  cout << "Changed value of smartCellp2: " << smartCellp2->getValue() << ", or as string: " << smartCellp2->getString() << endl;

  SpreadsheetCell aThirdCell("test"); // Uses string-arg ctor that uses delegated constructor so the string "test" becomes 0
  SpreadsheetCell const aFourthCell(9.4); // Uses double-arg ctor
  auto aThirdCellp = std::make_unique<SpreadsheetCell>("9.5"); // string-arg ctor
  cout << "aThirdCell: " << aThirdCell.getValue() << ", or as string: " << aThirdCell.getString() << endl;   // outputs 0 for number and 0 for the string
  cout << "aFourthCell: " << aFourthCell.getValue() << ", or as string: " << aFourthCell.getString() << endl;
  cout << "aThirdCellp: " << aThirdCellp->getValue() << ", or as string: " << aThirdCellp->getString() << endl;
  SpreadsheetCell str_numCell("13.3");
  SpreadsheetCell assignedCell = str_numCell;       //copy constructor  used!
  cout << "assignedCell : " << assignedCell.getValue() << ", or as string: " << assignedCell.getString() << endl;
  return 0;
}
