#include "workerManager.h"
WorkerManager::WorkerManager()
{
}

WorkerManager::~WorkerManager()
{
}

void WorkerManager::Show_Menu()
{
    cout << "***************************************" << endl;
    cout << "*************0.exit system*************" << endl;
    cout << "*************1.add member*************" << endl;
    cout << "*************2.show member*************" << endl;
    cout << "*************3.delete member*************" << endl;
    cout << "*************4.alter member*************" << endl;
    cout << "*************5.search member*************" << endl;
    cout << "*************6.sort by number*************" << endl;
    cout << "*************7.clear document*************" << endl;
    cout << "***************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout << "bye bye" << endl;
    system("pause");
    exit(0);
}