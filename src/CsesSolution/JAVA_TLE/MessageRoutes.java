import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.AbstractCollection;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Comparator;
import java.util.ArrayList;
//external library used for pair
import org.apache.commons.math3.util.Pair;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lazyboson
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        MessageRoute solver = new MessageRoute();
        solver.solve(1, in, out);
        out.close();
    }

    static class MessageRoute {
        public void PrintPath(int start, int end, int[] predecessors) {
            ArrayList<Integer> paths = new ArrayList<>();
            for (int i = end; i != start; i = predecessors[i]) {
                paths.add(i);
            }
            paths.add(start);
            for (int i = paths.size() - 1; i >= 0; i--)
                System.out.printf(paths.get(i) + " ");
            System.out.println();
        }

        public void Dijkstras(int start, int end, int[] distance, ArrayList<ArrayList<Pair<Integer, Integer>>> adj, int[] predecessors) {
            distance[start] = 0;
            //predecessors maintain the path
            Arrays.fill(predecessors, -1);
            PriorityQueue<Pair<Integer, Integer>> queue = new PriorityQueue<>(Comparator.comparing(Pair::getKey));
            boolean[] visited = new boolean[end + 1];
            queue.add(Pair.create(0, start));
            while (!queue.isEmpty()) {
                int a = queue.poll().getSecond();
                if (visited[a])
                    continue;
                visited[a] = true;
                for (var u : adj.get(a)) {
                    int b = u.getFirst(), w = u.getSecond();
                    if (distance[a] + w < distance[b]) {
                        distance[b] = distance[a] + w;
                        predecessors[b] = a;
                        queue.add(Pair.create(distance[b], b));
                    }
                }
            }
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n, m;
            n = in.nextInt();
            m = in.nextInt();
            ArrayList<ArrayList<Pair<Integer, Integer>>> adj = new ArrayList<>(n + 1);
            for (int i = 0; i < n + 1; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 1; i <= m; i++) {
                int src, dest;
                src = in.nextInt();
                dest = in.nextInt();
                adj.get(src).add(Pair.create(dest, 1));
                adj.get(dest).add(Pair.create(src, 1));
            }

            int[] distance = new int[n + 1];
            int[] predecessors = new int[n + 1];
            Arrays.fill(distance, Integer.MAX_VALUE);
            Dijkstras(1, n, distance, adj, predecessors);
            if (distance[n] == Integer.MAX_VALUE)
                System.out.println("IMPOSSIBLE");
            else {
                System.out.println(distance[n] + 1);
                PrintPath(1, n, predecessors);
            }
        }

    }
}

