import java.util.*;
import java.io.*;

public class calls {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int t = readInt();
        String[] cases = new String[t];
        for (int i = 0; i < t; ++i) {
            cases[i] = readLine();
        }

        for (int i = 0; i < t; ++i) {
            String s = cases[i];
            String temp = "";
            s = s.replaceAll("-", "");
            for (int j = 0; j < 10; ++j) {
                int n = s.charAt(j);
                if (n < 58) {
                    temp += s.charAt(j);
                } else if (n <= (int) 'C') {
                    temp += "2";
                } else if (n <= (int) 'F') {
                    temp += "3";
                } else if (n <= (int) 'I') {
                    temp += "4";
                } else if (n <= (int) 'L') {
                    temp += "5";
                } else if (n <= (int) 'O') {
                    temp += "6";
                } else if (n <= (int) 'S') {
                    temp += "7";
                } else if (n <= (int) 'V') {
                    temp += "8";
                } else {
                    temp += "9";
                }
                if (j == 2 || j == 5) temp += "-";
            }
            cases[i] = temp;
        }
        for (int i = 0; i < t; ++i) {
            System.out.println(cases[i]);
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static char readChar() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
}