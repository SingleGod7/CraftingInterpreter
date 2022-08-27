#include "double-linked_list.h"

int main() {
    list* test_1 = InitDulList();
    Insert(0, test_1, "woshishabi");
    Insert(1, test_1, "woshishabi");
    Insert(2, test_1, "woshishabi");
    Insert(3, test_1, "woshshabi");
    Insert(4, test_1, "woshishabi");

    DisplayList(test_1);

    Delete(0, test_1);
    int f;
    f = Find(test_1, "woshshabi");
    printf("find at index: %d\n",f);
    Delete(3, test_1);
    Delete(1, test_1);
    Delete(2, test_1);
    Delete(0, test_1);

    DisplayList(test_1);
}