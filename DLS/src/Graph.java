
import java.io.BufferedReader;
import java.io.InputStreamReader;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author ahmed
 */
class Graph {

    int MAXSIZE = 51;
    int adj[][] = new int[MAXSIZE][MAXSIZE];
    int visited[] = new int[MAXSIZE];
    Stack s = new Stack();

    /*Function  for Depth-First-Search    */
    void createGraph() {
        int n, i, j, parent, adj_parent, initial_node;
        int ans = 0, ans1 = 0;
        System.out.print("\nEnter total number elements in a Undirected Graph :");
        n = getNumber();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                adj[i][j] = 0;
            }
        }

        /*All graph nodes are unvisited, hence assigned zero to visited field of each node*/
        for (int c = 1; c <= 50; c++) {
            visited[c] = 0;
        }
        System.out.println("\nEnter graph structure for DFS  ");

        do {
            System.out.print("\nEnter parent node :");
            parent = getNumber();
            do {
                System.out.print("\nEnter adjacent node for node " + parent + " : ");
                adj_parent = getNumber();
                adj[parent][adj_parent] = 1;
                adj[adj_parent][parent] = 1;
                System.out.print("\nContinue to add adjacent node for " + parent + "(1/0)?");
                ans1 = getNumber();

            } while (ans1 == 1);
            System.out.print("\nContinue to add graph node?");
            ans = getNumber();

        } while (ans == 1);
        System.out.print("\nAdjacency matrix for your graph is :\n");
        for (i = 1; i <= n; i++) {

            for (j = 1; j <= n; j++) {
                System.out.print(" " + adj[i][j]);
            }
            System.out.print("\n");

        }

        System.out.println("\nYour Undirected Graph is :");
        for (i = 1; i <= n; i++) {
            System.out.print("\nVertex " + i + " is connected to : ");
            for (j = 1; j <= n; j++) {
                if (adj[i][j] == 1) {
                    System.out.print(" " + j);
                }

            }

        }
        System.out.println("\nEnter the initial node for DLS traversal:");
        initial_node = getNumber();
        DFS(initial_node, n);

    }

    void DFS(int initial_node, int n) {
        //added code
        System.out.println("\nEnter the limit of the DLS:");
        int limit = getNumber();

        int u, i;
        s.top = -1;
        s.push(initial_node);
        System.out.println("\nDLS traversal for given graph is : ");
        while (!s.isempty()) {

            u = s.pop();
            if (visited[u] == 0) {
                System.out.print("\n" + u);
                visited[u] = 1;
            }
            for (i = 1; i <= n; i++) {
                // add limit to code in for loop

                if ((adj[u][i] == 1) && (visited[i] == 0) && s.top < limit-1) {
                    s.push(u);
                    visited[i] = 1;
                    System.out.print(" " + i);
                    u = i;

                }

            }

        }

    }/*  end of DFS function  */


    int getNumber() {
        String str;
        int ne = 0;

        InputStreamReader input = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(input);
        try {
            str = in.readLine();
            ne = Integer.parseInt(str);
        } catch (Exception e) {
            System.out.println("I/O Error");
        }
        return ne;
    }
}
