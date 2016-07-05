#include <QtGui>
int main (int argc, char* argv[]) 
{
    QApplication app(argc, argv);      //here the name app() must be exactly app
    QTextStream consol_cout(stdout);   //I chose name consol_cout , it can be anything else 
    
    int answer = 0; 
    do {
         int factArg = 0;             //for the value enetered by user
         long int fact(1);           //initialization of result to the value 1
         bool result;                   //for OK[true] or Cancel[false] button
         QString response;
         factArg = QInputDialog::getInt(0, "Factorial Calculator","Factorial of:", 2, 0,25,1,&result);
         if(! result)  return EXIT_SUCCESS;     //user clicked Cancel button
         consol_cout << "User entered: " << factArg << endl;   //console output , can be omitted
         int i=2;
         while (i <= factArg && fact>0) 
         {
            fact = fact * i;
            ++i;
         }
         if(fact>0)
           response = QString("Factorial of %1 is %2.\n%3").arg(factArg).arg(fact).arg("Compute another one?");
         else 
           response = QString("Factorial of %1 too big (overflowed to negatives!)\n%2").arg(factArg).arg("Compute another one?");
         answer = QMessageBox::question(0, "Play again?", response, QMessageBox::Yes | QMessageBox::No);
      }while (answer == QMessageBox::Yes);
    return EXIT_SUCCESS;
}
