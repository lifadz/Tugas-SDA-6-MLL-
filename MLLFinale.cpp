#include <iostream>
using namespace std;

//Number X
struct numberX{
    int data;

    numberX(int val){
        this->data = val;
    }
};

struct data_numberX{
    numberX* info;
    data_numberX* next;
};

struct list_numberX{
    data_numberX* first;
};

//Number Y
struct numberY{
    int data;

    numberY(int val){
        this->data = val;
    }
};

struct data_numberY{
    numberY* info;
    data_numberY* next;
    list_numberX* xNums ;
};

struct list_numberY{
    data_numberY* first;
};

//Fungsi add data Number Y
void addNumberYData(list_numberY* list, int value){
    data_numberY* data = new data_numberY();
    numberY* ny = new numberY(value);
    data->info = ny;
    if(list->first == NULL){
        list->first = data;
    }
    else{
        data->next = list->first;
        list->first = data;
    }
}

//fungsi add data child
void addNumberXData(list_numberX* list, int value = NULL, data_numberX* inputedData = NULL) {
    if (value != NULL) {
        data_numberX* data = new data_numberX();
        numberX* nx = new numberX(value);
        data->info = nx;
        if (list->first == NULL) {
            list->first = data;
        }
        else {
            data->next = list->first;
            list->first = data;
        }
    }
    else if (inputedData != NULL) {
        if (list->first == NULL) {
            list->first = inputedData;
        }
        else {
            inputedData->next = list->first;
            list->first = inputedData;
        }
    }
}

//search data Number Y
data_numberY* searchNumberYData(list_numberY* list, int keyWord) {
    data_numberY* currentNumberY = list->first;
    while (currentNumberY != NULL) {
        if (keyWord == currentNumberY->info->data) {
            return currentNumberY;
        }
        currentNumberY = currentNumberY->next;
    }
    return NULL;
}

//search data Number X
data_numberX* searchNumberXData(list_numberX* list, int keyWord) {
    data_numberX* currentNumberX = list->first;
    while (currentNumberX != NULL) {
        if (keyWord == currentNumberX->info->data) {
            return currentNumberX;
        }
        currentNumberX = currentNumberX->next;
    }
    return NULL;
}
//remove data Number Y
void removeNumberYData(list_numberY* list, int keyNumberY) {
    data_numberY* target = NULL, * prev = NULL, * currentNumberY = list->first;
    bool finded = true;
    if (currentNumberY->info->data == keyNumberY) {
        list->first = currentNumberY->next;
        currentNumberY->next = NULL;
        return;
    }
    else {
        while (currentNumberY != NULL) {
            if (!finded) {
                keyNumberY == currentNumberY->next->info->data;
            }
            if (!finded) {
                prev = currentNumberY;
                finded = true;
            }
            if (keyNumberY == currentNumberY->info->data) {
                target = currentNumberY;
            }
            currentNumberY = currentNumberY->next;
        }
        if (target != NULL && prev != NULL) {
            prev->next = target->next;
            target->next = NULL;
        }
    }
}

//remove data Number X
void removeNumberXData(list_numberX* list, int keyNumberX) {
    data_numberX* target = NULL, *prev = NULL, *currentNumberX = list->first;
    bool finded = false;
    if (currentNumberX->info->data == keyNumberX) {
        list->first = currentNumberX->next;
        currentNumberX->next = NULL;
        return;
    }
    else {
        while (currentNumberX != NULL) {
            if (!finded) {
                keyNumberX == currentNumberX->next->info->data;
            }
            if (!finded) {
                prev = currentNumberX;
                finded = true;
            }
            if (keyNumberX == currentNumberX->info->data) {
                target = currentNumberX;
            }
            currentNumberX = currentNumberX->next;
        }
        if (target != NULL && prev != NULL) {
            prev->next = target->next;
            target->next = NULL;
        }
    }
}

//add Relation
void addRelationData(list_numberY* listY, list_numberX* listX, int keyNumberY, int keyNumberX) {
    //declare variables
    data_numberY* dy;
    data_numberX* dx, *r;
    list_numberX* newList;

    //code algorithm
    dy = searchNumberYData(listY, keyNumberY);
    dx = searchNumberXData(listX, keyNumberX);
    if (dy != NULL && dx != NULL) {
        r = new data_numberX();
        r->info = dx->info;
        if (dy->xNums == NULL) {
            newList= new list_numberX();
        }
        else {
            newList = dy->xNums;
        }
        dy->xNums = newList;
        addNumberXData(newList, 0, r);
    }
}

//remove relation
void removeRelationData(list_numberY* listY, int keyNumberY, int keyNumberX) {
    //declare variables
    data_numberY* dy;
    list_numberX* listChild;

    //code algorithm
    dy = searchNumberYData(listY, keyNumberY);
    if (dy != NULL && dy->xNums != NULL) {
        listChild = dy->xNums;
        removeNumberXData(listChild, keyNumberX);
    }
}

//fungsi print
void displayData(list_numberX* numberX = NULL, list_numberY* numberY = NULL ){
    if (numberY != NULL) {
        data_numberY* currentNumberY = numberY->first;
        cout<< "----------Node-------------" << "\n" << endl;
        cout << "Data Number Y:" << endl;
        while (currentNumberY != NULL) {
            cout << currentNumberY->info->data << "\t";
            if (currentNumberY->xNums != NULL) {
                data_numberX* currentNumberY_child = currentNumberY->xNums->first;
                cout << "\tChild:";
                while (currentNumberY_child != NULL) {
                    cout << "\t" << currentNumberY_child->info->data;
                    currentNumberY_child = currentNumberY_child->next;
                } 
            }
            cout << endl;
            currentNumberY = currentNumberY->next;
        }
        cout << endl;
    }
    
    if (numberX != NULL) {
        data_numberX* currentNumberX = numberX->first;
        cout << "Data Number X:" << endl;
        while (currentNumberX != NULL) {
            cout << currentNumberX->info->data << "\t" << endl;
            currentNumberX = currentNumberX->next;
        }
        cout << endl;
    }
}

int main(){
list_numberY* lNumberY = new list_numberY();
list_numberX* lNumberX = new list_numberX();

addNumberYData(lNumberY, 2);
displayData(lNumberX, lNumberY);

addNumberXData(lNumberX, 19);
displayData(lNumberX, lNumberY);

addNumberXData(lNumberX, 25);
displayData(lNumberX, lNumberY);

addNumberXData(lNumberX, 13);
displayData(lNumberX, lNumberY);

addNumberYData(lNumberY, 27);
displayData(lNumberX, lNumberY);

addRelationData(lNumberY, lNumberX, 27, 13);
displayData(lNumberX,lNumberY);

addRelationData(lNumberY, lNumberX, 27, 19);
displayData(lNumberX,lNumberY);

removeRelationData(lNumberY, 27, 13);
displayData(lNumberX,lNumberY);

removeNumberXData(lNumberX, 25);
displayData(lNumberX,lNumberY);


}

