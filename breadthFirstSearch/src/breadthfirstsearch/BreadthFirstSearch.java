package breadthfirstsearch;

import java.io.*;
import java.util.*;

class Queue {

    int items[] = new int[10];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    void insert(int e) {
        if (rear == 9) {
            System.out.println("Queue overflow");
        } else {
            items[++rear] = e;
        }
    }

    int empty() {
        return (rear < front ? 1 : 0);
    }

    int remove() {
        int x = 0;
        if (empty() == 1) {
            System.out.println("Queue Underflow");
            return 0;
        } else {
            x = items[front++];
            return x;
        }
    }

}

class Graph {

    int MAXSIZE = 51;
    int adj[][] = new int[MAXSIZE][MAXSIZE];
    int visited[] = new int[MAXSIZE];
    Queue q = new Queue();

    void createGraph() throws IOException {
        int n, i, j, parent, adj_parent, initial_node;
        int ans = 0, ans1 = 0;
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("\nEnter total number elements in a Undirected Graph :");
        n = Integer.parseInt(in.readLine());
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }

        for (int c = 1; c <= 50; c++) {
            visited[c] = 0;
        }
        System.out.println("\nEnter graph structure for BFS  ");

        do {
            System.out.print("\nEnter parent node :");
            parent = Integer.parseInt(in.readLine());

            do {
                System.out.print("\nEnter adjacent node for node " + parent + " : ");
                adj_parent = Integer.parseInt(in.readLine());
                ;
                adj[parent][adj_parent] = 1;
                adj[adj_parent][parent] = 1;
                System.out.print("\nContinue to add adjacent node for " + parent + "(1/0)?");
                ans1 = Integer.parseInt(in.readLine());

            } while (ans1 == 1);
            System.out.print("\nContinue to add graph node(1,0)?");
            ans = Integer.parseInt(in.readLine());

        } while (ans == 1);
        System.out.print("\nContenue to add graph node press 1 ? \n");
        while (ans == 1);

        System.out.println("\nAdiacency matrix for your graph is : \n");

        for (i = 1; i <= n; i++) {

            for (j = 1; j <= n; j++) {
                System.out.print(" " + adj[i][j]);
            }
            System.out.print("\n");

        }

        System.out.println("\nYour Undirected Graph is :");
        for (i = 1; i <= n; i++) {
            System.out.print("\nVertex " + i + "is connected to : ");
            for (j = 1; j <= n; j++) {
                if (adj[i][j] == 1) {
                    System.out.print(" " + j);
                }

            }

        }
        System.out.println("\nEnter the initial node for BFS traversal:");
        initial_node = Integer.parseInt(in.readLine());
        BFS(initial_node, n);

    }

    void BFS(int initial_node, int n) {
        int u, i;
        u = initial_node;
        visited[initial_node] = 1;
        System.out.println("\nDFS traversal for given graph is : ");
        System.out.print(initial_node);
        q.insert(initial_node);

        while (q.empty() == 0) {

            u = q.remove();
            for (i = 1; i <= n; i++) {
                if ((adj[u][i] == 1) && (visited[i] == 0)) {
                    q.insert(i);
                    visited[i] = 1;

                    System.out.print(" " + i);
                }

            }

        }

    }

}

public class BreadthFirstSearch {

    public static void main(String args[]) throws IOException {
        Graph g = new Graph();
        g.createGraph();
    }
}
