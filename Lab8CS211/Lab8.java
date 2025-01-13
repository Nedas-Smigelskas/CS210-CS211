import java.util.PriorityQueue;
import java.util.Scanner;
public class Lab8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine().toLowerCase(); 
        int[] frequencies = new int[27]; 
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            if (c >= 'a' && c <= 'z') {
                frequencies[c - 'a']++;
            }
            if(c == ' '){
                frequencies[26]++;
            }
        }

        System.out.println("Frequency of each letter:");
        for (char c = 'a'; c <= 'z'; c++) {
            if (frequencies[c - 'a'] > 0) {
                System.out.println("'" + c + "' has a frequency of " + frequencies[c - 'a']);
            }
        }
        if(frequencies[26] > 0){
            System.out.println("' '" + " has a frequency of " + frequencies[26]);
        }
        Tree[] trees = new Tree[27];
        int treeCount = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (frequencies[c - 'a'] > 0) {
                trees[treeCount++] = new Tree(c, frequencies[c - 'a']);
            }
        }
        if (frequencies[26] > 0) {
            trees[treeCount++] = new Tree(' ', frequencies[26]);
        }
        PriorityQueue<Tree> PQ = new PriorityQueue<>(treeCount);
        for (int i = 0; i < treeCount; i++) {
            PQ.add(trees[i]);
        }

        while (PQ.size() > 1) {
            Tree tree1 = PQ.poll();
            Tree tree2 = PQ.poll();

            Tree mergedTree = new Tree('@', tree1.frequency + tree2.frequency);
            mergedTree.root = new Node('@');
            mergedTree.root.leftChild = tree1.root;
            mergedTree.root.rightChild = tree2.root;

            PQ.add(mergedTree);
        }

        System.out.println("Combined tree frequency: " + PQ.peek().frequency);
        Tree FINALTREE = PQ.peek();
        generateHuffmanCodes(FINALTREE.root, "");
    }

    public static void generateHuffmanCodes(Node root, String code) {
        if (root == null) {
            return;
        }

        if (root.leftChild == null && root.rightChild == null) {
            System.out.println("'" + root.letter + "' : " + code);
            return;
        }

        generateHuffmanCodes(root.leftChild, code + "0");
        generateHuffmanCodes(root.rightChild, code + "1");
    }
}
