//Q1)Write a program that simulates a simple address book. Define a structure to store contact
//information (name, email, phone number). Allow the user to add new contacts to the
//address book dynamically. Use dynamic memory allocation for storing the contacts using
//malloc and update the memory allocation using realloc when adding new contacts.
//Implement an option to delete a contact and free the memory. Ensure that memory is
//properly managed throughout the program's execution.

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Contact {
//    char name[50];
//    char email[50];
//    char phoneNumber[15];
//};
//
//void addContact(struct Contact **addressBook, int *numContacts) {
//    (*numContacts)++;
//    *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));
//
//    printf("Enter name: ");
//    scanf("%s", (*addressBook)[*numContacts - 1].name);
//
//    printf("Enter email: ");
//    scanf("%s", (*addressBook)[*numContacts - 1].email);
//
//    printf("Enter phone number: ");
//    scanf("%s", (*addressBook)[*numContacts - 1].phoneNumber);
//
//    printf("Contact added successfully!\n");
//}
//
//void deleteContact(struct Contact **addressBook, int *numContacts) {
//    if (*numContacts == 0) {
//        printf("Address book is empty. No contacts to delete.\n");
//        return;
//    }
//
//    printf("Contacts in the address book:\n");
//    for (int i = 0; i < *numContacts; i++) {
//        printf("%d. %s\n", i + 1, (*addressBook)[i].name);
//    }
//
//    int index;
//    printf("Enter the index of the contact to delete: ");
//    scanf("%d", &index);
//
//    if (index < 1 || index > *numContacts) {
//        printf("Invalid index. No contact deleted.\n");
//        return;
//    }
//
//    memmove(*addressBook + index - 1, *addressBook + index, (*numContacts - index) * sizeof(struct Contact));
//    (*numContacts)--;
//    *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));
//
//    printf("Contact deleted successfully!\n");
//}
//
//void freeAddressBook(struct Contact *addressBook) {
//    free(addressBook);
//}
//
//int main() {
//    struct Contact *addressBook = NULL;
//    int numContacts = 0;
//    int choice;
//
//    do {
//        printf("\nAddress Book Menu:\n");
//        printf("1. Add Contact\n");
//        printf("2. Delete Contact\n");
//        printf("3. Quit\n");
//        printf("Enter your choice: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//            case 1:
//                addContact(&addressBook, &numContacts);
//                break;
//            case 2:
//                deleteContact(&addressBook, &numContacts);
//                break;
//            case 3:
//                freeAddressBook(addressBook);
//                printf("Memory freed. Quitting program.\n");
//                break;
//            default:
//                printf("Invalid choice. Please enter a valid option.\n");
//        }
//
//    } while (choice != 3);
//
//    return 0;
//}


//Write a C program to merge two sorted singly linked lists into a single sorted linked list

//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node {
//    int data;
//    struct Node* next;
//};
//
//struct Node* insertEnd(struct Node* head, int value) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = value;
//    newNode->next = NULL;
//
//    if (head == NULL) {
//        return newNode;
//    }
//
//    struct Node* temp = head;
//    while (temp->next != NULL) {
//        temp = temp->next;
//    }
//
//    temp->next = newNode;
//    return head;
//}
//
//struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
//    struct Node dummy = {0, NULL};
//    struct Node* current = &dummy;
//
//    while (list1 != NULL && list2 != NULL) {
//        if (list1->data < list2->data) {
//            current->next = list1;
//            list1 = list1->next;
//        } else {
//            current->next = list2;
//            list2 = list2->next;
//        }
//        current = current->next;
//    }
//
//    current->next = (list1 != NULL) ? list1 : list2;
//
//    return dummy.next;
//}
//
//void displayList(struct Node* head) {
//    while (head != NULL) {
//        printf("%d -> ", head->data);
//        head = head->next;
//    }
//    printf("NULL\n");
//}
//
//void freeList(struct Node* head) {
//    struct Node* temp;
//    while (head != NULL) {
//        temp = head;
//        head = head->next;
//        free(temp);
//    }
//}
//
//int main() {
//    struct Node *list1 = NULL, *list2 = NULL;
//
//    for (int i = 1; i <= 5; i += 2) {
//        list1 = insertEnd(list1, i);
//    }
//
//    for (int i = 2; i <= 6; i += 2) {
//        list2 = insertEnd(list2, i);
//    }
//
//    printf("List 1: ");
//    displayList(list1);
//    printf("List 2: ");
//    displayList(list2);
//
//    struct Node* mergedList = mergeSortedLists(list1, list2);
//
//    printf("Merged List: ");
//    displayList(mergedList);
//
//    freeList(list1);
//    freeList(list2);
//    freeList(mergedList);
//
//    return 0;
//}
//
//
//}

//Write a C program that converts a singly linked list into an array and returns it.
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to convert a linked list to an array
int* linkedListToArray(struct Node* head, int* size) {
    // Count the number of nodes to determine the size of the array
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Allocate memory for the array
    int* array = (int*)malloc(count * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy the linked list elements to the array
    current = head;
    for (int i = 0; i < count; i++) {
        array[i] = current->data;
        current = current->next;
    }

    // Set the size of the array
    *size = count;

    return array;
}

// Function to print an array
void printArray(int* array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to free the memory used by the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    // Convert linked list to array
    int size;
    int* array = linkedListToArray(head, &size);

    // Print the array
    printArray(array, size);

    // Free memory
    freeList(head);
    free(array);

    return 0;
}


//Write a C program that removes elements with odd indices from a singly linked list.


//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node {
//    int data;
//    struct Node* next;
//};
//
//struct Node* insertEnd(struct Node* head, int value) {
//    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//    newNode->data = value;
//    newNode->next = NULL;
//
//    if (head == NULL) {
//        return newNode;
//    }
//
//    struct Node* temp = head;
//    while (temp->next != NULL) {
//        temp = temp->next;
//    }
//
//    temp->next = newNode;
//    return head;
//}
//
//struct Node* removeOddIndices(struct Node* head) {
//    struct Node* current = head;
//
//    while (current != NULL && current->next != NULL) {
//        struct Node* oddNode = current->next;
//        current->next = oddNode->next;
//        free(oddNode);
//        current = current->next;
//    }
//
//    return head;
//}
//void displayList(struct Node* head) {
//    struct Node* temp = head;
//    while (temp != NULL) {
//        printf("%d -> ", temp->data);
//        temp = temp->next;
//    }
//    printf("NULL\n");
//}
//
//void freeList(struct Node* head) {
//    struct Node* temp;
//    while (head != NULL) {
//        temp = head;
//        head = head->next;
//        free(temp);
//    }
//}
//
//int main() {
//    struct Node* list = NULL;
//    for (int i = 1; i <= 6; i++) {
//        list = insertEnd(list, i * 2);
//    }
//    printf("Original Linked List: ");
//    displayList(list);
//    list = removeOddIndices(list);
//    printf("Modified Linked List: ");
//    displayList(list);
//    freeList(list);
//
//    return 0;
//}
//



