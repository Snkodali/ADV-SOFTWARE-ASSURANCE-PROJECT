#include <deepstate/DeepState.hpp>
#include "CircularLinkedList.h"

using namespace deepstate;

TEST(CLLTest, TestInsertDeleteAndSearch) {
    CLList myList;

    for (int i = 0; i < 100; ++i) {
        int val = DeepState_IntInRange(1, 1000);
        int index = DeepState_IntInRange(0, myList.getLength());

        myList.insertAtIndex(val, index);
        ASSERT_TRUE(myList.search(val));
    }

    for (int i = 0; i < 50; ++i) {
        if (myList.getLength() == 0) {
            break;
        }
        int index = DeepState_IntInRange(0, myList.getLength() - 1);
        int lengthBeforeDeletion = myList.getLength();

        myList.deleteAtIndex(index);
        ASSERT_EQ(myList.getLength(), lengthBeforeDeletion - 1);
    }

    myList.insertAtEnd(1001);
    int lengthBeforeDeletion = myList.getLength();
    myList.deleteAtEnd();
    ASSERT_EQ(myList.getLength(), lengthBeforeDeletion - 1);

    for (int i = 0; i < 1000; ++i) {
        if (DeepState_Bool()) {
            int valToSearch = DeepState_IntInRange(1, 1000);
            if (myList.search(valToSearch)) {
                ASSERT_TRUE(myList.search(valToSearch));
            } else {
                ASSERT_FALSE(myList.search(valToSearch));
            }
        }
    }
    myList.display();
}
