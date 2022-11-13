#Linked List — Abstract Data Type

Linked List is an Abstract Data Type (ADT) that holds a collection of Nodes, the nodes can be accessed in a sequential way. Linked List doesn’t provide a random access to a Node.

Usually, those Nodes are connected to the next node and/or with the previous one, this gives the linked effect. When the Nodes are connected with only the next pointer the list is called Singly Linked List and when it’s connected by the next and previous the list is called Doubly Linked List.

The Nodes stored in a Linked List can be anything from primitives types such as integers to more complex types like instances of classes.

ADT — Interface
The Linked List interface can be implemented in different ways, is important to have operations to insert a new node and to remove a Node:

# Main operations
prepend(value)        -> Add a node in the beginning
append(value)         -> Add a node in the end
pop()                 -> Remove a node from the end
popFirst()            -> Remove a node from the beginning
head()                -> Return the first node
tail()                -> Return the last node
remove(Node)          -> Remove Node from the list
Since abstract data types don’t specify an implementation, this means it’s also incorrect to talk about the time complexity of a given abstract data type.

ADT — Operations

Traversal : You must be thinking, “how could I print all the elements of a Linked List?”
A Linked List can be traversed , is possible to navigate in the list using the nodes next element.

list = LinkedList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
currentNode = LinkedList.head()    # Get the first Node
while the currentNode.next
    print currentNode.value
    currentNode = currentNode.next     # Assign the next element
This is an abstract operation and the implementation will define how you interact with the Linked List.

Search: You must be thinking, “how do I find an element inside the Linked List?”

Is possible to traverse the array and compare if the element we are looking for exists in the array:

list = LinkedList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
targetValue = 7
currentNode = LinkedList.head()    # Get the first Node
while the currentNode.next
    if currentNode.value is equal to targetValue
        print Node found
    currentNode = currentNode.next     # Assign the next element
This is an example of how we could search for an element inside a Linked List, but this could be not the optimal way. There are different and, in some cases, better algorithms to traverse and search in arrays.

Linked List — Data Structure
Implementation
A Linked List can be implemented in different ways, this is my implementation and it’s used to explain the concepts. The ADT defines what a Linked List should be able to do and the Data Structure is the implementation.

The implementation could use Nodes with a previous and next pointers, the LinkedList could have a head to keep track of the first element and a tail to keep track of the last element in the list. There’s a lot of improvement points to this implementation, the focus here is to understand the basics of a Linked List.