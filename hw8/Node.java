// The node class that implements a 2-way linked list
public class Node implements java.io.Serializable{
		private Node previous; // initializes the previous node
		private Node next; // initializes the next node
		private String info; // string object that actually contains our information
		
		public Node(){ // default constructor
			previous = null; // sets previous to a null object
			next = null; // sets next to a null object
			info = ""; // sets info to blank string
		}
		
		public Node(Node p, Node n, String in){ // alternate constructor
			previous = p; // sets previous to the inputted node object
			next = n; // sets next to inputted node object
			info = in; // sets the info of the current node to the inputted string
		}
		
		public Node getPrev(){ // returns previous node (e.g. goes backwards in the list)
			return previous;
		}
		
		public void setPrev(Node p){ // setter for previous node (sets previous element)
			previous = p;
		}
		
		public Node getNext(){ // getter for the next node (goes forward in the list)
			return next;
		}
		
		public void setNext(Node n){ // setter for the next node (sets forward element)
			next = n;
		}
		
		public void setInfo(String i){ // setter for the actual information string
			info = i;
		}
		
		public String getInfo(){ // getter for the information string
			return info;
		}
}
