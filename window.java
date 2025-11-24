import java.util.Scanner;

public class SimpleSlidingWindow {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter total number of frames: ");
        int n = sc.nextInt();

        System.out.print("Enter window size: ");
        int window = sc.nextInt();

        System.out.println("\nSending frames using Sliding Window Protocol:\n");

        int frame = 1;

        while (frame <= n) {
            System.out.print("Window: ");

            for (int i = 0; i < window && frame + i <= n; i++) {
                System.out.print((frame + i) + " ");
            }

            System.out.println("\nACK received for this window.\n");

            frame += window; // slide window
        }

        sc.close();
    }
}
