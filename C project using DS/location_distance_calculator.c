#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent locations in the network
struct location {
    char name[100];
    struct location* next;
};

// Structure to represent distances between locations
struct distance {
    char from[100];
    char to[100];
    float disval;
    struct distance* next;
};

// Function to insert a new location into the linked list
void insertLocation(struct location** head_ref, char* name) {
    struct location* newnode = (struct location*)malloc(sizeof(struct location));
    strcpy(newnode->name, name);
    newnode->next = *head_ref;

    if (*head_ref != NULL) {
        struct location* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = newnode;
    } else {
        newnode->next = newnode;
    }

    *head_ref = newnode;
}

// Function to insert a new distance into the linked list
void insertDistance(struct distance** head_ref, char* from, char* to, float disval) {
    struct distance* newnode = (struct distance*)malloc(sizeof(struct distance));
    strcpy(newnode->from, from);
    strcpy(newnode->to, to);
    newnode->disval = disval;
    newnode->next = *head_ref;
    *head_ref = newnode;

    // Also add the reverse distance (to keep it bidirectional)
    struct distance* reverse_node = (struct distance*)malloc(sizeof(struct distance));
    strcpy(reverse_node->from, to);
    strcpy(reverse_node->to, from);
    reverse_node->disval = disval;
    reverse_node->next = *head_ref;
    *head_ref = reverse_node;
}

// Function to retrieve the distance between two locations
float getDistance(struct distance* head, char* from, char* to) {
    while (head != NULL) {
        if (strcasecmp(head->from, from) == 0 && strcasecmp(head->to, to) == 0) {
            return head->disval;
        }
        head = head->next;
    }
    return -1;
}

// Function to print the list of available locations
void printLocations(struct location* head) {
    printf("\nAvailable locations:\n");
    struct location* current = head;
    do {
        printf("%s\n", current->name);
        current = current->next;
    } while (current != head);
}

// Function to find a location by name and return a pointer to its structure
struct location* findLocation(struct location* locations, char* enteredLocation) {
    struct location* temp = locations;
    do {
        if (strcasecmp(temp->name, enteredLocation) == 0) {
            return temp;
        }
        temp = temp->next;
    } while (temp != locations);
    return NULL;
}

int main() {
    struct location* locations = NULL;
    struct distance* distances = NULL;

    // Adding locations and distances
    insertLocation(&locations, "HYDERABAD");
    insertLocation(&locations, "VIJAYAWADA");
    insertLocation(&locations, "MANGALAGIRI");
    insertLocation(&locations, "SRM-UNI");

    insertDistance(&distances, "HYDERABAD", "VIJAYAWADA", 200);
    insertDistance(&distances, "HYDERABAD", "MANGALAGIRI", 240);
    insertDistance(&distances, "HYDERABAD", "SRM-UNI", 270);
    insertDistance(&distances, "VIJAYAWADA", "MANGALAGIRI", 40);
    insertDistance(&distances, "VIJAYAWADA", "SRM-UNI", 70);
    insertDistance(&distances, "MANGALAGIRI", "SRM-UNI", 30);

    // Getting user input for locations
    char start[100], end[100];
    printf("Enter the Starting location: ");
    scanf("%s", start);
    printf("Enter the Destination: ");
    scanf("%s", end);

    // Finding location structures
    struct location* startLocation = findLocation(locations, start);
    struct location* endLocation = findLocation(locations, end);

    // Validating user input
    if (!startLocation || !endLocation) {
        printf("\nInvalid locations entered.\n");
        printLocations(locations);
        return 0;
    }

    // Calculating and displaying the distance
    float dist = getDistance(distances, startLocation->name, endLocation->name);
    if (dist == -1) {
        printf("\nDistance not found.\n");
    } else {
        printf("\nDistance between %s and %s is %.2f km\n", startLocation->name, endLocation->name, dist);
    }

    // Printing all available locations
    printLocations(locations);

    return 0;
}
