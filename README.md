HinLIBS – Deliverable 1 (D1)

COMP 3004 – Fall 2025


Team #22: 

Members:

    Van Tien Phi Pham
    Mohammad Makkawi
    Zachary Kushner
    Michael Boyer

-------------

How to Build and Run

    1.    Extract the ZIP:
            Deliverable1.zip
            
    2.    Open Qt Creator → File → Open File or Project
            Select testProject.pro file.

    3.    Click Configure Project, then Build → Run.

No additional setup or libraries required.


------------

Patron Account Names and Passwords

    Name: john323, Password: littlejohn
    Name: dane dane113, Password: dane
    Name: littlehenry, Password: henry16
    Name: john323, Password: littlejohn
    Name: Harry9, Password: hair
    Name: moneylover, Password: $$

    Librarian name: lib1, Password: lib1
    Admin name: admin1, admin1


Implemented Patron Features

1. Browse Catalogue
    •    View all items with title, author/creator, and availability.

2. Borrow Item
    •    Borrow up to 3 active loans.
    •    Item marked unavailable.
    •    Due date = today + 14 days.
    •    Added to patron’s active loan list.

3. Return Item
    •    Returns item to the library.
    •    Item marked available.
    •    Removed from patron’s loan list.

4. Place Hold
    •    Allowed only on checked-out items.
    •    Patron added to item’s FIFO queue.
    •    Queue position shown.

5. Cancel Hold
    •    Patron removed from the hold queue.
    •    Queue positions updated.

6. View Account Status


Shows:
    •    Active Loans
    •    Title
    •    Due date
    •    Days remaining
    •    Active Holds
    •    Title
    •    Current queue position

