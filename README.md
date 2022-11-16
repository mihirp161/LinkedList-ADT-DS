# Linked List — Abstract Data Type

Linked List is an Abstract Data Type (ADT) that holds a collection of Nodes, the nodes can be accessed in a sequential way. Linked List doesn’t provide a random access to a Node.

Usually, those Nodes are connected to the next node and/or with the previous one, this gives the linked effect. When the Nodes are connected with only the next pointer the list is called Singly Linked List and when it’s connected by the next and previous the list is called Doubly Linked List. Likewise, when a linked list wraps around, it's called a Circularly Linked List.

The Nodes stored in a Linked List can be anything from primitives types such as integers to more complex types like instances of classes.

# ADT — Interface
```````````
- AddHead(value)            	-> Add a node in the beginning
- AddTail(value)            	-> Add a node in the end
- InsertAfter(Node, value)  	-> Inserts a node after a node
- InsertBefore(Node, value) 	-> Inserts a node before a node
- Head()                    	-> Return the first node
- Tail()                    	-> Return the last node
- RemoveHead()              	-> Removes the head
- RemoveTail()              	-> Removes the tail
- Remove(index)            	-> Remove the Node at an index
- Remove(value)             	-> Remove Node matching value from the list
- PrintForward()            	-> Prints the list left to right
- PrintReverse()            	-> Prints the list left to right
- GetNode(index)            	-> Prints the node at an index
- FindAll(outData, value)   	-> Loads a vector that matches the value  
- Find(value)               	-> Gives the node matching the value
- Clear()                   	-> Deletes the List
`````````````````

![](https://github.com/opendatasurgeon/LinkedList-ADT-DS/blob/main/rmd_images/list.gif)

![](https://github.com/opendatasurgeon/LinkedList-ADT-DS/blob/main/rmd_images/list-deletion.gif)

![](https://github.com/opendatasurgeon/LinkedList-ADT-DS/blob/main/rmd_images/list-insertion.gif)
