public class Tree implements Comparable<Tree> {
    public Node root;
    public int frequency = 0;

    public Tree() {
        root = null;
    }

    public Tree(char letter, int freq){
        root = new Node(letter);
        this.frequency = freq;
    }

    public int compareTo(Tree object) {
        if (frequency - object.frequency > 0) {
            return 1;
        } else if (frequency - object.frequency < 0) {
            return -1;
        }
        return 0;
    }
}

class Node {

    public char letter = '@';

    public Node leftChild;
    public Node rightChild;

    public Node(char letter){
        this.letter = letter;
        leftChild = null;
        rightChild = null;
    }
}
