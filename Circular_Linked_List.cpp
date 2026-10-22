#include <iostream>
#include <string>
using namespace std;
struct Song {
    string title;
    int duration;
    Song* next;
};
class Playlist {
    Song* tail = NULL;
public:
    // Insert song
    void insert(string title, int duration) {
        Song* newNode = new Song;
        newNode->title = title;
        newNode->duration = duration;
        if (tail == NULL) {
            tail = newNode;
            newNode->next = newNode;
        }
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Song added successfully.\n";
    }
    // Search song
    Song* search(string title) {
        if (tail == NULL)
            return NULL;
        Song* temp = tail->next;
        do {
            if (temp->title == title)
                return temp;
            temp = temp->next;
        } while (temp != tail->next);
        return NULL;
    }
    // Update song
    void update(string title, int duration) {
        Song* temp = search(title);
        if (temp != NULL) {
            temp->duration = duration;
            cout << "Song updated successfully.\n";
        }
        else {
            cout << "Song not found.\n";
        }
    }
    // Delete song
    void deleteSong(string title) {
        if (tail == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }
        Song* current = tail->next;
        Song* previous = tail;
        do {
            if (current->title == title) {
                // Only one song
                if (current == tail && current->next == current) {
                    tail = NULL;
                }
                else {
                    previous->next = current->next;
                    if (current == tail)
                        tail = previous;
                }
                delete current;
                cout << "Song deleted successfully.\n";
                return;
            }
            previous = current;
            current = current->next;
        } while (current != tail->next);
        cout << "Song not found.\n";
    }
    // Sort songs alphabetically
    void sort() {
        if (tail == NULL)
            return;
        Song* i = tail->next;
        while (i != tail) {
            Song* j = i->next;
            while (true) {
                if (j->title < i->title) {
                    swap(i->title, j->title);
                    swap(i->duration, j->duration);
                }
                if (j == tail)
                    break;
                j = j->next;
            }
            i = i->next;
        }
        cout << "Playlist sorted by title.\n";
    }
    // Display playlist
    void display() {
        if (tail == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }
        Song* temp = tail->next;
        cout << "\nMusic Playlist\n";
        do {
            cout << "Song: " << temp->title << endl;
            cout << "Duration: " << temp->duration << " seconds" << endl;
            temp = temp->next;
        } while (temp != tail->next);
    }
    // Destructor
    ~Playlist() {
        while (tail != NULL) {
            Song* current = tail->next;
            if (current == tail) {
                delete current;
                tail = NULL;
            }
            else {
                tail->next = current->next;
                delete current;
            }
        }
    }
};
int main() {
    Playlist p;
    int choice;
    string title;
    int duration;
    do {
        cout << "\nMUSIC PLAYLIST\n";
        cout << "1. Insert Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Search Song\n";
        cout << "4. Update Song\n";
        cout << "5. Sort Playlist\n";
        cout << "6. Delete Song\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter Song Title: ";
            cin >> title;
            cout << "Enter Duration: ";
            cin >> duration;
            p.insert(title, duration);
            break;
        case 2:
            p.display();
            break;
        case 3:
            cout << "Enter Song Title to search: ";
            cin >> title;
            if (p.search(title) != NULL)
                cout << "Song found.\n";
            else
                cout << "Song not found.\n";
            break;
        case 4:
            cout << "Enter Song Title: ";
            cin >> title;
            cout << "Enter New Duration: ";
            cin >> duration;
            p.update(title, duration);
            break;
        case 5:
            p.sort();
            break;
        case 6:
            cout << "Enter Song Title to delete: ";
            cin >> title;
            p.deleteSong(title);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);
    return 0;
}