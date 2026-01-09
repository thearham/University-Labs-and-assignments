#include "myLL.h"

int main()
{
    myLL obj;

    obj.insertAtHead(100);

    cout << "Deleted Value from head is: " << obj.deleteFromHead() << endl;

    
    cout << "This is Display Function: " << endl;
    obj.display();

    return 0;
}